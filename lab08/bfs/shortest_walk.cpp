#include "graph.cpp"
//#include<stack>


void shortest_walk(Graph g,vector<int>&stations, vector<int>& path)
{
    
    /*for(int i = 0; i < stations.size()-1; i++){
        int st = stations[i];
        int end = stations[i+1];
        unordered_map<int,int> parent;
        bfs(g,st,parent);
        stack<int> segment;
        while(end!=st){
            //path.insert(path.begin(),end);
            segment.push(end);
            end = parent[end];
        }
        if(path.empty()) path.push_back(st);
        while(!segment.empty()){
            path.push_back(segment.top());
            segment.pop();
        }
    }*/
   for(int i = stations.size()-1; i > 0; i--){
        int st = stations[i-1];
        int end = stations[i];
        unordered_map<int,int> parent;
        bfs(g,st,parent);
        //stack<int> segment;
        while(end!=st){
            path.insert(path.begin(),end);
            //segment.push(end);
            end = parent[end];
        }
   }
    path.insert(path.begin(),stations[0]);
}
