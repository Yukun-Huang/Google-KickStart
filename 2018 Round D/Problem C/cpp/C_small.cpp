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

#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;

const int MAX_R = 100 + 5;
const int MAX_C = 100 + 5;

int T, R, C, W;
char aGrid[MAX_R][MAX_C];
int aSum[MAX_R][MAX_C];
int wordDict[26 + 5];


void load_data() {
	cin >> R >> C >> W;
	char tmp;
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			cin >> tmp;
			aGrid[r][c] = tmp;
		}
	}
	memset(wordDict, 0, sizeof(wordDict));
	for (int w = 1; w <= W; ++w) {
		cin >> tmp;
		wordDict[tmp-'A'+1] = 1;
	}
}

int _inDict(const char& x) {
	if (wordDict[x - 'A' + 1])
		return 4;
	return 0;
}

int _checkMatchLength(const int& r1, const int& c1, const int& r2, const int& c2) {
	return aSum[r2][c2] + aSum[r1 - 1][c1 - 1] - aSum[r1 - 1][c2] - aSum[r2][c1 - 1];
}

int _gcd(int x, int y) {
	int z = y;
	if (y > x) {
		z = x;
		x = y;
		y = z;
	}
	while (x%y != 0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	return z;
}

void calc_aSum() {
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			aSum[r][c] = _inDict(aGrid[r][c]) + aSum[r][c-1] + aSum[r-1][c] - aSum[r-1][c-1];
		}
	}
	// DEBUG
	if (false) {
		for (int r = 0; r <= R; ++r) {
			for (int c = 0; c <= C; ++c) {
				cout << aSum[r][c] << " ";
			}
			cout << endl;
		}
	}
}

void solution(int& maxFunNum, int& maxFunDen, int& maxFunCount) {
	double maxFunValue = -1.0;

	// Calc sumArray
	calc_aSum();
	// Traverse all subGrid
	int nFunNum = 0, nFunDen = 0, nGcd = 0;
	for (int r1 = 1; r1 <= R; ++r1)
		for (int c1 = 1; c1 <= C; ++c1)
			for (int r2 = r1; r2 <= R; ++r2)
				for (int c2 = c1; c2 <= C; ++c2) {
					nFunNum = _checkMatchLength(r1, c1, r2, c2);
					nFunDen = (r2 - r1 + 1) + (c2 - c1 + 1);
					if (nFunNum) {
						nGcd = _gcd(nFunNum, nFunDen);
						nFunNum = nFunNum / nGcd;
						nFunDen = nFunDen / nGcd;
					}
					else
						nFunDen = 1;
					if ((double(nFunNum) / double(nFunDen)) > maxFunValue) {
						maxFunValue = double(nFunNum) / double(nFunDen);
						maxFunNum = nFunNum;
						maxFunDen = nFunDen;
						maxFunCount = 1;
					}
					else if (nFunNum == maxFunNum && nFunDen == maxFunDen)
						maxFunCount++;
				}
}

int main() {
	// redirection
	if (1) {
		//freopen("test.in", "r", stdin);
		//freopen("test_large.in", "r", stdin);
		freopen("C-small-practice.in", "r", stdin);
		//freopen("test.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		// load data
		load_data();
		// solution
		int maxFunNum = -1, maxFunDen = -1, maxFunCount = -1;
		solution(maxFunNum, maxFunDen, maxFunCount);
		cout << "Case #" << t << ": " << maxFunNum << "/" << maxFunDen << " " << maxFunCount << endl;
	}
}