#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;


vector<vector<int>> triplets(vector<int> arr, int sum) {
    vector<vector<int>> res;
    //sort array
    sort(arr.begin(), arr.end());
    // solve pair sum for remainning part
    int n = arr.size();
    for (int i = 0; i <= n - 3; i++) {
        // two pointer approach
        // for a[i] + rest of array j start from left and k start from right
        int j = i + 1; 
        int k = n - 1;
        // while j is smaller then k they will loop through
        while (j < k) {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];
            if (current_sum == sum) {
                res.push_back({ arr[i], arr[j], arr[k] });
                j++;
                k--;
            }
            else if (current_sum > sum) {
                k--;
            }
            else {
                j++;
            }
        }
    
    }
    return res;
}



int main() {
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S = 18;

    auto result = triplets(arr, S);

    for (auto v : result) {
        for (auto no : v) {
            cout << no << ",";
        }
        cout << endl;
    }
    
    
    
    
    return 0;
}
