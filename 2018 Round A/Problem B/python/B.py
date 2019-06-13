# -*- coding: utf-8 -*-
import sys
from bisect import bisect_right

DEBUG = False
if DEBUG:
    fin = open('B-large-practice.in', 'r')
    fout = open('B-large-practice.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


def solution_sort(N, K, V):
    V = sorted(V)
    E0 = sum(V) / N
    Ek_1 = E0
    Ek = E0
    for _ in range(K):
        xk = bisect_right(V, Ek_1)
        Ek = xk * Ek_1 / N + sum(V[xk:]) / N
        Ek_1 = Ek
    return Ek


t = int(input())
for i in range(1, t + 1):
    N, K = [int(s) for s in input().split(" ")]
    V = [int(s) for s in input().split(" ")]
    
    answer = solution_sort(N, K, V)
    
    print("Case #{}: {}".format(i, answer))
    
    
    
