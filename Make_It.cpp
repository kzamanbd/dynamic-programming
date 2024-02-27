#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

bool makeIt(int n, int value) {
    if (value > n) {
        return false;
    }
    if (n == value) {
        return true;
    }

    if (dp[value] != -1) {
        return dp[value];
    }

    bool value1 = makeIt(n, value + 3);
    bool value2 = makeIt(n, value * 2);

    return dp[value] = value1 || value2;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        if (makeIt(n, 1)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}