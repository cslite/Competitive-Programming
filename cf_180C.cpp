#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

ll chhote[100001] = {0};
ll bade[100001] = {0};

ll rightCost(int i, int end){
	//i is not included
	//end is also not included
	return bade[end-1] - bade[i];
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
	string s;
	cin>>s;

	int bp,i,end = s.length();
	chhote[0] = islower(s[0]) ? 1 : 0;
	bade[0] = isupper(s[0]) ? 1 : 0;
	
	for(i=1;i<end;i++){
		chhote[i] = chhote[i-1];
		bade[i] = bade[i-1];
		if(islower(s[i])){
			chhote[i]++;
		}
		else
			bade[i]++;
	}
	ll lc = end;	//least cost
	lc = bade[end-1];
	for(bp=0;bp<end;bp++){
		lc = min(lc,chhote[bp] + rightCost(bp,end));
	}

	cout<<lc<<endl;



return 0;
}