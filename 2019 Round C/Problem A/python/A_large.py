# -*- coding: utf-8 -*-
import sys

DEBUG = False
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')
    # fin = open('xxx_large.in', 'r')
    # fout = open('xxx_large.out', 'w')
    #
    sys.stdin = fin
    # sys.stdout = fout

direct_to_idx = {'N':0,'S':1,'W':2,'E':3}

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

def move(PR, PC, d, length):
    if d == 'E':
        PC += length
        return PR, PC
    if d == 'W':
        PC -= length
        return PR, PC
    if d == 'N':
        PR -= length
        return PR, PC
    if d == 'S':
        PR += length
        return PR, PC

def add(M, PR, PC):
    M[(PR, PC)] = [(PR - 1, PC), (PR + 1, PC), (PR, PC - 1), (PR, PC + 1)]

t = int(input())
for i in range(1, t + 1):
    N, R, C, SR, SC = [int(s) for s in input().split(" ")]
    SR -= 1
    SC -= 1
    M = {(SR, SC): [(SR-1, SC), (SR+1, SC), (SR, SC-1), (SR, SC+1)]}
    PR, PC = SR, SC
    for d in input():
        d_idx = direct_to_idx[d]
        add(M, PR, PC)

        while (PR, PC) in M.keys():
            nPR, nPC = M[(PR, PC)][d_idx]
            if (nPR, nPC) in M.keys():
                M[(PR, PC)][d_idx] = M[(nPR, nPC)][d_idx]
            PR, PC = nPR, nPC

    print("Case #{}: {} {}".format(i, PR+1, PC+1))

