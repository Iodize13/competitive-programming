#include<bits/stdc++.h>

using namespace std;

#define int long long int

vector<vector<char>> g(512, vector<char>(512));
vector<vector<int>> bk(513, vector<int>(513));

int h(int sx, int sy, int ex, int ey, int qt) {
	if (abs(sx - ex) == 1) {
		return g[sx][sy] == 'W';
	}

	int dx[] = {sx,            sx,            (sx + ex) / 2, (sx + ex) / 2};
	int dy[] = {sy,            (sy + ey) / 2, (sy + ey) / 2, sy           };
	int dw[] = {(sx + ex) / 2, (sx + ex) / 2, ex,            ex           };
	int dz[] = {(sy + ey) / 2, ey,            ey,            (sy+ey)/2    };

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += h(dx[i], dy[i], dw[i], dz[i], i);
    }
    bk[abs(ex - sx)][qt] = ans;
    return ans;
}

int f(int sx, int sy, int ex, int ey) {
	if (abs(sx - ex) == 1) {
		return 0;
	}
	// cerr << "dbg: " << sx << ' ' << sy << ' ' << ex << ' ' << ey << '\n';
	int ans = INT_MAX;
	// cerr << cntW[0].first << ' ' << cntW[3].first << '\n';

	int dx[] = {sx,            sx,            (sx + ex) / 2, (sx + ex) / 2};
	int dy[] = {sy,            (sy + ey) / 2, (sy + ey) / 2, sy           };
	int dw[] = {(sx + ex) / 2, (sx + ex) / 2, ex,            ex           };
	int dz[] = {(sy + ey) / 2, ey,            ey,            (sy+ey)/2    };

    int du[4];
    for (int i = 0; i < 4; i++) {
        du[i]= f(dx[i], dy[i], dw[i], dz[i]);
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
            int T = bk[abs(dx[i] - dw[i]) / 2][Ti];
            // cerr << "i: " << i << ", j: " << j << ", k: " << Ti << ", l: " << 6 - (i + j + Ti) <<'\n';
            int FO = bk[abs(dx[i] - dw[i]) / 2][6 - (i + j + Ti)];
            ans = min(ans, (long long )pow(abs(sx - ex), 2) / 4 - max(T, FO) + 
            min(T, FO) + F + S);
        }
    }
	// if (cntW[1].second == 1) ans += 
	// if (cntW[1].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex, ey);
	// if (cntW[1].second == 3) ans += f((sx + ex) / 2, sy, ex, (sy + ey)/ 2);
	// if (cntW[2].second == 0) ans += f(sx,            sy,            (sx + ex) / 2, (sy + ey) / 2);
	// if (cntW[2].second == 1) ans += f(sx,            (sy + ey) / 2, (sx + ex) / 2, ey);
	// if (cntW[2].second == 2) ans += f((sx + ex) / 2, (sy + ey) / 2, ex,            ey);
	// if (cntW[2].second == 3) ans += f((sx + ex) / 2, sy,            ex,            (sy + ey)/ 2);
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
    h(0,0,n,n,0);
    // cerr << bk[n][0];
    cerr << bk[n / 2][0] << '\n';
	cout << f(0, 0, n, n) << '\n';
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
