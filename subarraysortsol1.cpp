/*
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25191994#overview



*/



#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

vector<int> subarraysort(vector<int> nums)
{
    vector<int> result(2, 0);
    int n = nums.size(), s = 0, e = n - 1, mini  = 0, maxi = 0;

    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] < nums[i]) {
            s = i;
            break;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (nums[i  - 1] > nums[i]) {
            e = i;
            break;
        }
    }
    if ((s == 0) && (e == n - 1)) {
        result[0] = -1;
        result[1] = -1;
        cout << "unsorted index is " << result[0] << " " << result[1] << endl;
        return result;
    }
    mini = nums[s];
    maxi = nums[s];
    for (int i = s; i <= e; i++) {
        mini = min(mini, nums[i]);
        maxi = max(maxi, nums[i]);
    }
    for (int i = 0; i < s; i++) {
        if (nums[i] > mini) {
            s = i;
            break;
        }
    }
    for (int i = e + 1; i < n; i++) {
        if (nums[i] < maxi) {
            e = i;
            break;
        }
    }
    result[0] = s;
    result[1] = e;

   
   
     return result;

}

int main() {
    vector<int> array{ 1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11 }, sortI(2, 0);

    sortI = subarraysort(array);

   
    cout << "unsorted index is " << sortI[0] <<  " " << sortI[1] << endl;
    return 0;
}
