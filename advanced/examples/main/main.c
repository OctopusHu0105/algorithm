/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>

#include <string.h>

#define DIM(a) (sizeof(a)/sizeof(*a))

int lookup_keyword(const char* key, const char* table[], const int size)
{
    int ret = -1;
    
    int i = 0;
    
    for(i=0; i<size; i++)
    {
        if( strcmp(key, table[i]) == 0 )
        {
            ret = i;
            break;
        }
    }
    
    return ret;
}

// typedef int(AINT5)[5];
// typedef float(AFLOAT10)[10];
// typedef char(ACHAR9)[9];

#ifndef __GNUC__
#define __attribute__(x) 
#endif

__attribute__((constructor))
void before_main()
{
    printf("%s\n",__FUNCTION__);
}

__attribute__((destructor)) 
void after_main()
{
    printf("%s\n",__FUNCTION__);
}
void printArray(int a[], int size)
{
    int i = 0;
    
    printf("printArray: %d\n", sizeof(a));

    for(i=0; i<size; i++)
    {
        printf("%d\n", a[i]);
    }
}


int main()
{
    printf("%s\n",__FUNCTION__);
    

 int a[5][5] = {{0, 1, 2,3,4}, {3, 4, 5,3,4}, {6, 7, 8,3,4},{3, 4, 5,3,4},{3, 4, 5,3,4}};
    int* p = &a[0][0];
    
    int i = 0;
    int j = 0;
    
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            printf("%d, ", *(*(a+i) + j));
        }
        
        printf("\n");
    }

    printf("---------- %d\n", sizeof(int *));
    
    printArray(p, 25);

    // AINT5 a1;
    // int fArray[5];
    // AFLOAT10* pf = &fArray;
    // ACHAR9 cArray = {7};

    // char(*pc)[9] = &cArray;
    // char(*pcw)[4] = cArray;
    
    
    // int i = 0;
    
    // printf("%d, %d\n", sizeof(AINT5), sizeof(a1));
    
    // for(i=0; i<10; i++)
    // {
    //     (*pf)[i] = i;
    // }
     
    //  for(i=0; i<4; i++)
    // {
    //     (*pcw)[i] = i + 20;
    // }


    // for(i=0; i<10; i++)
    // {
    //     printf("%f\n", fArray[i]);
    // }
    
    // for(i=0; i<4; i++)
    // {
    //     printf("%d\n", cArray[i]);
    // }

    // printf("%p, %p, %p\n", &cArray, pc+1, pcw+1);

    // const char* keyword[8] = {
    //         "do",
            
    //         "if",
    //         "register213131231231",
    //         "return341241231234123413241321 ",
    //         "switch",
    //         "while",
    //         "case",
    //         "static"
    // };
    // printf("%d - %d \n", sizeof(keyword), sizeof(*keyword) );
    // printf("%d\n", lookup_keyword("return", keyword, DIM(keyword)));
    // printf("%d\n", lookup_keyword("main", keyword, DIM(keyword)));

    return 0;
}

