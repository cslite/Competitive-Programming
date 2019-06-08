#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

#define md 998244353

int n,m,k;

ll dp[2001][2001];

void computeWays(){
	int brick,ck;
	dp[1][0] = m % md;
	for(brick=2;brick <=n ; brick++){
		dp[brick][0] = m % md;
	}
	for(brick=2;brick<=n;brick++){
		for(ck=1;ck<=min(k,brick-1);ck++){
			dp[brick][ck] = ((dp[brick-1][ck - 1] * (m-1)) % md) + (((dp[brick-1][ck]))%md);
			dp[brick][ck] %= md;
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
	
	memset(dp,0,sizeof dp);

	cin>>n>>m>>k;

	computeWays();
	cout<<dp[n][k]<<endl;


return 0;
}