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

int T, N, G, M;
int H[100 + 5];
char C[100 + 5];
bool visit[100 + 5];
vector<vector<int> > memo;
vector<int> res;

void load_data() {
	// load
	cin >> N >> G >> M;
	for (int i = 1; i <= G; ++i) {
		cin >> H[i] >> C[i];
	}
}

void solution() {
	int pos, t_tmp;
	res = vector<int>(G + 1, 0);
	memo = vector<vector<int> >(N + 1, vector<int>());
	// init
	for (int g = 1; g <= G; ++g) {
		memo[H[g]].push_back(g);
	}
	// simu
	for (int t = 1; t <= M; ++t) {
		memset(visit, 0, sizeof(visit));
		for (int g = 1; g <= G; ++g) {
			if (C[g] == 'C') {
				pos = ((H[g] - 1 + t) % N) + 1;
			}
			else {
				t_tmp = N - t % N;
				pos = ((H[g] - 1 + t_tmp) % N) + 1;
			}
			if (!visit[pos]) {
				visit[pos] = true;
				memo[pos].clear();
				memo[pos].push_back(g);
			}
			else
				memo[pos].push_back(g);
		}
	}
	// result
	for (int n = 1; n <= N; ++n) {
		for (auto g : memo[n])
			res[g]++;
	}
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
		solution();
		cout << "Case #" << t << ": ";
		for (int g = 1; g <= G; ++g) {
			cout << res[g];
			if (g < G) cout << " ";
		}
		cout << endl;
	}
}