/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

void bubble_sort(int *arr, int len) 
{
  
}

int *merge_sort(int *arr, int len)  {
    if (len < 2) {
        return;
    }
    int middle = (int)len / 2;
    int *left = (int *)malloc(middle * sizeof(int));
    int *right = (int *)malloc((len - middle) * sizeof(int));
    return merge(merge_sort(left, middle), merge_sort(right, len - middle));
}
 
int merge(int *left, int len_l, int *right, int len_r)
{
    var res ult = [];
 
    while (left.length>0 && right.length>0) {
        if (left[0] <= right[0]) {
            result.push(left.shift());
        } else {
            result.push(right.shift());
        }
    }
 
    while (left.length)
        result.push(left.shift());
 
    while (right.length)
        result.push(right.shift());
 
    return result;
}

void main()
{
    printf("Hello world!\n");
    int a[5] = {2, 53, 32, 89, 1};
    merge_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
