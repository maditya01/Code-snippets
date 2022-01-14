//Find all the Devisors of a Given Number[N] 1->N me traverse kar do jo bhee i N ko divide kar de wo Devisor
//N ko kaun kaun Devide kar sakta hai

for(int i=1;i*i<=N;i++){
 if(n%i==0){
 cout<<i<<" ";
   if(n/i!=i){
     cout<<n/i<<endl;
   }
 }
}
