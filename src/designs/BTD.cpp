#include "BTD.h"
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include "../utils/utils.h"


using namespace std;

design::BalancedTournamentDesign::BalancedTournamentDesign(int n) : TournamentDesign(n) 
{
    assert (this->n > 2 && "Invalid side parameter");

    this->design = this->construct_design(this->n);
    
    //assert (this->validate_design() && "Failed at constructing the design");
}


design::BalancedTournamentDesign::BalancedTournamentDesign(int n, string filename) : TournamentDesign(n) 
{
    assert (this->n > 2 && "Invalid side parameter");

    this->design = this->read_design(this->n, filename);
    
    //assert (this->validate_design() && "Design from file is not a valid BTD");

}



vector<vector<set<int>>> design::BalancedTournamentDesign::construct_design(int n)
{
    if(n == 4 or n == 6)
        return this->construct_manual(n);
    
    
    if(n % 2 == 1)
        return this->construct_odd_side(n);
    
    else
        return this->construct_even_side(n);


}

bool design::BalancedTournamentDesign::validate_design()
{
    // rule no 1: every unordered pair appears exactly once in the array
    // rule no 2: every row contains every element of V exactly once
    // rule no 3: balanced property: every element of V appears in each column once or twice

    for(int row=0; row < this->n_rounds; row++)
    {
        std::vector<int> elements(this->n_teams, 0);
        for(auto pair: this->design[row])
        {
            int el_1 = *pair.begin();
            int el_2 = *(++pair.begin());

            if( el_1 < 0 || el_1 >= this->n_teams || el_2 < 0 || el_2 >= this->n_teams )
            { 
                cout << "Pair (" << el_1 << "," << el_2 << ") out of teams number scope [0," << this->n_teams -1 << "]" << endl;
                return false;
            }
            elements[el_1] += 1;
            elements[el_2] += 1;
        }

        int  num_incorrect_courts = count_if(elements.begin(), elements.end(), [](int i) {return i!=1;});
        if(num_incorrect_courts > 0)
        {
            cout << "Error in row " << row << endl;
            return false;
        }

    }

    std::vector<vector<int>> elements(this->n_courts, vector<int>(this->n_teams, 0));
    for(int col=0; col < this->n_courts; col++)
    {
        for(int row=0; row < this->n_rounds; row++)
        {
            elements[col][ * this->design[row][col].begin() ] += 1;
            elements[col][ * (++this->design[row][col].begin()) ] += 1;
        }
    }
    
    for(auto col=0; col < this->n_courts; col++)
    {
        int num_incorrect = count_if(elements[col].begin(), elements[col].end(), [](int i) {return i!=1 && i !=2;});
        if (num_incorrect > 0)
        {
            cout << "Error in column " << col << endl;
            return false;
        }
    }

    // check that every unordered pair occurs exactly once
    map<pair<int,int>, int> pairs;
    for(auto row : this->design)
        for(auto p: row)
        {
            int i = *p.begin();
            int j = *(++p.begin());
            int min = i <= j ? i : j;
            int max = i > j ? i : j;
            pairs[pair<int, int>(min, max)] = 1;
        }

    return pairs.size() == this->n_teams* (this->n_teams - 1) / 2.; 
}



std::vector<std::vector<std::set<int>>> design::BalancedTournamentDesign::construct_even_side(int n)
{
    std::vector<std::vector<std::set<int>>> upper_left = this->construct_design(n/2);

    std::vector<std::vector<std::set<int>>> upper_right = vector<vector<set<int>>>(n - 1, vector<set<int>>(n/2, set<int>({1, 2}))); 


    std::vector<std::vector<std::set<int>>> lower =  vector<vector<set<int>>>(n, vector<set<int>>(n, set<int>({3, 4}))); // call to construct a join of 2 orthogonal mates of Latin Squares of order n

    for(auto i=0; i<n-1; i++ )
    {

        upper_left[i].insert(std::end(upper_left[i]), std::begin(upper_right[i]), std::end(upper_right[i]));
    }

    upper_left.insert(std::end(upper_left), std::begin(lower), std::end(lower));

    return upper_left;
}



vector<vector<set<int>>> design::BalancedTournamentDesign::construct_odd_side(int n)
{
    int k = (n-1)/2;
    cout << "k = " << k << endl;
    vector<vector<vector<int>>> main(2*n-1, vector<vector<int>>(n, vector<int>(2, 0)));
    vector<vector<vector<int>>> index(2*n-1, vector<vector<int>>(n, vector<int>(2, -1)));

    main[0][0][0] = 0;
    main[0][0][1] = 0;

    for(int col= 0; col < n; col++)
    {
        index[0][col][0] = 1;
        index[0][col][1] = 2;

        for(int row=0; row < 2*n -1; row++)
        {
            if(row > 0)
            {
                //first term (indexing: row, column, term)
                main[row][0][0] = (row - 1) % k + 1;
                //second term
                main[row][0][1] =  2*k - (row -1) % k ;
            }

            if( 1 <= row && row <= k)
            {
                index[row][col][0] = 1;
                index[row][col][1] = 1;
            }
            else if (k+1 <= row && row <= 2*k)
            {
                index[row][col][0] = 2;
                index[row][col][1] = 2;
            }
            else if(2*k+1 <= row && row <= 3*k)
            {
                index[row][col][0] = 1;
                index[row][col][1] = 2;
            }
            else
            {
                index[row][col][0] = 2;
                index[row][col][1] = 1;
            }

            if(col > 0)
            {   
                main[row][col][0] = (main[row][col-1][0] +1) % n;
                main[row][col][1] = (main[row][col-1][1] +1) % n;
            }
        }
    }

    /*
    cout << "MAIN" << endl;
    for(auto row: main)
    {
        for(auto pair: row)
        {
            cout << pair[0] << " " << pair[1] << ";";
        }
        cout << endl;
    }

    cout << endl << "INDEX" << endl;
    for(auto row: index)
    {
        for(auto pair: row)
        {
            cout << pair[0] << " " << pair[1] << ";";
        }
        cout << endl;
    } 
    */

    // calculate solution i for rows 1 to 4k: y - x = -2i mod (2k+1)
    vector<int> i_s;
    for(int i=1; i<2*n-1; i++)
    {
        i_s.push_back(modulo_solver(n, main[i][0][1] - main[i][0][0], [](int j){return -2*j;} ));
    }

    /* cout << "I_s" << endl;
    for(int i=1; i<2*n -1; i++)
        cout <<"row " << i << " i " << i_s[i-1] << endl; 
    */

    for(int r=1; r <= k; r++)
    {
        get_coset(main[r], 0);
    }


    return vector<vector<set<int>>>(2*n -1 , vector<set<int>>(n, set<int>({3, 4})));
}



vector<vector<set<int>>> design::BalancedTournamentDesign::construct_manual(int n)
{
    assert ((n == 4 || n == 6 ) && "Invalid side argument for construct manual"); 
    
    cout << "Manual construction of BTD(" << n << ")" << endl;

    string filename = "./src/templates/FBTD_" + std::to_string(n) + ".in";

    return TournamentDesign::read_design(n, filename);
}   

