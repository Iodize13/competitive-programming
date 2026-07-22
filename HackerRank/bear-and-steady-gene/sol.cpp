#include <bits/stdc++.h>
#define sz(x) (long long)(x).size()

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene) {
    using ll = long long;
    ll N = sz(gene);
    string path = "CGAT";
    vector<ll> cnt(4, 0);
    for (ll i = 0; i < 4; i++) {
        for (ll j = 0 ; j < N; j++) {
            if (gene[j] == path[i]) { cnt[i]++; }
        }
    }
    auto f = [&](ll len) {
        vector<ll> sum(4, 0);
        for (ll i = 0; i < 4; i++) {
	    for (ll j = 0 ; j < len; j++) {
		if (gene[j] == path[i]) {
		    sum[i]++;
		}
	    }
        }
        for (ll j = 0; j < N - len + 1; j++) {
	    bool ok = true;
	    for (ll i = 0; i < 4; i++) {
		if (j != 0) {
		    sum[i] -= gene[j - 1] == path[i];
		    sum[i] += gene[len + j - 1] == path[i];
		}
		if (sum[i] < max(0ll, cnt[i] - N / 4)) ok = false;
	    }
	    if (ok) return true;
        }
        return false;
    };
    ll r = N, l = -1;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (f(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return (int)r;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

