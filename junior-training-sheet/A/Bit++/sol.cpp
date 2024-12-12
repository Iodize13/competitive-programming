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
   int ans = 0;
   for (int i = 0; i < n; i++) {
     string s;
     cin >> s;
     if (s[0] == '+' || s[1] == '+' || s[2] == '+') ans++;
     else ans--;
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



