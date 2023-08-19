First Pass: 
The largest element is placed in its correct position, i.e., the end of the array.
Second Pass: 
The second largest element is placed in its correct position,
Third Pass:
The third largest element is placed in its correct position.
And so on.
//each time greatest element will be at its correct position.
//Right side part of the array will be sorted.
It is a stable sorting algorithm, meaning that elements with the same key value maintain their relative order in the sorted output.
//Best time complexity will be O(N) we have to understand.

void bubbleSort(int arr[], int n){
        for(int i=0;i<n;i++){
            bool swaped = false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swaped = true;
                }
            }
            if(swaped==false){
                break;
            }
        }  
  }
