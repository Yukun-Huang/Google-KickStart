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

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

const uLL MAX_N = 1000 + 5, MAX_M = 1000 + 5;

int T;
uLL N, V1, H1, A, B, C, D, E, F, M;
uLL V[MAX_M], H[MAX_M];

uLL CA[MAX_M][MAX_M];
bool P[MAX_M][MAX_M];

/************ slow solution ***********/
bool check(uLL i, uLL j, uLL k) {
	if (min(V[i], V[j]) < V[k] && V[k] < max(V[i], V[j]) && 
		min(H[i], H[j]) < H[k] && H[k] < max(H[i], H[j]) )
		return false;
	if (min(V[i], V[k]) < V[j] && V[j] < max(V[i], V[k]) &&
		min(H[i], H[k]) < H[j] && H[j] < max(H[i], H[k]))
		return false;
	if (min(V[k], V[j]) < V[i] && V[i] < max(V[k], V[j]) &&
		min(H[k], H[j]) < H[i] && H[i] < max(H[k], H[j]))
		return false;
	return true;
}

uLL solution_n3() {
	uLL ans = 0;

	for (uLL i = 1; i <= N-2; ++i)
		for (uLL j = i+1; j <= N-1; ++j)
			for (uLL k = j+1; k <= N; ++k) {
				if (check(i, j, k))
					ans++;
			}
	return ans;
}

/************ solution for small dataset ***********/
uLL solution() {
	// record Point and axis plus one
	FOR(i, N) {
		V[i] += 1;
		H[i] += 1;
		P[V[i]][H[i]] = true;
	}
	// calc 2d accumulation array
	FOR(i, M)
		FOR(j, M) {
		CA[i][j] = CA[i-1][j] + CA[i][j-1] - CA[i-1][j-1] + P[i][j];
	}
	// count
	uLL count = 0;
	uLL V_max, V_min, H_max, H_min;
	for (uLL i = 1; i <= N - 1; ++i)
		for (uLL j = i + 1; j <= N; ++j) {
			if (H[i] == H[j] || V[i] == V[j])
				continue;
			V_max = max(V[i], V[j]);
			V_min = min(V[i], V[j]);
			H_max = max(H[i], H[j]);
			H_min = min(H[i], H[j]);
			count += (CA[V_max - 1][H_max - 1] - CA[V_max - 1][H_min] -
				CA[V_min][H_max - 1] + CA[V_min][H_min]);
		}
	uLL tol = N*(N - 1)*(N - 2) / 6;
	uLL ans = tol - count;
	return ans;
}


int main() {
	// redirection
	if (1) {
		freopen("C-small-practice.in", "r", stdin);
		freopen("C-small-practice.out", "w", stdout);
	}

	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; ++t) {

		// remember to clear the memory!
		memset(CA, 0, sizeof(CA));
		memset(P, 0, sizeof(P));

		cin >> N >> V1 >> H1 >> A >> B >> C >> D >> E >> F >> M;
		V[1] = V1; H[1] = H1;
		for (int i = 2; i <= N; ++i) {
			V[i] = (A * V[i - 1] + B * H[i - 1] + C) % M;
			H[i] = (D * V[i - 1] + E * H[i - 1] + F) % M;
		}
		//uLL ans = solution_n3();
		uLL ans = solution();
		cout << "Case #" << t << ": " << ans;
		cout << endl;
	}
}