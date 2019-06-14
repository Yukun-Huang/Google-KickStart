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

using namespace std;

typedef long long LL;

LL T, L, N, A, B, C, D;
char S1, S2;

char S[1000000+5];

vector<string> Dict;

bool check(string &word, int S_freq[], const int W_freq[] ){
    for (int i=0; i<26; ++i){
        if (S_freq[i] != W_freq[i])
            return false;
    }
    return true;
}


int solution(){
    int answer = 0;
    for ( string w : Dict){
        int l = w.size();

        // init S_freq
        int S_freq[26] = {0};
        for (int i = 1; i <= l; ++i){
            if (i + l - 1 > N)
                break;
            S_freq[int(S[i] - 97)]++;
            if (l > 500){
                cout << "???"<< endl;
            }
        }

        // init W_freq
        int W_freq[26] = {0};
        for (int i = 0; i < l; ++i){
            W_freq[int(w[i] - 97)]++;
        }

        // search
        for (int i = 1; i <= N; ++i){
            int j = i + l - 1;
            if (j > N)
                break;
            if (S[i] == w[0] && S[j] == w[l-1]){
                if (check(w, S_freq, W_freq)){
                    answer++;
                    break;
                }
            }
            // update S_freq
            if (S_freq[int(S[i] - 97)])
                S_freq[int(S[i] - 97)]--;
            S_freq[int(S[j+1] - 97)]++;
        }
    }
    return answer;
}


int main() {
    // redirection
    if (1){
//        freopen("../C-small.in", "r", stdin);
        freopen("../C-small-practice.in", "r", stdin);
        freopen("../C-small-practice.out", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> L;
        Dict.clear();
        for (int i = 0; i < L; ++i){
            string tmp;
            cin >> tmp;
            Dict.push_back(tmp);
        }
        cin >> S1 >> S2 >> N >> A >> B >> C >> D;
        S[1] = S1; S[2] = S2;
        LL xi_2 = LL(S1), xi_1 = LL(S2), xi = 0;
        for (int i = 3; i <= N; ++i){
            xi = ( A * xi_1 + B * xi_2 + C ) % D;
            S[i] = char(97 + (xi % 26));
            xi_2 = xi_1;
            xi_1 = xi;
        }
        int answer = solution();
        cout << "Case #" << t << ": " << answer << endl;
    }
}

