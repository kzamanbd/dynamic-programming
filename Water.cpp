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
        int firstMax = INT_MIN, index1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > firstMax) {
                firstMax = arr[i];
                index1 = i;
            }
        }

        int secondMax = INT_MIN, index2 = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != firstMax) {
                if (arr[i] > secondMax) {
                    secondMax = arr[i];
                    index2 = i;
                }
            }
        }

        if (index1 > index2) {
            cout << index2 << " " << index1;
        }
        else {
            cout << index1 << " " << index2;
        }
        cout << endl;
    }
    return 0;
}