#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 定义边的类
class Edge {
   public:
    int start, end, weight;

    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}

    // 用于排序的比较函数
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

// 定义并查集类
class UnionFind {
   public:
    vector<int> parent, rank;

    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    // 查找根节点
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// 定义图的类
class Graph {
   public:
    int V, E;            // 节点数和边数
    vector<Edge> edges;  // 存储边的数组

    Graph(int v, int e) : V(v), E(e) {}

    // 添加边
    void addEdge(int start, int end, int weight) {
        edges.push_back(Edge(start, end, weight));
    }

    // 执行Kruskal算法
    void kruskal() {
        sort(edges.begin(), edges.end());  // 按权重升序排序

        UnionFind uf(V);  // 初始化并查集

        cout << "Kruskal算法:\n";

        for (const Edge& edge : edges) {
            int rootStart = uf.find(edge.start);
            int rootEnd = uf.find(edge.end);

            if (rootStart != rootEnd) {
                cout << edge.start << " - " << edge.end << " : " << edge.weight
                     << "\n";
                uf.unite(rootStart, rootEnd);
            }
        }
    }
};

int main() {
    Graph graph(5, 7);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 50);
    graph.addEdge(2, 4, 10);
    graph.addEdge(3, 2, 20);
    graph.addEdge(3, 4, 60);
    graph.addEdge(0, 4, 100);
    graph.addEdge(0, 3, 30);
    graph.kruskal();
    return 0;
}
