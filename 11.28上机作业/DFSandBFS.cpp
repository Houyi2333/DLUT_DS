#include <iostream>
#include <list>
#include <queue>
#include <stack>
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
int main() {
    AdjGraph<int> graph(5, DIRECTED);
    graph.SetEdge(0, 1, 20);
    graph.SetEdge(0, 2, 30);
    graph.SetEdge(1, 3, 10);
    graph.SetEdge(1, 4, 5);
    graph.SetEdge(3, 4, 20);
    graph.SetEdge(4, 2, 10);
    //深度优先遍历
    graph.DFStraverse();
    cout << endl;
    //广度优先遍历
    graph.BFSraverse();
    cout << endl;
}