/*
Largest Band Problem
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24429164#overview

*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longest_band(vector<int> nums)
{
    int longest_band = 0;
    unordered_set<int> s1;
    unordered_set<int>:: iterator it;
    int temp = 0, head = 0, next = 0, count = 0;
    it = s1.begin();
    for (int i = 0; i < nums.size(); i++) {
        s1.insert(nums[i]);
    }
    for (it = s1.begin(); it != s1.end(); it++)
    {
        temp = *it;
        if (s1.find(temp - 1) == s1.end()) {
            next = temp + 1;
            count = 1;
            while (s1.find(next) != s1.end()) {
                next++;
                count++;
            }
            
            if (longest_band < count) {
                longest_band = count;
            }
           
        
        }
    }

     return longest_band;
}

int main() {
    vector<int> a{1,9,3,0,18,5,2,4,10,7,12,6};
    int count_max = longest_band(a);

   
    cout << "Longest Band is: " << count_max << endl;
    return 0;
}

