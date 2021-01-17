#ifndef __HU_SYSTEM_H__
#define __HU_SYSTEM_H__

#include<stdio.h>
#include <sys/syscall.h>

#define RES_OK    0 
#define RES_FAIL  -1
#define res_err_t int


enum LOG_COLOR
{
    COLOR_INFO  = 32,
    COLOR_WARN  = 33, 
    COLOR_ERROR = 31
};
 
#define printf_log(level, fmt, ...) \
    printf("\033[%d;40m", level); \
    printf("%s(%d), "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    printf("\033[0m\n")
 
#define printf_info(level, fmt, ...) \
    printf_log(level, fmt, ##__VA_ARGS__)
 
#define LOGI(fmt, ...) printf_info(COLOR_INFO, fmt, ##__VA_ARGS__)
#define LOFW(fmt, ...) printf_info(COLOR_WARN, fmt, ##__VA_ARGS__)
#define LOGE(fmt, ...) printf_info(COLOR_ERROR, fmt, ##__VA_ARGS__)




#endif
