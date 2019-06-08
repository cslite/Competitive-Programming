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
	int x,y,z;
	cin>>x>>y>>z;
	if(x > y+z){
		cout<<"+"<<endl;
	}
	else if(y > x+z){
		cout<<"-"<<endl;
	}
	else if(x==y && z==0){
		cout<<"0"<<endl;
	}
	else{
		cout<<"?"<<endl;
	}

return 0;
}