#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c0 = 0;
    int c1 = 0;
    int idx;
    int mx = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') ++c0;
        else ++c1;
        if ((c1 - c0) > mx) {
            mx = c1 - c0;
            idx = i;
        }
    }
    for (int i = idx; i < n; i++) {
        if (s[i] == '1')
    }
    if (!mx) cout << ""
    else cout << "-1\n";
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



