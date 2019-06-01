//works but uses too much memory
// 2d array of vectors
// dp solution

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

int n;
string s;
vector<int> col(200001);
vector<ll> dp[200001][3];


//this will return a vector whose first index is cost and others are characters
vector<ll> getCost(int idx, int prevcol){
	if(idx == n){
		vector<ll> vret(1);
		vret[0] = 0;
		return vret;
	}
	if(!(dp[idx][prevcol].empty()))
		return dp[idx][prevcol];
	vector<ll> c1,c2;
	c1 = getCost(idx+1,(prevcol+1)%3);
	c1.push_back((prevcol+1)%3);
	c2 = getCost(idx+1,(prevcol+2)%3);
	c2.pb((prevcol+2)%3);
	if(prevcol == col[idx]){
		c1[0] += 1LL;		
		c2[0] += 1LL;
	}
	else if(col[idx] == (prevcol+1)%3){
		c2[0] += 1LL;
	}
	else{
		c1[0] += 1LL;
	}
	if(c1[0]<c2[0]){
		dp[idx][prevcol] = c1;
		return c1;
	}
	else{
		dp[idx][prevcol] = c2;
		return c2;
	}
}

char n2c(int x){
	if(x==0){
		return 'R';
	}
	else if(x==1){
		return 'G';
	}
	else{
		return 'B';
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

	// memset(dp,-1,sizeof dp);

	cin>>n;
	cin>>s;
	int i;
	for(i=0;i<n;i++){
		switch(s[i]){
			case 'R':
				col[i] = 0;
				break;
			case 'G':
				col[i] = 1;
				break;
			case 'B':
				col[i] = 2;
				break;
		}
	}
	// cout<<"is this working"<<endl;

	vector<ll> c1,c2,c3;
	c1 = getCost(1,col[0]);
	c2 = getCost(1,(col[0]+1)%3);
	c2[0] +=1LL;
	c3 = getCost(1,(col[0]+2)%3);
	c3[0] += 1LL;
	ll cost = min(min(c1[0],c2[0]),c3[0]);
	string sres;
	if(cost == c1[0]){ 
		sres.pb(n2c(col[0]));
		for(i=c1.size()-1;i>0;i--){
			sres.pb(n2c(c1[i]));
		} 
	}
	else if(cost == c2[0]){
		sres.pb(n2c((col[0]+1)%3));
		for(i=c2.size()-1;i>0;i--){
			sres.pb(n2c(c2[i]));
		}
	}
	else{
		sres.pb(n2c((col[0]+2)%3));
		for(i=c3.size()-1;i>0;i--){
			sres.pb(n2c(c3[i]));
		}
	}

	cout<<cost<<endl;
	cout<<sres<<endl;

return 0;
}