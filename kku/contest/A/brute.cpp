#include<bits/stdc++.h>
#define int long long int

using ll = long long;

using namespace std;

void runcase() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = a; i <= b; i++) {
        int tmp = i;
        string s = to_string(i);
        map<int, int> mp;
        for (int j = 0; j < s.size() - 1; j++) {
            tmp -= (s[j] - '0') * (ll)pow(10, s.size() - 1);
            tmp *= 10;
            // cerr << tmp << '\n';
            tmp += (s[j] - '0');
            if (tmp > i && tmp <= b && tmp >= a && !mp.count(tmp)) {
                cerr << tmp << '\n';
                mp[tmp]++;
                ++ans;
            }
            // leading with zero handling.?????
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        runcase();
    }
	return 0;
}
