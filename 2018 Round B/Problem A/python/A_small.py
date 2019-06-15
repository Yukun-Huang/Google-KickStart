# -*- coding: utf-8 -*-
import sys

DEBUG = False
if DEBUG:
    fin = open('A-small-practice.in', 'r')
    fout = open('A-small-practice.out', 'w')
    sys.stdin = fin
    sys.stdout = fout


def check(n):
    if n % 9:
        while n > 0:
            d = n % 10
            if d == 9:
                return False
            n = n // 10
        return True
    else:
        return False


def solution_small(F, L):
    ans = 0
    for n in range(F, L+1):
        if check(n):
            ans += 1
    return ans


t = int(input())
for i in range(1, t + 1):
    F, L = [int(s) for s in input().split(" ")]
    answer = solution_small(F, L)
    print("Case #{}: {}".format(i, answer))


