import sys
import os
import random

T = 100
random.seed(1)

fwrite = open('test_large.in', 'w')
fwrite.write('{}\n'.format(T))

char_list = [chr(i) for i in range(ord("A"), ord("Z")+1)]


# ---------------- YOU SHOULD EDIT HERE ---------------- #
def write_case():
    R, C, W = 100, 100, 26
    fwrite.write('{} {} {}\n'.format(R, C, W))
    for _ in range(R):
        for _ in range(C):
            fwrite.write('{}'.format(random.choice(char_list)))
        fwrite.write('\n')
    for i in range(W):
        fwrite.write('{}\n'.format(char_list[i]))
# ------------------------------------------------------ #


if __name__ == '__main__':
    for t in range(1, T+1):
        write_case()
    fwrite.close()