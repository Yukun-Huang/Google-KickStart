#include <bits/stdc++.h>

using LL = long long;

const int max_N = 50000 + 21;

inline LL id(LL r, LL c) {
	return (r - 1) * max_N + c;
}

inline std::pair<LL, LL> inv_id(LL id) {
	return{ (id - 1) / max_N + 1, (id - 1) % max_N + 1 };
}

struct Dsu {
	std::unordered_map<LL, LL> f;

	LL find(LL x) {
		if (!f.count(x)) return f[x] = x;
		return f[x] == x ? x : f[x] = find(f[x]);
	}

	void clr() {
		f.clear();
	}
} dsu[4];

const LL dir[4][2] = {
	{ 1, 0 },
	{ -1, 0 },
	{ 0, 1 },
	{ 0, -1 },
};

int get_dir(char op) {
	if (op == 'S') return 0;
	if (op == 'N') return 1;
	if (op == 'E') return 2;
	if (op == 'W') return 3;
	assert(0);
}

void visit(LL r, LL c) {
	for (int i = 0; i < 4; ++i) {
		dsu[i].f[id(r, c)] = id(r + dir[i][0], c + dir[i][1]);
	}
}

int T, N, R, C, Sr, Sc;

char op[max_N];

void testCase(int t) {
	for (int i = 0; i < 4; ++i) {
		dsu[i].clr();
	}
	scanf("%d%d%d%d%d%s", &N, &R, &C, &Sr, &Sc, op);
	LL r = Sr, c = Sc;
	visit(r, c);
	for (int i = 0; i < N; ++i) {
		int d = get_dir(op[i]);
		auto nxt = inv_id(dsu[d].find(id(r + dir[d][0], c + dir[d][1])));
		visit(r = nxt.first, c = nxt.second);
	}
	printf("Case #%d: %lld %lld\n", t, r, c);
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		testCase(i);
	}
}

