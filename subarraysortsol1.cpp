/*
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/25191994#overview
Solution: 
Example array -> [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
1) Find the candidate unsorted subarray 
a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. In the above example 1, s is 3 (index of 30). 
b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). Let e be the index of such an element. In the above example 1, e is 7 (index of 31).
2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray. 
a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively. 
b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1. 
c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)
3) Print s and e.
Implementation: 
 


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
