#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

using namespace std;

struct RollbackUF {
    vector<int>  e;
    RollbackUF(int n): e(n, -1) {}
    int size(int x) {return -e[find(x)]; }
    int find(int x) {return e[x] < 0 ? x :find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;

    }
};

void sol() {
    int N, K; cin >> N >> K;
    RollbackUF UF(N);
    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        --u, --v;
        UF.join(u, v);
    }
    for (int i = 0; i < N / 2; i++) {
        if (UF.join(i, N - i - 1)) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int32_t main() {
    sol();
}
