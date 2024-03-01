#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

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
        if (totalSum % 3 == 0) {
            cout << "0";
        }
        else {
            cout << totalSum;
        }

        cout << endl;
    }
    return 0;
}