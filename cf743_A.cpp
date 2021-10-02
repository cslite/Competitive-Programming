#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define rep(i,a) for(i = 0 ; i < a ; i++)
#define whln(t) while(t--)
#define whlp(t) while(t++)

int main(){
	#ifndef ONLINE_JUDGEz
    // for getting input from input.txt
    freopen("../input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("../output.txt", "w", stdout);
	#endif
	ll t ;
	cin>>t;
	whln(t){
	
				// string s;
		int n;
		cin>>n;
		std::vector<char> v(n);
		int sum = 0;
		for(int i = 0 ; i < n-1; i++){
			cin>>v[i];
			sum+=v[i]-'0';
			if(v[i]-'0')
				sum++;
		}
		char c;
		cin>>c;
		sum+=c-'0';
		// for()
		cout<<sum<<"\n";
	}


    //your code here



    return 0;
}

//   *****  *******   !
//   *		     *    !
//   ***       *      !
//   *       *        !
//   *****  *******   !