#include <bits/stdc++.h>
//#include <cstdio>
 
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define eb emplace_back 
using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
 
void DBG() {
    cerr << "]" << endl;
}
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t))
        cerr << ", ";
    DBG(t...);
}
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
 
ll n, m, k, q, l, r, x, y ,z;
ll a[(int)1e6+9];
ll b[(int)1e6+9];
ll c[(int)1e6+9];
string s, t;
 
void runcase(){
    cin >> n;
    if (n % 2 == 1 && n < 27) {
        cout << -1 <<'\n';
        return;
    }
    if (n % 2 == 1) {
        vector<int> ans = {1,2,2,3,3,4,4,5,5,1,6,7,7,8,8,9,9,10,10,11,11,12,12,13,13,1,6};
        // 14,14
        for (auto &X: ans) cout << X << ' ';
        for (int i = 14; i <= n / 2; i++) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n/2; i++) {
        cout << i << ' ' << i << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testcase(1); cin>>testcase;
    while(testcase--) runcase();
    return 0;
}
 
