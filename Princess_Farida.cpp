#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
const int N = 1e4 + 5;
int dp[N];

int maxCoins(vector<int> arr, int i) {
    if (i <= 0) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    int val1 = maxCoins(arr, i - 1);
    int val2 = arr[i - 1] + maxCoins(arr, i - 2);
    return dp[i] = max(val1, val2);
}

int main() {

    int tc;
    cin >> tc;
    int output = 1;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << "Case " << output++ << ": " << maxCoins(arr, n) << endl;
    }
    return 0;
}