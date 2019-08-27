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

vector<pair<int, int>> Qs;

int T, N, M;
const int MAXN = 100005;

// Union-Find Set, STL style
class UF {
public:
	UF(int n) {
		count = n;
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int i) { // path compression
		if (parent[i] != i) parent[i] = find(parent[i]);
		return parent[i];
	}

	void Union(int x, int y) { // union with rank
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
			else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
			else {
				parent[rooty] = rootx; rank[rootx] += 1;
			}
			--count;
		}
	}

	int size() const {
		return count;
	}

	void clear() {
		parent.clear();
		rank.clear();
		count = 0;
	}

private:
	vector<int> parent;
	vector<int> rank;
	int count; // # of connected components
};

UF uSet(0);

void load_data() {
	cin >> N >> M;
	uSet = UF(N);
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		uSet.Union(a - 1, b - 1);
	}
}

int solution() {
	return N + uSet.size() - 2;
}

int main() {
	if (1) {
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