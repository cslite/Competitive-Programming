//O(n) time and O(1) Space solution
//using original array as storage of found numbers

int Solution::firstMissingPositive(vector<int> &A) {
    int n = A.size();
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i] <= 0 || A[i] >= n+1){
            A[i] = 0;
        }
    }
    for(i=0;i<n;i++){
        int x;
        if(A[i] > n)
            x = A[i] - (n+1);
        else
            x = A[i];
        if(x > 0){
            if(A[x-1] <= n)
                A[x-1] += (n+1);
        }
    }
    for(i=0;i<n;i++){
        if(A[i] <= n)
            break;
    }
    return i+1;
}


//Not optimal solution
/*
int Solution::firstMissingPositive(vector<int> &A) {
    sort(A.begin(),A.end());
    int i=0;
    while(i<A.size()){
        if(A[i]<=0)
            i++;
        else
            break;
    }
    if(i == A.size()){
        return 1;
    }
    int ans = 0;
    for(;i<A.size();i++){
        if(A[i] == ans+1)
            ans++;
        else if(A[i] > ans){
            return ++ans;
        }
    }
    return ans+1;
}
*/