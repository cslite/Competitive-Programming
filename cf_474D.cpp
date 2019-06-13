//dp , prefix sum

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

ll k;
vector<ll> dp(100001);
vector<ll> csum(100001);

void computeWays(){
	dp[0] = 0;
	csum[0] = 0;
	dp[1] = 1;
	if(k == 1)	dp[1] += 1;
	csum[1] = dp[1];
	int i;
	for(i=2;i<=100000;i++){
		dp[i] = dp[i-1];
		if(i > k)
			dp[i] += dp[i-k];
		else if(i == k)
			dp[i] += 1;
		dp[i] %= md;
		csum[i] = (csum[i-1] + dp[i]) % md;
	}
}

// ll computeWays(int n){
// 	if(dp[n] != -1)
// 		return dp[n];
// 	if(n<=0)
// 		return 0;
// 	ll ans = 0;
// 	if(n == k){
// 		ans += 1;
// 		ans %= md;
// 	}
// 	else if(n > k){
// 		ans += (computeWays(n-k) % md);
// 		ans %= md;
// 	}
// 	if(n == 1){
// 		ans += 1;
// 		ans %= md;
// 	}
// 	else if(n > 1){
// 		ans += (computeWays(n-1) % md);
// 		ans %= md;
// 	}
// 	dp[n] = (ans % md);
// 	return dp[n];
// }


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	ll t;
	cin>>t>>k;
	computeWays();
	while(t--){
		ll a,b;
		cin>>a>>b;
		ll ways = (csum[b] - csum[a-1] + md) % md;
		cout<<ways<<endl;
	}

return 0;
}