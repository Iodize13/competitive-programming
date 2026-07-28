#define sz(x) (int)(x).size()

class Solution {
    public:
	int minDistance(string N, string M) {
	    if (sz(N) > sz(M)) swap(N, M);
	    int szN = sz(N);
	    int szM = sz(M);
        if (N == "" ) return max(szN, szM);
	    vector<vector<int> > dp(szN, vector<int>(szM, INT_MAX));
	    vector<bool> visI(szN);
	    vector<bool> visJ(szM);
	    for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) {
		    int notEq = (int)(N[i] != M[j]);
		    if (i == 0 && j == 0) dp[i][j] = min(dp[i][j], notEq);
		    if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + notEq);
		    if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + (int)(notEq || visJ[j]));
		    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + (int)(notEq || visI[i]));
		    visI[i] = visI[i] | !notEq;
		    visJ[j] = visJ[j] | !notEq;
		}
	    }

	    return dp[szN - 1][szM - 1];
	}
};
