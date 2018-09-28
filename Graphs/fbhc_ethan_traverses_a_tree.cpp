//https://www.facebook.com/hackercup/problem/232395994158286/
//tree , DFS , post-order , pre-order, Facebook HackerCup 2018

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"
#define pb push_back
#define ll long long
long long zz;
#define tracelist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<x[zz]<<" "; cerr<<endl;
#define tracepairlist(x,x1,xn) for(zz=x1;zz<xn;zz++) cerr<<"("<<x[zz].ff<<","<<x[zz].ss<<") "; cerr<<endl;

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("ethan_traverses_a_tree.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif

	IOS;

	int ti,t;
	cin>>t;
	for(ti=1;ti<=t;ti++)
	{
		long i,n,k;
		cin>>n>>k;
		long tree[n+1][2];
		for(i=1;i<=n;i++)
		{
			cin>>tree[i][0]>>tree[i][1];
		}
		vector <bool> v_post(n+1,0);
		vector <bool> v_pre(n+1,0);
		vector <long> post_arr(n);
		vector <long> pre_arr(n);
		v_post[0] = true;	//so that parents with no children get visited automatically
		stack <long> s;
		s.push(1);
		long pre_idx = 0;
		long post_idx = 0;
		long idx_array[n+1][2];
		while(!s.empty())
		{
			long top = s.top();
			if(!v_pre[top]){
				v_pre[top] = true;
				pre_arr[pre_idx]= top;
				idx_array[top][0] = pre_idx;
				pre_idx++;

			}
			if((tree[top][1]) != 0)
				if(!v_post[tree[top][1]])	s.push(tree[top][1]);
			if(tree[top][0] != 0)
				if(!v_post[tree[top][0]])	s.push(tree[top][0]);
			if(v_post[tree[top][1]] && v_post[tree[top][0]])
			{
				s.pop();
				v_post[top] = true;
				post_arr[post_idx] = top;
				idx_array[top][1] = post_idx;
				post_idx++;
			}

		}
		long label[n+1] = {0};
		long lctr = 1; 
		bool kpaar = false;
		bool flag = false;
		for(i=0;i<n;i++)
		{
			long post_i = post_arr[i];
			long pre_i = pre_arr[i];
			if(label[pre_i] == label[post_i])
			{
				if(label[pre_i] != 0)
					continue;
				else
				{
					//both r 0
					label[pre_i] = lctr;
					label[post_i] = lctr;
					bool visited[n+1] = {0};

					s.push(idx_array[pre_i][1]);
					visited[pre_i] = true;
					if(!visited[post_i]){
						s.push(idx_array[post_i][0]);
						visited[post_i] = true;
					}
						
					
					while(!s.empty())
					{
						long idx = s.top();
						s.pop();
						pre_i = pre_arr[idx];
						post_i = post_arr[idx];
						if(label[pre_i] == label[post_i])
						{
							if(label[pre_i] == 0)
							{
								label[pre_i] = lctr;
								label[post_i] = lctr;
							}
							else if(label[pre_i] != lctr)
							{
								cout<<"Case #"<<ti<<": Impossible"<<endl;
								flag = true;
								break;
							}
						}
						else if(label[pre_i] == 0)
						{
							if(label[post_i] != lctr)
							{
								//impossible
								cout<<"Case #"<<ti<<": Impossible"<<endl;
								flag = true;
								break;
							}
							else
							{
								label[pre_i] = lctr;
							}
						}
						else if(label[post_i] == 0)
						{
							if(label[pre_i] != lctr){
								//impossible
								cout<<"Case #"<<ti<<": Impossible"<<endl;
								flag = true;
								break;
							}
							else
								label[post_i] = lctr;
						}
						else{
							//impossible
							cout<<"Case #"<<ti<<": Impossible"<<endl;
							flag = true;
							break;
						}
						if(!visited[pre_i]){
							s.push(idx_array[pre_i][1]);
							visited[pre_i] = true;
						}
						if(!visited[post_i]){
							s.push(idx_array[post_i][0]);
							visited[post_i] = true;
						}

					}
					if(flag)
						break;
					lctr++;
					if(lctr > k)
					{
						kpaar = true;
						lctr = 1;
					}
				}
			}
			else
			{
				//impossible
				cout<<"Case #"<<ti<<": Impossible"<<endl;
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			if(kpaar){
				cout<<"Case #"<<ti<<": ";
				for(i=1;i<=n;i++)
					cout<<label[i]<<" ";
				cout<<endl;
			}
			else{
				cout<<"Case #"<<ti<<": Impossible"<<endl;
			}
		}


	}


return 0;
}
