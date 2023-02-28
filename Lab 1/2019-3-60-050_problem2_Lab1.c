
#include<stdio.h>
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int i,j;
    int c=0;
    int f=0;
    int a[100];
for(;;){
    scanf("%d",&i);
    scanf("%d",&j);
    if(i==0){
        for(int k=0;k<c;k++){
          if(a[k]== j){
            f = 1;
          }
        }

        if (f == 0 ){
            a[c]=j;
            printf("value successfull insert\n");
            insertionSort(a, c);
            c++;
        }
        if(f == 1){
            printf("value already in the array try another value\n");
            f = 0;
        }
        }
    if(i==1){
        printf("array: [");
        for(int z=0;z<c;z++){
            printf(" %d ",a[z]);
            if(a[z]== j){
                f = 1;
            }

        }
        printf("]\n");
        if (f == 1){
        printf("already have the value\n");
        f = 0;
        }
        else{
            printf("not found\n");
        }

    }

}
}
