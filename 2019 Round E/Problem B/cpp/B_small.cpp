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
typedef unsigned long long uLL;
typedef long long LL;

const int MAXS = 100000 + 5, MAXD = 100000 + 5;
int T, D, S;
int totalC;
int C[MAXS], E[MAXS], A[MAXD], B[MAXD];
vector<pair<int, double> > EdivC;

bool cmp(const pair<int, double>& p1, const pair<int, double>& p2) {
	return p1.second > p2.second;
}

void load_data() {
	cin >> D >> S;
	totalC = 0;
	EdivC.clear();
	for (int s = 1; s <= S; ++s) {
		cin >> C[s] >> E[s];
		EdivC.push_back(make_pair(s, double(E[s]) / double(C[s])));
		totalC += C[s];
	}
	for (int d = 1; d <= D; ++d) {
		cin >> A[d] >> B[d];
	}
	sort(EdivC.begin(), EdivC.end(), cmp);
}

string solution() {
	string res;
	for (int d = 1; d <= D; ++d) {
		double targetC = A[d], targetE = B[d];
		if (totalC < targetC) {
			res += "N";
			continue;
		}
		int ableC = totalC - targetC;
		for (auto p : EdivC) {
			int maxTransC = min(ableC, C[p.first]);
			targetE -= maxTransC * p.second;
			ableC -= maxTransC;
			if (ableC <= 0)
				break;
		}
		if (targetE <= 0)
			res += "Y";
		else
			res += "N";
	}
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
		cout << "Case #" << t << ": ";
		/* --------------------- */
		load_data();
		cout << solution();
		/* --------------------- */
		cout << endl;
	}
}