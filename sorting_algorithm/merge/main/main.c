/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

void merge_two(int arr[], int brr[], int i, int j, int len);
void merge_line(int crr[], int brr[], int i, int k , int j);

int merge_sort(int *arr, int len)  {
    merge_two(arr, arr, 1, len , len); 
}

void merge_two(int arr[], int brr[], int i, int j, int len)
{
    int crr[len+1];
    if (i == j) {
        brr[i] = arr[j];
    } else {
        int k = (i + j) / 2;
        merge_two(arr, crr, i, k, len);
        merge_two(arr, crr, k+1, j, len);
        merge_line(crr, brr, i, k ,j);
    }
    
}

void merge_line(int crr[], int brr[], int i, int k , int j)
{
    int n = 0;
    for (int a = i, b = k+1; a <= k && b <= j; ) {
        if (crr[a] < crr[b]) {
            brr[n++] = crr[a];
            a++;       
        } else {
            brr[n++] = crr[b];
            b++;

        }
        while (a <= k) {
            brr[n++] = crr[a++];

        }

        while (b <= j) {
            brr[n++] = crr[b++];
        }
    }
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
