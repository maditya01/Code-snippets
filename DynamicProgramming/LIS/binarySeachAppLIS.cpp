//Binary Search Approach Longest increasing subsequence.

//sequence ka order maintain rhega uski chinta mat karo.


int LIS(const vector<int> &A) {
    vector<int> lis;
    lis.push_back(A[0]);
    for(int i=1;i<A.size();i++){
        int val = A[i];
        auto it=lower_bound(lis.begin(),lis.end(),val);
        if(it!=lis.end()){
            *it=val;  //update with lesser value.
        }else{
            lis.push_back(val); //val is greatest in lis.
        }
    }
    return lis.size();
}
