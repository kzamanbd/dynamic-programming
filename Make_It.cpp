#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool makeIt(ll n, ll value, map<ll, bool>& dp) {
    if (value > n) {
        return false;
    }
    if (n == value) {
        return true;
    }
    if (dp.count(value)) {
        return dp[value];
    }
    bool value1 = makeIt(n, value + 3, dp);
    bool value2 = makeIt(n, value * 2, dp);
    dp[value] = value1 || value2;
    return dp[value];
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        map<ll, bool> dp;
        if (makeIt(n, 1, dp)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}