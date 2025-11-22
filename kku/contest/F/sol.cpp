#include<bits/stdc++.h>

using namespace std;

#define int long long int

vector<vector<char>> g(512, vector<char>(512));
vector<vector<int>> bk(513, vector<int>(513));

int f(int sx, int sy, int ex, int ey) {
	if (abs(sx - ex) == 0) {
		return 0;
	}
    cerr << "sx: " << sx << ", ex" << ex << ", sy: " << sy << ", ey: " << ey << '\n';
	// cerr << "dbg: " << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
	int ans = INT_MAX;
	// cerr << cntW[0].first << ' ' << cntW[3].first << '\n';

	int dx[] = {sx,            sx,                (sx + ex) / 2 + 1, (sx + ex) / 2 + 1};
	int dy[] = {sy,            (sy + ey) / 2 + 1, (sy + ey) / 2 + 1, sy               };
	int dw[] = {(sx + ex) / 2, (sx + ex) / 2,      ex,               ex               };
	int dz[] = {(sy + ey) / 2, ey,                 ey,               (sy+ey)/2        };

    int du[4];
    int wt[4];
    for (int i = 0; i < 4; i++) {
        du[i]= f(dx[i], dy[i], dw[i], dz[i]);
        wt[i]= bk[dw[i] + 1][dz[i] + 1] - (bk[dw[i] + 1][dy[i]] + bk[dx[i]][dz[i] + 1] - bk[dx[i]][dy[i]]);
        // cerr << "dx[i]: " << dx[i] << ", dy[i]: " << dy[i] << '\n';
        // cerr << "dw[i]: " << dw[i] << "dz[i]: " << dz[i] << '\n';
        // cerr << "bk[dw[i] + 1][dz[i] + 1]: " << bk[dw[i] + 1][dz[i] + 1] <<'\n';
        // cerr << "wt[i]: " << wt[i] << '\n';
        cerr << "du[i]: " << du[i] << '\n';
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            int F = du[i];
            int S = du[j];
            int Ti;
            for (int k = 0; k < 4; k++) {
                if (k != i && k != j) {
                    Ti = k;
                    break;
                }
            }
            // cerr << "i: " << i << ", j: " << j << ", k: " << Ti << ", l: " << 6 - (i + j + Ti) <<'\n';
            int T = wt[Ti];
            int FO = wt[6 - (i + j + Ti)];
            // cerr << "abs(sx- ex) / 2: " << abs(sx - ex) / 2 << '\n';
            // cerr << "T: " << T << "FO: " << FO << '\n';
            if ((long long )pow(abs(sx - ex) + 1, 2) / 4 - max(T, FO) + min(T, FO) + F + S < ans) {
                ans = (long long )pow(abs(sx - ex) + 1, 2) / 4 - max(T, FO) + min(T, FO) + F + S;
                // cerr << "i: " << i << ", j: " << j << ", k: " << Ti << ", l: " << 6 - (i + j + Ti) <<'\n';
                cerr << T << ' ' <<  FO << '\n';
            }
        }
    }
	// if (cntW[1].second == 1) ans += 
	// if (cntW[1].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex, ey);
	// if (cntW[1].second == 3) ans += f((sx + ex) / 2, sy, ex, (sy + ey)/ 2);
	// if (cntW[2].second == 0) ans += f(sx,            sy,            (sx + ex) / 2, (sy + ey) / 2);
	// if (cntW[2].second == 1) ans += f(sx,            (sy + ey) / 2, (sx + ex) / 2, ey);
	// if (cntW[2].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex,            ey);
	// if (cntW[2].second == 3) ans += f((sx + ex) / 2, sy,            ex,            (sy + ey)/ 2);
    cerr << ans << '\n';
	return ans;
}

void runcase() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n;j ++) {
            bk[i][j] = (g[i - 1][j - 1] == 'W') + bk[i][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n;j ++) {
             bk[i][j] += bk[i - 1][j];
             cerr << bk[i][j] << ' ';
         }
         cerr << '\n';
     }
     // h(0,0,n,n,0);
     // cerr << bk[n][0];
    // cerr << "ye: " << bk[n][n] - (bk[n][n/2] + bk[n/2][n] - bk[n/2][n/2]) << '\n';
 	cout << f(0, 0, n-1, n-1) << '\n';
 }

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--) {
		runcase();
	}
	return 0;
}
