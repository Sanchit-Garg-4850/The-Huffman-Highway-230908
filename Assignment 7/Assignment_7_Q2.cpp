#include <bits/stdc++.h>
using namespace std;

struct item{
    int weight;
    int value;
    int limit;
    int category;
};


pair<int, int> preprocess(int idx, vector<int>& weights, vector<int>& values, vector<int>& dependencies, unordered_map<int, pair<int, int>>& updated_stats) {
    if (dependencies[idx] == -1) {
        return {weights[idx], values[idx]};
    }

    if (updated_stats.find(idx) != updated_stats.end()) {
        return updated_stats[idx];
    }

    auto curr_idx = preprocess(dependencies[idx], weights, values, dependencies, updated_stats);
    updated_stats[idx] = {weights[idx] + curr_idx.first, values[idx] + curr_idx.second};
    return updated_stats[idx];
}

int knapsack(int W, vector<item>& items) {
    vector<int> dp(W + 1, 0);
    unordered_map<int, int> category_max;

    for (auto& item : items) {
        vector<int> new_dp = dp;
        for (int k = 1; k <= item.limit; k++) {
            for (int w = W; w >= item.weight * k; w--) {
                new_dp[w] = max(new_dp[w], dp[w - item.weight * k] + item.value * k);
            }
        }
        dp = new_dp;
        category_max[item.category] = max(category_max[item.category], dp[W]);
    }
    int result = 0;
    for (auto& [_, max_val] : category_max) {
        result += max_val;
    }

    return result;
}

int main() {
    
    int N = 10;
    int W = 100;
    
    vector<int> weights = {10, 20, 30, 40, 15, 25, 35, 45, 55, 50};
    
    vector<int> values = {60, 100, 120, 240, 150, 90, 200, 170, 250, 300};
    
    vector<int> dependencies = {-1, 0, -1, 2, -1, -1, 1, 4, -1, 7} ;
    
    vector<int> categories = {1, 0, 0, 1, 2, 2, 3, 3, 4, 4} ;
    
    vector<int> limits = {1, 2, 1, 1, 1, 1, 1, 1, 1, 1} ;

    vector<item> items;
    unordered_map<int, pair<int, int>> updated_stats;

    for (int i = 0; i < N; i++) {
        auto [weight, value] = preprocess(i, weights, values, dependencies, updated_stats);
        items.push_back({weight, value, limits[i], categories[i]});
    }

    cout << "Maximum Knapsack Value: " << knapsack(W,items) << endl;
    
    return 0 ;
}