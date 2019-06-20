# -*- coding: utf-8 -*-
import sys

DEBUG = True
if DEBUG:
    fin = open('C-small-practice.in', 'r')
    fout = open('C-small-practice.out', 'w')
    # fin = open('C-large-practice.in', 'r')
    # fout = open('C-large-practice.out', 'w')

    sys.stdin = fin
    sys.stdout = fout


# O(N)
def calc_A(N, x1, y1, C, D, E1, E2, F):
    A = [(x1+y1)%F]
    for idx in range(2, N+1):
        xi = (C*x1 + D*y1 + E1) % F
        yi = (D*x1 + C*y1 + E2) % F
        A.append((xi+yi)%F)
        x1 = xi
        y1 = yi
    return A


# O(logK * N^2)
def solution(N, K, A):
    answer = 0
    for n in range(1, N+1):
        for nn in range(1, n+1):
            if nn == 1:
                answer += (N-n+1) * A[n-1] * K
            else:
                answer += (N-n+1) * A[n-1] * nn * (nn**K-1) // (nn-1)
    return answer % 1000000007


# O(logK * N), 内存超出
def solution_fast(N, K, A):
    answer = 0
    geo_seq = K
    buff = [K]
    for nn in range(2, N+1):
        geo_seq += nn * (nn**K-1) // (nn-1)
        buff.append(geo_seq)
    for n in range(1, N+1):
            answer += (N-n+1) * A[n-1] * buff[n-1]
    return answer % 1000000007


# 注意python的内置函数pow也有这个功能，但是要传入第三个参数才行。而math.pow是没有快速幂功能的。
def quick_pow(b, e, m):
    result = 1
    while e != 0:
        if (e&1) == 1:
            # ei = 1, then mul
            result = (result * b) % m
        e >>= 1
        # b, b^2, b^4, b^8, ... , b^(2^n)
        b = (b*b) % m
    return result


# O(logK * N)
def solution_better(N, K, A):
    answer = 0
    mod = 1000000007
    GP_sum = K
    for n in range(1, N + 1):
        answer += (N-n+1)*A[n-1] * GP_sum
        answer = answer % mod
        nn = n+1
        GP_sum += nn*(nn**K-1)//(nn-1)
        GP_sum = GP_sum % mod
    return answer


def solution_final(N, K, A):
    result = 0
    GP_sum = K # Handling p = 1 case separately.
    mod = 1000000007
    for x in range(1, N+1):
        if x != 1:
            GP_sum = GP_sum + x * (pow(x, K, mod)-1) * pow(x-1, mod-2, mod) # Multipyting by inverse modulo of x-1.
            GP_sum %= mod
        result = result + GP_sum * A[x-1] * (N-x+1)
        result %= mod
    return result


t = int(input())
for i in range(1, t + 1):
    N, K, x1, y1, C, D, E1, E2, F = [int(s) for s in input().split(" ")]
    A = calc_A(N, x1, y1, C, D, E1, E2, F)
    answer = solution_final(N, K, A)
    # answer = solution(N, K, A)
    # answer = solution_fast(N, K, A)
    # answer = solution_better(N, K, A)
    print("Case #{}: {}".format(i, answer))


