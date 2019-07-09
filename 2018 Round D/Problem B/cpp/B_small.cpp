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

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)
#define MOD 1000000007

using namespace std;
typedef unsigned long long uLL;
typedef long long LL;

const int MAX_N = 500000 + 5;
const int MAX_K = 500000 + 5;
int T;
int N, K;
LL P[MAX_N], H[MAX_N];
LL X[MAX_K], Y[MAX_K];

void load_data() {
	cin >> N >> K;
	LL p1, p2, A1, B1, C1, M1;
	LL h1, h2, A2, B2, C2, M2;
	LL x1, x2, A3, B3, C3, M3;
	LL y1, y2, A4, B4, C4, M4;
	cin >> p1 >> p2 >> A1 >> B1 >> C1 >> M1;
	cin >> h1 >> h2 >> A2 >> B2 >> C2 >> M2;
	cin >> x1 >> x2 >> A3 >> B3 >> C3 >> M3;
	cin >> y1 >> y2 >> A4 >> B4 >> C4 >> M4;

	P[1] = p1; P[2] = p2;
	H[1] = h1; H[2] = h2;
	X[1] = x1; X[2] = x2;
	Y[1] = y1; Y[2] = y2;

	for (int i = 3; i <= N; ++i) {
		P[i] = (A1 * P[i - 1] + B1 * P[i - 2] + C1) % M1 + 1;
		H[i] = (A2 * H[i - 1] + B2 * H[i - 2] + C2) % M2 + 1;
	}
	for (int i = 3; i <= K; ++i) {
		X[i] = (A3 * X[i - 1] + B3 * X[i - 2] + C3) % M3 + 1;
		Y[i] = (A4 * Y[i - 1] + B4 * Y[i - 2] + C4) % M4 + 1;
	}
}

//  x - y - p + h >= 0, true
// -x - y + p + h >= 0, true
bool check(int b) {
	LL x = X[b], y = Y[b];
	for (int i = 1; i <= N; i++) {
		LL p = P[i], h = H[i];
		if ((x - y - p + h >= 0) && (-x - y + p + h >= 0))
			return true;
	}
	return false;
}

int solution() {
	int answer = 0;
	for (int i = 1; i <= K; i++) {
		if (check(i))
			answer++;
	}
	return answer;
}

int main() {
	if (0) {
		freopen("../test.in", "r", stdin);
		// freopen("../test.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		load_data();
		cout << "Case #" << t << ": " << solution() << endl;
	}
}
