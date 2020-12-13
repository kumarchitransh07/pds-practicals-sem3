#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node {
    int m_key = -1, m_status=0;
    node() {}
    node(int key): m_key(key) {}
};

class Graph {
    int m_adjMatrix[10][10]{0};
    node vertices[10];
    
public:
    
    void addEdge(int v, int w) {
        m_adjMatrix[v][w] = 1;
        m_adjMatrix[w][v] = 1;
        
        if(vertices[v].m_key == -1) {
            vertices[v].m_key = v;
        }
        if(vertices[w].m_key == -1) {
            vertices[w].m_key = w;
        }
    }
    
    void DFS() {
        stack<int> dfsStack;
        dfsStack.push(0);
        vertices[0].m_status = 1;
        bool didBreak = false;
        while (!dfsStack.empty()) {
            for (int i=dfsStack.top(), j=0; j < 10; j++) {
                if(m_adjMatrix[i][j] == 1) {
                    if(vertices[j].m_status == 0) {
                        dfsStack.push(j);
                        vertices[j].m_status = 1;
                        didBreak = true;
                        break;
                    }
                    
                }
            }
            if(!didBreak) {
                cout << dfsStack.top() << " ";
                dfsStack.pop();
            }
            didBreak = false;
        }
        cout << endl;
        for (int i = 0; i < 10; i++) {
            vertices[i].m_status = 0;
        }
    }
    
    void BFS() {
        queue<int> bfsQueue;
        bfsQueue.push(0);
        vertices[0].m_status = 1;
        while(!bfsQueue.empty()) {
            for (int i = bfsQueue.front(), j=0; j < 10; j++) {
                if(m_adjMatrix[i][j] == 1) {
                    if(vertices[j].m_status == 0) {
                        bfsQueue.push(j);
                        vertices[j].m_status = 1;
                    }
                }
            }
            cout << bfsQueue.front() << " ";
            bfsQueue.pop();
        }
        cout << endl;
        for (int i = 0; i < 10; i++) {
            vertices[i].m_status = 0;
        }
    }
};

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    
    cout << "DFS: ";
    graph.DFS();
    cout << "BFS: ";
    graph.BFS();
}
