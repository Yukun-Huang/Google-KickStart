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
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

vector<pair<int, int>> Qs;

int T, N, Q;
bool booked[1000000 + 5];

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
	return (a.second-a.first) < (b.second - b.first);
}

void load_data() {
	// clear
	memset(booked, 0, sizeof(booked));
	Qs.clear();
	// load
	cin >> N >> Q;
	int Li, Ri;
	for (int i = 0; i < Q; ++i) {
		cin >> Li >> Ri;
		Qs.push_back(make_pair(Li, Ri));
	}
	// sort
	sort(Qs.begin(), Qs.end(), comp);
}

int solution() {
	int res = INT_MAX;
	int Li, Ri, cnt;
	for (int i = 0; i < Q; ++i) {
		Li = Qs[i].first, Ri = Qs[i].second, cnt = 0;
		for (int j = Li; j <= Ri; ++j) {
			if (!booked[j]) {
				booked[j] = true;
				cnt++;
			}
		}
		res = min(cnt, res);
	}
	return res;
}

int main() {
	// redirection
	if (1) {
		freopen("xxx_small.in", "r", stdin);
		//freopen("xxx.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		load_data();
		cout << "Case #" << t << ": " << solution() << endl;
	}
}