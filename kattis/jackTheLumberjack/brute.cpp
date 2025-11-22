#include <bits/stdc++.h>
#define int long long
using namespace std;

struct node {
    int y, i , s , b, val = 0;
};

void sol() {
    int n;cin >> n;
    vector<node> A(n);
    int mx = 0;
    for (int j = 0; j < n; j++) {
        cin >> A[j].y >> A[j].i >> A[j].s >> A[j].b;
        mx = max(mx, A[j].b + 2*A[j].y);
    }

    int ans = 0;
    for (int j = 0; j <= mx; j++) {
        int tmp = 0;
        for (int k = 0; k < n ;k++) {
            if (j == A[k].b) {
                A[k].val += A[k].s;
            }
            if (j > A[k].b && j <= A[k].b + A[k].y) {
                A[k].val += A[k].i;
            } else if (j > A[k].b && j > A[k].b + A[k].y){
                A[k].val -= A[k].i;
            }
            // if (k == 2) cerr << "test: " << A[k].val << '\n';
            tmp += max(0LL, A[k].val);
            // if (j == 5) cerr << max(0LL, A[k].val) << '\n';
        }
        if (ans < tmp) {
            // cerr << "j: " << j << '\n';
            ans = max(ans, tmp);
        }
    }
    cout << ans << '\n';
}
int32_t main() {
    sol();
}
