#include<bits/stdc++.h>

using namespace std;

int rand(int lo, int hi) {
    return lo + rand() % (hi - lo + 1);
}

void runcase() {
    int n = rand(2, 10);
    int x = rand(1, 10);
    vector<int> a(n);
    vector<int> b(n);
    a[0] = rand(1, 10);
    for (int i = 1 ; i < n; i++) {
        a[i] = a[i - 1] * rand(1, 10);
    }
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
        if (rand() % 2) b[i] *= x;
    }
    cout << 1 << '\n';
    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << ' ';
    cout << '\n';
}

int32_t main(int32_t argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    srand(atoi(argv[1]));
    while(tt--) {
        runcase();
    }
	return 0;
}
