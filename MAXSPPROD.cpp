//finding for each element the nearest element greater than it in O(n)
//stack , spans , interviewbit

int Solution::maxSpecialProduct(vector<int> &A) {
    vector<long long> lst;
    long long i,j;
    stack<long long> s;
    for(i=0;i<A.size();i++){
        if(s.empty()){
            s.push(i);
            lst.push_back(-1);
            continue;
        }
        if(A[i] >= A[s.top()]){
            while(!(s.empty()) && A[s.top()] <= A[i])
                s.pop();
            if(!(s.empty()))
                lst.push_back(s.top());
            else
                lst.push_back(-1);
            s.push(i);
        }
        else{
            lst.push_back(s.top());
            s.push(i);
        }
    }
    stack<long long> sr;
    vector<long long> rst(A.size());
    for(i=A.size()-1;i>=0;i--){
        if(sr.empty()){
            sr.push(i);
            rst[i] = -1;
            continue;
        }
        if(A[i] >= A[sr.top()]){
            while(!(sr.empty()) && A[sr.top()] <= A[i])
                sr.pop();
            if(!(sr.empty()))
                rst[i] = sr.top();
            else
                rst[i] = -1;
            sr.push(i);
        }
        else{
            rst[i] = sr.top();
            sr.push(i);
        }
    }
    long long x,xmax=0;
    long long m = 1000000007;
    // cout<<lst.size()<<" "<<rst.size()<<" debug\n";
    for(i=0;i<A.size();i++){
        if(lst[i] == -1 || rst[i] == -1)
            continue;
        x = lst[i] * rst[i];
        x%=m;
        xmax = x > xmax ? x : xmax;
    }
    return (int)(xmax%m);
}

//TLE SOLUTION

/*
int Solution::maxSpecialProduct(vector<int> &A) {
    int i,j;
    // vector<long long> B;
    long long mmax = 0;
    for(i=0;i<A.size();i++){
        long long x = 0;
        for(j = i-1; j>=0 ; j--){
            if(A[j] > A[i]){
                x = j;
                break;
            }
        }
        long long y = 0;
        for(j=i+1;j<A.size();j++){
            if(A[j] > A[i]){
                y = j;
                break;
            }
        }
        x*=y;
        x%=1000000007;
        mmax = x>mmax ? x : mmax;
        // B.push_back(x);
    }
    return (int)mmax;
}
*/