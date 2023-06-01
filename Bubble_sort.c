#include<stdio.h>
void Bubble_sort(int Arr[],int n){
    for(int i =0;i<n;i++){
       
       for(int j =0;j<(n-1)-i;j++){
          if(Arr[j]>Arr[j+1]){
            int temp = Arr[j];
            Arr[j] = Arr[j+1];
            Arr[j+1]= temp;

          }
       }
    }
}
int main(){
    int arr[10]={5,3,1,4,9,8,6,0,5,2};
    Bubble_sort(arr,10);
    for(int i =0;i<10;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}