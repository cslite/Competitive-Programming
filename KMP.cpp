//tutorial- https://medium.com/@giri_sh/string-matching-kmp-algorithm-27c182efa387

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define endl "\n"
#define pb push_back
#define ll long long

vector<int> createLPS(string w){
	//w is the string for which aux array is to be created
	//w is the string which is to be searched in a larger string

	vector<int> aux(w.length(),0);

	int m=0;	//m can be viewed as index of first mismatch
	int i=1;	//as aux[0] = 0
	
	while(i<w.length()){
		if(w[i] == w[m]){
			m++;
			aux[i] = m;
			i++;
		}	//prefix = suffix till m-1
		else if(w[i] != w[m] && m != 0){
			m = aux[m-1];
		}	//check the index of previous possible prefix
		else{
			aux[i] = m;
			i++;
		}	//m=0 and there was a mismatch
	}

	return aux;
}

int findPattern(string text, string pattern){
	vector<int> aux = createLPS(pattern);
	int i = 0; //counter for pattern
	int j = 0; //counter for text
	while(j<text.length()){
		if(text[j] != pattern[i]){
			if(i==0){
				j++;
			}	//starting pattern matching again from the next character in text
			else{
				i = aux[i-1];
			}	//get the index from where we have to start comparing next
		}
		else{
			i++;
			j++;
			if(i == pattern.length()){
				//when pattern is found
				return (j-i);
			}
			//to find more occurrences, use the below statement
			//i = aux[i-1];
		}
	}
	return -1;
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

	string text,word;
	cin>>text;
	cin>>word;
	cout<<findPattern(text,word)<<endl;


return 0;
}