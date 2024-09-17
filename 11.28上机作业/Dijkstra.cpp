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
    void print() {
        cout << start << "->" << end << " weight=" << weight << endl;
    }
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

class Dist {
   public:
    int length;  //与源s的距离
    int pre;     //前面的顶点
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
    // Dijkstra
    void Dijkstra(int s, list<Edge<T>>& dij) {
        T distances[this->Vertexcount()];
        int path[this->Vertexcount()];
        for (int i = 0; i < this->Vertexcount(); i++) {
            this->marks[i] = UNVISITED;
            distances[i] = this->MAX_VALUE;
            path[i] = s;
        }
        distances[s] = 0;
        for (int j = 0; j < this->Vertexcount(); j++) {
            T minDistance = this->MAX_VALUE;
            int minVertex = -1;
            for (int i = 0; i < this->Vertexcount(); i++) {
                if (this->marks[i] == UNVISITED && minDistance > distances[i]) {
                    minDistance = distances[i];
                    minVertex = i;
                }
            }
            if (minVertex >= 0) {
                dij.push_back(Edge<T>(path[minVertex], minVertex, minDistance));
                this->marks[minVertex] = VISITED;
                for (Edge<T> e = FirstEdge(minVertex); this->IsEdge(e);
                     e = NextEdge(e)) {
                    if (this->marks[e.end] == UNVISITED &&
                        distances[e.end] > (distances[minVertex] + e.weight)) {
                        distances[e.end] = distances[minVertex] + e.weight;
                        path[e.end] = minVertex;
                    }
                }
            }
        }
    }
};

template <class T>
T Graph<T>::MAX_VALUE = 2147483647;

int main() {
    AdjGraph<int> graph(5, DIRECTED);
    graph.SetEdge(0, 1, 10);
    graph.SetEdge(1, 2, 50);
    graph.SetEdge(2, 4, 10);
    graph.SetEdge(3, 2, 20);
    graph.SetEdge(3, 4, 60);
    graph.SetEdge(0, 4, 100);
    graph.SetEdge(0, 3, 30);
    list<Edge<int>> edgelist;
    int a = 0;
    graph.Dijkstra(a, edgelist);
    for (int i = 0; i < 5; i++) {
        Edge<int> e = edgelist.front();
        cout << a << "->" << e.end << " weight=" << e.weight << endl;
        edgelist.pop_front();
    }
}