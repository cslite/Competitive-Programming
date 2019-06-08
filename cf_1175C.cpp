//wrong solution, does not work
//read the question wrong
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

ll getRank(int x, int y){
	//x <= y
	return y-x;
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
	ll t;
	cin>>t;
	while(t--){
		ll i,n,k;
		ll fkx = -1;
		cin>>n>>k;
		vector<ll> a(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		ll dis_l_max, dis_r_max, dis_l, dis_r;
		ll rank;
		ll l,r,mid;
		ll tl,tr,tmid,tdis,tdisl;
		for(i=0;i<n;i++){
			//caluclate fk(x) for each x
			dis_l_max = a[i] - a[0];
			dis_r_max = a[n-1] - a[i];
			rank = 0;
			r = l = max(dis_l_max,dis_r_max);
			if(i-1>=0)
				l = a[i] - a[i-1];
			if(i+1 < n)
				l = min(l,(a[i+1]-a[i]));
			while(l<=r){
				mid = l + (r-l)/2;
				// cout<<mid<<'\t';
				rank = 0;
				tdis = 0;
				if(i-1 >= 0){
					tl = i-1;
					tr = 0;
					// putflag(1);
					while(tl >= tr){
						// putflag(2);
						tmid = tr + (tl-tr)/2;
						tdis = a[i] - a[tmid];
						if(tmid-1>=0){
							if(tdis <= mid && (a[i]-a[tmid-1]) > mid){
								rank += getRank(tmid,i);
								break;
							}
						}
						else if(tdis <= mid){
							rank += getRank(tmid,i);
							break;
						}
						if(tdis > mid){
							tr = tmid+1;
						}
						else if(tdis < mid){
							tl = tmid-1;
						}
					}
					// putflag(3);
					tdisl = tdis;
				}
				else
					tdisl = 0;
				if(i+1 < n){
					// putflag(4);
					tl = i+1;
					tr = n-1;
					while(tl<=tr){
						tmid = tl + (tr-tl)/2;
						tdis = a[tmid] - a[i];
						if(tmid + 1 < n){
							if(tdis <= mid && (a[tmid+1] - a[i]) > mid){
								rank += getRank(i,tmid);
								break;
							}
						}
						else if(tdis <= mid){
							rank += getRank(i,tmid);
							break;
						}
						if(tdis > mid){
							tr = tmid - 1;
						}
						else if(tdis < mid)
							tl = tmid + 1;
					}
					cerr<<rank<<endl;
				}
				if(rank == k){
					if(fkx == -1){
						fkx = max(tdis,tdisl);
						xapt = i;
					}
					else{
						if(max(tdis,tdisl) < fkx){
							fkx = max(tdis,tdisl);
							xapt = i;
						}
					}
					break;
				}
				else if(rank < k){
					l = mid + 1;
				}
				else{
					r = mid - 1;
				}
			}
		}
		cout<<a[xapt]<<endl;
	}


return 0;
}