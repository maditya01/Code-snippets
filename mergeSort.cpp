//2 Steps
// 1.Divide the array in 2 parts
// 2.Merge Both the Parts

void merge(int *a, int start, int end){
  
    //here we have to take
    int mid = (start + end) / 2;
    //i take three pointer i,j,k
    int i = start;   //points to start
    int j = mid + 1; //points to mid+1  why Mid because 0..mid is already sorted and mid+1 to end is also already sorted.
    int k = start;   //points to temp array ke start
    int temp[100];
    while (i <= mid && j <= end){
        if (a[i] < a[j])
        {
            //temp array me a[i](small value hai) daal do
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    //if j crosses your limit.
    while (i <= mid)
    {
        temp[k++] = a[i++];
    }
    //i crosses your limit.
    while (j <= end)
    {
        temp[k++] = a[j++];
    }
    //copy all elements
    for (int p = start; p <= end; p++)
    {
        a[p] = temp[p];
    }
}
void Mergesort(int *a, int start, int end){
  
    if (start == end){
        return;
    }
    int mid = (start + end) / 2;
    //devide in to two parts
    Mergesort(a, start, mid);
    Mergesort(a, mid + 1, end);
    merge(a, start, end);
  
}
