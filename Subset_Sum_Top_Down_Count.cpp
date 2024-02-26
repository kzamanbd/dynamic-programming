#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int dp[1005][1005];


int subsetSum(int arr[], int n, int target) {

    if (n == 0) {
        return target == 0 ? 1 : 0;
    }

    if (dp[n][target] != -1) {
        return dp[n][target];
    }

    if (arr[n - 1] <= target) {
        int opt1 = subsetSum(arr, n - 1, target - arr[n - 1]);
        int opt2 = subsetSum(arr, n - 1, target);

        return dp[n][target] = opt1 + opt2;
    }
    else {
        return dp[n][target] = subsetSum(arr, n - 1, target);
    }
}

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    memset(dp, -1, sizeof(dp));
    cout << subsetSum(arr, n, target);
    return 0;
}