//https://www.spoj.com/problems/BUGLIFE/
//DFS , GRAPH

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

#define sci(t) scanf("%d",&t)
#define scl(t) scanf("%ld",&t)

vector < vector<int> > v(2001);

bool checkhomo(int nbugs)
{
	//DFS Algorithm
	//bool visited[nbugs+1];
	int mf[2001] = {0};
	stack <int> s;
	
	int i;
	
for(int x=1; x<=nbugs;x++)
{
	if(x==1)
	{
		s.push(1);
		mf[1] = 1;	
	}
	else
	{
		if(mf[x]!=0)
		{
			continue;
		}
		else
		{
			s.push(x);
			mf[x] = 1;
		}
	}
	
	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		for(i=0;i<v[top].size();i++)
		{
			
			if(mf[v[top][i]] == 0)
			{
				s.push(v[top][i]);
				mf[v[top][i]] = (mf[top] * -1);	
			}
			else if(mf[v[top][i]] != mf[top])
			{
				continue;
			}
			else
			{
				return true;
			}
		}

	}
}
	
	return false;

}

int main()
{
	long t;
	scl(t);
	for(long tc = 1 ; tc<=t; tc++)
	{
		int nbugs,a,b;
		long nintr;
		sci(nbugs);	scl(nintr);
		long i;
		for(i=1;i<=nbugs;i++)
		{
			v[i].clear();
		}
		for(i=1;i<=nintr;i++)
		{
			sci(a);	sci(b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		printf("Scenario #%ld:\n",tc);
		if(checkhomo(nbugs))		//DFS Algorithm
		{
			
			printf("Suspicious bugs found!\n");
		}		
		else
		{
			printf("No suspicious bugs found!\n");
		}
	}
}
