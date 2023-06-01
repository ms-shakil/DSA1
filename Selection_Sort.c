#include<stdio.h>
void Selection_sort(int Arr[],int n){
    for(int i =0;i<n;i++){
       int min = i;
       for(int j =i+1;j<n;j++){
          if(Arr[j]<Arr[min]){
            int temp = Arr[j];
            Arr[j] = Arr[min];
            Arr[min]= temp;

          }
       }
    }
}
int main(){
    int arr[10]={5,3,1,4,9,8,6,0,5,2};
    Selection_sort(arr,10);
    for(int i =0;i<10;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}