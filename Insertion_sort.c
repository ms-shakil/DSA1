#include<stdio.h>
void printArray(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void InsertionSort(int arr[], int n)
{
      for(int i = 0;i<n-1;i++){
        int n =i+1;
        while(n >0 ){
          if (arr[n-1]>arr[n]){
            int temp = arr[n-1];
            arr[n-1] = arr[n];
            arr[n]=temp;
          }
          n-=1;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    printf("Before Applying Insertion Sort...... ");
    printArray(arr, n);

    InsertionSort(arr, n);

    printf("After Applying Insertion Sort...... ");
    printArray(arr, n);
    return 0;
}
