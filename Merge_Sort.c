#include <stdio.h>

//
void Merge(int Arr[],int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right -mid;
    int l_Arr[n1];
    int r_Arr[n2];
    for(int i = 0;i<n1;i++){
        l_Arr[i]=Arr[left+i];
    }
    for(int i =0;i<n2;i++){
        r_Arr[i]=Arr[mid+1+i];
    }
    int l=0;
    int r =0;
    int k =0;
    while(l< n1 && r<n2){
        if(l_Arr[l]<= r_Arr[r]){
            Arr[k]=l_Arr[l];
            k++;
            l++;
        }else{
            Arr[k]=r_Arr[r];
            k++;
            r++; 
        }
    }
    while(l < n1){
        Arr[k]=l_Arr[l];
        k++;l++;
    }
    while(r < n2){
        Arr[k]=r_Arr[r];
        k++;r++;
    }    
}

void Merge_sort(int Arr[],int left, int right){
    if(left >= right){
        return ;
    }
    int mid = left +(right-left)/2;
    Merge_sort(Arr,left,mid);
    Merge_sort(Arr,mid+1,right);
    Merge(Arr,left,mid,right);
}
int main() {
   int Arr[10]={5,6,2,1,8,7,9,0,3,5};
  for(int i =0;i<10;i++){
      printf("%d\n",Arr[i]);
  }
  printf("end \n");
  Merge_sort(Arr,0,9);
  for(int i =0;i<10;i++){
      printf("%d\n",Arr[i]);
  }
    return 0;
}