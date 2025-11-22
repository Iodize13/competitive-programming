#include <bits/stdc++.h>
#define int long long
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

void sol() {
    int n = rand(1, 5);
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << rand(0, 5) << ' ';
        cout << rand(0, 5) << ' ';
        cout << rand(0, 5) << ' ';
        cout << rand(0, 5) << ' ';
        cout << '\n';
    }
}

int32_t main(int32_t argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(atoi(argv[1]));
    sol();
}
