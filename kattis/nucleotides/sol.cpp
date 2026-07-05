#include "bits/stdc++.h"
#define int long long
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()

using namespace std;

void sol() {
    string S; cin >> S;
    int N; cin >> N;
    int len = sz(S) + 1;
    vector<int> T(len), A(len), C(len), G(len);
    T[0] = A[0] = C[0] = G[0] = 0;
    for (int i = 0; i < sz(S); i++) {
        if (S[i] == 'T') {
            T[i + 1] = 1;
        } else if (S[i] == 'A') {
            A[i + 1] = 1;
        } else if (S[i] == 'C') {
            C[i + 1] = 1;
        } else {
            G[i + 1] = 1;
        }
    }
    int tmpT = 0;
    int tmpA = 0;
    int tmpC = 0;
    int tmpG = 0;
    for (int i = 0; i < sz(S); i++) {
        tmpT += T[i + 1];
        tmpA += A[i + 1];
        tmpC += C[i + 1];
        tmpG += G[i + 1];
        T[i + 1] = tmpT;
        A[i + 1] = tmpA;
        C[i + 1] = tmpC;
        G[i + 1] = tmpG;
    }
    for (int i = 0; i < N; i++) {
        int st, en; cin >> st >> en;
        --st;
        --en;
        vector<pair<int, char> > ans;
        int cntT = T[en + 1] - T[st];
        int cntA = A[en + 1] - A[st];
        int cntC = C[en + 1] - C[st];
        int cntG = G[en + 1] - G[st];
        ans.emplace_back(cntT, 'T');
        ans.emplace_back(cntA,'A');
        ans.emplace_back(cntC, 'C');
        ans.emplace_back(cntG, 'G');
        map<char, int> path;
        path['A'] = 0;
        path['T'] = 1;
        path['G'] = 2;
        path['C'] = 3;
        sort(ans.begin(), ans.end(), [&](const pair<int, char> &a, const pair<int, char>& b) {
                if (a.first != b.first) {
                    return a.first > b.first;
                }
                return path[a.second] < path[b.second];
                });
        for (int j = 0; j < 4; j++) {
            cout << ans[j].second;
        }
        cout << '\n';
    }   
}

int32_t main() {
    sol();
}
