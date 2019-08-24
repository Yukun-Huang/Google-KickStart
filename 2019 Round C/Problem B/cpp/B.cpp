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

typedef unsigned int uint;
typedef unsigned long long uLL;
typedef long long LL;

const int MAX_R = 300+5, MAX_C = 300+5;
vector<vector<int> > arr(MAX_R, vector<int>(MAX_C, 0));
int arr_cnt[MAX_R][MAX_C];
int T, K, R, C;

void load_data(){
    cin >> R >> C >> K;
    for (int r=1; r<=R; ++r){
        for (int c=1; c<=C; ++c){
            cin >> arr[r][c];
        }
    }
    memset(arr_cnt, 0, sizeof(arr_cnt));
}

int monoStack(const vector<int>& heights) {
    int n = heights.size();
    int maxArea = 0;
    stack<int> s;
    s.push(-1);
    // 遍历所有元素
    for (int i=0; i<n; ++i){
        while (s.top() != -1 && heights[s.top()] >= heights[i]){
            int tmp = s.top();
            s.pop();
            maxArea = max(maxArea, heights[tmp]*(i-1-s.top()));
        }
        s.push(i);
    }
    // 剩余的元素出栈，结算
    while(s.top() != -1){
        int tmp = s.top();
        s.pop();
        maxArea = max(maxArea, heights[tmp]*(n-s.top()-1));
    }
    return maxArea;
}

int solution(){
    // 找到向右拓展的最大长度
    int max_thick, min_thick;
    for (int r=1; r<=R; ++r){
        for (int c=1; c<=C; ++c){
            max_thick = arr[r][c];
            min_thick = arr[r][c];
            int p = c + 1, count = 1;
            while (p <= C && max(max_thick, arr[r][p]) - min(min_thick, arr[r][p]) <= K){
                max_thick = max(max_thick, arr[r][p]);
                min_thick = min(min_thick, arr[r][p]);
                p++;
                count++;
            }
            arr_cnt[r][c] = count;
        }
    }
    // 使用单调栈对每一列找最大矩形
    int res = 0;
    vector<int> heights;
    for (int c=1; c<=C; ++c) {
        heights.clear();
        for (int r=1; r<=R; ++r) {
            heights.push_back(arr_cnt[r][c]);
        }
        res = max(res, monoStack(heights));
    }
    return res;
}

int main() {
    // redirection
    if (1) {
        freopen("../large.in", "r", stdin);
        freopen("../large.out", "w", stdout);
    }
    cin >> T;
    for (int t = 1; t <= T; ++t){
        cout << "Case #" << t << ": ";
        /* ------ edit here ------ */
        load_data();
        cout << solution();
        /* ----------------------- */
        cout << endl;
    }
}
