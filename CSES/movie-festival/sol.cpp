#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int prev = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        prev = min(v[i].second, INT_MAX);
    }
    sort(all(v), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
            });
    int j = 0;
    int ans = 1;
    while (j < n && v[j].first < prev) {
        if (j < n) prev = v[j].second;
        j++;
        ans++;
    }
    cout << ans << '\n';
}

int main() {
    sol();
}
