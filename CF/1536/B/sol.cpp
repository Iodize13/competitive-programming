#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string s;

void sol() {
    cin >> n >> s;
    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string temp(1, s[i]);
        mp[temp] = 1;
    }   

    for (int i = 1; i < n; i++) {
        string temp = s.substr(i - 1, 2);
        // cerr << temp << '\n';
        mp[temp] = 1;
    }

    for (int i = 2; i < n; i++) {
        string temp = s.substr(i -2, 3);
        mp[temp] = 1;
    }

    string ans = "";
    for (char X = 'a'; X <= 'z'; X++) {
        string temp(1, X);
        if (!mp[temp]) {
            ans = temp;
            break;
        }
    }

    if (ans == "") {
        for (char X = 'a'; X <= 'z'; X++) {
            string temp = "aa";
            temp[0] = X;
            if (ans != "") break;
            for (char Y = 'a'; Y <= 'z'; Y++) {
                temp[1] = Y;
                // cerr << temp << '\n';
                if (!mp[temp]) {
                    ans = temp;
                    break;
                }
            }
        }
    }

    if (ans == "") {
        for (char X = 'a'; X <= 'z'; X++) {
            string temp = "aaa";
            temp[0] = X;
            if (ans != "") break;
            for (char Y = 'a'; Y <= 'z'; Y++) {
                temp[1] = Y;
                if (ans != "") break;
                for (char Z = 'a'; Z <= 'z'; Z++) {
                    temp[2] = Z;
                    if (!mp[temp]) {
                        ans = temp;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int testcase(1);
    cin >> testcase;
    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

