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
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
        if (a[i] > mx) {
            idx = i;
            mx = a[i];
        }
        if (mx - a[i] == 1) swap(a[idx], a[i]);
    }
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



