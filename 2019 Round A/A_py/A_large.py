# -*- coding: utf-8 -*-
import sys
import math

DEBUG = True
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


def calc_min_k_init(chooce):
    min_k = 0
    max_S = max(chooce)
    for Si in chooce:
        min_k += (max_S - Si)
    first_element = chooce[0]
    return min_k, max_S, first_element


def calc_min_k(new_element, min_k, max_S, first_element, P):
    min_k -= (max_S - first_element)
    if new_element > max_S:
        min_k += (P-1) * (new_element - max_S)
        max_S = new_element
    elif new_element < max_S:
        min_k += (max_S - new_element)
    return min_k, max_S


def solution(N, P, S):
    S = sorted(S)
    # init
    min_k, max_S, first_element = calc_min_k_init(S[0:P])
    answer = min_k
    # run
    for p_left in range(1, N - P + 1):
        new_element = S[p_left+P-1]
        min_k, max_S = calc_min_k(new_element, min_k, max_S, first_element, P)
        first_element = S[p_left]
        if min_k < answer:
            answer = min_k
    return answer


t = int(input())
for i in range(1, t + 1):
    N, P = [int(s) for s in input().split(" ")]
    S = [int(s) for s in input().split(" ")]
    answer = solution(N, P, S)
    print("Case #{}: {}".format(i, answer))


