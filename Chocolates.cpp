#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

// bottom up approach
bool subsetSumBottomUp(vector<int> arr, int n, int target) {
    bool dp[n + 1][target + 1];
    dp[0][0] = true;
    for (int i = 1; i <= target; i++) {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (arr[i - 1] <= j) {
                bool opt1 = dp[i - 1][j - arr[i - 1]];
                bool opt2 = dp[i - 1][j];
                dp[i][j] = opt1 || opt2;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

const int N = 1e3 + 5;
int dp[N][N];

// top down approach
bool subsetSumTopDown(vector<int> arr, int n, int target) {
    if (n == 0) {
        return target == 0;
    }
    if (dp[n][target] != -1) {
        return dp[n][target];
    }
    if (arr[n - 1] <= target) {

        int opt1 = subsetSumTopDown(arr, n - 1, target - arr[n - 1]);
        int opt2 = subsetSumTopDown(arr, n - 1, target);
        dp[n][target] = opt1 || opt2;
        return dp[n][target];
    }
    else {
        dp[n][target] = subsetSumTopDown(arr, n - 1, target);
        return dp[n][target];
    }
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            totalSum += arr[i];
        }
        if (totalSum % 2 == 0) {
            int target = totalSum / 2;
            if (subsetSumBottomUp(arr, n, target)) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}