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
    int cnt = 0;
    bool bmc = 0;
    for (int i = 0; i < 3; i++) {
        int idx = s[i].find('A');
        if (idx != string::npos) {
            if (idx == 0) {
                if (s[i][1] == '>') cnt++;
            } else {
                if (s[i][1] == '<') cnt++;
            }
        } else {
            if (s[i] == "C<B" || "B>C") bmc = 1;
        }
    }
    if (cnt == 2) {
        if (bmc) cout << "CBA";
        else cout << "BCA";
    } else if (cnt == 1) {
        if (bmc) cout << "CAB";
        else cout << "BAC";
    } else {
        if (bmc) cout << "ACB";
        else cout << "ABC";
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



