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
    vector<pair<int, int> > lap(n);
    for (int i = 0; i < n; i++) { 
        cin >> lap[i].first >> lap[i].second;
    }
    sort(all(lap));
    for (int i = 0; i < n-1; i++) {
        if (lap[i].second > lap[i+1].second) {
            cout << "Happy Alex\n";
            return;
        }
    }
    cout << "Poor Alex\n";
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}


