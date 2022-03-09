/*
Problem Description: For given array and integer, find any pair which's sum is equal to given integer value
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24429114#overview
*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;


vector<int> pairsum(vector<int> a, int sum) {
    //PairSUM prblem with 0(n) time complexity with unordered set
    // Unordred set takes 0(1) time to access any elements 
    unordered_set <int> s1;
    //returing result in this res vector
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        // we need to find pair which's total is sum so for each a[i] other element's value is sum - a[i]
        int x = sum - a[i];
        //check if x is not in set
        if (s1.find(x) != s1.end()) {
            // if x is found in set then retrun x and a[i] to res vector
            res.push_back(x);
            res.push_back(a[i]);
            return res;
        }
        //insert each elements to set
        s1.insert(a[i]);
    
    }
    // return empty set if no pair found
    return {};
   
    
}



int main() {
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 15;

    auto result = pairsum(arr, S);

    if (result.size() == 0) {
        cout << " No Pair found ";
    }
    else
    {
        cout << result[0] << " " << result[1] << endl;
    }
    
    
    
    
    return 0;
}

