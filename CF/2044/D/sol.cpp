#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

void runcase(){
  int n;
  cin >> n;
  int a[n];
  int b[n + 1]{0};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int j = 1;
  for (int i = 0; i < n; i++) {
    if (b[a[i]] == 0) {
      cout << a[i];
      b[a[i]] = 1;
    } else {
      while (b[j] == 1) {
        ++j;
      }
        cout << j;
        b[j] = 1;
    }
    cout << ' ';
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
