#include "BTD.h"
#include <assert.h>
#include <iostream>

using namespace std;

design::BalancedTournamentDesign::BalancedTournamentDesign(int n) : TournamentDesign(n) 
{
    assert (this->n > 2 && "Invalid side parameter");

    this->design = this->construct_design(this->n);
    
    assert (this->validate_design() && "Failed at constructing the design");
}

vector<vector<int>> design::BalancedTournamentDesign::construct_design(int n)
{
    if(n == 4 or n == 6)
    {
        cout << "Manual construction of BTD(" << n << ")" << endl;
        return this->construct_manual(n);
    }
    
    if(n % 2 == 1)
    {
        return this->construct_odd_side(n);
    }
    else
    {
        return this->construct_even_side(n);
    }

}

bool design::BalancedTournamentDesign::validate_design()
{
    return true;
}



vector<vector<int>> design::BalancedTournamentDesign::construct_even_side(int n)
{
    vector<vector<int>> upper_left = this->construct_design(n/2);

    vector<vector<int>> upper_right = vector<vector<int>>(n - 1, vector<int>(n/2, -2)); 

    vector<vector<int>> lower_left =  vector<vector<int>>(n - 1, vector<int>(n/2, -3)); // call to construct 2 orthogonal mates of Latin Squares

    vector<vector<int>> lower_right = vector<vector<int>>(n - 1, vector<int>(n/2, -4));


    // TODO: not working (seg fault)
    for(auto i=0; i<n-1; i++ )
    {
        upper_left[i].insert(std::end(upper_left[0]), std::begin(upper_right[i]), std::end(upper_right[i]));
        lower_left[i].insert(std::end(lower_left[0]), std::begin(lower_right[i]), std::end(lower_right[i]));
    }

    cout << "AAAAA" << endl;

    upper_left.insert(std::end(upper_left), std::begin(lower_left), std::end(lower_left));

    return upper_left;
}



vector<vector<int>> design::BalancedTournamentDesign::construct_odd_side(int n)
{
    return vector<vector<int>>(2*n - 1, vector<int>(n, -1));
}



vector<vector<int>> design::BalancedTournamentDesign::construct_manual(int n)
{
    assert ((n == 4 || n == 6 ) && "Invalid side argument for construct manual"); 
    return vector<vector<int>>(2*n - 1, vector<int>(n, -1));  
}   


