//Taken a array  which tells that i is a prime or not.
//Every Number can be represented as  p1^a*p2^b*p3^c*p4^d---continue
//where p1,p2,p3,p4 are prime numbers

vector<bool> isPrime(N, 1);  //isPrime[i]-> i is prime or not
vector<int> lp(N); //lp[i]-> //lowest prime number by which i is Divisible
vector<int> hp(N); //hp[i]-> //highest prime number by which i is Divisible
void seive() {
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i < N; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j < N; j += i) {
        isPrime[j] = 0;
      }
    }
  }
}
