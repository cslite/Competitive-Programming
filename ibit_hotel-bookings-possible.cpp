//similar to finding chromatic number
//maximum simulataneous rooms required
//sorting

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector< pair<int,int> > v(arrive.size() * 2);
    int i;
    for(i=0;i<arrive.size();i++){
        v[i].first = arrive[i];
        v[i].second = 1;
    }
    for(i=0;i<depart.size();i++){
        v[arrive.size()+i].first = depart[i];
        v[arrive.size()+i].second = 0;
    }
    sort(v.begin(),v.end());
    int simul = 0;
    for(i=0;i<v.size();i++){
        if(v[i].second == 1)
            simul++;
        else
            simul--;
        // cout<<"found a_d="<<v[i].second<<" , simul ="<<simul<<"\n";
        if(simul > K){
            // cout<<"simul="<<simul;
            return false;
        }
    }
    return true;
}