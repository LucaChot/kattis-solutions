#include <iostream>
using namespace std;

void solve(int nodes){
    bool graph[nodes][nodes];
    bool strong[nodes];
    for(int i = 0; i < nodes; i++){
        strong[i] = false;
        for(int j = 0; j < nodes; j++){
            bool edge;
            cin >> edge;
            graph[i][j] = edge;
        }
    }

    for(int vertex = 0; vertex < nodes; vertex += 1){
        for(int a = vertex + 1; a < nodes; a += 1){
            if(!graph[vertex][a]){
                continue;
            }
            for(int b = vertex + 2; b < nodes; b+=1){
                if(!graph[vertex][b]){
                    continue;
                }
                if(graph[a][b]){
                    strong[vertex] = true;
                    strong[a] = true;
                    strong[b] = true;
                }
            }
        }
        if(!strong[vertex]){
            cout << vertex << ' ';
        }
    }
}

int main(){
    int nodes;
    cin >> nodes;
    while(nodes != -1){
        solve(nodes);
        cout << '\n';
        cin >> nodes;
    }
    
    return 0;
}