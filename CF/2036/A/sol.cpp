#include<bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int x;
    int prev;
    cin >> prev;
    bool isTrue = 1;
    for(int i = 0; i < n-1; i++) {
      cin >> x;
      int tem = abs(prev-x);
      if (!(tem == 5 || tem == 7 )) {
	// cout << "prev: " << prev << "x: " << x << ' ';
	// cout << tem << ' ';
	isTrue = 0;
      }
      prev = x;
    }
    if (isTrue) cout << "YES\n";
    else cout << "NO\n";
  }
}
