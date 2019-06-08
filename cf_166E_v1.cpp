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

#define m 1000000007

ll dp[4][10000001];

ll n;
ll getWays(int pos, int turnsLeft){
	if(pos == 0 && turnsLeft == 0)
		return 1;
	else if(turnsLeft == 0)
		return 0;
	if(dp[pos][turnsLeft] != -1)
		return dp[pos][turnsLeft];
	dp[pos][turnsLeft] = getWays((pos+1)%4,turnsLeft-1) % m; 
	dp[pos][turnsLeft] += getWays((pos+2)%4,turnsLeft-1) % m;
	dp[pos][turnsLeft] %= m;
	dp[pos][turnsLeft] += getWays((pos+3)%4,turnsLeft-1) % m;
	dp[pos][turnsLeft] %= m;
	return dp[pos][turnsLeft];
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
	cin>>n;

	cout<<getWays(0,n)<<endl;


return 0;
}