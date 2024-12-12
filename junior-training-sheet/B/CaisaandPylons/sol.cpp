#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int n;
    cin >> n;
    int h[n];
    int e = 0;
    int prev = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        e += (prev - h[i]);
        if (e < 0) {
            ans += e * -1;
            e = 0;
        }
        // cout << "e: " << e << ", ";
        // cout << (prev - h[i])  << '\n';
        prev = h[i];
    }
    //cout << e << '\n';
    //cout << (e >= 0 ? e : (e * -1));
    cout << ans;
    cout << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



