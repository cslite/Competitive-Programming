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


#define REST 0
#define CODE 1
#define GYM 2

#define can_code(i) (a[i] == 1 || a[i] == 3)
#define can_gym(i) (a[i] == 2 || a[i] == 3)

int n;
vector<int> a(101);

ll dp[101][3];	//day, prev_day_state


ll computeRest(){
	dp[n][REST] = 1;
	if(can_code(n))
		dp[n][CODE] = 0;
	else
		dp[n][CODE] = 999;
	if(can_gym(n))
		dp[n][GYM] = 0;
	else
		dp[n][GYM] = 999;
	for(int i = n-1; i>=1; i--){
		dp[i][REST] = 1+ min({dp[i+1][REST],dp[i+1][CODE], dp[i+1][GYM]});
		if(can_code(i))
			dp[i][CODE] = min(dp[i+1][REST],dp[i+1][GYM]);
		else
			dp[i][CODE] = 999;
		if(can_gym(i))
			dp[i][GYM] = min(dp[i+1][REST],dp[i+1][CODE]);
		else
			dp[i][GYM] = 999;
	}
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
	cin>>n;
	int i;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	computeRest();
	ll ans = min({dp[1][REST],dp[1][CODE], dp[1][GYM]});
	cout<<ans<<endl;


return 0;
}