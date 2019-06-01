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
	vector<ll> arr(n);
	int i;
	
	for(i=0;i<n;i++){
		cin>>arr[i];
	}

	int maxcnt = 1;
	int cnt = 1;
	for(i=1;i<n;i++){
		if(arr[i] <= arr[i-1]*2){
			cnt++;
			if(cnt > maxcnt)
				maxcnt = cnt;
		}
		else{
			cnt = 1;
		}
	}

	cout<<maxcnt<<endl;


return 0;
}