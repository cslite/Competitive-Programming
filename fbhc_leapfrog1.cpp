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

string lilypad;
int n;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	int i,t;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>lilypad;
		n = lilypad.length();
		if(n==2){
			cout<<"Case #"<<ti<<": "<<"N"<<endl;
			continue;
		}
		int b = 0;
		for(i=0;i<n;i++){
			if(lilypad[i] == 'B')
				b++;
		}
		if (b > (n-2)){
			cout<<"Case #"<<ti<<": "<<"N"<<endl;
			continue;
		}
		else if(b == (n-2)){
			cout<<"Case #"<<ti<<": "<<"Y"<<endl;
			continue;	
		}
		else{
			int bidx = n-1-b;
			int ai = 0;
			while(ai<(bidx-1) && bidx < (n-1)){
				bidx++;
				ai += 2;
			}
			if(bidx == n-1){
				cout<<"Case #"<<ti<<": "<<"N"<<endl;
				continue;				
			}
			if(ai+1 == bidx){
				cout<<"Case #"<<ti<<": "<<"Y"<<endl;
				continue;
			}

		}
	}

return 0;
}