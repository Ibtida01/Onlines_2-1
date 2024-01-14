//question link: https://onlinejudge.org/external/5/p544.pdf
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include<iomanip>
#include<cstring>
#define dbg(x) cout << #x << " = " << x << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pans cout << ans << "\n";
#define endl "\n"
#define pb push_back
#define mp make_pair
#define MAX 1000000000
#define pii pair<int,int>
#define EPS 1e-9
// const ll mod=1e9+7;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
using namespace std;
bool isEqualD(double x,double y)
{
   return (abs(x-y)<EPS) ? true : false;
}
bool isPrime(ll n)
{
  if(n==2) return true;
  int lim=sqrt(n)+1;
  for(int i=3;i<=lim;i++)
  {
    if(n%i==0)
      return false;
  }
  return true;
}
template <typename t>
void countingSort(vector<t>& arr, int startingIdx, int endingIdx, int minimum_val, int maximum_val)//arr = array to be sorted, might of edges too (for kruskal's algo)
{
    int arr_size=endingIdx-startingIdx+1;
    int i,k=0,sizeTemp = maximum_val-minimum_val+1;
    int temp[sizeTemp];

    // Initializing all element of counting array with 0
    for(i=0; i<sizeTemp; i++){
        temp[i] = 0;
    }

    //Store the frequency of each element of the original array
    //at the relative position in counting array
    for(i=0; i<=endingIdx; i++){
        temp[arr[i]-minimum_val]++;
    }

    //Iterate through the counting array and re-write the original array.
    for (i=minimum_val; i<=maximum_val; i++){
        while(temp[i-minimum_val]-->0){
            arr[k++]=i;
        }
    }
}

class DSU
{
public:
  vector<int> rank,parent;
  DSU(int n)
  {
    for(int i=0;i<=n;i++)
        rank.pb(0);
    //parent.resize(n);
    for(int i=0;i<=n;i++)
      parent.pb(i);
  }
  int findParent(int u)
  {
    if(u==parent[u]) return u;
    //else
    return parent[u]=findParent(parent[u]);
  }
  void _union(int u,int v)
  {
    int pu=parent[u];
    int pv=parent[v];
    if(pu==pv) return;
    //else
    if(rank[pu]<rank[pv])
    {
      parent[pu]=pv;
    }
    else if(rank[pu]>rank[pv])
    {
      parent[pv]=pu;
    }
    else{
      parent[pu]=pv;
      ++rank[pv];
    }
  }
};
class edge
{
public:
  int u,v,w;
   edge(int u,int v,int w)
   {
      this->u=u;
      this->v=v;
      this->w=w;
   }
    bool operator<(const edge& other) const
    {
      return w>other.w;
    }

};
void solve(int& t)
{
 //vector<int> adj[1000];
 std::vector<edge> edges;
 int n,m;
 cin>>n>>m;
 if(n==0 && m==0) 
  {
    //cout<<endl;
    t=0;
    exit(0);
  }
 DSU dsu(n);
 string u,v;
 int w;
 std::map<string, int> ct_id;
 int cityNo=1;
 int iu,iv;
 for(int i=0;i<m;i++)
 {
    cin>>u>>v>>w;
    if(ct_id.find(u)==ct_id.end())
      {
        ct_id.insert(mp(u,cityNo++));
        iu=ct_id[u];
      }
    else iu=ct_id[u];
    if(ct_id.find(v)==ct_id.end()) {
      ct_id.insert(mp(v,cityNo++));
      iv=ct_id[v];
    }
    else iv=ct_id[v];
    edge e(iu,iv,w);
    edges.pb(e);
 }
 cin>>u>>v;
 int src=ct_id[u];
 int dest=ct_id[v];
 sort(edges.begin(), edges.end());
 int ans=INT_MAX;
 int ct=0;
 for(auto e:edges)
 {
  if(dsu.findParent(e.u)!=dsu.findParent(e.v))
    {
      dsu._union(e.u,e.v);
      ans=min(ans,e.w);
      if(dsu.findParent(src)==dsu.findParent(dest))
        break;
      ++ct;
    }
 }
 cout<<"Scenario #"<<t<<endl;
 cout<<ans<<" tons"<<endl<<endl;
 cout<<endl;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
  // fast_io;
   int t;
  //  cin>>t;
   for(int i=1;i!=0;i++)
   //while(t--)
       solve(i);
}

