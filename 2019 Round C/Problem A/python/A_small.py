# -*- coding: utf-8 -*-
import sys
import math
import numpy as np
from copy import copy, deepcopy

DEBUG = True
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')
    # fin = open('xxx_large.in', 'r')
    # fout = open('xxx_large.out', 'w')
    #
    sys.stdin = fin
    # sys.stdout = fout


def direct(PR, PC, d):
    if d == 'E':
        PC += 1
        return PR, PC
    if d == 'W':
        PC -= 1
        return PR, PC
    if d == 'N':
        PR -= 1
        return PR, PC
    if d == 'S':
        PR += 1
        return PR, PC


t = int(input())
for i in range(1, t + 1):
    N, R, C, SR, SC = [int(s) for s in input().split(" ")]
    SR -= 1
    SC -= 1
    M = np.zeros((R, C), dtype=bool)
    M[SR][SC] = True
    PR, PC = SR, SC
    for d in input():
        while M[PR][PC]:
            PR, PC = direct(PR, PC, d)
        M[PR][PC] = True

    print("Case #{}: {} {}".format(i, PR+1, PC+1))

