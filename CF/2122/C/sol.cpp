#include<bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> A;
int N;

void MaxDist()
{
    // Vectors to store maximum and
    // minimum of all the four forms
    vector<pair<int, int>> V(N), V1(N);
    map<int, int> mp;

    for (int i = 0; i < N; i++) {
        V[i].first = A[i].first + A[i].second;
        V[i].second = i;
        V1[i].first = A[i].first - A[i].second;
        V1[i].second = i;
    }

    // Sorting both the vectors
    sort(V.begin(), V.end());
    sort(V1.begin(), V1.end());

    // int maximum = max(V.back() - V.front(), V1.back() - V1.front());
    int j = 0, k = N - 1;
    int h = 0, p = N - 1;
    int sum = 0;
    for (int i = 0 ; i< N / 2; i++) {
        while (mp.count(V[k].second)) k--;
        while (mp.count(V1[p].second)) p--;
        while (mp.count(V[j].second)) j++;
        while (mp.count(V1[h].second)) h++;
        if (V[k].first - V[j].first >= V1[p].first - V1[h].first) {
            cout << V[k].second + 1<< ' ' << V[j].second + 1 << '\n';
            mp[V[k].second] = 1;
            k--;
            mp[V[j].second] = 1;
            j++;
            sum += V[k].first - V[j].first;
        } else {
            cout << V1[p].second + 1<< ' ' << V1[h].second + 1 << '\n';
            mp[V1[p].second] = 1;
            p--;
            mp[V1[h].second] = 1;
            h++;
            sum += V1[p].first - V1[h].first;
        }
        // if (V[N - i - 1].first - V[i].first >= V1[N - i - 1].first - V1[i].first) {
        //     cout << V[N - i - 1].second << ' ' << V[i].second << '\n';
        // } else {
        //     cout << V1[N - i - 1].second << ' ' << V1[i].second << '\n';
        // }
    }

    cerr << sum << '\n';
    // cout << maximum << endl;
}

void sol() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }
    MaxDist();
}

int32_t main() {
    int tt;
    cin >> tt;
    while(tt--) {
        sol();
    }
}
