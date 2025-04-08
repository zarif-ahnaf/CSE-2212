#include <bits/stdc++.h>
using namespace std;
// Target ordered map and unordered map;
// CRUD
int main()
{
    unordered_map<int, string> um;
    um.insert({1, "One"});
    um[2] = "Two";

    if (um.find(2) != um.end())
    {
        um[2] = "TWo";
    }
    for (auto p : um)
    {
        cout << p.first << "," << p.second << " ";
    }

    um.erase(2);

    map<int, string> m;
    m.insert({1, "One"});
    m.insert({2, "One"});
    if (m.find(3) != m.end())
    {
        cout << "Found Three";
    }
}