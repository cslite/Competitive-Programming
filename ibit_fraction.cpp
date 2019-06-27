string Solution::fractionToDecimal(int A, int B) {
    int sign = 1;
    if(A==0 || B==0)
        return "0";
    if(A<0 && B<0)
        sign = 1;
    else if(A<0 || B<0)
        sign = -1;
    long long a,b;
    a = abs(A);
    b = abs(B);
    string res;
    if(sign == 1)
        res = "";
    else
        res = "-";
    map< pair<long long,long long>, int > mp;
    int si;
    
    long long q = a/b;
    long long rem = a%b;
    res.push_back((char)(q + '0'));
    if(rem)
        res.push_back('.');
    a = rem*10;
    while(rem != 0){
        si = res.length();
        pair<long long, long long> p(a,b);
        auto itr = mp.find(p);
        if(itr == mp.end()){
            mp[p] = si;
        }
        else{
            res.insert(mp[p],1,'(');
            res.push_back(')');
            break;
        }
        q = a/b;
        rem = a%b;
        res.push_back((char)(q+'0'));
        a =  rem*10;
    }
    return res;
}
