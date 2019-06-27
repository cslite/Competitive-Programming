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
	ll i,n,q;
	cin>>n>>q;
	// vector<ll> a(n);
	deque<ll> a;
	ll ti;
	ll me = -1;
	for(i=0;i<n;i++){
		cin>>ti;
		a.push_back(ti);
		me = max(me,ti);
	}
	vector< pair<ll,ll> > aq;
	aq.pb(mp(-1,-1));
	while(a.front() != me){
		ll x = a.front(); 
		a.pop_front();
		ll y = a.front(); 
		a.pop_front();
		a.push_front(max(x,y));
		a.push_back(min(x,y));
		aq.pb(mp(x,y));
	}
	vector< pair<ll,ll> > repq;
	for(i=0;i<(n-1);i++){
		ll x = a.front(); 
		a.pop_front();
		ll y = a.front(); 
		a.pop_front();
		a.push_front(max(x,y));
		a.push_back(min(x,y));
		repq.pb(mp(x,y));
	}
	ll mi;
	for(i=0;i<q;i++){
		cin>>mi;
		if(mi < aq.size())
			cout<<aq[mi].ff<<" "<<aq[mi].ssd<<endl;
		else{
			mi = mi -(aq.size());
			mi %= (n-1);
			cout<<repq[mi].ff<<" "<<repq[mi].ssd<<endl;
		}
	}



return 0;
}