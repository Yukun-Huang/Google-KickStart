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
#include <functional>	// greater, less
#include <limits>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

//#define INT_MAX 2147483647
//#define INT64_MAX 9223372036854775807i64
#define MOD 1000000007

using namespace std;

typedef unsigned int uint;
typedef unsigned long long uLL;
typedef long long LL;

const int MAX_N = 100000, MAX_K = 100000;

int T, K, N;
LL X[MAX_N + 5], C[MAX_N + 5];
vector<LL> newC;

void load_data() {
	// load
	cin >> K >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> X[i];
	}
	for (int i = 1; i <= N; ++i) {
		cin >> C[i];
	}
}

LL solution() {
	LL res = INT64_MAX, res_tmp, posW;
	for (int i = 1; i <= N; ++i) {
		posW = X[i], res_tmp = C[i];
		newC = vector<LL>(N + 1, INT64_MAX);
		for (int j = 1; j <= N; ++j) {
			if (j != i)
				newC[j] = C[j] + abs(posW - X[j]);
		}
		sort(newC.begin()+1, newC.end());
		for (int k = 1; k <= K; ++k) {
			res_tmp += newC[k];
		}
		res = min(res, res_tmp);
	}
	return res;
}

int main() {
	// redirection
	if (1) {
		freopen("xxx.in", "r", stdin);
		freopen("xxx.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		load_data();
		cout << "Case #" << t << ": " << solution() << endl;
	}
}