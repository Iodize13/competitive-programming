#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    string s;
    cin >> s;
    string ans = "";
    bool isSt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != '9') {
            ans += (min('9' - (int)s[i], (int)s[i] - '0') + '0');
            isSt = 1;
        }
        else {
            if (isSt) ans += (min('9' - (int)s[i], (int)s[i] - '0') + '0');
            else {
                ans += '9';
                isSt = 1;
            }
        }
    }
    //if (ans.empty()) ans += s[s.length() - 1];
    cout << ans << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



