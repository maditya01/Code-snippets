vector<int> pf;//Stores all the prime factors of a number
//O(sqrt(N))
void primeFactor(int N){
 for(int i=2; i*i <=N;i++){
     while(N%i==0){
       pf.push_back(i);
       N=N/i;
     }
  }
//i*i-> works only for Non Prime Numbers 
if(n>1){
    pf.push_back(i);
}
}

//O(log(N))->using seive
// First Find highest prime or lowest prime of by which given number is Divisible
// using seive algo
while(N>1){
 x=hp[N];//Highest prime factor of N
 while(N%x==0){
    N=N/x;
  pf.push_back(x);
 }
}
