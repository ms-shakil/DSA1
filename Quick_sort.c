#include<stdio.h>

int Pattern(int arr[],int low ,int high){
    int prov,i,j;
    prov = arr[high];
    for(i = low-1,j= low;j<high;j++){
        if(arr[j]<prov){
            i++;
            int temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        
    }
    i++;
    int t = arr[i];
    arr[i]=arr[high];
    arr[high]= t;
    return i;
}


void Quick_sort(int arr[],int low,int high){
    if(low >= high){
        return;
    }
    int p = Pattern(arr,low,high);
    Quick_sort(arr,low,p-1);
    Quick_sort(arr,p+1,high);
}


int main(){
    int arr[10]={6,3,6,2,8,1,2,9,11,0};
    Quick_sort(arr,0,9);
    for(int i =0;i<10;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}