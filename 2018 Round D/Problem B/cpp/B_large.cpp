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
typedef long long LL;
typedef unsigned long long uLL;

const int MAX_N = 500000 + 5;
const int MAX_K = 500000 + 5;
int T;
int N, K;
//  Tx = h-p, Bx = y-x
//  Ty = h+p, By = y+x
LL P[MAX_N], H[MAX_N];
LL X[MAX_K], Y[MAX_K];

vector<pair<LL, LL> > Tower;
vector<pair<LL, LL> > Ball;

void load_data() {

	LL p1, p2, A1, B1, C1, M1;
	LL h1, h2, A2, B2, C2, M2;
	LL x1, x2, A3, B3, C3, M3;
	LL y1, y2, A4, B4, C4, M4;

	cin >> N >> K;
	cin >> p1 >> p2 >> A1 >> B1 >> C1 >> M1;
	cin >> h1 >> h2 >> A2 >> B2 >> C2 >> M2;
	cin >> x1 >> x2 >> A3 >> B3 >> C3 >> M3;
	cin >> y1 >> y2 >> A4 >> B4 >> C4 >> M4;

	P[1] = p1; P[2] = p2;
	H[1] = h1; H[2] = h2;
	X[1] = x1; X[2] = x2;
	Y[1] = y1; Y[2] = y2;

	Tower.emplace_back(make_pair(h1 - p1, h1 + p1));
	Tower.emplace_back(make_pair(h2 - p2, h2 + p2));
	Ball.emplace_back(make_pair(y1 - x1, y1 + x1));
	Ball.emplace_back(make_pair(y2 - x2, y2 + x2));

	for (int i = 3; i <= N; ++i) {
		P[i] = (A1 * P[i - 1] + B1 * P[i - 2] + C1) % M1 + 1;
		H[i] = (A2 * H[i - 1] + B2 * H[i - 2] + C2) % M2 + 1;
		Tower.emplace_back(make_pair(H[i] - P[i], H[i] + P[i]));
	}
	for (int i = 3; i <= K; ++i) {
		X[i] = (A3 * X[i - 1] + B3 * X[i - 2] + C3) % M3 + 1;
		Y[i] = (A4 * Y[i - 1] + B4 * Y[i - 2] + C4) % M4 + 1;
		Ball.emplace_back(make_pair(Y[i] - X[i], Y[i] + X[i]));
	}
}

//  h-p >= y-x, true
//  h+p >= y+x, true
int solution() {
	int answer = 0;
	sort(Tower.begin(), Tower.end());
	sort(Ball.begin(), Ball.end());
	reverse(Ball.begin(), Ball.end());
	int id = N - 1;
	LL maxY = INT64_MIN;
	for (pair<LL, LL> b : Ball) {
		while (id >= 0 && b.first <= Tower[id].first) {
			maxY = max(maxY, Tower[id].second);
			id--;
		}
		if (maxY >= b.second)
			answer++;
	}
	return answer;
}

int main() {
	if (0) {
		freopen("../test.in", "r", stdin);
		//        freopen("../test.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		load_data();
		cout << "Case #" << t << ": " << solution() << endl;
		Tower.clear();
		Ball.clear();
	}
	return 0;
}
