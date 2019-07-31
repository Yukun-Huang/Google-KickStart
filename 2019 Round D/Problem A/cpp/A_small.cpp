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
//#define INT_MIN (-INT_MAX - 1)
#define MOD 1000000007

using namespace std;

typedef unsigned int uint;
typedef unsigned long long uLL;
typedef long long LL;

const int MAX_N = 100000, MAX_Q = 100000;

int T, N, Q;
uint A[MAX_N + 5], preA[MAX_N + 5], P[MAX_Q + 5], V[MAX_Q + 5];

void load_data() {
	// load
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < Q; ++i) {
		cin >> P[i] >> V[i];
	}
}

bool check_even(uint x) {
	int cnt = 0;
	while (x)
	{
		cnt++;
		x &= x - 1;
	}
	return !(cnt & 1);
}

int solution() {
	int res = 0;
	preA[0] = A[0];
	for (int i = 1; i < N; ++i) {
		preA[i] = preA[i-1] ^ A[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (i > 0 && check_even(preA[j] ^ preA[i - 1]))
				res = max(res, j - i + 1);
			else if (check_even(preA[j]))
				res = max(res, j + 1);
		}
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
		cout << "Case #" << t << ": ";
		for (int q = 0; q < Q; ++q) {
			A[P[q]] = V[q];
			cout << solution();
			if (q < Q - 1) cout << " ";
		}
		cout << endl;
	}
}