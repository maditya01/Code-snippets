//WHEN TO APPLY THIS THING.



1.
// Intialise a direction array
//Assuming Only in 4 direction movement is possible. can be in 8 direction.
// int dx[]={-1,1,0,0}
// int dy[]={0,0,1,-1}

2.
//if ask some minimum distance type in question TAKE a matrix dp to store 
//if not ask then continue.

3.
// take a visited matrix to confirm a cell that is visited or not.

4.
// push initial value in queue for single source it is only one
// for multiple source this value is multiple insert all value in queue.
//initialise intial value in all the matrix taken .
  
  while(!q.empty()){
   // take front values.
    //q.pop();
    
for(int i=0;i<4;i++){
    int newX=x+dx[i];
    int newY=y+dy[i];
   if(check validity of this index){
        //push values in queue with due respect condition.
        q.push({newX,newY});
     vis[newX][newY]=true;
//      update your matrix here.
   }
 }  
  } 
