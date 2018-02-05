int swap(int arr[], int posA, int posB){
    int temp = arr[posA];
    arr[posA] = arr[posB];
    arr[posB] = temp;
    return 0;
}

int BubbleSort(int arr[], int size, bool smallestToLargest = true){
    bool swapped;
    if (smallestToLargest){
        for (int i = 0; i < size; i++){
            swapped = false;
            for (int j = 1; j < size - i; j++){
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j - 1, j);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }else{
        for (int i = 0; i < size; i++){
            swapped = false;
            for (int j = 1; j < size - i; j++){
                if (arr[j] > arr[j - 1]) {
                    swap(arr, j - 1, j);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
    return 0;
}

