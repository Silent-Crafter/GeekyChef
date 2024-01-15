/*
 * Given an array of size N-1 such that it only contains
 * distinct integers in the range of 1 to N. Find the missing element.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int missingNumber(vector<int>& array, int n) {
        vector<int> bucket(n+1, 0);
        for ( int num : array ) {
            bucket[num]++;
        }

        int i = 0;
        while ( bucket[++i] != 0 )
            ;
        return i;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.missingNumber(array, n) << "\n";
    }
    return 0;
}
