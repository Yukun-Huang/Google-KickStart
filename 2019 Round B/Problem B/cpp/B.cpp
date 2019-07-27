#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define INT_MIN     (-2147483647 - 1) // minimum (signed) int value
#define INT_MAX       2147483647    // maximum (signed) int value

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

const int MAX_N = 100, MAX_S = 100;
int T, N, S[MAX_N + 5], E[MAX_N + 5], L[MAX_N + 5], O[MAX_N + 5];
int dp[MAX_N*MAX_S + 5], odp[MAX_N*MAX_S + 5], totS;

int cmp(const int& a, const int& b) {
	return L[a] > L[b];
}

int cmp2(const int& x, const int& y) {
	int xe = E[x] + E[y] - L[y] * S[x];
	int xy = E[x] + E[y] - L[x] * S[y];
	return xe > xy;
}

// DP: dp[i][t] = max(dp[i-1][t-S[i]] + energy, dp[i-1][t])
int solution() {
	int energy;
	FOR(i, N) {
		copy(dp, dp + totS + 1, odp);
		FOR(t, totS) {
			if (t >= S[O[i]]) {
				energy = max(E[O[i]] - L[O[i]] * (t - S[O[i]]), 0);
				dp[t] = max(odp[t - S[O[i]]] + energy, odp[t]);
			}
			dp[t] = max(dp[t], dp[t - 1]);
		}
	}
	int res = 0;
	REP(t, totS + 1) res = max(res, dp[t]);
	return res;
}

int main() {
	// redirection
	if (0) {
		freopen("xxx.in", "r", stdin);
		freopen("xxx.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N;
		totS = 0;
		FOR(i, N)
			cin >> S[i] >> E[i] >> L[i], O[i] = i, totS += S[i];
		sort(O + 1, O + 1 + N, cmp2);
		memset(dp, 0, sizeof(dp));
		memset(odp, 0, sizeof(odp));
		cout << "Case #" << t << ": " << solution() << endl;
	}
}

