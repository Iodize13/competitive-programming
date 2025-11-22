#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

int tt = 1;

int n, m;
string sum;

// void proof(int l, int r) {
//     string ret = "";
//     cerr << "l, r: " << l << ' ' << r << endl;
//     while(l || r) {
//         int tempN = l % 10;
//         int tempT = r % 10;
//         l /= 10;
//         r /= 10;
//         string S = to_string(tempN + tempT);
//         reverse(all(S));
//         ret += S;
//     }
//     reverse(all(ret));
//     cerr << "ret: " << ret << endl;
//     assert(sum == ret);
// }

void sol() {
    string a;
    cin >> a >> sum;
    string ans = "";
    int j = sz(sum) - 1;
    for (int i = sz(a) - 1; i >= 0; i--, j--) {
        if (j < 0) {
            cout << "-1\n";
            return;
        }
        if (a[i] > sum[j]) {
            int temp = sum[j] - '0';
            j--;
            if (j >= 0) temp = temp + (sum[j] - '0')* 10;
            else {
                cout << "-1\n";
                return;
            }
            if (temp - a[i] + '0' > 9 || temp - a[i] + '0' < 0) {
                cout << "-1\n";
                return;
            }
            ans += to_string(temp - (a[i] - '0'));
        } else {
            ans += to_string(sum[j] - a[i]);
        }
    }

    for (;j >= 0; j--) {
        ans += sum[j];
    }
    reverse(all(ans));
    // proof(stoll(ans), stoll(a));
    cout << stoll(ans) << '\n';
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

