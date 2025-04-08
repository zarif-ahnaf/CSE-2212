#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {10, 20, 40};
    v.erase(v.begin() + 1);
    v.resize(10, -1);
    v.reserve(50);

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}