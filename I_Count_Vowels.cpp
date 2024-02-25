#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;

int countVowels(string str, int i) {

    if (str.size() < i) {
        return 0;
    }

    int val = countVowels(str, i + 1);
    int count = 0;
    if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
        count = 1;
    }
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
        count = 1;
    }
    return val + count;
}

int main() {

    string str;

    getline(cin, str);
    cout << countVowels(str, 0);
    return 0;
}