vector<int> pf;//Stores all the prime factors of a number
//O(sqrt(N))
void primeFactor(int N){
 for(int i=2; i*i <=N;i++){
     if(N%i==0){
    pf.push_back(i);//only Single prime factors
     while(N%i==0){
      //All prime factors.
       N=N/i;
     }
  }
//i*i-> works only for Non Prime Numbers 
//if after dividing at any step our number is prime so we can not get any pf <sqrt(i)
if(n>1){
    pf.push_back(n);
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
