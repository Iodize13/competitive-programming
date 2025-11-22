#include<bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cerr << s << '\n';
    string ans = "";
    for (int i = 0; i < (int)s.length(); i++) ans += '0';

    ans[0] = s[0];
    for (int i = 1; i < (int)s.length(); i++) {
        int pos = (i * 3) / 4;
        int mul = (1 << (i * 3) % 4);
        cerr << "mul: " << mul << '\n';
        int val = (s[i] - '0') * mul;
        int tmp = (ans[pos] - '0') + val;
        ans[pos] = tmp % 16 + '0';
        ans[pos + 1] = ((ans[pos + 1] - '0') + tmp / 16) + '0';
    }

    reverse(ans.begin(), ans.end());
    bool ok = false;
    string ans2 = "";
    for (int i = 0; i< (int)ans.size(); i++) {
        if (!ok) {
            if (ans[i] == '0') continue;
            else ok = true;
        }
        if (ans[i] == '?')  ans2 += 'F';
        else if (ans[i] == '>')  ans2 += 'E';
        else if (ans[i] == '=')  ans2 += 'D';
        else if (ans[i] == '<')  ans2 += 'C';
        else if (ans[i] == ';')  ans2 += 'B';
        else if (ans[i] == ':')  ans2 += 'A';
        else  ans2 += ans[i];
    }
    cout << (ans2 == "" ? "0" : ans2) << '\n';
    cerr << char('0' + 16) << '\n';
    cerr << char('0' + 15) << '\n';
    cerr << char('0' + 14) << '\n';
    cerr << char('0' + 13) << '\n';
    cerr << char('0' + 12) << '\n';
    cerr << char('0' + 11) << '\n';
    cerr << char('0' + 10) << '\n';
    // cout << ans << '\n'; 

    return 0;
}
