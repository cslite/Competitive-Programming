int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(n == 0)
        return 1%d;
    else if(n == 1)
        return (x+d)%d;
    else{
        long long p1 = ((long long)pow(x,n/2,d) + d) % d;
        long long p2 = ((long long)pow(x,n - ((n/2)*2),d) + d) % d;
        long long prod = ((((p1 * p1)%d)*p2) + d )%d;
        return (int)prod;
    }
}
