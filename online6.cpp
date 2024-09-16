#include <bits/stdc++.h>
using namespace std;
struct Bag {
    int volume;
    int weight;
};

struct Element {
    int weight;
    int profit;
};

int knapsack(const vector<Element>& elements, int weightLimit) {
    int n = elements.size();
     vector< vector<int>> dp(n + 1,  vector<int>(weightLimit + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= weightLimit; ++w) {
            if (elements[i - 1].weight <= w) {
                dp[i][w] =  max(elements[i - 1].profit + dp[i - 1][w - elements[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][weightLimit];
}

int main() {
    int containerVolume = 15;
     vector<Bag> bags = {
        {5, 8},
        {5, 8},
        {8, 9}
    };

     vector<vector<Element>> elementsForBags = {
        {{2, 5}, {4, 6}, {3, 1}, {1, 4}},
        {{3, 1}, {2, 3}, {1, 2}, {5, 4}},
        {{1, 3}, {2, 6}, {3, 5}, {7, 1}}
    };

    int totalProfit = 0;
     vector<int> selectedBags;

    for (int i = 0; i < bags.size(); ++i) {
        int maxProfit = knapsack(elementsForBags[i], bags[i].weight);
        totalProfit += maxProfit;
        selectedBags.push_back(maxProfit > 0 ? 1 : 0);
    }

     cout << "Container : Max profit : " << totalProfit << " bags selected: ";

    for (int bagSelected : selectedBags) {
         cout << bagSelected << " ";
    }
     cout << endl;

    return 0;
}
