# -*- coding: utf-8 -*-
import sys
import math

inFile = sys.argv[1]
outFile = sys.argv[2]


def find_rightmost_all(pL, N, O, D, S):
    rightmost = 'IMPOSSIBLE'
    SS = 0
    SO = 0
    for pR in range(pL, N):
        valS = S[pR]
        if valS % 2:
            valO = 1
        else:
            valO = 0
        if (SS+valS > D) | (SO+valO > O):
            break
        else:
            SS += valS
            SO += valO
            rightmost = pR
    return rightmost, SS, SO


def find_rightmost(SS, SO, pR_, N, O, D, S):
    rightmost = pR_
    for pR in range(pR_+1, N):
        valS = S[pR]
        if valS % 2:
            valO = 1
        else:
            valO = 0
        if (SS+valS > D) | (SO+valO > O):
            break
        else:
            SS += valS
            SO += valO
            rightmost = pR
    return rightmost, SS, SO


def solution(N, O, D, S):
    POSSIBLE_FLAG = False
    sweetness = []
    pR, SS, SO = find_rightmost_all(0, N, O, D, S)
    sweetness.append(SS)
    for pL in range(1, N+1):
        SS -= S[pL-1]
        if S[pL-1] % 2:
            SO -= 1
        if pR == 'IMPOSSIBLE':
            pR, SS, SO = find_rightmost_all(pL, N, O, D, S)
            if pR != 'IMPOSSIBLE':
                POSSIBLE_FLAG = True
        else:
            POSSIBLE_FLAG = True
            pR, SS, SO = find_rightmost(SS, SO, pR, N, O, D, S)
        sweetness.append(SS)
    if POSSIBLE_FLAG:
        answer = max(sweetness)
    else:
        answer = 'IMPOSSIBLE'
    return answer


f = open(outFile, mode='w')

with open(inFile, mode='r') as txtData:

    lines = txtData.readlines()
    p = 0
    t = int(lines[p].strip('\n'))
    p = p+1
    print('t={}'.format(t))

    for case in range(1, t+1):
        N, O, D = lines[p].strip('\n').split(' ')
        N, O, D = int(N), int(O), int(D)
        p = p+1
        X1, X2, A, B, C, M, L = lines[p].strip('\n').split(' ')
        x1, x2, A, B, C, M, L = int(X1), int(X2), int(A), int(B), int(C), int(M), int(L)
        X = [x1, x2]
        S = [x1+L, x2+L]
        for i in range(3-1, N):
            Xi = (A * X[i-1] + B * X[i-2] + C) % M
            X.append(Xi)
            S.append(Xi+L)
        p = p+1
        answer = solution(N, O, D, S)
        print("Case #{}: {}\n".format(case, answer))

        f.write("Case #{}: {}\n".format(case, answer))

f.close()
