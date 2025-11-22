#include<bits/stdc++.h>
#define int long long
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

void sol() {
    int n,k;cin >> n >> k;
    vector<vector<int>> adj(n+1);

    int ans = 0;
    for(int i=0;i<k;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    stack<int> q;
    vector<bool> vis(n+1);
    for(int i=1;i<=n;i++) {
        int cnt = 0;
        if(vis[i])continue;
        q.push(i);
        while(!q.empty()) {
            int tmp = q.top();
            q.pop();
            if(vis[tmp]) continue;
            cnt++;
            vis[tmp] = 1;
            for(auto x : adj[tmp]) {
                if (vis[x]) continue;
                q.push(x);
            }
        }
       ans += (cnt*(cnt-1))/2;
    }
    int all = (n*(n-1))/2;
    // cerr << ans << " " << all << " \n";
    cout <<fixed << setprecision(12) <<  ((long double)ans/(long double)all) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int tt = 1, testcase(1);


    while(testcase--) {
        sol();
        tt++;
    }
    return 0;
}

