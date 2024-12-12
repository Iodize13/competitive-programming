#include <bits/stdc++.h>
using namespace std;
     
#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define rep(i,a,b) for (int i = a, i < b; i++)
             
void runcase(){
    string s;
    cin >> s;
    int sS = (int)s.length();
    int a[10]{0};
    long double sum = 0;
    for (int i = 0; i < sS;i++) {
        ++a[s[i] - '0'];
        sum += s[i] - '0';
    }
    /*for (auto x: a) {*/
    /*    sum += x;*/
    /*}*/
    bool ans = 0;
    int k = ceil(sum / 9) * 9 - (int)sum;
    if (k == 8) {
        if (a[2] >= 4) {
            ans = 1;
        } else if (a[3] >= 1 && a[2] >= 1) {
            ans = 1;
        }
    } else if (k == 7) {
        if (a[3] >= 2 && a[2] >= 2) {
            ans = 1;
        } else if (a[3] >= 1 && a[2] >= 5) {
            ans = 1;
        } else if (a[2] >= 8) {
            ans = 1;
        }
    } else if (k == 6) {
        if (a[3] >= 1) {
            ans = 1;
        } else if (a[2] >= 3) {
            ans = 1;
        }
    } else if (k == 5) {
        if (a[3] >=2 && a[2] >= 1) {
            ans = 1;
        } else if (a[3] >=1 && a[2] >= 4) {
            ans = 1;
        } else if (a[2] >= 7) {
            ans = 1;
        }
    } else if (k == 4) {
        if (a[2] >= 2) {
            ans = 1;
        }
    } else if (k == 3) {
        if (a[3] >= 2) {
            ans = 1;
        } else if (a[3] >= 1 && a[2] >= 3) {
            ans = 1;
        } else if (a[2] >= 6) {
            ans = 1;
        }
    } else if (k == 2) {
        if (a[2] >= 1) {
            ans = 1;
        }
    } else if (k == 1) {
        if (a[3] >= 1 && a[2] >= 2) {
            ans = 1;
        } else if (a[2] >= 5) {
            ans = 1;
        }
    } else if (k == 0) {
            ans = 1;
    }
    //cout << sum << '\n';
    /*cout << k << '\n';*/
    cout << (ans ? "YES\n" : "NO\n");
}
     
int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t(1); cin>>t;
   while(t--) runcase();
   return 0;
}



