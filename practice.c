// Online C compiler to run C program online
#include <stdio.h>
void selection_Sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i]= arr[j];
                arr[j]= temp;
            }
        }
    }
}

void Bubble_sort(int arr[],int n){
    for(int i=1;i<=n;i++){
        for(int j =0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
}

void Insertion_sort(int arr[],int n){
    for(int i =0;i<n-1;i++){
        int L=i+1;
        while(L >0){
           if(arr[L]<arr[L-1]){
               int temp = arr[L];
               arr[L]= arr[L-1];
               arr[L-1]=temp;
           }
           L-=1;
        }
    }
}

void B_search(int arr[],int n,int key){
    int left =0;
    int right = n-1;
    int F =-1;
    while(left <= right){
        int mid = (int)(left+right)/2;
        if(arr[mid]== key){
            printf("Find it. and index are %d ",mid);
            F=1;
            break;
        }else if(arr[mid]<key){
            left = mid+1;
        }else{
            right =mid-1;
        }
    }
    if(F=-1){
        printf("Fot Found.");
    }
}
int main() {
    int n =10;
    int arr[10]={8,5,3,6,8,3,1,0,4,2};
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    Insertion_sort(arr,n);
        for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    B_search(arr,n,9);
    return 0;
    
}