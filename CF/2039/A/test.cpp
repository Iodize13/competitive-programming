#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    int n;
    cin >> n;
    for (int i = 1, j = 1; i <= 100 && j < n+1; i+=2) {
        cout << i << ' ';
        j++;
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



