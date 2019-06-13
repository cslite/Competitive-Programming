//dp

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

int n,m,k;
ll dp[5001][5001];	//(starting_idx , k)
vector<ll> p(5001);
vector<ll> csum(5001);

ll getSum(int si, int ei){
	if(si == 0)
		return csum[ei];
	else
		return csum[ei] - csum[si-1];
}

ll getOptimalSol(int sidx,int krem){
	if(krem == 0 && sidx <= n){
		return 0;
	}
	else if(sidx+m-1 >= n){
		return LLONG_MIN;
	}
	if(dp[sidx][krem] != -1){
		return dp[sidx][krem];
	}
	ll max_sum = LLONG_MIN;
	ll s1 = getSum(sidx,sidx+m-1) + getOptimalSol(sidx+m,krem-1);
	ll s2 = getOptimalSol(sidx+1,krem);
	max_sum = max((ll)s1,(ll)s2);
	dp[sidx][krem] = max_sum;
	return max_sum;
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

	cin>>n>>m>>k;
	int i;
	cin>>p[0];
	csum[0] = p[0];
	for(i=1;i<n;i++){
		cin>>p[i];
		csum[i] = csum[i-1] + p[i];
	}

	ll sum;
	ll max_sum = LLONG_MIN;
	ll s1= (ll)getSum(0,m-1) + (ll)getOptimalSol(m,k-1);
	ll s2 = (ll)getOptimalSol(1,k);
	max_sum = max(s1,s2);

	cout<<max_sum<<endl;




return 0;
}