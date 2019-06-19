# -*- coding: utf-8 -*-
import sys

DEBUG = True
if DEBUG:
    # fin = open('A-small-practice.in', 'r')
    # fout = open('A-small-practice.out', 'w')
    fin = open('A-large-practice.in', 'r')
    fout = open('A-large-practice.out', 'w')
    sys.stdin = fin
    sys.stdout = fout


class DFS_FIND_LOOP:

    def __init__(self):
        self.stack = []

    def DFS_recursive(self, graph, v, visited, father, loop):
        visited[v] = 1
        for neighbor in graph[v]:
            if visited[neighbor] == 0:
                father[neighbor] = v
                self.DFS(graph, neighbor, visited, father, loop)
            elif visited[neighbor] == 1 and father[v] != neighbor: # father[v] != neighbor是避免两节点环
                # find circle
                temp = v
                loop.append(temp)
                while temp != neighbor:
                    temp = father[temp]
                    loop.append(temp)
        visited[v] = 2

    def DFS_stack(self, graph, v0, visited, father, loop):
        stack = [v0]
        visited[v0] = 1
        while len(stack):
            v = stack[-1]
            for neighbor in graph[v]:
                if visited[neighbor] == 0:
                    father[neighbor] = v
                    visited[neighbor] = 1
                    stack.append(neighbor)
                    break
                elif visited[neighbor] == 1 and father[v] != neighbor: # father[v] != neighbor是避免两节点环
                    # find circle
                    temp = v
                    loop.append(temp)
                    while temp != neighbor:
                        temp = father[temp]
                        loop.append(temp)
            else:
                visited[v] = 2
                stack.pop()

    def find_loop(self, G):
        n = len(G)
        visited = [0] * n
        father = [-1] * n
        loop = []
        self.DFS_stack(G, 0, visited, father, loop)
        return loop


class BFS_CALC_DIST:

    def clac_dist(self, G, loop):
        n = len(G)
        depth = 0
        dist = [0] * n
        visited = [0] * n
        record = {depth: []}
        for v in loop:
            visited[v] = 1
            if len(G[v]) > 2:
                record[depth].append(v)
        while 1:
            depth += 1
            for i in record[depth-1]:
                for j in G[i]:
                    if visited[j] == 1:
                        continue
                    visited[j] = 1
                    dist[j] = depth
                    if depth not in record.keys():
                        record[depth] = [j]
                    else:
                        record[depth].append(j)
            if depth not in record.keys():
                break
        return dist


D = DFS_FIND_LOOP()
B = BFS_CALC_DIST()

t = int(input())
for i in range(1, t + 1):
    N = int(input())
    g = {}
    for _ in range(N):
        v1, v2 = [int(s)-1 for s in input().split(" ")]
        if v1 not in g:
            g[v1] = [v2]
        else:
            g[v1].append(v2)
        if v2 not in g:
            g[v2] = [v1]
        else:
            g[v2].append(v1)
    loop = D.find_loop(g)
    dist = B.clac_dist(g, loop)
    # output
    dist = [str(item) for item in dist]
    dist = ' '.join(dist)
    print("Case #{}: {}".format(i, dist))


