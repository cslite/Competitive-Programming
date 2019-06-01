/*
Goldbach's conjecture
Every even integer greater than 2 can be expressed as the sum of two primes.
The conjecture has been shown to hold for all integers less than 4 × 10^18, but remains unproven despite considerable effort.
*/

vector<int> Solution::primesum(int A) {
    vector<bool> primes(A+1,1);
    primes[0] = primes[1] = 0;
    int i,j;
    for(i=2;i<=A;i++){
        for(j=2;i*j < A; j++){
            primes[i*j] = 0;
        }
    }
    vector<int> p;
    for(i=0;i<A+1;i++){
        if(primes[i])
            p.push_back(i);
    }
    for(i=0;i<p.size();i++){
        int rem = A - p[i];
        int idx = lower_bound(p.begin(),p.end(),rem) - p.begin();
        if(idx < p.size() && p[idx] == rem){
            vector<int> ans;
            ans.push_back(p[i]);
            ans.push_back(p[idx]);
            return ans;
        }
    }
}
