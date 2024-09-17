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
    //��ĳ���㿪ʼ
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
//Ӧ��Prim�㷨��s��������õ�����С������
Edge<T>* Prim(Graph<T>& G, int s) {
    int i, j;
    //�洢��С�������ı�
    Edge<T>* MST;
    //�������㵽�������еĸ����������̵ı�
    // nearest[i]��ʾ�������е㵽i�����С��Ȩֵ
    T* nearest;
    // neighbor[i]��ʾ����������i������ĵ��ţ�-1��ʾi���Ѿ���������������
    int* neighbor;
    //ͼ�Ķ������
    int n = G.Vertexcount();
    nearest = new T[n];
    neighbor = new int[n];
    MST = new Edge<T>[n - 1];
    for (i = 0; i < n; i++)  //��ʼ��neighor�����nearest����
    {
        neighbor[i] = s;
        nearest[i] = AFFINITY;
    }
    //��s���ڽӵĶ���ı�Ȩֵ ��Ϊ��Щ�� �������������ϵ���̱߳�
    for (Edge<T> e = G.FirstEdge(s); G.IsEdge(e); e = G.NextEdge(e)) {
        nearest[e.end] = e.weight;
    }
    //���Ѽ��뵽�������ĵ�����������Ϊ-1
    neighbor[s] = -1;
    // i����Ѿ����뵽�������еĵ����
    for (i = 1; i < n; i++) {
        //��¼��СȨֵ
        T min = AFFINITY;
        //��¼��һ����Ҫ���뵽�����еĵ�
        int v = -1;
        //ȷ��һ�����������������ϣ�һ�����㲻��������������Ȩֵ��С��
        for (j = 0; j < n; j++) {
            //���������Ķ���
            if (nearest[j] < min && neighbor[j] > -1) {
                min = nearest[j];
                v = j;
            }
        }
        //��v���뵽������������,���µ���������ĸ�������СȨֵ�ı���Ϣ
        if (v >= 0) {
            Edge<T> tempEdge(neighbor[v], v, nearest[v]);
            //���߼��뵽������������
            MST[i - 1] = tempEdge;
            neighbor[v] = -1;
            for (Edge<T> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
                int u = e.end;
                //����v�����ı߸���������֮�ⶥ�㵽���������ϵ���СȨֵ��
                if (neighbor[u] != -1 && nearest[u] > e.weight) {
                    neighbor[u] = v;
                    nearest[u] = e.weight;
                }
            }
        }
    }
    //�ͷſռ�
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
    // Prim�㷨
    edge = Prim(graph, 0);
    cout << "Prim�㷨:" << endl;
    for (int i = 0; i < n; i++) {
        cout << edge[i].start << " - " << edge[i].end << " : " << edge[i].weight
             << endl;
    }
}