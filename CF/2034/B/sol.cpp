#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int m, n, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
        else cnt = 0;
        if (cnt >= m) {
            i+= k - 1;
            ans++;
            cnt = 0;
        }
        // cout << i << '\n';m
    }
    cout << ans << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



