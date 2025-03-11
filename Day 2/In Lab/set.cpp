#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s = {10, 20, 30, 40, 50};
    cout << "Size: " << s.size() << endl;
    cout << "Max Size: " << s.max_size() << endl;
    cout << "Is empty? " << (s.empty() ? "Yes" : "No") << endl;

    s.insert(25);
    s.insert(60);
    s.insert(10);

    s.erase(20);
    auto it = s.find(30);
    if (it != s.end())
        s.erase(it);
    cout << "Does 40 exist? " << (s.count(40) ? "Yes" : "No") << endl;

    cout << "Set elements: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    cout << "Lower bound of 25: " << *s.lower_bound(25) << endl;
    cout << "Upper bound of 25: " << *s.upper_bound(25) << endl;
    set<int> a = {1, 2, 3};
    set<int> b = {4, 5, 6};
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