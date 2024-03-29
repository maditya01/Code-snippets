Analysis of quick sort algorithms-> Quick sort is a divide and conquer algorithm.
Average Case: T(n) = T(n/10) + T(9n/10) + O(N) = O(NlogN)
Best Case: 
Worst Case: if we choose the maximum or minimum element as the pivot element then T.C = T(n) = T(n-1) + O(N) = O(N^2)


int partition (int arr[], int low, int high){
       int X=arr[low];//low-> Pivot Point Man rhe hain
      //At the End before X all the values are less than X After X all the Values are greater than X.
       int i=low;
       for(int j=low+1;j<=high;j++){
           if(arr[j]<=X){
               i++;
               swap(arr[i],arr[j]);
           }
       }
       swap(arr[low],arr[i]);
       return i;
}
void quickSort(int arr[], int low, int high){
        if(low>=high) return;
        int j = partition(arr,low,high);
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
}
