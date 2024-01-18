#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurences;
        for (int& elem : arr)
            occurences[elem] += 1;

        for (auto iter = occurences.begin() ; iter != occurences.end() ; iter++)
            for (auto iter2 = next(iter) ; iter2 != occurences.end() ; iter2++)
                if (iter2->second == iter->second) return false;

        return true;
    }
};