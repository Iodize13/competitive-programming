#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int a[n];
    for (int i = 0 ; i < n; i++) {
        cin >>  a[i];
    }
    sort(a, a + n);
    for (int i = n-1 ; i >=0; i--) {
        sum += a[i];
            //cout << "sum :" << sum << '\n';
        if (sum > k) {
            sum -= a[i];
            break;
        }
    }
    cout << k - sum << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



