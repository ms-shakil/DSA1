// Online C compiler to run C program online
#include <stdio.h>
void counting_sort(int arr[],int n,int high){
    int temp[high];
    
    int arr2[n];
  
    for(int i =0;i<=high;i++){
        temp[i]=0;
    }
    for(int i =0;i<n;i++){
        int val = arr[i];
        temp[val] = temp[val]+1;
    }
    for(int i =1;i<=high;i++){
        temp[i] =temp[i]+temp[i-1];
    }
    for(int i =n-1;0<=i;i--){
        
        arr2[temp[arr[i]]] = arr[i];
        temp[arr[i]]= temp[arr[i]] -1;
    }

    for(int i =1;i<=n;i++){
        printf("%d \n",arr2[i]);
    }
}
int main() {
    int arr[10]={2,5,3,0,2,1,0,3};
 
    counting_sort(arr,8,5);    

    return 0;
}