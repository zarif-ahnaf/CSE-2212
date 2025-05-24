#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    double profit;
    double weight;
    double ratio;

    Item(double profit, double weight)
    {
        this->profit = profit;
        this->weight = weight;
        this->ratio = profit / weight;
    }
};

int main()
{
    int n;
    cin >> n;

    string id;
    cin >> id;

    string last_two = string(id.end() - 2, id.end());
    int last_two_int = stoi(last_two);

    int capacity = last_two_int % 10;
    vector<Item> data;

    for (int i = 0; i < n; i++)
    {
        int profit, weight;
        cin >> profit >> weight;
        data.push_back(Item(profit, weight));
    }

    sort(data.begin(), data.end(), [](const Item &a, const Item &b)
         { return a.ratio > b.ratio; });

    double totalProfit = 0.0;

    for (auto &item : data)
    {
        if(capacity == 0) break;

        if (capacity >= item.weight)
        {
            // Take the whole item
            capacity -= item.weight;
            totalProfit += item.profit;
            cout << "Taken full: " << item.profit << "-" << item.weight << "-" << item.ratio << ", Remaining Capacity: " << capacity << endl;
        }
        else
        {
            double fraction = capacity / item.weight;
            totalProfit += item.profit * fraction;
            cout << "Taken fraction: " << item.profit * fraction << "-" << capacity << "-" << item.ratio << endl;
            break;
        }
    }
    cout << "Total Profit: " << totalProfit << endl;

    return 0;
}
