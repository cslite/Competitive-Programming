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

int n,m;
ll memo[1001][1001];
vector<string> s(1001);

ll getFlags(int sz){
	if(sz==-1)
		return 0;
	else if(sz == 0)
		return 0;
	else{
		ll rs = (sz*(sz-1));
		rs /=2;
		return rs;
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
	cin>>n>>m;
	int i,j;
	for(i=0;i<n;i++){
		cin>>s[i];
	}
	for(j=0;j<m;j++){
		memo[n-1][j] = 1;
	}
	for(j=0;j<m;j++){
		for(i=(n-2);i>=0;i--){
			if(s[i+1][j] == s[i][j]){
				memo[i][j] = memo[i+1][j] + 1;
			}
			else{
				memo[i][j] = 1;
			}
		}
	}
	// for(i=0;i<n;i++){
	// 	for(j=0;j<m;j++)
	// 		cerr<<memo[i][j]<<" ";
	// 	cerr<<endl;
	// }

	ll flags = 0;
	int prev_mij = -1;
	string clr = "000";
	int sz = 0;
	for(i=0;i<(n-2);i++){
		for(j=0;j<m;j++){
			int mij = memo[i][j];
			if(i+mij < n && memo[i+mij][j] == mij){
				if(i+mij+mij < n && memo[i+mij+mij][j] >= mij){
					flags++;
					string x1(1,s[i][j]);
					string x2(1,s[i+mij][j]);
					string x3(1,s[i+mij+mij][j]);
					string thisclr = x1 + x2 + x3; 
					// cerr<<thisclr<<endl;
					if(prev_mij != -1 && prev_mij == mij){
						if(thisclr == clr){
							sz += 1;
						}
						else{
							flags += getFlags(sz);
							prev_mij = mij;
							clr = thisclr;
							sz = 1;
						}
					}
					else{
						flags += getFlags(sz);
						prev_mij = mij;
						clr = thisclr;
						sz = 1;
					}
				}
				else{
					flags += getFlags(sz);
					prev_mij = -1;
					clr = "000";
					sz = 0;
				}
			}
			else{
				flags += getFlags(sz);
				prev_mij = -1;
				clr = "000";
				sz = 0;
			}
		// cerr<<flags<<endl;
		}
		flags += getFlags(sz);
		prev_mij = -1;
		clr = "000";
		sz = 0;
	}
	cout<<flags<<endl;



return 0;
}