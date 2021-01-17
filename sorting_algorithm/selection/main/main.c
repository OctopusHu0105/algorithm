/* selection_sort Example
*/
#include <stdio.h>


void selection_sort(int *arr, int len) {
    int temp, min_index;
    for(int i = 0; i < len - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < len; j++) {
            if(arr[j] < arr[min_index]) {     // 寻找最小的数
                min_index = j;                 // 将最小数的索引保存
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}


void main()
{
    printf("Hello world!\n");
    int a[5] = {2, 53, 32, 89, 1};
    selection_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
