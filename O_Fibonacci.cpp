#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;


int fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;
    cin >> n;
    cout << fibonacci(n - 1);
    return 0;
}