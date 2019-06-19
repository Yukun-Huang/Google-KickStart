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

int T, N, K, A[100+5], B[100+5], C[100 + 5];
uLL P;

int S[100 + 5];

void solution() {
	memset(S, -1, sizeof(S));

	int count = 0;
	FOR(i, K) {
		assert(A[i] == B[i]);
		S[A[i]] = bool(C[i]);
	}
	bitset<100 + 5> bs(P-1);
	int idx_bs = 0;
	RFOR(i, N) {
		if (S[i] == -1) {
			S[i] = bs[idx_bs];
			idx_bs++;
		}
	}
}


int main() {
	// redirection
	if (1) {
		freopen("B-small-practice.in", "r", stdin);
		freopen("B-small-practice.out", "w", stdout);
	}

	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		cin >> N >> K >> P ;
		FOR(i, K)
			cin >> A[i] >> B[i] >> C[i];
		solution();
		cout << "Case #" << t << ": ";
		FOR(i, N) {
			cout << S[i];
		}
		cout << endl;
	}
}