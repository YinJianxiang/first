#define NOT_NODE_INDEX -1  
  
void adjustRoot(int *data, int count, int root);  
void heapSort(int *data,int count);  
  
void heapSort(int *data,int count) {  
    int root;  
    int tmp;  
  
    for(root = count/2 - 1;root >= 0;root--) {  
        adjustRoot(data,count,root);      
    }  
    tmp = data[0];  
    data[0] = data[count - 1];  
    data[count - 1] = tmp;  
  
    for(count--;count > 1;count--) {  
        adjustRoot(data,count,0);  
  
        tmp = data[0];  
        data[0] = data[count-1];  
        data[count-1] = tmp;  
    }  
}  
void adjustRoot(int *data, int count, int root) {  
    int leftChild = NOT_NODE_INDEX;  
    int rightChild = NOT_NODE_INDEX;  
    int whichChild;  
    int tmp;  
  
    while(root <= count/2 - 1) {  
        leftChild = 2*root + 1;  
        rightChild = ((leftChild+1) >= count ? NOT_NODE_INDEX : (leftChild+1));  
  
        whichChild = ((rightChild == NOT_NODE_INDEX) ? leftChild :  
            (data[leftChild] > data[rightChild] ? leftChild : rightChild));  
        whichChild = data[root] > data[whichChild] ? NOT_NODE_INDEX : whichChild;  
  
        if(whichChild == NOT_NODE_INDEX) {  
            return;  
        }  
  
        tmp = data[root];  
        data[root] = data[whichChild];  
        data[whichChild] = tmp;  
  
        root = whichChild;  
    }  
}  


