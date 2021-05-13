#include<iostream>
#include<vector>
using namespace std;
enum Color{white,grey,black};
struct node{
	int parent;
	Color color;
	int discoveredt;
	int finishedt;
	int vertexcolor;
};
int visit_time=0;
bool dfs_visit(vector<node> &vertices,vector<vector<int>> &adj,int s)
{
	vertices[s].discoveredt=++visit_time;
	vertices[s].color=grey;
	for(int x:adj[s])
	{
		if(vertices[x].color==white)
		{
			vertices[x].parent=s;
			vertices[x].vertexcolor=1-vertices[s].vertexcolor;
			if(!dfs_visit(vertices,adj,x)){
			return false;
			}
		}
		else
		{
			if(vertices[x].vertexcolor==vertices[s].vertexcolor)
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	vector<node> vertices(n);
	for(int i=0;i<n;i++)
	{
		vertices[i].color=white;
		vertices[i].parent=-1;
		vertices[i].vertexcolor=-1;
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
	bool bipartite=true;
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			vertices[i].vertexcolor=0;
			bipartite=bipartite&&dfs_visit(vertices,adj,i);
			if(!bipartite)
			{
				break;
			}
		}
	
	}
	if(bipartite)
	{
		cout<<"yes bipartite"<<endl;
	}
	else 
	{
		cout<<"No not bipartite"<<endl;
	}
}
