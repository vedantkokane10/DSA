#include<bits/stdc++.h>
using namespace std;

void matrix(){
	// undirected and non-weighted
	// matrix methdod
	int n,m;
	// n -> no of vertices
	// m -> no of edges
	// assume that n starts with 1 rather than 0 
	cin>>n>>m;
	vector<vector<int>> g(n+1,vector<int>(n+1,0));
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	// space -> O(n*m)
}


// Undirected graph
void adjListU(vector<int> &g[],int n,int m){
	// n -> no of vertices
	// m -> no of edges
	// assume that n starts with 1 rather than 0 
	// g -> Adjancey List
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		// there is a edge between u and v as well as there is a edge between v and u
	}
	// Space - O(2E)
}


// directed graph
void adjListD(vector<int> &g[],int n,int m){
	// n -> no of vertices
	// m -> no of edges
	// assume that n starts with 1 rather than 0 
	// g -> Adjancey List
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		// there is a edge between u and v only and not between v and u
	}
	// Space - O(E)
}

int main(){
	int n,m;
	// n -> no of vertices
	// m -> no of edges
	cin>>n>>m;
	vector<int> g[n+1];
	adjListU(g,n,m);
	for(int i=1;i<n+1;i++){
		cout<<i<< " - ";
		for(auto x : g[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*
5 6
2 1
1 3
2 4
3 4
2 5
4 5
*/
