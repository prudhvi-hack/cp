#include<iostream>
#include<queue>
using namespace std;

enum Color{white,gray,black};
struct node
{
	Color color;
	int distance;
	int parent;	
};
int main(){
	int n;
	cin>>n;
	
	vector<node> vertices(n);
	for(int i=0;i<n;i++)
	{
		vertices[i].color=white;
		vertices[i].distance=0;
		vertices[i].parent=-1;
	}
	vector<vector<int>> adj(n,vector<int>());
	int edge_count;
	cin>>edge_count;
	for(int i=0;i<edge_count;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vertices[0].color=gray;
	vertices[0].distance=0;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty())
	{
		int vertex=Q.front();
		Q.pop();
		for(int x:adj[vertex])
		{
			if(vertices[x].color==white)
			{
				vertices[x].parent=vertex;
				vertices[x].distance=vertices[vertex].distance+1;
				vertices[x].color=gray;
				Q.push(x);
				cout<<x<<endl;
			}
		}
		vertices[vertex].color=black;
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<vertices[i].parent<<" "<<vertices[i].distance<<endl;
	}*/
	

}
