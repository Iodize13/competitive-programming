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
  reverse(s.begin(), s.end());
  for (int i = 0 ; i < s.length(); i++) {
    if (s[i] == 'q') cout << 'p';
    else if (s[i] == 'p') cout << 'q';
    else cout << 'w';
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
