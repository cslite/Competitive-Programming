//binary search, dp, abab string

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

int n,k;
string s;


int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	vector<ll> acnt(n,0);
	vector<ll> bcnt(n,0);
	if(s[0] == 'a')
		acnt[0] = 1;
	else
		bcnt[0] = 1;
	int i;
	for(i=1;i<s.length();i++){
		acnt[i] = acnt[i-1];
		bcnt[i] = bcnt[i-1];
		if(s[i] == 'a')
			acnt[i]++;
		else
			bcnt[i]++;
	}
	//first try to make the sub-string with 'a'
	int sti; //start index
	int kadj = k;	//k-adjusted
	int max_score = 0;
	for(sti=0;sti<s.length();sti++){
		kadj = k;
		if(sti!=0)
			kadj += bcnt[sti-1];
		int idx = upper_bound(bcnt.begin()+sti,bcnt.end(),kadj) - (bcnt.begin());
		idx--;
		// cout<<"a.. sti="<<sti<<" score="<<(idx-sti+1)<<endl;
		max_score = max(max_score,idx-sti+1);
	}
	//now try to make sub-string with 'b'
	for(sti=0;sti<s.length();sti++){
		kadj = k;
		if(sti != 0)
			kadj += acnt[sti-1];
		int idx = upper_bound(acnt.begin()+sti,acnt.end(),kadj) - (acnt.begin());
		idx--;
		// cout<<"b.. sti="<<sti<<" score="<<(idx-sti+1)<<endl;
		max_score = max(max_score,idx-sti+1);
	}

	cout<<max_score<<endl;




return 0;
}