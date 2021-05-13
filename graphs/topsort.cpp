#include<bits/stdc++.h>
using namespace std;
enum Color{white,gray,black};

struct node{
	Color color;
	int parent;
	int discover;
	int completed;

};
int local_time=0;
void dfs_visit(vector<node> &vertices,vector<vector<int>> &adj,int s)
{
	cout<<s<<endl;
	vertices[s].discover=++local_time;
	vertices[s].color=gray;
	for(int x: adj[s])
	{
		
		if(vertices[x].color==white)
		{
			vertices[x].parent=s;
			vertices[x].color=gray;
			dfs_visit(vertices,adj,x);
		}
	}
	vertices[s].completed=++local_time;
	vertices[s].color=black;
		
}
int main(){
	int n;
	cin>>n;
	vector<node> vertices(n);
	vector<vector<int>> adj(n,vector<int>());
	int e;
	cin>>e;
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	
	/*for(int i=0;i<n;i++)
	{
		cout<<i<<":";
		for(int x:adj[i])
		cout<<x<<"\t";
		cout<<endl;
		
	}*/
	for(node &x:vertices)
	
	{
		x.color=white;
		x.parent=-1;
		x.completed=0;
		x.discover=0;
	}
	
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			dfs_visit(vertices,adj,i);
		}
	}
	
	/*for(int i=0;i<n;i++)
	{
		cout<<i<<"  "<<vertices[i].parent<<"  "<<vertices[i].discover<<" "<<vertices[i].completed<<endl;
		
	}*/
}















