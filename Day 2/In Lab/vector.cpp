#include <bits\stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {10, 20, 30, 40, 50};
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max Size: " << v.max_size() << endl;

    v.push_back(60);
    v.insert(v.begin() + 2, 25);

    v.pop_back();
    v.erase(v.begin() + 1);

    cout << "First Element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;
    cout << "Element at index 1: " << v.at(1) << endl;

    v.resize(10, -1);
    v.reserve(50);

    cout << "Vector elements: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    cout << "Using Iterators: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << endl;
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