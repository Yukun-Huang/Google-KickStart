// 并查集
// 主要的两个优化方法是路径压缩和按秩合并，优化后可以实现常数时间（阿克曼函数）的查找和合并复杂度。

// Union-Find Set, c++ style
class UF{
private:
    int count;
    int* id;
    int* sz;
public:
    UF(int n){
        count=n;
        id=new int[n];
        sz=new int[n];
        for(int i=0;i<n;i++)id[i]=i;
        for(int i=0;i<n;i++)sz[i]=1;
    }
    ~UF(){
        delete []id;
    }
    int size(){
        return count;
    }
    bool isConnect(int a,int b){
        return find(a)==find(b);
    }
    int find(int a){
        if(id[a] != a)
            id[a] = find(id[a]);
        return id[a];
    }
    void Union(int a,int b){
        int af=find(a),bf=find(b);
        if(af==bf)return;
        if(sz[af]<sz[bf]){
            id[af]=bf;sz[bf]+=sz[af];
        }else {
            id[bf]=af;sz[af]+=sz[bf];
        }
        count--;
    }
};

// Union-Find Set, STL style
class UF {
public:
    UF(int n) {
        count = n;
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int i) { // path compression
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void Union(int x, int y) { // union with rank
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
            else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
            else {
                parent[rooty] = rootx; rank[rootx] += 1;
            }
            --count;
        }
    }

    int size() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count; // # of connected components
};
