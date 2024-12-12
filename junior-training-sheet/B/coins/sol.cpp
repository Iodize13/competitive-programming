#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
             
void runcase(){
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    int a[3]{0};
    vector<pair<char, int> > a = {{'A', 0}, {'B', 0}, {'C', 0}};
    for (int i = 0; i < 3; i++) {
        if(s[i][1] == '>') a[s[i][0] - 'A'].second++;
        else a[s[i][2] - 'A'].second++;;
    }
    
    cout << '\n';
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); //cin>>t;
   while(t--) runcase();
   return 0;
}



