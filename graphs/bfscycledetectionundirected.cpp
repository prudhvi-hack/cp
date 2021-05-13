#include<bits/stdc++.h>
using namespace std;
enum Color{white,grey,black};
struct node{
	int parent;
	int distance;
	Color color;
};

int main()
{
	int n;
	cin>>n;
	vector<node> vertices(n);
	int e;
	cin>>e;
	vector<vector<int>> adj(n,vector<int>());
	for(int i=0;i<n;i++)
	{
		vertices[i].color=white;
		vertices[i].parent=-1;
		vertices[i].distance=0;
	}
	/*for(int i=0;i<n;i++)
	{
		cout<<vertices[i].color;
		cout<<vertices[i].parent;
		cout<<vertices[i].distance;
		cout<<endl;
	}*/
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> Q;
	bool cycle=false;
	for(int i=0;i<n;i++)
	{
		if(vertices[i].color==white)
		{
			Q.push(i);
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
						vertices[x].color=grey;
						vertices[x].distance=vertices[s].distance+1;
						Q.push(x);
						cout<<x<<endl;
					}
					else 
					{
						if(x!=vertices[s].parent)
						{
							cycle=true;
							break;
						}
					}
					
				}
				vertices[s].color=black;
			}
		}
	}
	
	if(cycle)
	{
		cout<<"cycle present";
	}
	else
	{
		cout<<"cycle not present";
	}
}
