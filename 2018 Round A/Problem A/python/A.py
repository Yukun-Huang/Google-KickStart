# -*- coding: utf-8 -*-
import sys


def is_odd(digits):
    return digits % 2


def int_to_digits(N, reverse=True):
    l=[]
    while N >= 0:
        l.append(N % 10)
        N = N // 10
        if N == 0:
            break
    if reverse:
        return l    # 倒序
    else:
        return l[::-1]


def digits_to_int(digits, reverse=False):
    if reverse:
        digits = digits[::-1]
    N = 0
    for digit in digits:
        N = 10*N + digit
    return N


def solution(N):
    digits = int_to_digits(N)
    # 去除了高位的偶数
    for digit in digits[::-1]:
        if not is_odd(digit):
            digits.pop(-1)
        else:
            break
    num = len(digits)
    if num < 2:
        return num
    # 去除了最高位奇数后剩下的数
    nine_flag = False
    if digits[-1] == 9:
        nine_flag = True
    digits.pop(-1)
    m = digits_to_int(digits, reverse=True)
    num = num - 1
    # 计算步数
    plus = 10**num - m
    minus = digits_to_int([1]*num, reverse=True) + 1 + m
    if not nine_flag:
        return min(plus, minus)
    else:
        return minus


t = int(input())
for i in range(1, t + 1):
    n, = [int(s) for s in input().split(" ")]
    answer = solution(n)
    print("Case #{}: {}".format(i, answer))
