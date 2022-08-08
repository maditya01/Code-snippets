//Heap Sort 
// I) build MAX Heap using heapify method
// II) delete element one by one then call heapify method.
// ->0 based index l=2*i+1 ,r=2*i+2
// ->1 based index l=2*i,r=2*i+1
  
class Solution
{
    
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i){
        
         int largest = i;
         int l = 2*i+1;
         int r = 2*i+2;
         if(l<n and arr[l]> arr[largest]){
             largest=l;
         }
         if(r<n and arr[r]> arr[largest]){
             largest=r;
         }
         if(i!=largest){
             swap(arr[i],arr[largest]);
             heapify(arr,n,largest);
         }
         
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i= (n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
             
    }
    public:
  //Heap Sort.   
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--){
             swap(arr[i],arr[0]);
             heapify(arr,i,0);
        }
    }
};
