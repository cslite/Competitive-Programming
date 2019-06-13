//wrong solution , quite close but not working

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

#define md 1000000007

ll dp[101][101][101];	//index, value at idx, value at idx+1
int n;
vector<int> a(51);

ll getWays(int idx, int ai, int aip){
	
	int i = 0;
	// ll &res = dp[idx][ai][aip];
	// if(res != -1)
	// 	return res;
	// else{
	// 	res = 0;
	// 	if(idx > n && ai == 0)
	// 		return res = 1;
	// 	for(i=0;i<=min(ai,aip);i++){
	// 		if(idx + 2 < n)
	// 			res += getWays(idx+1,aip-i,a[idx+2]+i);
	// 		else
	// 			res += getWays(idx+1,aip-i,i);
	// 		res %= md;
	// 	}
	// 	return res; 
	// }
	if(idx > n && ai == 0)
		return 1;
	ll ways = 0;
	ll &dp_res = dp[idx][ai][aip];
	if(dp_res != -1)
		return dp_res;
	while(ai >=0 && aip >= 0){
		if(idx + 2 < n){
			ways += getWays(idx+1,aip,a[idx+2]+i);
		}
		else{
			ways += getWays(idx+1,aip,i);
		}
		ways %= md;
		ai--;	aip--;
		i++;
	}
	dp_res = ways;
	return ways;
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
	int i,t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin>>n;
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		ll wayz = getWays(0,a[0],a[1]);
		cout<<wayz<<endl;
	}


return 0;
}