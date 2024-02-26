#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;
int dp[1000][1000];
int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            if (arr[i - 1] <= j) {
                int opt1 = dp[i - 1][j - arr[i - 1]];
                int opt2 = dp[i - 1][j];
                dp[i][j] = opt1 + opt2;
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][target];
    return 0;
}