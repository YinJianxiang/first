#include<stdio.h>
void dirextSelectdeSort(int a[],int n);
void directInsertSort(int a[],int n);
int partition(int* arr,int low,int high);
void quicksort(int arr[],int start,int end);

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while(low < high && arr[low] <= key )
            low++;
        if(low < high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}
void quicksort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quicksort(arr,start,pos-1);
        quicksort(arr,pos+1,end);
    }
    return;
}
/*
void directInsertSort(int a[],int n) {
	int i;
	int j;
	int t;

	for(i = 1;i < n;i++) {
		t = a[i];
		for(j = i - 1;j >= 0 && a[j] > t;j--) {
			a[j+1] = a[j];	
		}
		a[j+1] = t;
	}
}
void directSelectedSort(int a[],int n) {
	int i;
	int j;
	int minData;
	int minIndex;
	int t;

	for(i = 0;i < n-1;i++) {
		minData = a[i];
		minIndex = i;
		for(j = i;j < n;j++) {
			if(minData > a[j]) {
				minData = a[j];
				minIndex = j;
			}
		}
		t = a[minIndex];
		a[minIndex] = a[i];
		a[i] = t;
	}
}
*/

int main(void) {
	int a[10];
	int i;

	for(i = 0;i < 10;i++) {
		scanf("%d",&a[i]);
	}
		
	quicksort(a,0,9);

	for(i = 0;i < 10;i++) {
		printf(i == 0 ?"%d" : " %d ",a[i]);
	}

	printf("\n");
	return 0;
}
