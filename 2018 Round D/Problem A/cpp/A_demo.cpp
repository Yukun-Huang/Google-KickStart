#include <stdio.h>
#include <set>
#include <algorithm>

const int MAXN = 500005;

int X[MAXN];
int S[MAXN];
long long sum[MAXN];

void erase_one(std::multiset<long long> &s, long long x) {
	auto it = s.find(x);
	auto it1 = it;
	it1++;
	s.erase(it, it1);
}

void solve() {
	int N, O;
	long long D;
	scanf("%d%d%lld", &N, &O, &D);
	int X1, X2, A, B, C, M, L;
	scanf("%d%d%d%d%d%d%d", &X1, &X2, &A, &B, &C, &M, &L);
	X[1] = X1, X[2] = X2;
	for (int i = 3; i <= N; i++) {
		X[i] = (1LL * A * X[i - 1] + 1LL * B * X[i - 2] + C) % M;
	}
	for (int i = 1; i <= N; i++) {
		S[i] = X[i] + L;
		sum[i] = sum[i - 1] + S[i];
	}
	int cnt_odd = 0;
	int l = 1;
	std::multiset<long long> s;
	long long ans = -0x3f3f3f3f3f3f3f3fLL;
	for (int i = 1; i <= N; i++) {
		s.insert(sum[i - 1]);
		cnt_odd += S[i] & 1;
		while (cnt_odd > O) {
			erase_one(s, sum[l - 1]);
			cnt_odd -= S[l] & 1;
			l++;
		}
		auto it = s.lower_bound(sum[i] - D);
		if (it != s.end()) {
			ans = std::max(ans, sum[i] - *it);
			if (ans >= 40) {
			    printf("l=%d,  i=%d  *it=%lld\n", l, i, *it);
			    for(int ii=1;ii<=116;ii++)printf("S%d = %lld\n", ii, sum[ii]);
                break;
			}
		}
	}
	if (ans == -0x3f3f3f3f3f3f3f3fLL) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%lld\n", ans);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}
