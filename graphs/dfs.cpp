#include<bits/stdc++.h>
using namespace std;

enum Color{white,gray,black};

struct node{
	int parent;
	int arrival;
	int departure;
	Color color;
};
int tim=0;
void dfs_visit(vector<node> &vertices,vector<vector<int>> &adj,int s)
{
	cout<<s<<endl;
	tim++;
	vertices[s].arrival=tim;
	for(auto x:adj[s])
	{
		if(vertices[x].color==white)
		{
			vertices[x].parent=s;
			vertices[x].color=gray;
			dfs_visit(vertices,adj,x);
			
		}
	}
	vertices[s].color=black;
	vertices[s].departure=++tim;
	

}

int main()
{
	int n;
	cin>>n;
	vector<node> vertices(n);
	for(auto &x:vertices)
	{
		x.parent=-1;
		x.arrival=0;
		x.departure=0;
		x.color=white;
		
	}
	vector<vector<int>> adj(n,vector<int>());
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		
	}
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			vertices[i].color=gray;
			dfs_visit(vertices,adj,i);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<"  "<<vertices[i].parent<<"  "<<vertices[i].arrival<<" "<<vertices[i].departure<<endl;
		
	}
}
