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
    for(int i = 0; i< s.length(); i++) {
        if (s[i] == 'a' ||
                s[i] == 'o' ||
                s[i] == 'y' ||
                s[i] == 'e' ||
                s[i] == 'u' ||
                s[i] == 'i' ||
                s[i] == 'A' ||
                s[i] == 'O' ||
                s[i] == 'Y' ||
                s[i] == 'E' ||
                s[i] == 'U' ||
                s[i] == 'I') continue;
        else cout << '.' << char(tolower(s[i]));
    }
    cout << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



