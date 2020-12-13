#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int source, destination, weight;
    edge(int s, int d, int w): source(s), destination(d), weight(w){};
};

int main() {
    
    int graph[5][5] = { {1000,3,10,5,1000},
                        {3,1000,1000,1000,2},
                        {10,1000,1000,1000,4},
                        {5,1000,1000,1000,6},
                        {1000,2,4,6,1000}
    };
    queue<edge> edges;
    int min = NULL;
    int minI, minJ;
    
    while (edges.size() < 4) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if(min == NULL) {
                    min = graph[i][j];
                    minI = i;
                    minJ = j;
                }else{
                    if(graph[i][j] < min) {
                        min = graph[i][j];
                        minI = i;
                        minJ = j;
                    }
                }
            }
        }
        
        edges.push(edge(minI, minJ, min));
        graph[minI][minJ] = 1000;
        graph[minJ][minI] = 1000;
        min = 1000;
    }
    
    for (int i = 0; i < 4; i++) {
        cout << "Source: " << edges.front().source << endl;
        cout << "Destination: " << edges.front().destination << endl;
        cout << "Weight: " << edges.front().weight << endl;
        cout << endl;
        edges.pop();
    }
    return 0;
}
