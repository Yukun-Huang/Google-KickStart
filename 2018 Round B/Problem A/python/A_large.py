# -*- coding: utf-8 -*-
import sys

DEBUG = False
if DEBUG:
    fin = open('A-large-practice.in', 'r')
    fout = open('A-large-practice.out', 'w')
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


def fun(X):
    s_X = str(X)
    l = len(s_X)
    if l == 1:
        ans = solution_small(1, X)
        return ans
    else:
        ans = solution_small(X - X % 10, X)
    C = 0
    for i in range(1, l):   # 数值第2位到最后一位
        C += int(s_X[l-1-i]) * pow(9, i)
    C = C * 8 // 9
    return C + ans



def solution(F, L):
    return fun(L) - fun(F) + 1


t = int(input())
for i in range(1, t + 1):
    F, L = [int(s) for s in input().split(" ")]
    answer = solution(F, L)
    print("Case #{}: {}".format(i, answer))


