#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

bool solve(ll n, ll value) {
    if (n == value) {
        return true;
    }
    if (value > n) {
        return false;
    }
    bool value1 = solve(n, value * 10);
    bool value2 = solve(n, value * 20);

    return value1 || value2;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        ll n;
        cin >> n;
        if (solve(n, 1)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}