#include <bits/stdc++.h>
using namespace std;

int main()
{
    int item, capacity;
    cout << "Enter the number of items: ";
    cin >> item;

    vector<int> weights(item), profits(item);

    for (int i = 0; i < item; i++)
    {
        cout << "Enter the weight and profit of item " << i + 1 << ": ";
        cin >> weights[i] >> profits[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    vector<vector<int>> dp(item + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= item; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], profits[i - 1] + dp[i - 1][j - weights[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Maximum profit: " << dp[item][capacity] << endl;
    return 0;
}
