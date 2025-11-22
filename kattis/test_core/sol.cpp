#include <bits/stdc++.h>
using namespace std;

void sol() {
   int N;
   cin >> N;
   map<string, int> mp;
   while(N--) {
       string a, b;
       int d;
       cin >> a >> b >> d;
       mp[a] -= d;
       mp[b] += d;
   }
   vector<pair<string, int>> v(mp.begin(), mp.end());
   for(int i = 0, j = v.size()-1; i < v.size(); i++) {
       if(v[i].second >= 0) continue; 
       while(j >= i && v[j].second == 0) j--;

       while(v[i].second < 0) {
           int temp = v[i].second;
           cerr << temp << '\n';
          if(v[i].second + v[j].second <= 0) {
              int nd = min(abs(v[i].second), abs(v[j].second));
              v[i].second += v[j].second;
              v[j].second += temp;
              cout << v[j].first << ' ' << v[i].first << ' ' << nd << '\n'; 
          }
          else if(v[i].second + v[j].second > 0) {
              int nd = min(abs(v[i].second), abs(v[j].second));
              v[j].second += v[i].second;
              v[i].second = 0;
              cout << v[j].first << ' ' << v[i].first << ' ' << nd << '\n'; 
              continue;
          }
          j--;
       }
   }
   cout << "settled\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sol();
}
