#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

void gen() {
    cout << 1 << '\n';
    cout << rand(1, 5) << ' ' << rand(1, 5) << '\n';
}

int32_t main(int32_t argc, char *argv[]) {
    srand(atoi(argv[1]));
    gen();
}
