//correct but gives segfault on interviewbit
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i;
    int maxnum = A[0];
    for(i=0;i<A.size();i++){
        if(A[i] > maxnum)
            maxnum = A[i];
    }
    int bits = log2(maxnum) + 1;
    for(i=0;i<A.size();i++){
        // cout<<"A[i]="<<A[i];
        A[i] = A[i]<<bits;
        // cout<<" A'[i]="<<A[i]<<"\n";
    }
    for(i=0;i<A.size();i++){
        A[i] += (A[A[i]>>bits])>>bits;
    }
    int ndr = 1;
    for(i=1;i<bits;i++){
        ndr += (1<<i);
    }
    // cout<<"bits="<<bits<<" ndr="<<ndr<<"\n";
    for(i=0;i<A.size();i++){
        // cout<<"A[i]="<<A[i];
        A[i] = A[i]&ndr;
        // cout<<" A'[i]="<<A[i]<<"\n";
    }
    
}
