#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)
             
void runcase(){
    int n, k;
    cin >> n >> k;
    int mn = int(1e9);
    int h[n + k]{0};
    int p[n + k]{0};
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int ans = 0;
    for (int i = n + k - 2; i >= 0; i--) {
        p[i] = p[i + 1] + h[i];
        /*cout << p[i] << ' ';*/
    }
    /*cout << '\n';*/
    for (int i = 0; i < n - k; i++) {
        if (p[i] - p[i + k] < mn) {
            mn = p[i] - p[i + k];
            ans = i + 1;
        }
    }
    cout << ans << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



