#include <bits/stdc++.h>

using namespace std;

// The main function that returns
// the minimum cost to connect n
// ropes of lengths stored in len[0..n-1]
int minCost(int len[], int n)
{
	int cost = 0; // Initialize result
	std::priority_queue<int,vector<int>,std::greater<int>> pq;
	for(int i = 0; i < n ; i++){
		pq.push(len[i]);
	}
	if(n == 1) return len[0];
	else{
		int p1 = pq.top();
		pq.pop();
		int p2 = pq.top();
		pq.pop();
		cost = p1+p2;
		while(!pq.empty()){
			pq.push(p1+p2);
			p1 = pq.top();
			pq.pop();
			p2 = pq.top();
			pq.pop();
			cost = cost + p1 + p2;
		}
		return cost;
	}


        // Write your code here

	
}


