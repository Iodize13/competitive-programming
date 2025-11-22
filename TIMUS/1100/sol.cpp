// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    solve();
}

void merge(vector<pair<int, int> > &a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<pair<int, int> > L(n1), R(n2);
    rep(i,0,n1) L[i] = a[l+i];
    rep(i,0,n2) R[i] = a[m+1+i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if (L[i].se >= R[j].se) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<pair<int, int> >& a, int left, int right) {
    if (left >= right) return;

    int mid = midpoint(left, right);
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge(a, left, mid, right);
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for (auto &[x, f]: a) {
        cin >> x >> f;
    }

    mergeSort(a, 0, n-1);
    for (auto &[x, f]: a) cout << x << ' ' << f << '\n';
}

