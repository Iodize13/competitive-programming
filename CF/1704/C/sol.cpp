#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> A(m);
    for (int i = 0; i < m ;i++) 
        cin >> A[i];

    sort(all(A));

    vector<int> B(m);
    for (int i = 1; i < m; i++) B[i - 1] = A[i] - A[i - 1] - 1;

    B[m - 1] = A[0] + (n - A[m - 1]) - 1;

    sort(all(B), greater<int>());
    int ans = m;
    for (int i = 0; i < m; i++) {
        if (i * 4 + 1 == B[i]) {
            ans += i * 4;
        } else {
            ans += min(B[i], i * 4 + 1);
        }
    }

    cout << ans << '\n';
}

int32_t main() {    
    int tt;
    cin >> tt;
    while(tt--) sol();
}
