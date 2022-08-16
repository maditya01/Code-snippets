 //2-d array Given hai . envelop given hain ak ke upar sab rkhna hai
//Big envelop ke inside small envelop rakh sakte ho width, height given hai every envelop ke.

//pahle 1-d array ka binary search wala approach kar lo whi logic yha par legega.

// width*height given hai width ko increasing order me sort kar lo when width are equcal then height ke decreasing  oder me sort kar lo

//Now Width ko bhool jao aisa mano ki one d array hai with values as height of the array.

class Solution {
public:
    static bool cmp(vector<int>& v1,vector<int>& v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    
    vector<int> lis;
    
    int maxEnvelopes(vector<vector<int>>& e) {        
        sort(e.begin(),e.end(),cmp);
     
     //Jaisa One D Array me karte hain.
     //lower bound karne par value mil jaye to update kar do
     //cross kar jaye to push kar do val ko inside LIS array.
     
        lis.push_back(e[0][1]);
        
        for(int i=1;i<e.size();i++){           
               auto it= lower_bound(lis.begin(),lis.end(),e[i][1]);
              if(it!=lis.end()){
                  *it = e[i][1];
              }else{
                  lis.push_back(e[i][1]);
              }             
        }
        
        return lis.size();        
    }
};






