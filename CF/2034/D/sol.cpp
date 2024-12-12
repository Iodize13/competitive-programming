#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double 
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

int r;
int n;
int a[int(2e5+9)];
vector<pair<int, int> > ans;

void twoSum(){

    ans.clear();
    int left = 0;
    while (left < n - 1){
        if (a[left] == 0 || left == r) {
            left++;
            r = n - 1;
        } else if (a[left] - a[r] == 1) {
            ans.emplace_back(left + 1, r + 1);
            // swap(a[left], a[r]);
            int tmp = a[left];
            a[left] = a[r];
            a[r] = tmp;
            /*cout << "if\n";*/
            r = n - 1;
        }         else {
            r--;
            /*cout << "elif\n";*/
        }
    //     cout << "left: " << left << ' ' << "r: " << r << '\n';
    //         cout << "l: " << left << "r: " << r << '\n';
    //     for (int i = 0; i < n; i++) {
    //         cout << a[i] << ' ';
    //     }
    //     cout << '\n';
    }

    // If no pair found
    return;
}            

void runcase(){
    cin >> r;
    n = r;
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }
    if (r == 1) {
        cout << "0\n";
        return;
    }
    r--;
    twoSum();
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t(1); cin>>t;
    while(t--) runcase();
    return 0;
}



