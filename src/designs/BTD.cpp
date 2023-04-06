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

design::BalancedTournamentDesign::BalancedTournamentDesign(int n, string filename) : TournamentDesign(n) 
{
    assert (this->n > 2 && "Invalid side parameter");

    this->design = this->read_design(this->n, filename);
    
    assert (this->validate_design() && "Failed at constructing the design");
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



    return true;
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
    return vector<vector<set<int>>>(2*n - 1, vector<set<int>>(n, set<int>{5, 6}));
}



vector<vector<set<int>>> design::BalancedTournamentDesign::construct_manual(int n)
{
    assert ((n == 4 || n == 6 ) && "Invalid side argument for construct manual"); 
    
    cout << "Manual construction of BTD(" << n << ")" << endl;

    return vector<vector<set<int>>>(2*n - 1, vector<set<int>>(n, set<int>{7, 8}));
}   


