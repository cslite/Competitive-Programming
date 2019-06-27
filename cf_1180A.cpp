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
	int a[n+1];
	a[1] = 1;
	for(int i=2;i<=n;i++)
		a[i] = a[i-1] + (4*(i-1));
	cout<<a[n]<<endl;

return 0;
}