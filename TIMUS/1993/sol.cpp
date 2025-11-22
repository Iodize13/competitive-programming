// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...) 42
#endif
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define fi first
#define se second
#define int long long
#define ll long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
void solve();
const int di[4] = {0, 0, -1, 1};
const int dj[4] = {-1, 1, 0, 0};

int32_t main() {
    send help

    solve();
}

void solve() {
    vector<string> s(2, "");
    getline(cin, s[0]);
    if (auto x = s[0].find(','); x != string::npos) {
        s[1] = s[0].substr(x);
        s[0] = s[0].substr(0, x);
    }

    rep(to,0,2) {
        string ob = "", sub = "" , verb = "";
        auto x = s[to];
        if (!sz(x)) break;
        int i = 0;
        if (to == 1) {
            while (x[i] != '(' && x[i] != '{' && x[i] != '[') {
                cout << x[i];
                i++;
            }
        }
        for (; i < sz(x); i++) {
            if (x[i] == '(') {
                i++;
                while (x[i] != ')') {
                    sub += x[i];
                    i++;
                }
            }
            if (x[i] == '{') {
                i++;
                while (x[i] != '}') {
                    ob += x[i];
                    i++;
                }
            }
            if (x[i] == '[') {
                i++;
                while (x[i] != ']') {
                    verb += x[i];
                    i++;
                }
            }
        }
        for (auto &y: ob) y = (char)tolower(y);
        for (auto &y: sub) y = (char)tolower(y);
        for (auto &y: verb) y = (char)tolower(y);
        dbg(ob);
        dbg(sub);
        dbg(verb);
        if (to == 0) cout << (char)toupper(ob[0]) << ob.substr(1) << ' ' << sub << ' ' << verb;
        else cout << ob << ' ' << sub << ' ' << verb;
    }

    // dbg((char)toupper(','));
    cout << '\n';
}
// bell 
// four top
//JS Stick Letters.flf
//LCD.flf
//
//Moscow.flf
//muzzle
/// //Shimrod.flf
/// ///Stampate.flf
/// Thin

