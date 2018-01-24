/*@NanoBit*/

bool CheckValid(char c){
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

bool CheckValid(int a){
    return (1 <= a && a <= 100);
}

int Count(char list[]){
    int count = 0;
    while(true){
        char temp = list[count];
        if (CheckValid(temp)) {
            count++;
        }else break;
    }
    return count;
}

int Count(int arr[]){
    int count = 0;
    while(true){
        int temp = arr[count];
        if (CheckValid(temp)) {
            count++;
        }else break;
    }
    return count;
}

int Count(char list[][10]){
    int count = 0;
    while(true){
        char temp = list[count][0];
        if (CheckValid(temp)) {
            count++;
        }else break;
    }
    return count;
}

int Count(int arr[][2]){
    int count = 0;
    while(true){
        int temp = arr[count][0];
        if (CheckValid(temp)) {
            count++;
        }else break;
    }
    return count;
}