#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
private:
    std::unordered_map<int, int> indices;
    std::vector<int> randomSet;
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
    }

    inline bool exists(int val) {
        return (indices.find(val) != indices.end());
    }

    bool insert(int val) {
        if (exists(val)) return false;

        randomSet.push_back(val);
        indices[val] = (int)randomSet.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (!exists(val)) return false;

        auto iter = indices.find(val);
        int index = iter->second;
        int back = randomSet.back();

        indices[back] = index;
        swap(randomSet[index], randomSet[randomSet.size()-1]);

        indices.erase(val);
        randomSet.pop_back();

        return true;
    }

    inline int getRandom() {
        return randomSet[rand() % randomSet.size()];
    }
};

int main() {
    RandomizedSet randomizedSet;
    cout << std::boolalpha
         << randomizedSet.insert(1)   << "  "
         << randomizedSet.remove(2)   << "  "
         << randomizedSet.insert(2)   << "  "
         << randomizedSet.getRandom() << "  "
         << randomizedSet.remove(1)   << "  "
         << randomizedSet.insert(2)   << "  "
         << randomizedSet.getRandom()
         << endl;
}
