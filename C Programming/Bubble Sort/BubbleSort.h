int swap(int arr[], int posA, int posB){
    int temp = arr[posA];
    arr[posA] = arr[posB];
    arr[posB] = temp;
    return 0;
}

int BubbleSort(int arr[], int size, bool smallestToLargest = true){
    int timesToRun = size;
    bool swapped;
    if (smallestToLargest){
        while(timesToRun-- > 0){
            swapped = false;
            for (int j = 1; j < size; j++){
                if (arr[j] < arr[j - 1]) {
                    swap(arr, j - 1, j);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }else{
        while(timesToRun-- > 0){
            swapped = false;
            for (int j = 1; j < size; j++){
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

