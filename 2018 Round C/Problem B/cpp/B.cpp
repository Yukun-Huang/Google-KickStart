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
#include<functional>	// greater, less

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

const uLL MAX_N = 15 + 5;

int T;
int N;
int M[MAX_N][MAX_N];

void dfs(int cur, int& ans, int sum, vector<pair<int, int>>& pq, vector<bool>& canUse, vector<int>& res) {
	if (res.size() >= 3 && sum>res[0] * 2)
		ans++;

	for (int i = cur; i<pq.size(); i++) {
		int a = pq[i].second / N + 1;
		int b = pq[i].second % N + 1;
		int len = pq[i].first;
		if (canUse[a] && canUse[b]) {
			canUse[a] = false;
			canUse[b] = false;
			res.push_back(len);
			dfs(i + 1, ans, sum + len, pq, canUse, res);
			res.pop_back();
			canUse[a] = true;
			canUse[b] = true;
		}
	}

}


int main() {
	// redirection
	if (1) {
		freopen("B-small-practice.in", "r", stdin);
		freopen("B-small-practice.out", "w", stdout);
		//freopen("B-large-practice.in", "r", stdin);
		//freopen("B-large-practice.out", "w", stdout);
	}

	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int t = 1; t <= T; ++t) {
		
		vector<pair<int, int>> pq;
		cin >> N;
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j){
				cin >> M[i][j];
				if (i < j && M[i][j] > 0) {
					pq.push_back(make_pair(M[i][j], (i-1)*N + j-1));
				}
		}
		// sort from large to small
		sort(pq.begin(), pq.end(), greater<pair<int,int>>());

		vector<bool> canUse(N+1, true);
		vector<int> res;
		int ans = 0;
		
		dfs(0, ans, 0, pq, canUse, res);

		cout << "Case #" << t << ": " << ans;
		cout << endl;
	}
}