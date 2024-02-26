#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int dp[1005][1005];

int subsetSumCount(vector<int> arr, int n, int target) {

    if (n == 0) {
        return target == 0 ? 1 : 0;
    }

    if (dp[n][target] != -1) {
        return dp[n][target];
    }

    if (arr[n - 1] <= target) {
        int opt1 = subsetSumCount(arr, n - 1, target - arr[n - 1]);
        int opt2 = subsetSumCount(arr, n - 1, target);

        return dp[n][target] = opt1 + opt2;
    }
    else {
        return dp[n][target] = subsetSumCount(arr, n - 1, target);
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    int diff;
    cin >> diff;

    int target = (diff + totalSum) / 2;

    memset(dp, -1, sizeof(dp));
    cout << subsetSumCount(arr, n, target);

    return 0;
}