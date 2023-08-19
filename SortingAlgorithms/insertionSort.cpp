//Here we have to remember the concept of inserting element at its correct position.
//Take element i and insert it at correct postion from i-1 to 0. 
//If arr[j] is greater than key then shift one right side.

The worst-case time complexity of the Insertion sort is O(N^2)
The average case time complexity of the Insertion sort is O(N^2)
The time complexity of the best case is O(N).

Basically, Insertion sort is efficient for small data values
Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already partially sorted.
Yes, insertion sort is a stable sorting algorithm.

  
void insert(int arr[], int i){  
        int key = arr[i];
        int j = i-1;
  //Because left part is already sorted so if arr[j] <key that means element before than arr[j] is also <key so we don't need to check that element.
            while(j>=0 && arr[j]>key){
               arr[j+1] = arr[j];
                j--;
            }
        arr[j+1] = key;
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n){
         for(int i=1;i<n;i++){
             insert(arr,i);
         }
    }
