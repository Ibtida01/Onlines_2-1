#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
class graph
{
public:
    int v;
    vector<vector<int>>distance;
    int indexBase=-1;
    graph(int v)

    {
        this->v=v;
        distance.resize(v+1,vector<int>(v+1,INF));
    }
    void AddEdge(int u,int v,int w)
    {
        distance[u][v]=w;
        distance[v][u]=w;
    }


    void floydWarshall()
    {
        // int i,j,k;
        for(int k=indexBase; k<=n; k++)
        {
            for(int i=indexBase; i<=n; i++)
            {
                for(int j=indexBase; j<=n; j++)
                {
                    if(distance[i][j]>distance[i][k]+distance[k][j])
                    {
                        distance[i][j]=distance[i][k]+distance[k][j];
                    }
                }
            }
        }
        for(int i=indexBase; i<=n; i++)
        {
            if(distance[i][i]<0)
            {
                cout<<"Yes";
                return;
            }

        }
        cout<<"No\n";
    }

};
int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    vector<int>store;
    graph g(n);
    g.indexBase=1;//by default
    for(int i=0; i<m; i++)
    {
        cin>>u>>v>>w;
        if(u==0 || v==0)
            g.indexBase=0;
        store.push_back(u);
        store.push_back(v);
        g.AddEdge(u,v,w);
    }
    g.floydWarshall();
    return 0;
}
