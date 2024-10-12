#include<unordered_map>
#include<vector>
#include<iostream>
#include<utility>
#include<queue>
#include<unordered_set>
using namespace std;

// Implement a node struct if you feel 


// Implement the graph class
class Graph
{
public:
    vector<vector<int>> A;

    Graph(int no_of_vertices, vector<pair<int,int> > edges){
        A.resize(no_of_vertices);
        for(int i = 0; i< edges.size(); i++){
            A[std::get<0>(edges[i])].push_back(std::get<1>(edges[i]));
            A[std::get<1>(edges[i])].push_back(std::get<0>(edges[i]));
        }
    };
};


void bfs(Graph g, int source,unordered_map<int, int>& parent)
{
    std::queue<int> q;
    unordered_set<int> visited;
    visited.insert(source);
    q.push(source);
    parent.insert({source,-1});
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0; i < g.A[v].size(); i++){
            
            if(visited.find(g.A[v][i])== visited.end()){
                visited.insert(g.A[v][i]);
                q.push(g.A[v][i]);
                parent.insert({g.A[v][i],v});
            }
        }
    }
    return;
};

