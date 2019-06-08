//modified kadane, dp, Largest Sum Contiguous Subarray
// O(n)

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
	int t;
	cin>>t;
	while(t--){
		int i,n;
		cin>>n;
		vector<ll> a(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		ll currmax, globmax, currmin;
		currmax = a[0];
		globmax = a[0];
		currmin = a[0];
		ll size = 1;
		for(i=1;i<n;i++){
			ll tmp = currmax + a[i];
			// !! it is compared to a[i] !!
			if(tmp >= a[i]){
				size++;
				currmax = tmp;
				currmin = min(currmin,a[i]);
				ll bestcmax = max(currmax, (currmax - currmin));
				globmax = max(globmax, bestcmax);
			}
			else{
				if(currmin < 0 && size>1){
					ll tcurrmax = currmax - currmin;
					ll tglobmax = globmax;
					for(int j=i;j<n;j++){
						ll ttmp = tcurrmax + a[j];
						if(ttmp >= a[j]){
							tcurrmax =ttmp;
							tglobmax = max(tglobmax,tcurrmax);
						}
						else{
							break;
						}
					}
					globmax = max(globmax,tglobmax);
				}
				size = 1;
				currmax = a[i];
				currmin = a[i];
				globmax = max(globmax,currmax);
			}
		}
		cout<<globmax<<endl;
	}


return 0;
}