# -*- coding: utf-8 -*-
import sys
import math
from copy import deepcopy

DEBUG = False
if DEBUG:
    fin = open('xxx.in', 'r')
    fout = open('xxx.out', 'w')
    # fin = open('xxx_large.in', 'r')
    # fout = open('xxx_large.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


def near_search(k, pos, R, C, M, M_dict):
    r, c = pos
    full_flag = True
    if r+1 < R:
        if k+1 < M[r+1][c]:
            M[r+1][c] = k + 1
            if k+1 not in M_dict.keys():
                M_dict[k+1] = [(r+1,c)]
            else:
                M_dict[k+1].append((r+1,c))
            full_flag = False

    if r-1 >= 0:
        if k+1 < M[r-1][c]:
            M[r-1][c] = k + 1
            if k+1 not in M_dict.keys():
                M_dict[k+1] = [(r-1,c)]
            else:
                M_dict[k+1].append((r-1,c))
            full_flag = False

    if c+1 < C:
        if k+1 < M[r][c+1]:
            M[r][c+1] = k + 1
            if k+1 not in M_dict.keys():
                M_dict[k+1] = [(r,c+1)]
            else:
                M_dict[k+1].append((r,c+1))
            full_flag = False

    if c-1 >= 0:
        if k+1 < M[r][c-1]:
            M[r][c-1] = k + 1
            if k+1 not in M_dict.keys():
                M_dict[k+1] = [(r,c-1)]
            else:
                M_dict[k+1].append((r,c-1))
            full_flag = False

    return full_flag


def BFS(R, C, M, M_dict):
    # first phase
    max_k = 0
    while 1:
        full_flag = True
        for pos in M_dict[max_k]:
            full_flag &= near_search(max_k, pos, R, C, M, M_dict)
        if full_flag == True:
            break
        max_k += 1
    return max_k


def check(K, max_K, R, C, M_dict):
    if K == max_K:
        return True
    lx, rx, ly, ry = R+C-2, 0, R-1, -C+1
    for k in range(K+1, max_K+1):
        for (x,y) in M_dict[k]:
            tx, ty = x+y, x-y
            lx, rx = min(lx, tx), max(rx, tx)
            ly, ry = min(ly, ty), max(ry, ty)
    for x in range(R):
        for y in range(C):
            dist = max(abs(lx - (x + y)), abs(rx - (x + y)), \
                       abs(ly - (x - y)), abs(ry - (x - y)))
            if dist <= K:
                return True
    return False


t = int(input())

for i in range(1, t + 1):
    ## reading data
    R, C = [int(s) for s in input().split(" ")]
    M = [[float('inf')] * C for _ in range(R)]
    M_dict = {0: []}
    for r in range(R):
        for c, s in enumerate(input()):
            val = int(s)
            if val == 1:
                M[r][c] = 0
                M_dict[0].append((r,c))
    ## BFS
    max_K = BFS(R, C, M, M_dict)
    ## binary search
    Bl, Br = 0, max_K
    answer = max_K
    while Bl <= Br:
        K = ( Bl + Br ) // 2
        if check(K, max_K, R, C, M_dict):
            if K < answer:
                answer = K
            Br = K - 1
        else:
            Bl = K + 1
    print("Case #{}: {}".format(i, answer))

