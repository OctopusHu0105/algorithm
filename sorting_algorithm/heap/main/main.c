/* 
heap sort
*/
#include <stdio.h>

void heap_adjust(int *arr, int i, int len);
void swap(int *arr, int i, int j);

void build_max_heap(int *arr, int len)
{   // 建立大顶堆
    for(int i = (int)(len/2); i >= 0; i--) {
        printf("-- i %d \n", i);
        heap_adjust(arr, i, len);
    }
}
 
void heap_adjust(int *arr, int i, int len)
{     // 堆调整
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    printf("left %d right %d larg %d \n", left, right,largest);
    if(left < len && arr[left] > arr[largest]) {
        largest = left;
    }
 
    if(right < len && arr[right] > arr[largest]) {
        largest = right;
    }
 
    if(largest != i) {
        swap(arr, i, largest);
        printf("----------------- %d\n", largest);
        heap_adjust(arr, largest, len);
    }
}
 
void swap(int *arr, int i, int j) 
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
 
void heap_sort(int *arr, int len) 
{
    build_max_heap(arr, len);
 
    for(int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        len--;
        heap_adjust(arr, 0, len);
    }
}
void main()
{
    printf("Hello world!\n");
    int a[5] = {4, 9, 6, 7, 1};
    
    heap_sort(a, 5);
    
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
