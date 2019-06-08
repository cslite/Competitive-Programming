//Wrong Answer, Does not work!

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
	ll i,n;
	cin>>n;
	vector<ll> hand(n);
	vector<ll> pile(n);
	ll ops = 0;
	for(i=0;i<n;i++)
		cin>>hand[i];
	for(i=0;i<n;i++)
		cin>>pile[i];
	
	set<ll> nzh;
	for(i=0;i<n;i++){
		if(hand[i] != 0){
			nzh.insert(hand[i]);
		}
	}
	i=0;
	ll cnt = nzh.size();
	bool sflag = false;
	if(*(nzh.begin()) == 1){
		sflag = true;
	}
	ll smax=0;
	while(i<n && !nzh.empty()){
		if(sflag){
			smax = max(smax,*(nzh.begin()));
		}
		if(pile[i] != 0 && pile[i]> *(nzh.begin())){
			nzh.erase(nzh.begin());
			nzh.insert(pile[i]);
			cnt++;
		}
		else
			nzh.erase(nzh.begin());
		i++;
	}
	i = n-1;
	while(i>=0 && pile[i] == 0)
		i--;
	if(i < 0){
		//pile is full of zeros
		cout<<n<<endl;
		return 0;
	}
	else{
		ll li = i;
		while(i>0 && pile[i] != 0 && pile[i] > pile[i-1])
			i--;
		if(pile[i] == 0){
			i++;
		}
		ll size = pile[li] - pile[i] + 1;
		// cerr<<cnt<<endl;
		ll opscnt = n + n - cnt;
		// if(sflag && smax != (cnt - 1LL))
		// 	opscnt += 1; 
		if(pile[i] == 1 && pile[li] == size && cnt == (n-size)){
			//prefix already present
			// ll itmp = i-1;
			// while(itmp>0 && pile[itmp] == 0)
			// 	itmp--;
			// if(itmp == 0)
			// putflag(1);
			ops = n-size;
			ops = min(ops,opscnt);
			cout<<ops<<endl;
			return 0; 
		}
		if(i!=0){
			//extra operations required to bring this to 0
			ops = i;
			cerr<<i<<endl;
			// putflag(2);
		}
		if(pile[i] == 1 /*&& pile[li] != size*/){
			ops += 1;
			size -= 1;
			// putflag(3);
		}
		ops += (n);
		ops = min(ops,opscnt);
		cout<<ops<<endl;
		return 0;
	}


return 0;
}