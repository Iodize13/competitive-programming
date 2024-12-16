#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

void runcase(){
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 1; j < 10 && i + j < s.length(); j++) {
            if (s[i + j] - j > s[i]) {
                s[i + j] -= j;
                swap(s[i + j], s[i]);
            }
        }
    }
    cout << s << '\n';
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}
