bool check(input_arguments){
 
 //Each Time This Function will Change
 
 //input_arguments me minimum value ya maximum value hi ayegi
//Time complexity o(logN) or you can do  o(N) according to question
}


int lo= lowest possible value in range, hi=  highest possible value in range,ans;

//The most important thing BS lagana kis range par hai.
// kis attribute ko range me lena hai.isi par dimaak lagana hai


//TC-> O(logN)*O(checkFunction)
while(lo<=hi){
int mid= lo+(hi-lo)/2;
  if(check(mid)){
 //Minimum poocha hai -> hi=mid-1
 //Maximum Poocha hai-> lo=mid+1
    ans=mid;
 }else{
  //Update hi,lo according to questions  
 //Minimum poocha hai -> lo=mid+1
 //Maximum Poocha hai-> hi=mid-1 
  
}
  
  


