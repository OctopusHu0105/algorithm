/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <math.h>

void shell_sort(int *arr, int len)
{
    for(int gap = (int)len / 2; gap > 0; gap = (int)gap / 2) {
       //多个分组交替执行
        for(int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while(j - gap >= 0 && current < arr[j - gap]) {
                 arr[j] = arr[j - gap];
                 j = j - gap;
            }
            arr[j] = current;
        }
    }
}

void main()
{
    printf("Hello world!\n");
    int a[5] = {2, 53, 32, 89, 1};
    shell_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
