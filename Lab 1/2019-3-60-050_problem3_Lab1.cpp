#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int insertionSort(int arr[], int n)
{
    int i, key,key2,temp, j;
	for(i = n-1; i>0; i--){
        key = arr[i];
        key2 = arr[i-1];
        if(key < key2){
                temp = key;
            arr[i] = key2;
            arr[i-1] = temp;
        }else{
            return 1;
        }
	}
}


int main(){
    int n,c=-1,a,j,b=0;
    int arr[c];
    set<int> s1;

    while(true){
        scanf("%d",&n);
        if(n == 0){
            scanf("%d",&a);
            if(s1.insert(a).second){
                c++;
                s1.insert(a);
                arr[c] = a;
                insertionSort(arr, c);
            }
        }else{
            scanf("%d",&a);
            for(int i=0; i<c; i++){
                if(arr[i] == a){
                    b++;
                }
            }
             if(b>0){
                    b=0;
                    printf("already have the value\n");

                }else{
                    b=0;
                    printf("not found");
                }
        }
    }
}
