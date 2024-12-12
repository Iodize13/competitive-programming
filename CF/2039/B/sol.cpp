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
    if (s.length() == 1) {
        cout << "-1\n";
        return;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == s[i + 1]) {
            cout << s[i] << s[i] << '\n';
            return;
        }
        if (i + 2 < s.length() && s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i +2])  {
            cout << s[i] << s[i + 1] << s[i + 2] << '\n';
            return;
        }
    }
    cout << "-1\n";
    return;
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



