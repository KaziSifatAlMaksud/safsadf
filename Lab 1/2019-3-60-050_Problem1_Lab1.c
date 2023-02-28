#include<stdio.h>
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
            c++;
        }

        if(f == 1){
            printf("value already in the array try another value\n");
            f = 0;
        }
        }

    if(i==1){
        for(int z=0;z<c;z++){
            if(a[z]== j){
                f = 1;
            }
        }
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
