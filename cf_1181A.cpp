//cf_1181A
#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	ll x,y,z;
	cin>>x>>y>>z;
	ll cocs = 0;
	ll xchng = 0;
	cocs += (x/z);
	cocs += (y/z);
	x = x%z;
	y = y%z;
	if(x+y >= z){
		xchng = min(z-x,z-y);
		cocs += 1;
	}
	else{
		xchng = 0;
	}
	cout<<cocs<<" "<<xchng<<endl;

return 0;
}