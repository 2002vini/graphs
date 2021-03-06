#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex]=true;
    for(int child:graph[vertex])
    {
        if(vis[child])
        continue;

        dfs(child);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

    }
    int ctr=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        continue;
        cout<<"vertex:"<<i<<endl;
        dfs(i);
        ctr++;
    }
    cout<<"no of connected components are:"<<ctr<<endl;

}