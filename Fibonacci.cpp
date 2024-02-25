#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

// bottom up
void solve(int n) {
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    cout << arr[n - 1];
}

int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;
    // solve(n);
    cout << fibonacci(n);
    return 0;
}