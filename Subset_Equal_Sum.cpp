#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

bool subsetSumTopDown(vector<int> arr, int n, int target) {
    if (n == 0) {
        return target == 0;
    }
    if (arr[n - 1] <= target) {

        int opt1 = subsetSumTopDown(arr, n - 1, target - arr[n - 1]);
        int opt2 = subsetSumTopDown(arr, n - 1, target);
        return opt1 || opt2;
    }
    else {
        return subsetSumTopDown(arr, n - 1, target);
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    if (totalSum % 2 == 0) {
        int target = totalSum / 2;
        if (subsetSumTopDown(arr, n, target)) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }
    else {
        cout << "NO";
    }
    return 0;
}