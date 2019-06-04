// odd even , sorting

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
	ll n;
	cin>>n;
	vector<ll> a(n);
	int i;
	int evens=0,odds=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%2==0)
			evens++;
		else
			odds++;
	}
	if(!(odds==0 || evens==0)){
		//array remains same
		sort(a.begin(),a.end());
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;



return 0;
}