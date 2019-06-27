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
	int n;
	cin>>n;
	int i;
	vector<ll> a(n);
	ll mav = -1;
	
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i] >= 0){
			a[i] = (-1)*(a[i] + 1ll);
		}
		mav = max(mav,abs(a[i]));
	}
	if(mav == 1 && n%2 != 0){
		for(i=0;i<n;i++){
			if(a[i] == -1)
				a[i] = 0;
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	else if(n%2 != 0){
		bool done = false;
		for(i=0;i<n;i++){
			if(a[i] == -mav && !done){
				a[i] = mav-1;
				done = true;
			}
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	else{
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}





return 0;
}