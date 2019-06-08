#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long
#define ff first
#define ssd second

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	int n;
	cin>>n;
	int m = 1;
	int i,j;
	vector< pair<int,int> > v;
	int rd = 1;
	v.pb(mp(1,1));
	int r=1,c=1;
	for(i=2;i<=n;i++){
		if(rd == 1){
			c += 1;
			v.pb(mp(r,c));
			m = max(m,c);
			rd *= -1;
		}
		else{
			r += 1;
			v.pb(mp(r,c));
			m = max(m,r);
			rd *= -1;
		}
	}
	cout<<m<<endl;
	for(i=0;i<v.size();i++){
		cout<<v[i].ff<<" "<<v[i].ssd<<endl;
	}


return 0;
}