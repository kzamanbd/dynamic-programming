#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
int const N = 1e3 + 5;
int dp[N][N];

int knapsack(int n, int w, int value[], int weight[]) {

    if (n == 0 || w == 0) {
        return 0;
    }
    if (dp[n][w] != -1) {
        return dp[n][w];
    }
    if (weight[n - 1] <= w) {
        int opt1 = knapsack(n - 1, w - weight[n - 1], value, weight) + value[n - 1];
        int opt2 = knapsack(n - 1, w, value, weight);
        return dp[n][w] = max(opt1, opt2);
    }
    else {
        int opt3 = knapsack(n - 1, w, value, weight);
        return dp[n][w] = opt3;
    }
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n, w;
        cin >> n >> w;
        int value[n], weight[n];
        for (int i = 0; i < n; i++) {
            cin >> weight[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> value[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << knapsack(n, w, value, weight) << endl;
    }
    return 0;
}