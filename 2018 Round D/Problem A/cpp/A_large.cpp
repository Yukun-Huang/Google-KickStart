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

const int MAX_N = 500000 + 5;
int T;
LL N, O, D;
LL X1, X2, A, B, C, M, L;
LL S[MAX_N];

LL pre_odd[MAX_N];
LL pre_sum[MAX_N];


void erase_one(multiset<long long> &s, long long x) {
    auto it = s.find(x);
    auto it1 = it;
    it1++;
    s.erase(it, it1);
}


LL solution(bool &has_solution) {
    LL max_score = INT64_MIN;
    FOR(i, N) {
        pre_odd[i] = pre_odd[i - 1] + (S[i] & 1);   // 与运算的优先级小于加减乘除
        pre_sum[i] = pre_sum[i - 1] + S[i];
    }
    LL left = 1, right = 1;
    multiset<LL> ms;
    ms.insert(-pre_sum[left-1]);
    ms.insert(-pre_sum[right]);
    for(; left <= N; left++){
        if(right >= left){
            erase_one(ms, -pre_sum[left-1]);
            erase_one(ms, -pre_sum[right]);
        }
        else{
            ms.clear();
            right = left;
        }
        // find range of right index
        while(right <= N){
            if (pre_odd[right] - pre_odd[left - 1] <= O){
                ms.insert(-pre_sum[right]);
                right++;
            }
            else{
                right--;
                break;
            }
        }
        // find right index
        if(right < left) continue;
        else {
            right = min(right, N);
            auto it = ms.lower_bound(-pre_sum[left-1] - D);
            if (it != ms.end()){
                has_solution = true;
                max_score = max(max_score, -(*it) - pre_sum[left-1] );
            }
        }
    }
    return max_score;
}


int main() {
    // redirection
    if (1) {
//        freopen("../test.in", "r", stdin);
//        freopen("../test.out", "w", stdout);
//		freopen("../A-small-practice.in", "r", stdin);
//		freopen("../A-small-practice.out", "w", stdout);
		freopen("../A-large-practice.in", "r", stdin);
		freopen("../A-large-practice.out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int t = 1; t <= T; ++t) {

        cin >> N >> O >> D;
        cin >> X1 >> X2 >> A >> B >> C >> M >> L;
        S[1] = X1 + L;
        S[2] = X2 + L;
        LL X3 = 0;
        for (int i = 3; i <= N; ++i) {
            X3 = (A * X2 + B * X1 + C) % M;
            S[i] = X3 + L;
            X1 = X2;
            X2 = X3;
        }
        bool has_solution = false;
        LL ans = solution(has_solution);
        if (has_solution)
            cout << "Case #" << t << ": " << ans << endl;
        else
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
    }
}
