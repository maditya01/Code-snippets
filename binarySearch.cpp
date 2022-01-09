bool check(input_arguments){
 //input_arguments me minimum value ya maximum value hi ayegi
//Time complexity o(logN) or you can do  o(N) according to question
}


int lo= lowest possible value in range, hi=  highest possible value in range,ans;
//TC-> O(logN)*O(checkFunction)
while(lo<=hi){
int mid= lo+(hi-lo)/2;
  if(check(mid)){
 //Minimum poocha hai -> hi=mid-1
 //Maximum Poocha hai-> lo=mid+1
    ans=mid;
 }else{
  //Update hi,lo according to questions  
 //Minimum poocha hai -> lo=mid-1
 //Maximum Poocha hai-> hi=mid-1 
  
}
  
  


