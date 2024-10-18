#include "graph.h"


// Implement this function to check if there is a cycle present in the graph
bool Graph::isCyclePresent(){
    int n = nodes.size();

    if(n == 0) return false;
    
    std::map<int, int> parent;
    std::map<int , bool> visited;

    for(auto i = nodes.begin(); i != nodes.end(); i++){
        parent[i->second->label] = -1;
        visited[i->second->label] = false;
    }

    for(auto i = nodes.begin(); i != nodes.end(); i++){
        if(!visited[i->second->label]){
            std::queue<int> q;
            visited[i->second->label] = true;
            q.push(i->second->label);
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(unsigned long j = 0; j < nodes[v]->adj.size(); j++){
                    int neighbour = nodes[v]->adj[j];
                    if(!visited[neighbour]){
                        visited[neighbour] = true;
                        q.push(neighbour);
                        parent[neighbour] = v;
                    }
                    else if(parent[v] != neighbour) return true;
                    
                }
            }
        }
    }

    // dummy return
    return false;
}