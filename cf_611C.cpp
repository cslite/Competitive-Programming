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

vector<string> s(501);
ll dp[501][501];
//in which horizontal ways were cut
int hcut[501][501];
//in which vertical ways were cut
int vcut[501][501];
int h,w;

void computeWays(){
	int i,j;
	dp[0][0] = 0;
	hcut[0][0] = 0;
	vcut[0][0] = 0;
	for(j=1;j<w;j++){
		dp[0][j] = dp[0][j-1];
		vcut[0][j] = 0;
		if(s[0][j] == '.' && s[0][j-1] == '.'){
			hcut[0][j] = 1;
			dp[0][j] += 1;
		}
		else
			hcut[0][j] = 0;
	}
	for(i=1;i<h;i++){
		dp[i][0] = dp[i-1][0];
		hcut[i][0] = 0;
		if(s[i][0] == '.' && s[i-1][0] == '.'){
			vcut[i][0] = 1;
			dp[i][0] += 1;
		}
		else
			vcut[i][0] = 0;
	}
	for(i=1;i<h;i++){
		for(j=1;j<w;j++){
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			hcut[i][j] = hcut[i-1][j];
			vcut[i][j] = vcut[i][j-1];
			if(s[i][j] == '.' && s[i-1][j] == '.'){
				vcut[i][j] += 1;
				dp[i][j]++;
			}
			if(s[i][j] == '.' && s[i][j-1] == '.'){
				hcut[i][j] += 1;
				dp[i][j]++;
			}
		}
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
	cin>>h>>w;
	int i,j;
	for(i=0;i<h;i++)
		cin>>s[i];
	computeWays();
	// for(i=0;i<h;i++){
	// 	for(j=0;j<w;j++)
	// 		cerr<<dp[i][j]<<"\t";
	// 	cerr<<endl;
	// }
	ll q;
	cin>>q;
	int r1,c1,r2,c2;
	while(q--){
		cin>>r1>>c1>>r2>>c2;
		r1--;	r2--;	c2--;	c1--;
		ll ans = dp[r2][c2];
		if(r1 >= 1){
			ans -= vcut[r1][c2];
			if(c1 >= 1)
				ans += vcut[r1][c1-1];
			ans -= dp[r1-1][c2];
		}
		if(c1 >= 1){
			ans -= hcut[r2][c1];
			if(r1>=1)
				ans += hcut[r1-1][c1];
			ans -= dp[r2][c1-1];
		}
		if(c1 >= 1 && r1 >= 1)
			ans += dp[r1-1][c1-1];
		cout<<ans<<endl;
	}



return 0;
}