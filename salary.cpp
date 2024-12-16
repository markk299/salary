#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define int long long
#define nodes first
#define sl second
int n,st[2*N],en[2*N],tree[2*N],tour[2*N],m,edges,sal[N],lazy[4*N];
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
void push(int id){
	if(lazy[id]!=0){
		tree[id*2]+=lazy[id];
		lazy[id*2]+=lazy[id];
		tree[id*2+1]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void up(int id,int l,int r,int u,int v,int k){
	if(l>v||r<u) return;
	if(u<=l&&r<=v){
		tree[id]+=k;
		lazy[id]+=k;
		return;
	}
	push(id);
	int mid=(l+r)>>1;
	up(id*2,l,mid,u,v);
	up(id*2+1,mid+1,u,v);
	tree[id]=max(tree[id*2],tree[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
	if(l>v||r<u) return 0;
	if(u<=l&&r<=v){
		return tree[id];
	}
	push(id);
	int mid=(l+r)>>1;
	
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
