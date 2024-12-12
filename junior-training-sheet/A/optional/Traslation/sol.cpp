#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    string s, t;
    cin >> s >> t;
    string ans = "";
    for (int i = s.length() - 1; i >= 0; i--) {

        ans += s[i];

    }
    cout << ((ans == t) ? "YES\n" : "NO\n");
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



