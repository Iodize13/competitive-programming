// unsolved
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)

vector<vector<int>> a(2e5, vector<int>(2e5, 0));

void runcase(){
  int n, m ,q;
  cin >> n >> m >> q;
  int aa[n], b[m];
  for (int i = 0; i < n; i++) {
    cin >> aa[i] ;
      }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0 ; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = aa[i]*b[j];
      cout << a[i][j] << ' ';;
    }
    cout << '\n';
  }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}
