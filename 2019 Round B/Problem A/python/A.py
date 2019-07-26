# -*- coding: utf-8 -*-
import sys
import math
from copy import copy, deepcopy

DEBUG = False
if DEBUG:
    # fin = open('xxx.in', 'r')
    # fout = open('xxx.out', 'w')
    fin = open('xxx_large.in', 'r')
    fout = open('xxx_large.out', 'w')

    sys.stdin = fin
    # sys.stdout = fout

def solution(N, Q, S, LR):
    answer = 0
    record = []
    dat = []
    # N´Î
    for char in S:
        if char not in dat:
            dat.append(char)
        else:
            dat.remove(char)
        record.append([item for item in dat])
    # Q´Î
    for l, r in LR:
        ll = l-1
        if ll == 0:
            temp = set(record[r-1])
        else:
            temp = set(record[r-1]) - set(record[ll-1]) | set(record[ll-1]) - set(record[r-1])
        if len(temp) <= 1:
            answer += 1
    return answer



t = int(input())
for i in range(1, t + 1):
    N, Q = [int(s) for s in input().split(" ")]
    S = input()
    LR = []
    for _ in range(Q):
        l, r = [int(s) for s in input().split(" ")]
        LR.append((l, r))
    answer = solution(N, Q, S, LR)
    print("Case #{}: {}".format(i, answer))

