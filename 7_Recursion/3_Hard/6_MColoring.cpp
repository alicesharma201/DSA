#include<bits/stdc++.h>
using namespace std;
bool isSafe(int node, int requiredColor, vector<int>& color, bool graph[101][101], int N){
    for(int k = 0; k < N; k++){
        // k is not the same node + path between our node & kth node exists + adjacent Node's color is same as our node, so we return false
        if(k != node && graph[node][k] == 1 && color[k] == requiredColor) return false;
    } return true;
}
bool solve(int node, vector<int>& color, int m, int N, bool graph[101][101]){
    if(node == N) return true;
    for(int i = 1; i <= m; i++){ // colors
        if(isSafe(node, i, color, graph, N)){
            color[node] = i;
            if(solve(node+1, color, m, N, graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int N){
    vector<int> color(N, 0);
    if(solve(0, color, m, N, graph)) return true;
    return false;
}
int main(){
    int N = 4;  // Number of nodes
    int m = 3;  // Maximum number of colors

    bool graph[101][101];
    memset(graph, false, sizeof graph);

    // Create a sample graph with edges (0,1), (1,2), (2,3), (3,0), (0,2)
    graph[0][1] = 1; graph[1][0] = 1;
    graph[1][2] = 1; graph[2][1] = 1;
    graph[2][3] = 1; graph[3][2] = 1;
    graph[3][0] = 1; graph[0][3] = 1;
    graph[0][2] = 1; graph[2][0] = 1;

    cout << boolalpha << graphColoring(graph, m, N);

    return 0;
}