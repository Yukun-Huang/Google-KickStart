#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>
#include <functional>	// greater, less
#include <limits>

#define FOR(i,n) for (int i = 1 ; i <= n ; ++i)
#define RFOR(i,n) for (int i = n ; i >= 1 ; --i)
#define REP(i,n) for (int i = 0 ; i < n ; ++i)

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)
#define MOD 1000000007

using namespace std;

typedef unsigned long long uLL;
typedef long long LL;
typedef unsigned int uINT;

int T, N, M;
vector<vector<int> > G;

const int maxn = 105;

void load_data() {
	cin >> N >> M;
	G = vector<vector<int> >(N, vector<int>(N, 2));
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		G[a-1][b-1] = 1;
		G[b-1][a-1] = 1;
	}
}

// A utility function to find the vertex with  
// minimum key value, from the set of vertices  
// not yet included in MST  
int minKey(const vector<int>& key, const vector<bool>& mstSet)
{
	int V = key.size();
	// Initialize min value  
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


// A utility function to print the  
// constructed MST stored in parent[]  
void printMST(const vector<int>& parent, const vector<vector<int> >& graph)
{
	int V = graph.size();
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}


// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
int primMST(const vector<vector<int> >& graph)
{
	// num of vertices
	int V = graph.size();
	
	// Array to store constructed MST  
	vector<int> parent(V);

	// Key values used to pick minimum weight edge in cut  
	vector<int> key(V);

	// To represent set of vertices not yet included in MST  
	vector<bool> mstSet(V);

	// Initialize all keys as INFINITE  
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.  
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST  

					// The MST will have V vertices  
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the  
		// set of vertices not yet included in MST  
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set  
		mstSet[u] = true;

		// Update key value and parent index of  
		// the adjacent vertices of the picked vertex.  
		// Consider only those vertices which are not  
		// yet included in MST  
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m  
			// mstSet[v] is false for vertices not yet included in MST  
			// Update the key only if graph[u][v] is smaller than key[v]  
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// minimum weight
	int minWeight = 0;
	for (int k : key)
		minWeight += k;

	// print the constructed MST  
	//printMST(parent, graph);

	return minWeight;
}

int solution() {
	return primMST(G);
}

int main() {
	// redirection
	if (1) {
		freopen("xxx.in", "r", stdin);
		freopen("xxx.out", "w", stdout);
	}
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		/* --------------------- */
		load_data();
		cout << solution();
		/* --------------------- */
		cout << endl;
	}
}