#include<iostream>
#include<vector>
#include<queue>
using namespace std;
enum Color{white,grey,black};

struct node{
	int parent;
	Color color;
	int distance;
	int vertexcolor;
	
};
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
		adj[b].push_back(a);
	}
	queue<int> Q;
	for(int i=0;i<n;i++)
	{
		vertices[i].color=white;
		vertices[i].parent=-1;
		vertices[i].distance=0;
		vertices[i].vertexcolor=-1;
	}
	bool bipartite=true;
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			Q.push(i);
			vertices[i].vertexcolor=0;
		}
		while(!Q.empty())
		{
			int s=Q.front();
			Q.pop();
			vertices[s].color=grey;
			for(int x:adj[s])
			{
				
				if(vertices[x].color==white)
				{
					vertices[x].parent=s;
					vertices[x].distance=vertices[s].distance+1;
					vertices[x].vertexcolor=1-vertices[s].vertexcolor;
					Q.push(x);
				}
				else
				{
					if(vertices[x].vertexcolor==vertices[s].vertexcolor)
					{
						cout<<x<<"and"<<s<<"have same colro";
						bipartite=false;
						break;
					}
				}
			}
			vertices[s].color=black;
		}
	}
	if(bipartite)
		cout<<"yes bipartite";
	else
		cout<<"No not bipartite";
		for(int i=0;i<n;i++)
		{
			cout<<i<<" "<<vertices[i].parent<<" "<<vertices[i].color<<" "<<vertices[i].vertexcolor;
			cout<<endl;
		}
	
	
}
