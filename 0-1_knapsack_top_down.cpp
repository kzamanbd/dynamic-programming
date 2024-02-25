#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int dp[100][100];

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

    int N, W;
    cin >> N >> W;
    int value[N], weight[N];
    for (int i = 0; i < N; i++) {
        int v, w;
        cin >> w >> v;
        value[i] = v;
        weight[i] = w;
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(N, W, value, weight);
    return 0;
}