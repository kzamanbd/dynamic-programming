#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {
        int a, b, l;
        cin >> a >> b >> l;

        vector<int> arr;

        for (int i = 1; i <= sqrt(l); ++i) {
            if (l % i == 0) {
                arr.push_back(i);
                if (i != l / i) {
                    arr.push_back(l / i);
                }
            }
        }

        int count = 0;

        for (int k : arr) {
            int x = 0;
            while (k % a == 0) {
                k /= a;
                x++;
            }

            int y = 0;
            while (k % b == 0) {
                k /= b;
                y++;
            }

            if (k == 1) {
                count++;
            }
        }

        cout << count << endl;

    }
    return 0;
}