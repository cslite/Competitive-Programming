/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int i = 0,j;
    while(i< intervals.size()){
        if(intervals[i].end < newInterval.start)
            i++;
        else
            break;
    }
    vector<Interval> v;
    if(i == intervals.size()){
        //this will be inserted at the end
        for(i=0;i<intervals.size();i++){
            v.push_back(intervals[i]);
        }
        v.push_back(newInterval);
        return v;
    }
    if(intervals[i].start > newInterval.end){
        //we need to disjointly add this
        for(j=0;j<i;j++)
            v.push_back(intervals[j]);
        v.push_back(newInterval);
        for(j=i;j<intervals.size();j++)
            v.push_back(intervals[j]);
        return v;
    }
    Interval x;
    for(j=0;j<i;j++){
        v.push_back(intervals[j]);
    }
    if(newInterval.start < intervals[i].start)
        x.start = newInterval.start;
    else
        x.start = intervals[i].start;
    while(i<intervals.size() && intervals[i].end < newInterval.end)
        i++;
    if(i==intervals.size()){
        //sab kucch merge krdiya
        x.end = newInterval.end;
        v.push_back(x);
        return v;
    }
    if(intervals[i].start > newInterval.end){
        x.end = newInterval.end;
        v.push_back(x);
        v.push_back(intervals[i]);
    }
    else{
        x.end = intervals[i].end;
        v.push_back(x);
    }
    for(j=i+1;j<intervals.size();j++)
        v.push_back(intervals[j]);
    return v;
}     
    