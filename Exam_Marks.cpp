#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

bool isSubsetSum(vector<int> arr, int n, int target) {
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

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n, marks;
        cin >> n >> marks;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int target = 1000 - marks;
        if (target == 0) {
            cout << "YES";
        }
        else {
            if (isSubsetSum(arr, n, target)) {
                cout << "YES";
            }
            else {
                cout << "NO";
            }
        }
        cout << endl;
    }
    return 0;
}