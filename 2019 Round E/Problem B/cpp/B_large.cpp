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
int totalC, totalE;
int C[MAXS], E[MAXS], A[MAXD], B[MAXD];
vector<int> prefixC;
vector<int> prefixE;
vector<pair<int, double> > EdivC;

bool cmp(const pair<int, double>& p1, const pair<int, double>& p2) {
	return p1.second > p2.second;
}

void load_data() {
	cin >> D >> S;
	EdivC.clear();
	for (int s = 1; s <= S; ++s) {
		cin >> C[s] >> E[s];
		EdivC.push_back(make_pair(s, double(E[s]) / double(C[s])));
	}
	for (int d = 1; d <= D; ++d) {
		cin >> A[d] >> B[d];
	}
	sort(EdivC.begin(), EdivC.end(), cmp);
	// 必须排序后再计算前缀和！
	prefixC = { 0 };
	prefixE = { 0 };
	int prefixIdx = 0;
	for (auto p : EdivC) {
		prefixC.push_back(prefixC[prefixIdx] + C[p.first]);
		prefixE.push_back(prefixE[prefixIdx] + E[p.first]);
		prefixIdx++;
	}
	totalC = prefixC[S], totalE = prefixE[S];
}

string solution() {
	string res;
	for (int d = 1; d <= D; ++d) {
		double targetC = A[d], targetE = B[d];
		if (totalC < targetC || totalE < targetE) {
			res += "N";
			continue;
		}
		int ableC = totalC - targetC;
		// binary search
		vector<int>::iterator iter;
		iter = lower_bound(prefixE.begin() + 1, prefixE.end(), targetE); // first element that >= targetE
		int idx = distance(prefixE.begin(), iter);
		if (idx == 1) {
			if (targetE / EdivC[0].second <= ableC)
				res += "Y";
			else
				res += "N";
			continue;
		}
		targetE -= prefixE[idx - 1];
		ableC -= prefixC[idx - 1];
		if (targetE / EdivC[idx - 1].second <= ableC)
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