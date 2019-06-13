//dp , knapsack 0-1 , standard-dp
// 3d states

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

ll n,m;
ll a[11],b[11],c[11],d[11];

ll dp[11][101][1001];

ll getMoney(int i, ll ingleft, ll doleft){
	ll mani = 0;
	if (i>m || i<0)
		return 0;
	if(doleft <= 0)
		return 0;
	if(dp[i][ingleft][doleft] != -1)
		return dp[i][ingleft][doleft];
	if(i==0){
		ll tmani = 0;
		if(doleft >= c[i]){
			tmani = d[0];
			tmani += max(getMoney(i,0,doleft-c[i]),getMoney(i+1,a[i+1],doleft-c[i]));			
		}
		tmani = max(tmani,getMoney(i+1,a[i+1],doleft));
		mani = max(mani,tmani);
	}
	else if(i>0 && b[i] <= ingleft && c[i] <= doleft){
		ll tmani = d[i];
		if(i+1 <= m)
			tmani += max(getMoney(i,ingleft-b[i],doleft-c[i]),getMoney(i+1,a[i+1],doleft-c[i]));
		else
			tmani += getMoney(i,ingleft-b[i],doleft-c[i]);
		mani = max(tmani,mani);
	}
	if(i+1 <= m)
		mani = max(mani,getMoney(i+1,a[i+1],doleft));
	
	dp[i][ingleft][doleft] = mani;
	return mani;
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
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>c[0]>>d[0];
	int i;
	for(i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	}
	ll ans = getMoney(0,0,n);
	cout<<ans<<endl;

return 0;
}