#include <bits/stdc++.h>
#define int long long
using namespace std;

struct t{
    public:
        int y,i,s,b;
        long long peakDay;
        long long val;
        t(int a,int x,int c ,int d) {
            y = a;
            i = x;
            s = c;
            b = d;

            peakDay = b + y;
            val = y*i + s;
        }

};

long long getV(long long day, t tree){
    return max(0LL, tree.val - abs(day-tree.peakDay) * tree.i);
}

void sol() {
    int n;cin >> n;
    vector<t> tr;
    for(int x=0;x<n;x++) {
        int y,i,s,b;
        cin >> y >> i >> s >> b;
        tr.push_back(t(y,i,s,b));
    }
        

    long long mx = 0;
    for(auto x : tr) {
        long long tmp = 0;
        int tmp2 = 0;
        for(auto other : tr) {
            // if (x.peakDay == 5) cerr << getV(x.peakDay, other) << '\n';
            if (other.b <= x.peakDay) tmp += getV(x.peakDay, other);
            if (other.b <= x.b) tmp2 += getV(x.b, other);
            // if (tmp == 44) cerr << x.peakDay << '\n';
        }
        mx = max(mx, tmp);
        mx = max(mx, tmp2);
    }
    cout << mx << endl; }
int32_t main() {
    sol();
}
