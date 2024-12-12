#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
int a[1009];
void runcase(){
    int n;
    cin >> n;
    memset(a, 0, sizeof a);
        int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    sort(a, a + n);
    bool alice = 1;
    int sum = 0;
    for (int i = 0; i < 1001; i++) {
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            if (alice) {
                sum += 2;
                alice = 0;
            } else {
                alice = 1;
            }
        } else {
            sum++;
        }
    }
    cout << sum << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



