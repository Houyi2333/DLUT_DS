#include <cassert>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#define AFFINITY 999999
using namespace std;

template <class T>
class Edge {
   public:
    int start;
    int end;
    T weight;
    Edge() {}
    Edge(int start, int end, T weight)
        : start(start), end(end), weight(weight) {}
    bool operator==(const Edge<T>& other) const {
        return (start == other.start && end == other.end &&
                weight == other.weight);
    }
    bool operator!=(const Edge<T>& other) const { return !(*this == other); }
    bool operator<(const Edge<T>& other) const {
        return (this->weight < other.weight);
    }
    bool operator>(const Edge<T>& other) const {
        return (this->weight > other.weight);
    }
    static Edge Empty() { return Edge(-1, -1, 0); }
};

enum VisitFlag { UNVISITED, VISITED };
enum EdgeType { DIRECTED, UNDIRECTED };

template <class T>
class Graph {
   public:
    int vertexNum;
    int edgeNum;
    VisitFlag* marks;
    EdgeType edgeType;

   public:
    static T MAX_VALUE;
    Graph(int vertexNum, EdgeType edgeType = DIRECTED) {
        this->vertexNum = vertexNum;
        this->edgeNum = 0;
        this->edgeType = edgeType;
        this->marks = new VisitFlag[vertexNum];
        for (int i = 0; i < vertexNum; i++) {
            marks[i] = UNVISITED;
        }
    }
    ~Graph() { delete[] marks; }
    virtual Edge<T> FirstEdge(int oneVertex) = 0;
    virtual Edge<T> NextEdge(Edge<T> oneEdge) = 0;
    int Vertexcount() { return vertexNum; }
    int Edgecount() { return edgeNum; }
    bool IsEdge(Edge<T> oneEdge) { return (oneEdge != Edge<T>::Empty()); }
    int StartVertex(Edge<T> oneEdge) { return oneEdge.start; }
    int EndVertex(Edge<T> oneEdge) { return oneEdge.end; }
    T Weight(Edge<T> oneEdge) { return oneEdge.weight; }
    virtual void SetEdge(int start, int end, T weight) = 0;
    virtual void DeleteEdge(int start, int end) = 0;
};

template <class T>
class AdjGraph : public Graph<T> {
   private:
    T** matix;

   public:
    AdjGraph(int vertexNum, EdgeType edgeType = DIRECTED)
        : Graph<T>::Graph(vertexNum, edgeType) {
        this->matix = (T**)new T*[vertexNum];
        for (int i = 0; i < vertexNum; i++) {
            matix[i] = new T[vertexNum];
        }
        for (int i = 0; i < vertexNum; i++) {
            for (int j = 0; j < vertexNum; j++) {
                matix[i][j] = 0;
            }
        }
    }
    ~AdjGraph() {
        for (int i = 0; i < this->Vertexcount(); i++) {
            delete[] matix[i];
        }
        delete[] matix;
    }
    Edge<T> FirstEdge(int oneVertex) {
        for (int i = 0; i < this->Vertexcount(); i++) {
            if (matix[oneVertex][i] != 0) {
                return Edge<T>(oneVertex, i, matix[oneVertex][i]);
            }
        }
        return Edge<T>::Empty();
    }
    Edge<T> NextEdge(Edge<T> oneEdge) {
        for (int i = oneEdge.end + 1; i < this->Vertexcount(); i++) {
            if (matix[oneEdge.start][i] != 0) {
                return Edge<T>(oneEdge.start, i, matix[oneEdge.start][i]);
            }
        }
        return Edge<T>::Empty();
    }
    void SetEdge(int start, int end, T weight) {
        if (start < 0 || start >= this->Vertexcount() || end < 0 ||
            end >= this->Vertexcount()) {
            return;
        }
        if (matix[start][end] == 0) {
            this->edgeNum++;
        }
        matix[start][end] = weight;
        if (this->edgeType == UNDIRECTED) {
            matix[end][start] = weight;
        }
    }
    void DeleteEdge(int start, int end) {
        if (start < 0 || start >= this->Vertexcount() || end < 0 ||
            end >= this->Vertexcount()) {
            return;
        }
        if (matix[start][end] != 0) {
            this->edgeNum--;
        }
        matix[start][end] = 0;
        if (this->edgeType == UNDIRECTED) {
            matix[end][start] = 0;
        }
    }
    void visit(int v) { cout << v << " "; }
    //从某顶点开始
    void DFS(int v) {
        visit(v);
        this->marks[v] = VISITED;
        for (Edge<T> e = FirstEdge(v); this->IsEdge(e); e = NextEdge(e)) {
            if (this->marks[this->EndVertex(e)] == UNVISITED)
                DFS(this->EndVertex(e));
        }
    }
    void DFStraverse() {
        int i;
        for (i = 0; i < this->Vertexcount(); i++)
            this->marks[i] = UNVISITED;
        for (i = 0; i < this->Vertexcount(); i++) {
            if (this->marks[i] == UNVISITED)
                DFS(i);
        }
    }
    void DFSnoraverse() {
        stack<int> mystack;
        for (int i = 0; i < this->Vertexcount(); i++) {
            this->marks[i] = UNVISITED;
        }
        for (int i = 0; i < this->Vertexcount(); i++) {
            if (this->marks[i] == UNVISITED) {
                mystack.push(i);
                while (!mystack.empty()) {
                    int v = mystack.top();
                    if (this->marks[v] == UNVISITED)
                        visit(v);
                    this->marks[v] = VISITED;
                    mystack.pop();
                    for (Edge<T> e = FirstEdge(v); this->IsEdge(e);
                         e = NextEdge(e)) {
                        if (this->marks[e.end] == UNVISITED)
                            mystack.push(e.end);
                    }
                }
            }
        }
    }
    void BFS(int v) {
        queue<int> myqueue;
        myqueue.push(v);
        while (!myqueue.empty()) {
            int v = myqueue.front();
            if (this->marks[v] == UNVISITED)
                visit(v);
            myqueue.pop();
            this->marks[v] = VISITED;
            for (Edge<T> e = FirstEdge(v); this->IsEdge(e); e = NextEdge(e)) {
                if (this->marks[e.end] == UNVISITED)
                    myqueue.push(e.end);
            }
        }
    }
    void BFSraverse() {
        for (int i = 0; i < this->Vertexcount(); i++) {
            this->marks[i] = UNVISITED;
        }
        for (int i = 0; i < this->Vertexcount(); i++) {
            if (this->marks[i] == UNVISITED)
                BFS(i);
        }
    }
};
template <class T>
//应用Prim算法从s顶点出发得到的最小生成树
Edge<T>* Prim(Graph<T>& G, int s) {
    int i, j;
    //存储最小生成树的边
    Edge<T>* MST;
    //各个顶点到生成树中的各个顶点的最短的边
    // nearest[i]表示生成树中点到i点的最小边权值
    T* nearest;
    // neighbor[i]表示生成树中与i点最近的点编号，-1表示i点已经在生成树集合中
    int* neighbor;
    //图的顶点个数
    int n = G.Vertexcount();
    nearest = new T[n];
    neighbor = new int[n];
    MST = new Edge<T>[n - 1];
    for (i = 0; i < n; i++)  //初始化neighor数组和nearest数组
    {
        neighbor[i] = s;
        nearest[i] = AFFINITY;
    }
    //与s相邻接的顶点的边权值 作为这些点 距离生成树集合的最短边长
    for (Edge<T> e = G.FirstEdge(s); G.IsEdge(e); e = G.NextEdge(e)) {
        nearest[e.end] = e.weight;
    }
    //将已加入到生成树的点的最近邻设置为-1
    neighbor[s] = -1;
    // i标记已经加入到生成树中的点个数
    for (i = 1; i < n; i++) {
        //记录最小权值
        T min = AFFINITY;
        //记录下一个将要加入到集合中的点
        int v = -1;
        //确定一个顶点在生成树集合，一个顶点不在生成树集合且权值最小的
        for (j = 0; j < n; j++) {
            //边所关联的顶点
            if (nearest[j] < min && neighbor[j] > -1) {
                min = nearest[j];
                v = j;
            }
        }
        //将v加入到生成树集合中,更新到生成树外的各个点最小权值的边信息
        if (v >= 0) {
            Edge<T> tempEdge(neighbor[v], v, nearest[v]);
            //将边加入到生成树集合中
            MST[i - 1] = tempEdge;
            neighbor[v] = -1;
            for (Edge<T> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
                int u = e.end;
                //用与v关联的边更新生成树之外顶点到生成树集合的最小权值边
                if (neighbor[u] != -1 && nearest[u] > e.weight) {
                    neighbor[u] = v;
                    nearest[u] = e.weight;
                }
            }
        }
    }
    //释放空间
    delete[] neighbor;
    delete[] nearest;
    return MST;
}
int main() {
    AdjGraph<int> graph(5, UNDIRECTED);
    graph.SetEdge(0, 1, 10);
    graph.SetEdge(1, 2, 50);
    graph.SetEdge(2, 4, 10);
    graph.SetEdge(3, 2, 20);
    graph.SetEdge(3, 4, 60);
    graph.SetEdge(0, 4, 100);
    graph.SetEdge(0, 3, 30);
    Edge<int>* edge;
    int n = graph.Vertexcount() - 1;
    // Prim算法
    edge = Prim(graph, 0);
    cout << "Prim算法:" << endl;
    for (int i = 0; i < n; i++) {
        cout << edge[i].start << " - " << edge[i].end << " : " << edge[i].weight
             << endl;
    }
}