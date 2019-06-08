vector<string> Solution::fullJustify(vector<string> &A, int B) {
    int n = A.size();
    vector<string> ans;
    if(A.empty())
        return ans;
    int i = -1;
    
    while(1){
        int si = ++i;
        int currlen = A[i].length();
        while(i < n-1){
            if((A[i+1].length() + 1 + currlen) <= B){
                currlen += A[i+1].length() + 1;
                i++;
            }
            else
                break;
        }
        if(i != n-1){
            int xtra_blanks = B - currlen;
            int pits = i - si;
            int xtra_per_pit = 0;
            int num_xtra_plus1 = 0;
            if(pits != 0){
                xtra_per_pit = xtra_blanks / pits;
                num_xtra_plus1 = xtra_blanks % pits;
            }
            
            string s(A[si]);
            for(int j=si+1;j<=i;j++){
                //string(count,char)
                s.push_back(' '); //+= " ";
                if(xtra_per_pit){
                    string x(xtra_per_pit,' ');
                    s += x;
                }
                if(num_xtra_plus1){
                    s.push_back(' '); //s += " ";
                    num_xtra_plus1--;
                }
                s += A[j];
            }
            // cout<<s<<"\n";
            while(s.length() < B)
                s.push_back(' ');
            ans.push_back(s);
        }
        else{
            string s(A[si]);
            for(int j=si+1;j<=i;j++){
                s.push_back(' '); //s += " ";
                s += A[j];
            }
            while(s.length() < B)
                s.push_back(' ');
            ans.push_back(s);
            break;
        }
    }
    return ans;
    
}
