#include <bits/stdc++.h>

using namespace std;
int main()
{
    map<int, string> ordered_map;
    ordered_map[1] = "One";
    ordered_map[3] = "Three";
    ordered_map[2] = "Two";

    ordered_map.insert({5, "Five"});
    ordered_map.insert({4, "Four"});
    ordered_map.insert({6, "Six"});

    cout << "Size of ordered_map: " << ordered_map.size() << endl;

    cout << "Is ordered_map empty? ";
    if (ordered_map.empty())
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;

    cout << "Ordered Map Elements: ";
    for (auto p : ordered_map)
    {
        cout << "[" << p.first << " -> " << p.second << "] ";
    }
    cout << endl;
    cout << "Value of key 3: " << ordered_map[3] << endl;

    if (ordered_map.contains(2))
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
    unordered_map.insert({6, "Six"});

    cout << "Unordered Map Elements: ";

    for (auto p : unordered_map)
    {
        cout << "[" << p.first << " -> " << p.second << "] ";
    }
    cout << endl;

    cout << "Does key 5 exist? " << (unordered_map.contains(5) ? "Yes" : "No") << endl;
    unordered_map.erase(1);

    cout << "After erasing key 1, size: " << unordered_map.size() << endl;

    return 0;
}