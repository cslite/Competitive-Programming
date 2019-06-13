//dp , binary search
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

ll n;

int dp[100001];
// vector<ll> b(100001);

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	ll i;
	cin>>n;
	vector< pair<ll,ll> > ab(n);
	for(i=0;i<n;i++){
		cin>>ab[i].ff>>ab[i].ssd;
	}
	sort(ab.begin(),ab.end());
	dp[0] = 0;
	for(i=0;i<n;i++){
		ll diff = (ab[i].ff - ab[i].ssd);
		// cerr<<"diff="<<diff<<endl;
		ll idx = lower_bound(ab.begin(),ab.end(),mp(diff,0LL)) - ab.begin();
		// cerr<<"idx="<<idx<<endl;
		dp[i] = 0;
		if(idx-1 >= 0)
			dp[i] += dp[idx-1];
		dp[i] += (i - idx); 
		// cerr<<"dp["<<i<<"] = "<<dp[i]<<endl;
	}
	// tracelist(dp,0,n);
	ll mindestroy = n;
	for(i=0;i<n;i++){
		ll destroy = dp[i] + (n-1LL-i);
		mindestroy = min(mindestroy,destroy);
	}
	cout<<mindestroy<<endl;

return 0;
}