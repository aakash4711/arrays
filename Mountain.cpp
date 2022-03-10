/*
Given an array, find a maximum mountain length
https://www.udemy.com/course/cpp-data-structures-algorithms-levelup-prateek-narang/learn/lecture/24429144#overview
like for a{5,6,1,2,3,4,5,4,3,2,1,0,1,3,-2,4} = ans is 9 (1,2,3,4,5,4,3,2,1,0)
*/
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    vector<int> a{ 5,6,1,2,3,4,5,4,3,2,1,0,1,3,-2,4 };
    int S = 15;
    int n = a.size();
    int start = 0, pick = 0, stop = 1, count = 0, count_max = 0;

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i]) {
            if (stop == 1 || pick == 0) {
                start = 1;
                stop = 0;
                count++;
                cout << "a[" << i << "]:" << a[i] << " start: " << start << " stop: " << stop << " pick: " << pick << " count: " << count << " count_max: " << count_max << endl;
                cout << endl;
            }
            if (pick == 1) {
                stop = 1;
                pick = 0;
                start = 0;
                count++;
                if (count_max < count) {
                    count_max = count;
                }
                count = 0;
                cout << "a[" << i << "]:" << a[i] << " start: " << start << " stop: " << stop << " pick: " << pick << " count: " << count << " count_max: " << count_max << endl;
                cout <<  endl;
            }
        }
        else
        {
            if (start == 1) {
                pick = 1;
                count++;
                cout << "a[" << i << "]:" << a[i] << " start: " << start << " stop: " << stop << " pick: " << pick << " count: " << count << " count_max: " << count_max << endl;
                cout << endl;
            }
            //if (pick == 1) {
            //    count++;
           // }

        }

    }

    cout << "Mountain Height is " << count_max << endl;
    
    
    
    return 0;
}
