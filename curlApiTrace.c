#define _GNU_SOURCE
#define CURL_EXTERN
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>
#include "curlenum.h"
#include "curlopttostr.h"
//#include <curl/easy.h>

#define CURL void
#define CURLcode unsigned int
//#define CURLoption unsigned int


typedef unsigned int (*Curl_setopt_t)(void* data, unsigned int tag, ...);

CURLcode curl_easy_setopt(CURL* data, CURLoption tag, long parameter)
{
    printf("==== curl_easy_setopt(..., ");
    printOptName(tag,parameter);
    if(!data)
        return 43;
    Curl_setopt_t Curl_setopt_f = (Curl_setopt_t)dlsym(RTLD_NEXT, "curl_easy_setopt");
    unsigned int ret = Curl_setopt_f(data, tag, parameter);
    return ret;
}
