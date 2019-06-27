//string sum, big integer, compare

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

string getSum(string x, string y){
	int c = 0;
	ll i;
	ll xl = x.length();
	ll yl = y.length();
	// cerr<<"x="<<x<<endl;
	// cerr<<"y="<<y<<endl;
	if(xl > yl){
		ll nz = xl - yl;
		string zz(nz,'0');
		// cerr<<zz<<endl;
		y = zz + y;
	}
	else{
		ll nz = yl - xl;
		string zz(nz,'0');
		// cerr<<zz<<endl;
		x = zz + x;
	}
	string res;
	for(i = x.length()-1; i>=0; i--){
		int sum = (x[i] - '0') + (y[i] - '0') + c;
		if(sum >= 10){
			sum %= 10;
			c = 1;
		}
		else
			c = 0;
		// cerr<<sum<<endl;
		res.pb(sum+'0');
	}
	if(c>0){
		res.pb('1');
	}
	for(i=res.length()-1; i>=0;i--){
		if(res[i]=='0')
			res.pop_back();
		else
			break;
	}
	reverse(res.begin(),res.end());
	// cerr<<res<<endl;
	return res;

}

int cmp(string x, string y){
	ll xl = x.length();
	ll yl = y.length();
	if(xl > yl)
		return 1;
	else if(yl > xl)
		return -1;
	else{
		ll i;
		for(i=0;i<xl;i++){
			if(x[i] > y[i])
				return 1;
			else if(y[i] > x[i])
				return -1;
		}
		return 0;
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

	ll i,l;
	cin>>l;
	string n;
	cin>>n;
	ll best_split_length = l;
	ll best_split_cnt = 0;
	ll best_split_idx = -1;
	for(i=0;i<(l-1LL);i++){
		if(n[i+1] != '0'){
			ll tmp = best_split_length;
			best_split_length = min(best_split_length,max(i+1LL,l-i-1LL));
			if(best_split_length == tmp)
				best_split_cnt += 1;
			else{
				best_split_idx = i;
				best_split_cnt = 1;
			}
		}
	}
	string num;
	if(best_split_cnt == 1){
		num = getSum(n.substr(0,best_split_idx+1),n.substr(best_split_idx+1));
		cout<<num<<endl;
		return 0;
	}
	else{
		vector<string> big;
		vector<string> smol;
		if(best_split_idx+1LL > (l - best_split_idx - 1LL)){
			big.pb(n.substr(0,best_split_idx+1));
			smol.pb(n.substr(best_split_idx+1));
		}
		else{
			big.pb(n.substr(best_split_idx+1));
			smol.pb(n.substr(0,best_split_idx+1));
		}
		for(i=0;i<(l-1LL);i++){
			if(i!=best_split_idx && n[i+1] != '0'){
				ll sl = max(i+1LL,l-i-1LL);
				if(sl == best_split_length || sl == best_split_length+1){
					if(i+1LL > (l - i - 1LL)){
						big.pb(n.substr(0,i+1));
						smol.pb(n.substr(i+1));
					}
					else{
						big.pb(n.substr(i+1));
						smol.pb(n.substr(0,i+1));
					}
				}
			}
		}
		string ans = getSum(big[0],smol[0]);
		for(i=1;i<big.size();i++){
			string sumx = getSum(big[i],smol[i]);
			int cres = cmp(ans,sumx);
			if(cres == 1){
				ans = sumx;
			}
		}
		cout<<ans<<endl;
		return 0;
	}



return 0;
}