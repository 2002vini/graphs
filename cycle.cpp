#include<iostream>
#include<bits/stdc++.h>
//program to find out if loop exist or not
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool vis[N];
bool cycle (int vertex,int par)
{
    vis[vertex]=true;
    bool isloopexist=false;
    for(int child:graph[vertex])
    {
        if(vis[child] && child==par)
        continue;
        if(vis[child])
        return true;

        isloopexist|=cycle(child,vertex);
    }

    return isloopexist;
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

    bool ans=cycle(1,1);
    cout<<"loop exist:"<<ans<<endl;
}