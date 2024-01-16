#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection {
private:
    std::unordered_multimap<int, int> indices;
    vector<int> randColl;

public:
    RandomizedCollection() {
        ios_base::sync_with_stdio(false);
        srand(time(nullptr));
    }

    bool insert(int val) {
        bool ret_val = (indices.find(val) == indices.end());

        randColl.push_back(val);
        indices.insert({val, randColl.size() - 1});

        return ret_val;
    }

    bool remove(int val) {
        auto elementToRemove = indices.find(val);
        if (elementToRemove == indices.end()) return false;

        int lastIndex = (int)randColl.size() - 1;
        int lastElement = randColl.back();

        auto elementToSwap = std::find_if(indices.begin(), indices.end(), [lastIndex, lastElement](pair<int, int> p) {
            return p.first == lastElement && p.second == lastIndex;
        });


        swap(randColl[elementToRemove->second], randColl[lastIndex]);
        elementToSwap->second = elementToRemove->second;

        indices.erase(elementToRemove);
        randColl.pop_back();

        return true;
    }

    inline int getRandom() { return randColl[rand() % randColl.size()]; }
};


int main() {
    RandomizedCollection randomizedSet;
    cout << std::boolalpha
         << randomizedSet.insert(10)   << "  "
         << randomizedSet.insert(10)   << "  "
         << randomizedSet.insert(20)   << "  "
         << randomizedSet.insert(20)   << "  "
         << randomizedSet.insert(30)   << "  "
         << randomizedSet.insert(30)   << "  "
         << randomizedSet.remove(10)   << "  "
         << randomizedSet.remove(20)   << "  "
         << randomizedSet.remove(20)   << "  "
         << randomizedSet.remove(10)   << "  "
         << randomizedSet.remove(30)   << "  "
         << randomizedSet.insert(40)   << "  "
         << randomizedSet.remove(30)   << "  "
         << randomizedSet.remove(30)   << "  "
         << randomizedSet.getRandom()  << "  "
         << endl;
    return 0;
}
