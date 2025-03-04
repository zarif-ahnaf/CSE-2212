#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> _vector = {10, 20, 30, 40, 50, 60};
    cout << "Size: " << _vector.size() << endl;
    cout << "Capacity: " << _vector.capacity() << endl;
    cout << "Max Size: " << _vector.max_size() << endl;

    _vector.push_back(60);
    _vector.insert(_vector.begin() + 2, 25);

    _vector.pop_back();
    _vector.erase(_vector.begin() + 1);

    cout << "First Element: " << _vector.front() << endl;
    cout << "Last Element: " << _vector.back() << endl;
    cout << "Element at index 1: " << _vector.at(1) << endl;

    _vector.resize(10, -1);
    _vector.reserve(50);

    cout << "Vector elements: ";
    for (auto p : _vector)
        cout << p << " ";
    cout << endl;

    cout << "Using Iterators: ";
    for (auto it = _vector.begin(); it != _vector.end(); ++it)
        cout << *it << " ";

    cout << endl;
    cout << "Is empty? " << (_vector.empty() ? "Yes" : "No") << endl;
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    a.swap(b);

    cout << "After Swap - a: ";
    for (int x : a)
        cout << x << " ";
    cout << endl;
    cout << "After Swap - b: ";
    for (int x : b)
        cout << x << " ";
    cout << endl;
    return 0;
}