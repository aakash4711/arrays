/*
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25192002#overview
*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

int trappedwater(vector<int> nums)
{
    int water= 0;
    int n = nums.size();
    vector<int> left(n, 0), right(n,0); 
    left[0] = nums[0];
    right[n - 1] = nums[n - 1];
    if (n <= 2) { return 0;  }
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], nums[i]);
        right[n - i - 1] = max(right[n - i], nums[n - i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - nums[i];
    
    }
     return water;
}

int main() {
    vector<int> water{0,1,0,2,1,0,1,3,2,1,2,1};
    int water_max = trappedwater(water);

   
    cout << "Capacity is : " << water_max << endl;
    return 0;
}

