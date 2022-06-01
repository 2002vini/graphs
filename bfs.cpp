#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//aplications of bfs
//1.to calculate shortest path in unweighted graph by maintaning level array in bfs
//2.web crawler-it traces back pages from source to all it's child and then onto next pages
//3.social network
//4.to detect bipartite graphs
const int N=1e5+10;
vector<int>graph[N];
int visited[N];
int level[N];

void bfs(int vertex)
{
    memset(visited,0,sizeof(visited));
memset(level,0,sizeof(level));
    //1.push the vertex in the queue and mark it as visited
    queue<int>q;
    q.push(vertex);
    visited[vertex]=1;
    //2.pop elements until the queue is empty
    while(!q.empty())
    {
        //while loop runs for each vertex 
        int ele=q.front();
        cout<<ele<<" ";
        q.pop();
        for(int child:graph[ele])
        {
            //for loop runs for each edge 
            //time complexity=o(v+e)
            if(!visited[child])
            {
                q.push(child);
                visited[child]=1;
                level[child]=level[ele]+1;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    bfs(1);

}