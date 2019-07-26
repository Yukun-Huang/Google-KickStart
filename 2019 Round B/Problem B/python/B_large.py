# -*- coding: utf-8 -*-
import sys
import functools
from copy import copy

DEBUG = False
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')
    # fin = open('xxx_large.in', 'r')
    # fout = open('xxx_large.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


def cmp(a, b):
    if a>b: return 1
    if a<b: return -1
    return 0

def compare(a, b):
    Sa, Ea, La = a
    Sb, Eb, Lb = b
    return cmp(La/Sa, Lb/Sb)



def solution(N, S, E, L):
    S_total = sum(S)
    dp = [0]*(S_total+1)
    for i in range(1, N+1):
        odp = copy(dp)
        for t in range(S[i-1], S_total+1):  # t
            energy = max(E[i-1] - L[i-1] * (t-S[i-1]), 0)
            if odp[t-S[i-1]] + energy > odp[t]:
                dp[t] = odp[t-S[i-1]] + energy
            else:
                dp[t] = odp[t]
            # 下面这部分不影响最终结果，只是为了保证DP表各项的含义正确
            if dp[t] < dp[t-1]:
                dp[t] = dp[t-1]
        if DEBUG:
            print(dp)
    return max(dp)


t = int(input())
for i in range(1, t + 1):
    N = int(input())
    S, E, L = [], [], []
    for _ in range(N):
        s, e, l = [int(s) for s in input().split(" ")]
        S.append(s)
        E.append(e)
        L.append(l)
    zip_SEL = sorted(zip(S, E, L), key=functools.cmp_to_key(compare), reverse=True)
    S, E, L = [list(t) for t in zip(*zip_SEL)]
    answer = solution(N, S, E, L)
    print("Case #{}: {}".format(i, answer))

