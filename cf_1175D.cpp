//brute-force solution, does not work
//WrongAnswer

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

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	ll i,j,n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	vector<ll> posidx;
	vector<ll> res;
	vector<ll> r_pre_sum(n);
	r_pre_sum[n-1] = a[n-1];
	for(i=n-2;i>=0;i--){
		if(a[i] > 0)
			posidx.pb(i);
		r_pre_sum[i] = r_pre_sum[i+1] + a[i];
	}
	i = n-1;
	ll c=0;
	ll st = n-1;
	while(i>=0){
		// cerr<<i<<endl;
		if(res.size() == (k-1LL)){
			res.pb(0);
			break;
		}
		ll next_pos;
		if(c < posidx.size())
			next_pos = posidx[c];
		else
			next_pos = -1;
		// cerr<<next_pos<<" "<<(k - res.size() - 1)<<" "<<res.size()<<endl;
		ll tcmp = (k - res.size() - 1LL);
		if(next_pos < tcmp){
			//we can't take this number
			// putflag(111);
			res.pb(i);
			st = i-1;
			i--;
		}
		else{
			// if(next_pos == -1){
			// 	cerr<<"errr!!!"<<endl;
			// 	return -1;
			// }
			ll curr = a[st];
			ll newr = r_pre_sum[next_pos] ;
			if(st+1 < n)
				newr -= r_pre_sum[st+1];
			if(newr > curr){
				i = next_pos;
				c++;
			}
			else{
				res.pb(i);
				st = i-1;
				i--;
			}
		}
	}
	// tracelist(res,0,res.size());
	ll cost = r_pre_sum[res[0]]*k;
	k--;
	for(i=1;i<res.size();i++){
		cost += (r_pre_sum[res[i]] - r_pre_sum[res[i-1]])*k;
		k--;
	}
	cout<<cost<<endl;

return 0;
}