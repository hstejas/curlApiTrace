# curlApiTrace
trace out curl_easy_setopt using LD_PRELOAD

# Usage
- update curl enum.h with CURLoption enum from required curl version
- `./ppToStr.pl` #creates the print function in header curlopttostr.h by reading curlenum.h
- `gcc -O2 -fPIC -shared ./curlApiTrace.c -ldl -o curlApiTrace.so`  #compile the .so
- `LD_PRELOAD=$PWD/curlApiTrace.so curl -I https://duckduckgo.com/`

## Example output


    ....
    curl_easy_setopt(0xptr, CURLOPT_URL, https://duckduckgo.com/)
    curl_easy_setopt(0xptr, CURLOPT_NOPROGRESS, 1)
    curl_easy_setopt(0xptr, CURLOPT_NOBODY, 1)
    curl_easy_setopt(0xptr, CURLOPT_HEADER, 1)
    ...
    curl_easy_setopt(0xptr, CURLOPT_USERAGENT, curl/7.55.1)
    curl_easy_setopt(0xptr, CURLOPT_MAXREDIRS, 50)
    curl_easy_setopt(0xptr, CURLOPT_POSTREDIR, 0)
    ...
    
    HTTP/1.1 200 OK
    Server: nginx
    Date: Sun, 27 May 2018 18:00:49 GMT
    Content-Type: text/html; charset=UTF-8
    Content-Length: 5496
    Connection: keep-alive
    ETag: "5b085f90-1578"
    Strict-Transport-Security: max-age=31536000
    X-Frame-Options: SAMEORIGIN
    Content-Security-Policy: default-src https: blob: data: 'unsafe-inline' 'unsafe-eval'; frame-ancestors 'self'
    X-XSS-Protection: 1;mode=block
    X-Content-Type-Options: nosniff
    Referrer-Policy: origin
    Expect-CT: max-age=0
    Expires: Sun, 27 May 2018 18:00:48 GMT
    Cache-Control: no-cache
    Accept-Ranges: bytes

