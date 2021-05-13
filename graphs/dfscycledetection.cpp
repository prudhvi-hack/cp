#include<bits/stdc++.h>
using namespace std;
enum Color{white,grey,black};
struct node{
	Color color;
	int parent;
	int discoveredt;
	int finisht;
};

int visit_time=0;
bool dfs_visit(vector<node> &vertices,vector<vector<int>>& adj,int s)
{
	bool cycle=false;
	vertices[s].color=grey;
	vertices[s].discoveredt=++visit_time;
	for(int x:adj[s])
	{
		if(vertices[x].color==white)
		{
			vertices[x].parent=s;
			cycle=cycle||dfs_visit(vertices,adj,x);
			if(cycle)
				return true;
		}
		else {
			if(x!=vertices[s].parent)
			{
				cycle=true;
				return true;
			}
		}
			
	}
	vertices[s].color=black;
	vertices[s].finisht=++visit_time;
	return cycle;
}
int main()
{
	int n;
	cin>>n;
	vector<node> vertices(n);
	vector<vector<int>> adj(n,vector<int>());
	for(int i=0;i<n;i++)
	{
		vertices[i].color=white;
		vertices[i].parent=-1;
	}
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	bool cycle=false;
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			cycle = cycle||dfs_visit(vertices,adj,i);
			if(cycle)
			{
				cout<<"cycle detected";
				break;
			}
		}
	}
	if(cycle==false)
	{
	cout<<"cycle not detected";
	}

		

}
