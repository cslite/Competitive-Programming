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
	vector<ll> v(2*n);
	int i;
	for(i=0;i<2*n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	ll s1=0,s2=0;
	for(i=0;i<n;i++){
		s1 += v[i];
	}
	for(i=n;i<2*n;i++)
		s2 += v[i];
	if(s1 == s2){
		cout<<-1<<endl;
	}
	else{
		for(i=0;i<2*n;i++){
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}


return 0;
}