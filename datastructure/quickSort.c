#include <stdio.h>
#define SIZE 1000

int a[SIZE];

void swap(int *a, int *b) {
    int temp;
    temp  = *a;
    *a = *b;
    *b = temp;
}

void show(int n) {
    for(int i=0 ; i<n ; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void quickSort(int start, int end) {
    if(end-start < 1)
        return;

    int pivot = start;
    int leftIdx = start+1;
    int rightIdx = end;
    
    while(leftIdx < rightIdx) {
        while(a[leftIdx] < a[pivot] && leftIdx <= end) leftIdx++;
        while(a[rightIdx] > a[pivot] && rightIdx >= start) rightIdx--;
        //printf("left : %d, right : %d\n",leftIdx,rightIdx);
        if(rightIdx > leftIdx) {
            swap(&a[leftIdx],&a[rightIdx]);
        }
        if(rightIdx == leftIdx && a[leftIdx] > a[pivot]) {
            swap(&a[leftIdx],&a[pivot]);
        }
        if(rightIdx < leftIdx) {
            swap(&a[rightIdx],&a[pivot]);
        }
    }
    //show(end+1);
    quickSort(start, pivot);
    quickSort(pivot+1, end);
}





int main(void) {
    int n;
    scanf("%d",&n);
    for (int i=0 ; i<n ; i++)
        scanf("%d",&a[i]);
    quickSort(0,n-1);
    show(n);
    return 0;
}
