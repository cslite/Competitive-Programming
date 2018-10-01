//DFS Problem
//Codeforces Round #395 (Div. 1)
//http://codeforces.com/problemset/problem/763/A

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define ff first
#define ssd second
#define endl "\n"
#define pb push_back
#define ll long long
long long zz;
#define putflag(xx) cerr<<"!! flag_"<<xx<<" !!"<<endl;
#define tracelist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<x[zz]<<" "; cerr<<endl;
#define tracepairlist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<"("<<x[zz].ff<<","<<x[zz].ss<<") "; cerr<<endl;

vector < vector<long> > adj(100001);
long color[100001];
// bool visited[100001] = {0};

vector<bool> visited;

bool isAnnoyed(long start, long root, long n)
{
	//dfs to find out whether all nodes of the given subtree are
	// of the same color
	stack <long> s;
	long i;
	// bool visited[n+1] = {0};
	visited = vector<bool>(n+1,0);	//** making your vector point to a new vector is fastest way to reinitialize
	s.push(start);
	visited[start] = true;
	visited[root] = true;
	long c = color[start];
	bool flag = false;
	while(!s.empty())
	{
		long top = s.top();
		s.pop();
		visited[top] = true;
		if(color[top] != c)
		{
			flag = true;
			break;
		}
		for(i=0;i<adj[top].size();i++)
		{
			if(!visited[adj[top][i]])
				s.push(adj[top][i]);
		}
	}
	return flag;
}

vector < pair<long,long> > e;

bool check_for_root(long root, long n)
{
	bool flag = true;
	long j;
	for(j=0;j<adj[root].size();j++)
	{
		if(isAnnoyed(adj[root][j],root,n) == true)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;

	// cout<<"Hello World!";
	long i,n,u,v,j;
	cin>>n;
	// long color[n+1];
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
		e.pb(mp(u,v));
	}
	for(i=1;i<=n;i++)
		cin>>color[i];
	bool done = false;
	for(i=0;i<n-1;i++)
	{
		if(color[e[i].ff] != color[e[i].ssd])
		{
			if(check_for_root(e[i].ff,n))
			{
				cout<<"YES"<<endl;
				cout<<e[i].ff<<endl;


			}
			else if(check_for_root(e[i].ssd,n))
			{
				cout<<"YES"<<endl;
				cout<<e[i].ssd<<endl;
			}
			else
			{
				cout<<"NO"<<endl;
			}
			done = true;
			break;
		}
	}
	if(!done)
	{
		cout<<"YES"<<endl;
		cout<<"1"<<endl;
	}




return 0;
}
