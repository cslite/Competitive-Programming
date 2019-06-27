//READ THE QUESTION WRONG, incomplete
#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define ff first
#define ssd second
#define endl "\n"
#define pb push_back
#define ll long long
long long zz;
#define putflag(xx) cerr<<"!! flag_"<<xx<<" !!"<<endl;
#define tracelist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<x[zz]<<" "; cerr<<endl;
#define tracepairlist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<"("<<x[zz].ff<<","<<x[zz].ss<<") "; cerr<<endl;

vector<int> unocs;
string lilypad;
int n;
int ptr;

void process_unocs(){
	unocs = vector<int>();
	n = lilypad.length();
	int i;
	for(i=1;i<(n-1);i++){
		if(lilypad[i] == '.')
			unocs.pb(i);
	}
	ptr = 0;
}

bool make_last_empty(){
	if(lilypad[n-1] == '.'){
		return true;
	}
	else{
		lilypad[n-1] = '.';
		if(unocs.empty()){
			return false;
		}
		lilypad[unocs[unocs.size()-1]] = 'B';
		unocs.pop_back();
		return true;
	}
}

bool clear_at_idx(int idx){
	if(idx == n-1){		//last position was already cleared
		return true;
	}
	if(lilypad[idx] != '.'){
		if(unocs.empty() || ptr == unocs.size())
			return true;
		lilypad[unocs[ptr++]] = 'B';
		lilypad[idx] = '.';
	}
	return false;
}

bool can_it_reach(int idx){
	if(idx == n-2)	//it can't reach the adjacent finish position
		return false;
	if(lilypad[idx+1] == 'B'){
		if(clear_at_idx(idx+2))
			return true;
		return can_it_reach(idx+2);
	}
	else if(lilypad[idx+1] == '.' && lilypad[idx+2] == '.'){
		return false;
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
	int t;
	cin>>t;
	for(int ti=1;ti<=t;ti++){
		cin>>lilypad;
		process_unocs();
		if(!make_last_empty()){
			cout<<"Case #"<<ti<<": "<<"N"<<endl;
			break;
		}
	}


return 0;
}