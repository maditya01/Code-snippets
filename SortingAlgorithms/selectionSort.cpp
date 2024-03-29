//First select index i then loop from  i+1 to n to find the minimum value index and then swap that index with index i.
//Left part is already sorted
/* Advantages of Selection Sort Algorithm
   Simple and easy to understand.
   Works well with small datasets.*/
Does not work well on large datasets.
Does not preserve the relative order of items with equal keys which means it is not stable.

The worst-case time complexity of the Insertion sort is O(N^2)
The average case time complexity of the Insertion sort is O(N^2)
The time complexity of the best case is O(N^2).
   
int N;
    int select(int arr[], int i){
         int ind=i;
            for(int j=i+1;j<N;j++){
              if(arr[j]<arr[ind]){
                    ind = j;
              }
            }
     return ind;
    }
     
    void selectionSort(int arr[], int n)
    {
        N = n;
       for(int i=0;i<n;i++){
            int ind = select(arr,i);
            swap(arr[i],arr[ind]);
     }

    }
