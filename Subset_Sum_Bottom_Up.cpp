#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    bool dp[n + 1][target + 1];
    dp[0][0] = true;
    for (int i = 1; i <= n; i++) {
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
    if (dp[n][target]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}