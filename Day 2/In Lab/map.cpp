#include <bits\stdc++.h>
using namespace std;
int main()
{
    map<int, string> ordered_map;
    ordered_map[1] = "One";
    ordered_map[3] = "Three";
    ordered_map[2] = "Two";
    ordered_map.insert({5, "Five"});
    ordered_map.insert({4, "Four"});
    cout << "Size of ordered_map: " << ordered_map.size() << endl;
    cout << "Is ordered_map empty? " << (ordered_map.empty() ? "Yes" : "No") << endl;
    cout << "Ordered Map Elements: ";
    for (auto it : ordered_map)
    {
        cout << "[" << it.first << " -> " << it.second << "] ";
    }
    cout << endl;
    cout << "Value of key 3: " << ordered_map[3] << endl;

    if (ordered_map.find(2) != ordered_map.end())
    {
        cout << "Key 2 exists, erasing it." << endl;
        ordered_map.erase(2);
    }
    cout << "Lower bound of 3: " << ordered_map.lower_bound(3)->first << endl;
    cout << "Upper bound of 3: " << ordered_map.upper_bound(3)->first << endl;
    unordered_map<int, string> unordered_map;
    unordered_map[1] = "One";
    unordered_map[3] = "Three";
    unordered_map[2] = "Two";
    unordered_map.insert({5, "Five"});
    unordered_map.insert({4, "Four"});
    cout << "Unordered Map Elements: ";
    for (auto it : unordered_map)
    {
        cout << "[" << it.first << " -> " << it.second << "] ";
    }
    cout << endl;
    cout << "Does key 5 exist? " << (unordered_map.count(5) ? "Yes" : "No") << endl;
    unordered_map.erase(1);
    cout << "After erasing key 1, size: " << unordered_map.size() << endl;

    return 0;
}