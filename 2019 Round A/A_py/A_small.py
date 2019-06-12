# -*- coding: utf-8 -*-
import sys
import math

DEBUG = False
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


def calc_min_k(chooce):
    min_k = 0
    max_S = max(chooce)
    for Si in chooce:
        min_k += (max_S - Si)
    return min_k

def solution(N, P, S):
    min_k_list = []
    S = sorted(S)
    for p_left in range(N - P + 1):
        chooce = S[p_left:p_left+P]
        min_k_list.append(calc_min_k(chooce))
    answer = min(min_k_list)
    return answer


t = int(input())
for i in range(1, t + 1):
    N, P = [int(s) for s in input().split(" ")]
    S = [int(s) for s in input().split(" ")]
    answer = solution(N, P, S)
    print("Case #{}: {}".format(i, answer))


