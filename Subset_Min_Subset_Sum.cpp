#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    bool dp[n + 1][totalSum + 1];
    dp[0][0] = true;

    for (int i = 1; i <= totalSum; i++) {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= totalSum; j++) {
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

    vector<int> res;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= totalSum; j++) {
            if (dp[i][j]) {
                res.push_back(j);
            }
        }
    }
    int mn = INT_MAX;
    for (int val : res) {
        int s1 = val;
        int s2 = totalSum - s1;
        mn = min(mn, abs(s1 - s2));
    }
    cout << mn;
    return 0;
}