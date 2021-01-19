shida/* insertion_sort

*/
#include <stdio.h>

void insertion_sort(int *arr, int len)  {
    
    int pre_index, current;
    for(int i = 1; i < len; i++) {
        pre_index = i - 1;
        current = arr[i];
        while(pre_index >= 0 && arr[pre_index] > current) {
            arr[pre_index + 1] = arr[pre_index];
            pre_index--;
        }
        arr[pre_index + 1] = current;
    }
}

void main()
{
    printf("Hello world!\n");
    int a[5] = {2, 53, 32, 89, 1};
    insertion_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
