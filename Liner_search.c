#include<stdio.h>
void Liner_search(int Arr[],int n,int val){
    int ind = -1;
    for(int i =0;i<n;i++){
       if(Arr[i]==val){
        ind = i;
        break;
       }
    }
    if(ind !=-1){
        printf("Find it . and index number is %d",ind);
    }else{
        printf("Not Found.");
    }
}
int main(){
    int arr[10]={5,3,1,4,9,8,6,0,5,2};

    Liner_search(arr,10,8);

    return 0;
}