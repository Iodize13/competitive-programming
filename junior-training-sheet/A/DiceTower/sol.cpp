#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
          
int findFace(int a, int b) {
    int face = 0;
    if ((a == 4 || a == 3) && (b == 5 || b == 2)) face = 1;
    if ((a == 1 || a == 6) && (b == 5 || b == 2)) face = 4;
    if ((a == 1 || a == 6) && (b == 4 || b == 3)) face = 5;
    return face;
}

void runcase(){
    int n;
    cin >> n;
    int x;
    cin >> x;
    int a[n], b[n];
    cin >> a[0] >> b[0];
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        //if (a > b) swap(a, b);
    }
    bool can = 1;
    for (int i = 0; i < n - 1; i++) {
        int face = max(findFace(a[i], b[i]), findFace(b[i], a[i]));
        if (face == 7 - x || face == x) {}
        else can = 0;
    }
    cout << ((can || n == 1) ? "YES\n" : "NO\n");
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



