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
	int k,a,b;
	cin>>k>>a>>b;
	string s;
	cin>>s;
	int chars_per_line = s.length() / k;
	int extra_chars = s.length() - (chars_per_line*k);
	// cerr<<chars_per_line<<" "<<extra_chars<<endl;
	if(chars_per_line < a || chars_per_line > b || (extra_chars > 0 && chars_per_line+1 > b)){
		cout<<"No solution"<<endl;
		return 0;
	}
	int i = 0,j;
	while(extra_chars){
		for(j=0;j<chars_per_line+1;j++){
			cout<<s[i+j];
		}
		cout<<endl;
		extra_chars--;
		k--;
		i+=j;
	}
	while(k){
		for(j=0;j<chars_per_line;j++){
			cout<<s[i+j];
		}
		cout<<endl;
		k--;
		i += j;
	}



return 0;
}