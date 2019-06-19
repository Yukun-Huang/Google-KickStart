# -*- coding: utf-8 -*-
import copy
# ------------------------------------------------------------
# Floyd算法：多源的最短路径算法，支持有向图、负权无环图
# 输入邻接矩阵，返回最短路径的邻接矩阵

# Floyd-Warshal Algorithm
def Floyd_Warshal(_adj_mat, _path_mat):
    adj_mat = copy.deepcopy(_adj_mat)
    path_mat = copy.deepcopy(_path_mat)
    for k in range(len(adj_mat)):
        for i in range(len(adj_mat)):
            for j in range(len(adj_mat)):
                if adj_mat[i][j] > adj_mat[i][k] + adj_mat[k][j]:
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j]
                    path_mat[i][j] = path_mat[i][k]
    return adj_mat, path_mat


# Floyd算法：多源的最短路径算法，支持有向图、负权无环图
# 输入路径矩阵、起始点、终点，返回最短路径
def Floyd_Warshal_Path(path_mat, p_from, p_to):
    path = []
    p_mid = path_mat[p_from][p_to]
    path.append(p_from)
    while(p_mid != p_to):
        path.append(p_mid)
        p_mid = path_mat[p_mid][p_to]
    path.append(p_to)
    # path_set = set(path)
    # if len(path) != len(path_set):
    #     raise AssertionError
    return path


# ------------------------------------------------------------
# Dijkstra算法
def Dijkstra(graph, src):
  if graph ==None:
    return None
  # 定点集合
  nodes = [i for i in range(len(graph))] # 获取顶点列表，用邻接矩阵存储图
  # 顶点是否被访问
  visited = []
  visited.append(src)
  # 初始化dis
  dis = {src:0}# 源点到自身的距离为0
  for i in nodes:
    dis[i] = graph[src][i]
  path={src:{src:[]}} # 记录源节点到每个节点的路径
  k=pre=src
  while nodes:
    temp_k = k
    mid_distance=float('inf') # 设置中间距离无穷大
    for v in visited:
      for d in nodes:
        if graph[src][v] != float('inf') and graph[v][d] != float('inf'):# 有边
          new_distance = graph[src][v]+graph[v][d]
          if new_distance <= mid_distance:
            mid_distance=new_distance
            graph[src][d]=new_distance # 进行距离更新
            k=d
            pre=v
    if k!=src and temp_k==k:
      break
    dis[k]=mid_distance # 最短路径
    path[src][k]=[i for i in path[src][pre]]
    path[src][k].append(k)

    visited.append(k)
    nodes.remove(k)
    # print(nodes)
  return dis,path


# ------------------------------------------------------------
# 深度优先遍历判断是否有环,适合无向图
# 输入参数:
#   graph: 邻接矩阵
#   v: 目标顶点
#   visited: 顶点的访问表,长度为顶点数,对图中的所有顶点定义三种状态:
#               0-顶点未被访问过、1-顶点刚开始被访问、2-顶点被访问过并且其所有邻接点也被访问过
#   father: 父节点表,长度为顶点数

def DFS(graph, v, visited, father, has_loop):
    visited[v] = 1
    for i in range(len(graph)):
        if i != v and graph[v][i] != float('inf'):
            if visited[i] == 1 and father[v] != i:
                if len(has_loop) == 0:
                    has_loop.append(v)
            elif visited[i] == 0:
                father[i] = v
                DFS(graph, i, visited, father, has_loop)
    visited[v] = 2

def DFS_find_circle(G):
    num_vertex = len(G)
    visited = [0 for _ in range(num_vertex)]
    father = [-1 for _ in range(num_vertex)]
    has_loop = []
    for i in range(num_vertex):
        if not visited[i]:
            DFS(G, i, visited, father, has_loop)
            if len(has_loop):
                return True
    return False

# ------------------------------------------------------------

if __name__ == '__main__':
    # ------- Floyd Algorithm Demo -------
    adj_mat = [ [0, 4, 5,],
                [1, 0, 4,],
                [3, 1, 0,], ]
    num = len(adj_mat)
    path_mat = [[end_point for end_point in range(num)] for _ in range(num)]
    adj_mat, path_mat = Floyd_Warshal(adj_mat, path_mat)
    path = Floyd_Warshal_Path(path_mat, 2, 0)
    print('Floyd Algorithm, from 2 to 0:')
    print('  Distance: {}'.format(adj_mat[2][0]))
    print('  Path: {}'.format(path))

    print('\n\n')

    # ------- Dijkstra Algorithm Demo -------
    graph_list = [ [0, 4, 5,],
                   [1, 0, 4,],
                   [3, 1, 0,], ]
    num = len(graph_list)
    distance, path_mat = Dijkstra(graph_list, 2)  # 查找从源点0开始到其他节点的最短路径

    print('Dijkstra Algorithm, from 2 to 0:')
    print('  Distance: {}'.format(distance[0]))
    print('  Path: {}'.format(path_mat[2][0]))

    print('\n\n')

    # ------- DFS Find Circle Algorithm Demo -------
    graph_list = [ [0, 1, 1,],
                   [1, 0, 1,],
                   [1, 1, 0,], ]
    has_loop = DFS_find_circle(graph_list)
    print(graph_list)
    print('has_loop: {}\n'.format(has_loop))

    inf = float('inf')
    graph_list = [ [0,   inf,  1,],
                   [inf,   0,  1,],
                   [1,     1,  0,], ]
    has_loop = DFS_find_circle(graph_list)
    print(graph_list)
    print('has_loop: {}\n'.format(has_loop))