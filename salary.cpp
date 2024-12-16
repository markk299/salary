#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
#define nodes first
#define sl second
int n,st[2*N],en[2*N],tree[2*N],tour[2*N],m,edges,sal[N];
vector<int>adj[N];
void dfs(int u, int parent_of_u) {
    tour[++m].first=u;
    tour[m].second=u;
    st[u]=m;
    for (int v:adj[u]) {
        if(v!=parent_of_u){
            dfs(v,u);
        }
    }
    en[u]=m;
}
void build(int id,int l,int r){
	if(l==r){
		tree[id]=tour[l].second;
		return;
	}
	int mid=(l+r)>>1;
	build(id*2,l,mid); build(id*2+1,mid+1,r);
	tree[id]=max(tree[id*2],tree[id*2+1]);
}
void up(int id,int l,int r,int u,int v,int k){
	if(l>v||r<u)
}
main(){
	cin>>n>>edges;
	for(int i=1;i<=edges;i++){
		int u,v;
		cin>>u>>v;
		adj[i].push_back(v);
		adj[v].push_back(v);
		sal[i]=u;
	}
	dfs(1,0);

}
