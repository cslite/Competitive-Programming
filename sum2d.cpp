#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[5][5];
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			cin>>arr[i][j];
			if(i>0)	arr[i][j] += arr[i-1][j];
			if(j>0)	arr[i][j] += arr[i][j-1];
			if(i>0 && j>0)	arr[i][j] -= arr[i-1][j-1];
		}
	}
	int ch,sum;
	int a,b,c,d;
	do{
		cin>>ch;
		switch(ch){
			case 1:
				//(a,b) to (c,d)
				cin>>a>>b>>c>>d;
				sum = arr[c][d];
				if(a-1 >=0)
					sum -= arr[a-1][d];
				if(b-1 >=0)
					sum -= arr[c][b-1];
				if(a-1 >=0 && b-1 >= 0)
					sum += arr[a-1][b-1];
				cout<<sum<<endl;
				break;
			default:
				break;
		}
	}while(ch != -1);
return 0;
}