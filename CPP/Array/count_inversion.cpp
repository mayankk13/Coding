class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    
    long long int merge(long long int arr[], long long int low, long long int mid, long long int high) {
        long long int n1 = mid - low + 1;
        long long int n2 = high - mid;
        
        long long int count = 0;
        
        long long int left[n1];
        long long int right[n2];
        
        for (long long int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for (long long int i = 0; i < n2; i++) {
            right[i] = arr[mid + i + 1];
        }
        
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
                k++;
            }
            else {
                arr[k] = right[j];
                j++;
                k++;
                count += n1 - i; // Increment count when an inversion is found
            }
        }
        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
        
        return count;
    }
    
    long long int mergeSort(long long int arr[], long long int low, long long int high) {
        long long int count = 0;
        if (low >= high) {
            return count;
        }
        long long int mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid); // left half array
        count += mergeSort(arr, mid+1, high); // right half array
        count += merge(arr, low, mid,  high); // merge sorted halves
        
        return count;
    }
    
    long long int numberOfInversion(long long int arr[], long long int n) {
        return mergeSort(arr, 0, n-1);
    }
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        // Your Code Here
        long long int count = numberOfInversion(arr, N);
        
        return count;
    }

};