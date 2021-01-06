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


void main()
{
    printf("Hello world!\n");
    int a[5] = {2, 53, 32, 89, 1};
    bubble_sort(a, 5);
    for(int i = 0; i < 5; i++) {
        printf("a[%d] %d\n" , i, a[i]);
    }   

}
