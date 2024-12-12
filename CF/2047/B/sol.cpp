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
    string s;
    cin >> s;
    int a[26]{0};
    int mx = 0;
    char idx = s[0];
    char idxn = s[0];
    int mn = 11;
    for (int i = 0; i < n; i++) {
        a[s[i] - 'a']++;
        if (a[s[i] - 'a'] >= mx) {
            mx = a[s[i] - 'a'];
            idx = s[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[s[i] - 'a'] < mn && s[i] != idx) {
            mn = a[s[i] - 'a'];
            idxn = s[i];
        }
    }
    bool ok = 1;
    //cout << idx << ' ' << idxn << '\n';
    for (int i = 0; i < n; i++) {
        if (s[i] == idxn && ok) {
            cout << idx;
            ok = 0;
        } else {
            cout << s[i] ;
        }
    }
    cout << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



