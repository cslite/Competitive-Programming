#include <bits/stdc++.h>
#include<string.h>
using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define Max(x,y,z) max(x,max(y,z))
#define Min(x,y,z) min(x,min(y,z))
#define fr(i,s,e) for(i=s;i<e;i++)
#define rf(i,s,e) for(i=s-1;i>=e;i--)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define ff first
#define ss second
//#define int   long long
#define ll   long long
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define vl vector<long long>
#define inf (1LL<<61)
#define vi vector<int>
#define vii vector< vector<int> >
#define vll vector< vector<long long> >
#define vpi vector< pair<int,int> >
#define vpl vector< pair<ll,ll> >
#define viii vector< vector<vector<int> > >
typedef pair<pair<int, int>,int> P;
#define cd complex<double>
#define PI 4*atan(1)
#define mod %1000000007
#define pi 3.14159265358979323846//20 decimals
#define ld long double

int main()
{
    FAST;
	ll n, i, j;
	cin >> n;
	ll a[n], b[n];
	ll loc[n+1];
	fr(i,0,n)
	{
		cin >> a[i];
		if(a[i] != 0)
			loc[a[i]] = -1;
	}
	fr(i,0,n)
	{
		cin >> b[i];
		if(b[i] != 0)
			loc[b[i]] = i;
	}
	sort(a, a+n);
	ll tmp = b[n-1];
	ll st = 1;
	if(tmp != 0)
	{
		j = n - 1;
		while(tmp > 0)
		{
			if(b[j] != tmp)
				break;
			j--;
			tmp--;
		}
		if((tmp == 0))
		{
			if(b[n-1] == n)
				st = n+1;
			else if((loc[b[n-1] + 1] == -1))
				st = b[n-1] + 1;
		}
	}
	ll ans = 0;
	ll t1 = 0;
	ll rep = 0;
	fr(i,st,n+1)
	{
		if((loc[i] == -1)||(loc[i] - t1 <= i - 2 - st + 1))
			continue;
		else
		{
			if(st != 1)
			{
				ans = 0;
				st = 1;
				t1 = 0;
				rep = 1;
				break;
			}
			if(i == 1)
			{
				ans += loc[i] - t1 + 1;
				t1 += loc[i] - t1 + 1;
			}	
			else
			{
				ans += loc[i] - t1 - i + 2;
				t1 += loc[i] - t1 - i + 2;
			}
		}
//		trace3(i, t1, ans);
	}
	if(rep == 1)
	{
		fr(i,st,n+1)
		{
			if((loc[i] == -1)||(loc[i] - t1 <= i - 2))
				continue;
			else
			{
				if(i == 1)
				{
					ans += loc[i] - t1 + 1;
					t1 += loc[i] - t1 + 1;
				}	
				else
				{
					ans += loc[i] - t1 - i + 2;
					t1 += loc[i] - t1 - i + 2;
				}
			}
//			trace3(i, t1, ans);
		}
	}
	ans += n - st + 1;
	cout << ans;
}