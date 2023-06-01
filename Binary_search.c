#include<stdio.h>
void Binary_search(int Arr[],int n,int val){
    int left =0;
    int right = n-1;
    int F =-1;
   while (left<=right)
   {
       int mid = (int)(left+right)/2;

    if(Arr[mid]==val){
        F =mid;
        break;
    }
    else if(Arr[mid]<val){
        left = mid+1;
    }else{
        right =mid-1;
    }
   }
    if(F !=-1){
        printf("Find it . and index number is %d",F);
    }else{
        printf("Not Found.");
    }
   
}
int main(){
    int arr[10]={1,3,4,5,7,8,9,10,15,20};

    Binary_search(arr,10,7);

    return 0;
}