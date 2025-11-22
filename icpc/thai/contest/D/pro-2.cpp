#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
#define all(x) begin(x),end(x)
#define rep(i,a,b) for(int i=a;i<b;++i)
typedef complex<long double> pt;
#define X real()
#define Y imag()
bool comp(pt a, pt b) {
    if(a.X==b.X) return a.Y<b.Y;
    return a.X<b.X;
}
pt read() {
    int x,y; cin >> x >> y;
    pt p = {x,y};
    return p;
}
int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int n; cin >> n;
    vector<pt> pts(n);
    for(auto& i : pts) i = read();
    vector<pt> pts2(n);
    for(auto& i : pts2) i = read();
    sort(all(pts),comp);
    sort(all(pts2),comp);
    int at=0;
    while(at<n and pts[at]==pts[0]) ++at;
    if(at==n) at=0;
    ll S;
    {
        auto d1 = abs(pts[0]-pts[at]);
        auto d2 = abs(pts2[0]-pts2[at]);
        if(d1==0) S=1;
        else S = llround(d2/d1);
    }
    pt offset = pts2[0] - (long double)S*pts[0];
    for(auto& i : pts) {
        i = i*(long double)S + offset;
    }
    if(pts==pts2) {
        cout << S << ' ' << ll(offset.X) << ' ' << ll(offset.Y) << '\n';
    } else cout << "-1\n";

}
