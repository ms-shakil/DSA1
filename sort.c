// selection Sort
/*
#include <stdio.h>
void Selection_sort(int arr[],int N){
    for(int i =0;i<N;i++){
        for(int j =i+1;j<N;j++){
            if(arr[i]>arr[j]){
                int temp= arr[i];
                arr[i]= arr[j];
                arr[j]= temp;
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
*/



// Bubble sort

/*#include <stdio.h>
void Bubble_sort(int arr[],int N){
    for(int i =0;i<N;i++){
        for(int j =0;j<(N-1)-i;j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
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
} */


// Insertion sort
/*
#include <stdio.h>
void Insertion_Sort(int arr[],int N){
    for(int i =0;i<N-1;i++){
        int ind = i+1;
       while(ind >0){
           if(arr[ind]<arr[ind-1]){
               int temp = arr[ind];
               arr[ind]= arr[ind -1];
               arr[ind-1]= temp;
           }
           ind -=1;
       }

    }
}
int main(){
    int arr[10]={5,3,1,4,9,8,6,0,5,2};
    Insertion_Sort(arr,10);
    for(int i =0;i<10;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}
*/



// Online C compiler to run C program online
#include <stdio.h>
void Counting_sort(int arr[],int N,int high){
    int temp[high];
    int arr2[N];
    for(int i =0;i<high;i++){
        temp[i]=0;
    }
    for(int i =0;i<N;i++){
        temp[arr[i]] =temp[arr[i]]+1;
    }
    for(int i=1;i<high;i++){
        temp[i]= temp[i]+temp[i-1];
    }
    for(int i =N-1;i>=0;i--){
        int val = arr[i];
        int val2 = temp[val];
        arr2[val2] = val;
        temp[val] = val2-1;
    }
    
    for(int i =0;i<N;i++){
        arr[i]=arr2[i];
    }

}
int main(){
    int arr[10]={5,3,1,4,9,8,6,0,5,2};
    Counting_sort(arr,10,9);
    for(int i =0;i<10;i++){
        printf("%d\n",arr[i]);
    }

    return 0;
}