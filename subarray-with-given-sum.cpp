/*
 * Given an unsorted array A of size N that contains only non-negative integers,
 * find a continuous sub-array that adds to a given number S and
 * return the left and right index(1-based indexing) of that subarray.
 * In case of multiple sub-arrays, return the sub-array indexes which comes
 * first on moving from left to right.
 *
 * Note:- You have to return an ArrayList consisting of two elements left and right.
 * In case no such subarray exists return an array consisting of element -1.
 *
 * Example 1:
 *
 * Input:
 * 5 12
 * 1 2 3 7 5
 * Output:
 * 2 4
 *
 * Explanation: The sum of elements
 * from 2nd position to 4th position
 * is 12.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        int sum = 0;
        int f = -1, l = -1;
        int i;
        for ( i = 0 ; i < arr.size() ; i++ ) {
            int elem = arr[i];
            if ( s < elem ) {
                sum = 0;
                f = -1;
                continue;
            }

            sum += elem;

            if ( f == -1 )
                f = i + 1;

            while ( sum > s ) {
                sum -= arr[f-1];
                f += 1;
            }

            if ( sum == s ) {
                l = i + 1;
                break;
            }
        }

        if ( l == -1 ) return {-1};
        else return {f, l};
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);

        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;

    }
    return 0;
}