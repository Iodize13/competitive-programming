// #pragma GCC optimize("O3,unroll-loops")
#include "bits/stdc++.h"

using namespace std;

#define int long long
#define sz(x) (int)(x).size()


struct point2d {
	int x, y, i;
	point2d() {}
	point2d(int x, int y, int i): x(x), y(y), i(i) {}
};

int cross(point2d a, point2d b) {
	return a.x*b.y - a.y*b.x;
}

void solve() {
	int N; cin >> N;
	point2d ori; cin >> ori.x >> ori.y;
	ori.i = 0;
	vector<vector<point2d> > A(2);
	for (int i = 0; i < N - 1; i++) {
		int x, y; cin >> x >> y;
		x -= ori.x;
		y -= ori.y;
		if ((x >= 0 && y >= 0) || (x > 0 && y <= 0)) {
			A[0].push_back(point2d(x,y,i+1));
		} else {
			A[1].push_back(point2d(x, y, i + 1));
		}
	}
	//for (int i = 0; i < N - 1; i++) {
	//	cerr << A[i].x << ' ' << A[i].y << ' ' << A[i].i << '\n';
	//}
	auto angular = [](const point2d &a, const point2d &b) {
			if (cross(a, b) == 0) {
				return a.x*a.x+a.y*a.y < (b.x*b.x+b.y*b.y);
			} else {
				return cross(a, b) < 0;
			}
	};
	sort(A[0].begin(), A[0].end(), angular);
	sort(A[1].begin(), A[1].end(), angular);
	if (!A[0].empty() && !A[1].empty()) {
		if (cross(A[0].back(), A[1].front()) >= 0) swap(A[0], A[1]);
	}
	cout << N << '\n';
	cout << ori.i + 1 << '\n';
	for (int i = 0; i < 2; i++) {
		for (auto &y: A[i]) cout << y.i + 1 << '\n';
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    solve();
}

