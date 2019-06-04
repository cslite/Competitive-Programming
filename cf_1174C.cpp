//sieve , co-prime, coloring, minimal

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

vector<bool> prime(100001,true);
vector<int> res(100001,0);
int color;
void sieve(int n){
	int i,j;
	for(i=2;i*i<=n;i++){
		if(prime[i]){
			color++;
			res[i] = color;
			for(j=i*i;j<=n;j+=i){
				prime[j] = false;
				// cout<<"making j="<<j<<" as color="<<color<<endl;
				res[j] = color;
			}
		}
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
	int i,n;
	cin>>n;
	color = 0;
	sieve(n);
	for(i=2;i<=n;i++){
		if(prime[i] && res[i]==0){
			res[i] = ++color;
		}
	}
	for(i=2;i<=n;i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;



return 0;
}