#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> _set = {10, 20, 30, 40, 50};
    cout << "Size: " << _set.size() << endl;
    cout << "Max Size: " << _set.max_size() << endl;
    cout << "Is empty? " << (_set.empty() ? "Yes" : "No") << endl;

    _set.insert(25);
    _set.insert(60);
    _set.insert(10);

    _set.erase(20);

    if (_set.contains(30))
    {
        _set.erase(30);
    };

    cout << "Does 40 exist? ";
    if (_set.contains(40))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    cout << endl;

    cout << "Set elements: ";
    for (auto p : _set)
        cout << p << " ";
    cout << endl;

    cout << "Lower bound of 25: " << *_set.lower_bound(25) << endl;
    cout << "Upper bound of 25: " << *_set.upper_bound(25) << endl;
    set<int> a = {1, 2, 3};
    set<int> b = {4, 5, 6};
    a.swap(b);

    cout << "After Swap - a: ";
    for (auto p : a)
        cout << p << " ";
    cout << endl;

    cout << "After Swap - b: ";
    for (auto p : b)
        cout << p << " ";
    cout << endl;
    return 0;
}