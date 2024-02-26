#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int n, m;

ll maxPathSum(vector<vector<int>> matrix, int i, int j) {
    if (i >= n || j >= m) {
        return INT_MIN;
    }
    if (i == n - 1 && j == m - 1) {
        return matrix[i][j];
    }

    ll rowSum = maxPathSum(matrix, i + 1, j);
    ll colSum = maxPathSum(matrix, i, j + 1);

    return max(rowSum, colSum) + matrix[i][j];
}

int main() {

    cin >> n >> m;
    vector < vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << maxPathSum(matrix, 0, 0);
    return 0;
}