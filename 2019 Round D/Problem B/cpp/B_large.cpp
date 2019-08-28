#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <time.h>
#include <map>
#include <set>

#define mem(a,x) memset(a,x,sizeof(a))
#define gi(x) scanf("%d",&x)
#define gi2(x,y) scanf("%d%d",&x,&y)
#define gi3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define gll(x) scanf("%lld",&x)
#define gll2(x,y) scanf("%lld%lld",&x,&y)

using namespace std;
const double eps = 1e-8;
typedef long long ll;
const int MAXN = 200005;
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
vector<int>a[2][MAXN];//0 is clockwise , 1 is anti-clockwise
int book[MAXN];//book[i]代表最后经过i号地点的人的下标(原位置的下标)
int book1[MAXN];//若某个地点同时被顺时针和逆时针的人最后经过,用book[i]记录顺时针,book1[i]记录逆时针
int flag[MAXN];//flag[i]=-1,0,1,2 分别代表没有人经过i,最后经过是顺时针的,最后经过是逆时针的,最后是顺时针和逆时针同时经过的
int s[MAXN];//逆时针的队列
int num[2][MAXN];//num[0][i]代表最初在i号点且顺时针方向行驶的人 最后经过了多少个地点 num[1][i]代表逆时针
int n, g, m;
int ss[MAXN];//ss[i]代表标号为i的人 最后经过了ss[i]个地点
queue<int>q;//瞬时针的队列

int dis(int a, int b) {
	if (a <= b) {
		return b - a;
	}
	else {
		return n - a + b;
	}
}
void init() {
	while (!q.empty())q.pop();
	for (int i = 1;i <= n;i++) {
		num[0][i] = num[1][i] = 0;
		a[0][i].clear();
		a[0][i + n].clear();
		a[1][i].clear();
		a[1][i + n].clear();
		book[i] = -1;
		book1[i] = -1;
		flag[i] = 0;
	}
	if (m >= 2 * n) {
		m %= n;
		m += n;
	}
}

int main() {

	int T, cnt = 1;
	gi(T);
	while (T--) {
		printf("Case #%d:", cnt++);
		int l = 1, r = 0;
		gi3(n, g, m);//n 不是乘客
		init();
		for (int i = 1;i <= g;i++) {
			ss[i] = 0;
			int x;char s1[3];
			gi(x);scanf("%s", s1);
			if (s1[0] == 'C') {
				a[0][x].push_back(i);
				a[0][x + n].push_back(i);
			}
			else {
				a[1][x].push_back(i);
				a[1][x + n].push_back(i);
			}
		}
		n *= 2;//把1-n复制成两段
		for (int i = n - m + 1;i <= n;i++) {
			if (a[0][i].size()) {
				q.push(i);
			}
		}
		if (a[0][1].size()) {
			q.push(1);
		}
		for (int i = 1;i <= m + 1;i++) {
			if (a[1][i].size()) {
				++r;
				s[r] = i;
			}
		}
		for (int i = 1;i <= n / 2;i++) {
			if (i != 1) {//更新队列
				while (!q.empty() && (dis(q.front(), i)>m || q.front() == i)) {
					q.pop();
				}
				if (a[0][i].size()) {
					q.push(i);
				}
				int nx = i + m;
				if (nx>n)nx -= n;
				if (a[1][nx].size()) {
					++r;
					s[r] = nx;
				}
			}
			if (q.empty() && l>r) {//都为空,没人经过此点
				flag[i] = -1;
				book[i] = -1;
			}
			else if (q.empty()) {//逆时针不为空
				flag[i] = 1;
				book[i] = s[r];
			}
			else if (l>r) {//顺时针不为空
				flag[i] = 0;
				book[i] = q.front();
			}
			else {//顺时针和逆时针都不为空
				int t1 = dis(q.front(), i);
				int t2 = dis(i, s[r]);
				if (t1 == t2) {//距离相等,则都要记录
					flag[i] = 2;
					book[i] = q.front();
					book1[i] = s[r];
				}
				else if (t1>t2) {//顺时针离得更远,则顺时针最后经过
					flag[i] = 0;
					book[i] = q.front();
				}
				else {//逆时针离得更远,则逆时针最后经过
					flag[i] = 1;
					book[i] = s[r];
				}
			}
			if (l <= r&&s[l] == i) {//更新队列, 如果逆时针队列里有i,要计算i+1时,当然要把i删除
				l++;
			}
		}
		n /= 2;
		for (int i = 1;i <= n;i++) {
			if (flag[i] == 0 || flag[i] == 1) {
				int t = book[i];
				while (t>n)t -= n;
				num[flag[i]][t]++;
			}
			else if (flag[i] == 2) {
				int t = book[i];
				while (t>n)t -= n;
				num[0][t]++;

				t = book1[i];
				while (t>n)t -= n;
				num[1][t]++;
			}
		}
		for (int i = 0;i <= 1;i++) {
			for (int j = 1;j <= n;j++) {
				for (int q = 0;q<a[i][j].size();q++) {
					int id = a[i][j][q];
					ss[id] += num[i][j];
				}
			}
		}
		for (int i = 1;i <= g;i++) {
			printf(" %d", ss[i]);
		}
		puts("");
	}
	return 0;
}

