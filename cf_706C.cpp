//dp

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

ll dp[100001][2];
ll cost[100001];
vector<string> s(100001);
vector<string> srev(100001);
int n;

ll getCost(int idx, int p_rev){
	if(idx == n)
		return 0;
	if(dp[idx][p_rev] != -1){
		return dp[idx][p_rev];
	}
	string prev;
	if(p_rev == 0)
		prev = s[idx-1];
	else
		prev = srev[idx-1];
	ll c1 = -2,c2 = -2;
	if(s[idx] >= prev){
		c1 = getCost(idx+1,0);
	}
	if(srev[idx] >= prev){
		c2 = getCost(idx+1,1);
		if(c2 != -2)
			c2 += cost[idx];
	}
	if(c1==-2 && c2 == -2){
		//not possible from this state
		dp[idx][p_rev] = -2;
		return -2;
	}
	else if(c1 == -2)
		dp[idx][p_rev] = c2;
	else if(c2 == -2)
		dp[idx][p_rev] = c1;
	else
		dp[idx][p_rev] = min(c1,c2);

	return dp[idx][p_rev];
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
	int i;
	for(i=0;i<n;i++){
		cin>>cost[i];
	}
	for(i=0;i<n;i++){
		cin>>s[i];
		srev[i] = string(s[i]);
		reverse(srev[i].begin(),srev[i].end());
	}
	ll c1 = getCost(1,0);
	ll c2 = getCost(1,1);
	ll ans;
	if(c2 != -2)
		c2 += cost[0];
	if(c1 == -2 && c2 ==-2)
		ans = -1;
	else if(c1 == -2)
		ans = c2;
	else if(c2 == -2)
		ans = c1;
	else
		ans = min(c1,c2);

	cout<<ans<<endl;

return 0;
}