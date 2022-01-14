//Initially sabko Prime Man Lo.
//MULTIPLES ME ITERATE KARTE HAIN
//AK NUMBER LO uske Multiples me iterate karo aur sab ko false Karte Jao

vector<bool> isPrime(N, 1);  //isPrime[i]-> i is prime or not
vector<int> lp(N); //lp[i]-> //lowest prime number by which i is Divisible
vector<int> hp(N); //hp[i]-> //highest prime number by which i is Divisible

void seive() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      lp[i]=hp[i]=i;
      for (int j = i * 2; j < N; j += i) {
        isPrime[j] = 0;
        hi[j]=i;
        if(lp[j]==0){
        lp[j]=i;
        }
      }
    }
  }
}
