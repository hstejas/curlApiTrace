#define _GNU_SOURCE
#define CURL_EXTERN
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>
#include "curlenum.h"
//#include <curl/easy.h>

#define CURL void
#define CURLcode unsigned int
//#define CURLoption unsigned int

void printOptName(unsigned int option, long parameter)
{
    switch(option)
    {
        case CURLOPT_WRITEDATA: printf("CURLOPT_WRITEDATA, ..."); break;
        case CURLOPT_URL: printf("CURLOPT_URL, %s", (char*)parameter); break;
        case CURLOPT_PORT: printf("CURLOPT_PORT, ..."); break;
        case CURLOPT_PROXY: printf("CURLOPT_PROXY, ..."); break;
        case CURLOPT_USERPWD: printf("CURLOPT_USERPWD, ..."); break;
        case CURLOPT_PROXYUSERPWD: printf("CURLOPT_PROXYUSERPWD, ..."); break;
        case CURLOPT_RANGE: printf("CURLOPT_RANGE, ..."); break;
        case CURLOPT_READDATA: printf("CURLOPT_READDATA, ..."); break;
        case CURLOPT_ERRORBUFFER: printf("CURLOPT_ERRORBUFFER, ..."); break;
        case CURLOPT_WRITEFUNCTION: printf("CURLOPT_WRITEFUNCTION, ..."); break;
        case CURLOPT_READFUNCTION: printf("CURLOPT_READFUNCTION, ..."); break;
        case CURLOPT_TIMEOUT: printf("CURLOPT_TIMEOUT, ..."); break;
        case CURLOPT_INFILESIZE: printf("CURLOPT_INFILESIZE, ..."); break;
        case CURLOPT_POSTFIELDS: printf("CURLOPT_POSTFIELDS, ..."); break;
        case CURLOPT_REFERER: printf("CURLOPT_REFERER, ..."); break;
        case CURLOPT_FTPPORT: printf("CURLOPT_FTPPORT, ..."); break;
        case CURLOPT_USERAGENT: printf("CURLOPT_USERAGENT, %s", (char*)parameter); break;
        case CURLOPT_LOW_SPEED_LIMIT: printf("CURLOPT_LOW_SPEED_LIMIT, ..."); break;
        case CURLOPT_LOW_SPEED_TIME: printf("CURLOPT_LOW_SPEED_TIME, ..."); break;
        case CURLOPT_RESUME_FROM: printf("CURLOPT_RESUME_FROM, ..."); break;
        case CURLOPT_COOKIE: printf("CURLOPT_COOKIE, ..."); break;
        case CURLOPT_HTTPHEADER: printf("CURLOPT_HTTPHEADER, ..."); break;
        case CURLOPT_HTTPPOST: printf("CURLOPT_HTTPPOST, ..."); break;
        case CURLOPT_SSLCERT: printf("CURLOPT_SSLCERT, ..."); break;
        case CURLOPT_KEYPASSWD: printf("CURLOPT_KEYPASSWD, ..."); break;
        case CURLOPT_CRLF: printf("CURLOPT_CRLF, ..."); break;
        case CURLOPT_QUOTE: printf("CURLOPT_QUOTE, ..."); break;
        case CURLOPT_HEADERDATA: printf("CURLOPT_HEADERDATA, ..."); break;
        case CURLOPT_COOKIEFILE: printf("CURLOPT_COOKIEFILE, ..."); break;
        case CURLOPT_SSLVERSION: printf("CURLOPT_SSLVERSION, ..."); break;
        case CURLOPT_TIMECONDITION: printf("CURLOPT_TIMECONDITION, ..."); break;
        case CURLOPT_TIMEVALUE: printf("CURLOPT_TIMEVALUE, ..."); break;
        case CURLOPT_CUSTOMREQUEST: printf("CURLOPT_CUSTOMREQUEST, ..."); break;
        case CURLOPT_STDERR: printf("CURLOPT_STDERR, ..."); break;
        case CURLOPT_POSTQUOTE: printf("CURLOPT_POSTQUOTE, ..."); break;
        case CURLOPT_OBSOLETE40: printf("CURLOPT_OBSOLETE40, ..."); break;
        case CURLOPT_VERBOSE: printf("CURLOPT_VERBOSE, ..."); break;
        case CURLOPT_HEADER: printf("CURLOPT_HEADER, ..."); break;
        case CURLOPT_NOPROGRESS: printf("CURLOPT_NOPROGRESS, ..."); break;
        case CURLOPT_NOBODY: printf("CURLOPT_NOBODY, ..."); break;
        case CURLOPT_FAILONERROR: printf("CURLOPT_FAILONERROR, ..."); break;
        case CURLOPT_UPLOAD: printf("CURLOPT_UPLOAD, ..."); break;
        case CURLOPT_POST: printf("CURLOPT_POST, ..."); break;
        case CURLOPT_DIRLISTONLY: printf("CURLOPT_DIRLISTONLY, ..."); break;
        case CURLOPT_APPEND: printf("CURLOPT_APPEND, ..."); break;
        case CURLOPT_NETRC: printf("CURLOPT_NETRC, ..."); break;
        case CURLOPT_FOLLOWLOCATION: printf("CURLOPT_FOLLOWLOCATION, ..."); break;
        case CURLOPT_TRANSFERTEXT: printf("CURLOPT_TRANSFERTEXT, ..."); break;
        case CURLOPT_PUT: printf("CURLOPT_PUT, ..."); break;
        case CURLOPT_PROGRESSFUNCTION: printf("CURLOPT_PROGRESSFUNCTION, ..."); break;
        case CURLOPT_PROGRESSDATA: printf("CURLOPT_PROGRESSDATA, ..."); break;
        case CURLOPT_AUTOREFERER: printf("CURLOPT_AUTOREFERER, ..."); break;
        case CURLOPT_PROXYPORT: printf("CURLOPT_PROXYPORT, ..."); break;
        case CURLOPT_POSTFIELDSIZE: printf("CURLOPT_POSTFIELDSIZE, ..."); break;
        case CURLOPT_HTTPPROXYTUNNEL: printf("CURLOPT_HTTPPROXYTUNNEL, ..."); break;
        case CURLOPT_INTERFACE: printf("CURLOPT_INTERFACE, ..."); break;
        case CURLOPT_KRBLEVEL: printf("CURLOPT_KRBLEVEL, ..."); break;
        case CURLOPT_SSL_VERIFYPEER: printf("CURLOPT_SSL_VERIFYPEER, ..."); break;
        case CURLOPT_CAINFO: printf("CURLOPT_CAINFO, ..."); break;
        case CURLOPT_MAXREDIRS: printf("CURLOPT_MAXREDIRS, ..."); break;
        case CURLOPT_FILETIME: printf("CURLOPT_FILETIME, ..."); break;
        case CURLOPT_TELNETOPTIONS: printf("CURLOPT_TELNETOPTIONS, ..."); break;
        case CURLOPT_MAXCONNECTS: printf("CURLOPT_MAXCONNECTS, ..."); break;
        case CURLOPT_OBSOLETE72: printf("CURLOPT_OBSOLETE72, ..."); break;
        case CURLOPT_FRESH_CONNECT: printf("CURLOPT_FRESH_CONNECT, ..."); break;
        case CURLOPT_FORBID_REUSE: printf("CURLOPT_FORBID_REUSE, ..."); break;
        case CURLOPT_RANDOM_FILE: printf("CURLOPT_RANDOM_FILE, ..."); break;
        case CURLOPT_EGDSOCKET: printf("CURLOPT_EGDSOCKET, ..."); break;
        case CURLOPT_CONNECTTIMEOUT: printf("CURLOPT_CONNECTTIMEOUT, ..."); break;
        case CURLOPT_HEADERFUNCTION: printf("CURLOPT_HEADERFUNCTION, ..."); break;
        case CURLOPT_HTTPGET: printf("CURLOPT_HTTPGET, ..."); break;
        case CURLOPT_SSL_VERIFYHOST: printf("CURLOPT_SSL_VERIFYHOST, ..."); break;
        case CURLOPT_COOKIEJAR: printf("CURLOPT_COOKIEJAR, ..."); break;
        case CURLOPT_SSL_CIPHER_LIST: printf("CURLOPT_SSL_CIPHER_LIST, ..."); break;
        case CURLOPT_HTTP_VERSION: printf("CURLOPT_HTTP_VERSION, ..."); break;
        case CURLOPT_FTP_USE_EPSV: printf("CURLOPT_FTP_USE_EPSV, ..."); break;
        case CURLOPT_SSLCERTTYPE: printf("CURLOPT_SSLCERTTYPE, ..."); break;
        case CURLOPT_SSLKEY: printf("CURLOPT_SSLKEY, ..."); break;
        case CURLOPT_SSLKEYTYPE: printf("CURLOPT_SSLKEYTYPE, ..."); break;
        case CURLOPT_SSLENGINE: printf("CURLOPT_SSLENGINE, ..."); break;
        case CURLOPT_SSLENGINE_DEFAULT: printf("CURLOPT_SSLENGINE_DEFAULT, ..."); break;
        case CURLOPT_DNS_USE_GLOBAL_CACHE: printf("CURLOPT_DNS_USE_GLOBAL_CACHE, ..."); break;
        case CURLOPT_DNS_CACHE_TIMEOUT: printf("CURLOPT_DNS_CACHE_TIMEOUT, ..."); break;
        case CURLOPT_PREQUOTE: printf("CURLOPT_PREQUOTE, ..."); break;
        case CURLOPT_DEBUGFUNCTION: printf("CURLOPT_DEBUGFUNCTION, ..."); break;
        case CURLOPT_DEBUGDATA: printf("CURLOPT_DEBUGDATA, ..."); break;
        case CURLOPT_COOKIESESSION: printf("CURLOPT_COOKIESESSION, ..."); break;
        case CURLOPT_CAPATH: printf("CURLOPT_CAPATH, ..."); break;
        case CURLOPT_BUFFERSIZE: printf("CURLOPT_BUFFERSIZE, ..."); break;
        case CURLOPT_NOSIGNAL: printf("CURLOPT_NOSIGNAL, ..."); break;
        case CURLOPT_SHARE: printf("CURLOPT_SHARE, ..."); break;
        case CURLOPT_PROXYTYPE: printf("CURLOPT_PROXYTYPE, ..."); break;
        case CURLOPT_ACCEPT_ENCODING: printf("CURLOPT_ACCEPT_ENCODING, ..."); break;
        case CURLOPT_PRIVATE: printf("CURLOPT_PRIVATE, ..."); break;
        case CURLOPT_HTTP200ALIASES: printf("CURLOPT_HTTP200ALIASES, ..."); break;
        case CURLOPT_UNRESTRICTED_AUTH: printf("CURLOPT_UNRESTRICTED_AUTH, ..."); break;
        case CURLOPT_FTP_USE_EPRT: printf("CURLOPT_FTP_USE_EPRT, ..."); break;
        case CURLOPT_HTTPAUTH: printf("CURLOPT_HTTPAUTH, ..."); break;
        case CURLOPT_SSL_CTX_FUNCTION: printf("CURLOPT_SSL_CTX_FUNCTION, ..."); break;
        case CURLOPT_SSL_CTX_DATA: printf("CURLOPT_SSL_CTX_DATA, ..."); break;
        case CURLOPT_FTP_CREATE_MISSING_DIRS: printf("CURLOPT_FTP_CREATE_MISSING_DIRS, ..."); break;
        case CURLOPT_PROXYAUTH: printf("CURLOPT_PROXYAUTH, ..."); break;
        case CURLOPT_FTP_RESPONSE_TIMEOUT: printf("CURLOPT_FTP_RESPONSE_TIMEOUT, ..."); break;
        case CURLOPT_IPRESOLVE: printf("CURLOPT_IPRESOLVE, ..."); break;
        case CURLOPT_MAXFILESIZE: printf("CURLOPT_MAXFILESIZE, ..."); break;
        case CURLOPT_INFILESIZE_LARGE: printf("CURLOPT_INFILESIZE_LARGE, ..."); break;
        case CURLOPT_RESUME_FROM_LARGE: printf("CURLOPT_RESUME_FROM_LARGE, ..."); break;
        case CURLOPT_MAXFILESIZE_LARGE: printf("CURLOPT_MAXFILESIZE_LARGE, ..."); break;
        case CURLOPT_NETRC_FILE: printf("CURLOPT_NETRC_FILE, ..."); break;
        case CURLOPT_USE_SSL: printf("CURLOPT_USE_SSL, ..."); break;
        case CURLOPT_POSTFIELDSIZE_LARGE: printf("CURLOPT_POSTFIELDSIZE_LARGE, ..."); break;
        case CURLOPT_TCP_NODELAY: printf("CURLOPT_TCP_NODELAY, ..."); break;
        case CURLOPT_FTPSSLAUTH: printf("CURLOPT_FTPSSLAUTH, ..."); break;
        case CURLOPT_IOCTLFUNCTION: printf("CURLOPT_IOCTLFUNCTION, ..."); break;
        case CURLOPT_IOCTLDATA: printf("CURLOPT_IOCTLDATA, ..."); break;
        case CURLOPT_FTP_ACCOUNT: printf("CURLOPT_FTP_ACCOUNT, ..."); break;
        case CURLOPT_COOKIELIST: printf("CURLOPT_COOKIELIST, ..."); break;
        case CURLOPT_IGNORE_CONTENT_LENGTH: printf("CURLOPT_IGNORE_CONTENT_LENGTH, ..."); break;
        case CURLOPT_FTP_SKIP_PASV_IP: printf("CURLOPT_FTP_SKIP_PASV_IP, ..."); break;
        case CURLOPT_FTP_FILEMETHOD: printf("CURLOPT_FTP_FILEMETHOD, ..."); break;
        case CURLOPT_LOCALPORT: printf("CURLOPT_LOCALPORT, ..."); break;
        case CURLOPT_LOCALPORTRANGE: printf("CURLOPT_LOCALPORTRANGE, ..."); break;
        case CURLOPT_CONNECT_ONLY: printf("CURLOPT_CONNECT_ONLY, ..."); break;
        case CURLOPT_CONV_FROM_NETWORK_FUNCTION: printf("CURLOPT_CONV_FROM_NETWORK_FUNCTION, ..."); break;
        case CURLOPT_CONV_TO_NETWORK_FUNCTION: printf("CURLOPT_CONV_TO_NETWORK_FUNCTION, ..."); break;
        case CURLOPT_CONV_FROM_UTF8_FUNCTION: printf("CURLOPT_CONV_FROM_UTF8_FUNCTION, ..."); break;
        case CURLOPT_MAX_SEND_SPEED_LARGE: printf("CURLOPT_MAX_SEND_SPEED_LARGE, ..."); break;
        case CURLOPT_MAX_RECV_SPEED_LARGE: printf("CURLOPT_MAX_RECV_SPEED_LARGE, ..."); break;
        case CURLOPT_FTP_ALTERNATIVE_TO_USER: printf("CURLOPT_FTP_ALTERNATIVE_TO_USER, ..."); break;
        case CURLOPT_SOCKOPTFUNCTION: printf("CURLOPT_SOCKOPTFUNCTION, ..."); break;
        case CURLOPT_SOCKOPTDATA: printf("CURLOPT_SOCKOPTDATA, ..."); break;
        case CURLOPT_SSL_SESSIONID_CACHE: printf("CURLOPT_SSL_SESSIONID_CACHE, ..."); break;
        case CURLOPT_SSH_AUTH_TYPES: printf("CURLOPT_SSH_AUTH_TYPES, ..."); break;
        case CURLOPT_SSH_PUBLIC_KEYFILE: printf("CURLOPT_SSH_PUBLIC_KEYFILE, ..."); break;
        case CURLOPT_SSH_PRIVATE_KEYFILE: printf("CURLOPT_SSH_PRIVATE_KEYFILE, ..."); break;
        case CURLOPT_FTP_SSL_CCC: printf("CURLOPT_FTP_SSL_CCC, ..."); break;
        case CURLOPT_TIMEOUT_MS: printf("CURLOPT_TIMEOUT_MS, ..."); break;
        case CURLOPT_CONNECTTIMEOUT_MS: printf("CURLOPT_CONNECTTIMEOUT_MS, ..."); break;
        case CURLOPT_HTTP_TRANSFER_DECODING: printf("CURLOPT_HTTP_TRANSFER_DECODING, ..."); break;
        case CURLOPT_HTTP_CONTENT_DECODING: printf("CURLOPT_HTTP_CONTENT_DECODING, ..."); break;
        case CURLOPT_NEW_FILE_PERMS: printf("CURLOPT_NEW_FILE_PERMS, ..."); break;
        case CURLOPT_NEW_DIRECTORY_PERMS: printf("CURLOPT_NEW_DIRECTORY_PERMS, ..."); break;
        case CURLOPT_POSTREDIR: printf("CURLOPT_POSTREDIR, ..."); break;
        case CURLOPT_SSH_HOST_PUBLIC_KEY_MD5: printf("CURLOPT_SSH_HOST_PUBLIC_KEY_MD5, ..."); break;
        case CURLOPT_OPENSOCKETFUNCTION: printf("CURLOPT_OPENSOCKETFUNCTION, ..."); break;
        case CURLOPT_OPENSOCKETDATA: printf("CURLOPT_OPENSOCKETDATA, ..."); break;
        case CURLOPT_COPYPOSTFIELDS: printf("CURLOPT_COPYPOSTFIELDS, ..."); break;
        case CURLOPT_PROXY_TRANSFER_MODE: printf("CURLOPT_PROXY_TRANSFER_MODE, ..."); break;
        case CURLOPT_SEEKFUNCTION: printf("CURLOPT_SEEKFUNCTION, ..."); break;
        case CURLOPT_SEEKDATA: printf("CURLOPT_SEEKDATA, ..."); break;
        case CURLOPT_CRLFILE: printf("CURLOPT_CRLFILE, ..."); break;
        case CURLOPT_ISSUERCERT: printf("CURLOPT_ISSUERCERT, ..."); break;
        case CURLOPT_ADDRESS_SCOPE: printf("CURLOPT_ADDRESS_SCOPE, ..."); break;
        case CURLOPT_CERTINFO: printf("CURLOPT_CERTINFO, ..."); break;
        case CURLOPT_USERNAME: printf("CURLOPT_USERNAME, ..."); break;
        case CURLOPT_PASSWORD: printf("CURLOPT_PASSWORD, ..."); break;
        case CURLOPT_PROXYUSERNAME: printf("CURLOPT_PROXYUSERNAME, ..."); break;
        case CURLOPT_PROXYPASSWORD: printf("CURLOPT_PROXYPASSWORD, ..."); break;
        case CURLOPT_NOPROXY: printf("CURLOPT_NOPROXY, ..."); break;
        case CURLOPT_TFTP_BLKSIZE: printf("CURLOPT_TFTP_BLKSIZE, ..."); break;
        case CURLOPT_SOCKS5_GSSAPI_SERVICE: printf("CURLOPT_SOCKS5_GSSAPI_SERVICE, ..."); break;
        case CURLOPT_SOCKS5_GSSAPI_NEC: printf("CURLOPT_SOCKS5_GSSAPI_NEC, ..."); break;
        case CURLOPT_PROTOCOLS: printf("CURLOPT_PROTOCOLS, ..."); break;
        case CURLOPT_REDIR_PROTOCOLS: printf("CURLOPT_REDIR_PROTOCOLS, ..."); break;
        case CURLOPT_SSH_KNOWNHOSTS: printf("CURLOPT_SSH_KNOWNHOSTS, ..."); break;
        case CURLOPT_SSH_KEYFUNCTION: printf("CURLOPT_SSH_KEYFUNCTION, ..."); break;
        case CURLOPT_SSH_KEYDATA: printf("CURLOPT_SSH_KEYDATA, ..."); break;
        case CURLOPT_MAIL_FROM: printf("CURLOPT_MAIL_FROM, ..."); break;
        case CURLOPT_MAIL_RCPT: printf("CURLOPT_MAIL_RCPT, ..."); break;
        case CURLOPT_FTP_USE_PRET: printf("CURLOPT_FTP_USE_PRET, ..."); break;
        case CURLOPT_RTSP_REQUEST: printf("CURLOPT_RTSP_REQUEST, ..."); break;
        case CURLOPT_RTSP_SESSION_ID: printf("CURLOPT_RTSP_SESSION_ID, ..."); break;
        case CURLOPT_RTSP_STREAM_URI: printf("CURLOPT_RTSP_STREAM_URI, ..."); break;
        case CURLOPT_RTSP_TRANSPORT: printf("CURLOPT_RTSP_TRANSPORT, ..."); break;
        case CURLOPT_RTSP_CLIENT_CSEQ: printf("CURLOPT_RTSP_CLIENT_CSEQ, ..."); break;
        case CURLOPT_RTSP_SERVER_CSEQ: printf("CURLOPT_RTSP_SERVER_CSEQ, ..."); break;
        case CURLOPT_INTERLEAVEDATA: printf("CURLOPT_INTERLEAVEDATA, ..."); break;
        case CURLOPT_INTERLEAVEFUNCTION: printf("CURLOPT_INTERLEAVEFUNCTION, ..."); break;
        case CURLOPT_WILDCARDMATCH: printf("CURLOPT_WILDCARDMATCH, ..."); break;
        case CURLOPT_CHUNK_BGN_FUNCTION: printf("CURLOPT_CHUNK_BGN_FUNCTION, ..."); break;
        case CURLOPT_CHUNK_END_FUNCTION: printf("CURLOPT_CHUNK_END_FUNCTION, ..."); break;
        case CURLOPT_FNMATCH_FUNCTION: printf("CURLOPT_FNMATCH_FUNCTION, ..."); break;
        case CURLOPT_CHUNK_DATA: printf("CURLOPT_CHUNK_DATA, ..."); break;
        case CURLOPT_FNMATCH_DATA: printf("CURLOPT_FNMATCH_DATA, ..."); break;
        case CURLOPT_RESOLVE: printf("CURLOPT_RESOLVE, ..."); break;
        case CURLOPT_TLSAUTH_USERNAME: printf("CURLOPT_TLSAUTH_USERNAME, ..."); break;
        case CURLOPT_TLSAUTH_PASSWORD: printf("CURLOPT_TLSAUTH_PASSWORD, ..."); break;
        case CURLOPT_TLSAUTH_TYPE: printf("CURLOPT_TLSAUTH_TYPE, ..."); break;
        case CURLOPT_TRANSFER_ENCODING: printf("CURLOPT_TRANSFER_ENCODING, ..."); break;
        case CURLOPT_CLOSESOCKETFUNCTION: printf("CURLOPT_CLOSESOCKETFUNCTION, ..."); break;
        case CURLOPT_CLOSESOCKETDATA: printf("CURLOPT_CLOSESOCKETDATA, ..."); break;
        case CURLOPT_GSSAPI_DELEGATION: printf("CURLOPT_GSSAPI_DELEGATION, ..."); break;
        case CURLOPT_DNS_SERVERS: printf("CURLOPT_DNS_SERVERS, ..."); break;
        case CURLOPT_ACCEPTTIMEOUT_MS: printf("CURLOPT_ACCEPTTIMEOUT_MS, ..."); break;
        case CURLOPT_TCP_KEEPALIVE: printf("CURLOPT_TCP_KEEPALIVE, ..."); break;
        case CURLOPT_TCP_KEEPIDLE: printf("CURLOPT_TCP_KEEPIDLE, ..."); break;
        case CURLOPT_TCP_KEEPINTVL: printf("CURLOPT_TCP_KEEPINTVL, ..."); break;
        case CURLOPT_SSL_OPTIONS: printf("CURLOPT_SSL_OPTIONS, ..."); break;
        case CURLOPT_MAIL_AUTH: printf("CURLOPT_MAIL_AUTH, ..."); break;
        case CURLOPT_SASL_IR: printf("CURLOPT_SASL_IR, ..."); break;
        case CURLOPT_XFERINFOFUNCTION: printf("CURLOPT_XFERINFOFUNCTION, ..."); break;
        case CURLOPT_XOAUTH2_BEARER: printf("CURLOPT_XOAUTH2_BEARER, ..."); break;
        case CURLOPT_DNS_INTERFACE: printf("CURLOPT_DNS_INTERFACE, ..."); break;
        case CURLOPT_DNS_LOCAL_IP4: printf("CURLOPT_DNS_LOCAL_IP4, ..."); break;
        case CURLOPT_DNS_LOCAL_IP6: printf("CURLOPT_DNS_LOCAL_IP6, ..."); break;
        case CURLOPT_LOGIN_OPTIONS: printf("CURLOPT_LOGIN_OPTIONS, ..."); break;
        case CURLOPT_SSL_ENABLE_NPN: printf("CURLOPT_SSL_ENABLE_NPN, ..."); break;
        case CURLOPT_SSL_ENABLE_ALPN: printf("CURLOPT_SSL_ENABLE_ALPN, ..."); break;
        case CURLOPT_EXPECT_100_TIMEOUT_MS: printf("CURLOPT_EXPECT_100_TIMEOUT_MS, ..."); break;
        case CURLOPT_PROXYHEADER: printf("CURLOPT_PROXYHEADER, ..."); break;
        case CURLOPT_HEADEROPT: printf("CURLOPT_HEADEROPT, ..."); break;
        case CURLOPT_PINNEDPUBLICKEY: printf("CURLOPT_PINNEDPUBLICKEY, ..."); break;
        case CURLOPT_UNIX_SOCKET_PATH: printf("CURLOPT_UNIX_SOCKET_PATH, ..."); break;
        case CURLOPT_SSL_VERIFYSTATUS: printf("CURLOPT_SSL_VERIFYSTATUS, ..."); break;
        case CURLOPT_SSL_FALSESTART: printf("CURLOPT_SSL_FALSESTART, ..."); break;
        case CURLOPT_PATH_AS_IS: printf("CURLOPT_PATH_AS_IS, ..."); break;
        case CURLOPT_PROXY_SERVICE_NAME: printf("CURLOPT_PROXY_SERVICE_NAME, ..."); break;
        case CURLOPT_SERVICE_NAME: printf("CURLOPT_SERVICE_NAME, ..."); break;
        case CURLOPT_PIPEWAIT: printf("CURLOPT_PIPEWAIT, ..."); break;
        case CURLOPT_DEFAULT_PROTOCOL: printf("CURLOPT_DEFAULT_PROTOCOL, ..."); break;
        case CURLOPT_STREAM_WEIGHT: printf("CURLOPT_STREAM_WEIGHT, ..."); break;
        case CURLOPT_STREAM_DEPENDS: printf("CURLOPT_STREAM_DEPENDS, ..."); break;
        case CURLOPT_STREAM_DEPENDS_E: printf("CURLOPT_STREAM_DEPENDS_E, ..."); break;
        case CURLOPT_TFTP_NO_OPTIONS: printf("CURLOPT_TFTP_NO_OPTIONS, ..."); break;
        case CURLOPT_CONNECT_TO: printf("CURLOPT_CONNECT_TO, ..."); break;
        case CURLOPT_TCP_FASTOPEN: printf("CURLOPT_TCP_FASTOPEN, ..."); break;
        case CURLOPT_KEEP_SENDING_ON_ERROR: printf("CURLOPT_KEEP_SENDING_ON_ERROR, ..."); break;
        case CURLOPT_PROXY_CAINFO: printf("CURLOPT_PROXY_CAINFO, ..."); break;
        case CURLOPT_PROXY_CAPATH: printf("CURLOPT_PROXY_CAPATH, ..."); break;
        case CURLOPT_PROXY_SSL_VERIFYPEER: printf("CURLOPT_PROXY_SSL_VERIFYPEER, ..."); break;
        case CURLOPT_PROXY_SSL_VERIFYHOST: printf("CURLOPT_PROXY_SSL_VERIFYHOST, ..."); break;
        case CURLOPT_PROXY_SSLVERSION: printf("CURLOPT_PROXY_SSLVERSION, ..."); break;
        case CURLOPT_PROXY_TLSAUTH_USERNAME: printf("CURLOPT_PROXY_TLSAUTH_USERNAME, ..."); break;
        case CURLOPT_PROXY_TLSAUTH_PASSWORD: printf("CURLOPT_PROXY_TLSAUTH_PASSWORD, ..."); break;
        case CURLOPT_PROXY_TLSAUTH_TYPE: printf("CURLOPT_PROXY_TLSAUTH_TYPE, ..."); break;
        case CURLOPT_PROXY_SSLCERT: printf("CURLOPT_PROXY_SSLCERT, ..."); break;
        case CURLOPT_PROXY_SSLCERTTYPE: printf("CURLOPT_PROXY_SSLCERTTYPE, ..."); break;
        case CURLOPT_PROXY_SSLKEY: printf("CURLOPT_PROXY_SSLKEY, ..."); break;
        case CURLOPT_PROXY_SSLKEYTYPE: printf("CURLOPT_PROXY_SSLKEYTYPE, ..."); break;
        case CURLOPT_PROXY_KEYPASSWD: printf("CURLOPT_PROXY_KEYPASSWD, ..."); break;
        case CURLOPT_PROXY_SSL_CIPHER_LIST: printf("CURLOPT_PROXY_SSL_CIPHER_LIST, ..."); break;
        case CURLOPT_PROXY_CRLFILE: printf("CURLOPT_PROXY_CRLFILE, ..."); break;
        case CURLOPT_PROXY_SSL_OPTIONS: printf("CURLOPT_PROXY_SSL_OPTIONS, ..."); break;
        case CURLOPT_PRE_PROXY: printf("CURLOPT_PRE_PROXY, ..."); break;
        case CURLOPT_PROXY_PINNEDPUBLICKEY: printf("CURLOPT_PROXY_PINNEDPUBLICKEY, ..."); break;
        case CURLOPT_ABSTRACT_UNIX_SOCKET: printf("CURLOPT_ABSTRACT_UNIX_SOCKET, ..."); break;
        case CURLOPT_SUPPRESS_CONNECT_HEADERS: printf("CURLOPT_SUPPRESS_CONNECT_HEADERS, ..."); break;
        case CURLOPT_REQUEST_TARGET: printf("CURLOPT_REQUEST_TARGET, ..."); break;
        case CURLOPT_SOCKS5_AUTH: printf("CURLOPT_SOCKS5_AUTH, ..."); break;
        case CURLOPT_SSH_COMPRESSION: printf("CURLOPT_SSH_COMPRESSION, ..."); break;
        case CURLOPT_MIMEPOST: printf("CURLOPT_MIMEPOST, ..."); break;
        case CURLOPT_TIMEVALUE_LARGE: printf("CURLOPT_TIMEVALUE_LARGE, ..."); break;
        case CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS: printf("CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS, ..."); break;
        case CURLOPT_RESOLVER_START_FUNCTION: printf("CURLOPT_RESOLVER_START_FUNCTION, ..."); break;
        case CURLOPT_RESOLVER_START_DATA: printf("CURLOPT_RESOLVER_START_DATA, ..."); break;
        case CURLOPT_HAPROXYPROTOCOL: printf("CURLOPT_HAPROXYPROTOCOL, ..."); break;
        case CURLOPT_DNS_SHUFFLE_ADDRESSES: printf("CURLOPT_DNS_SHUFFLE_ADDRESSES, ..."); break;

    default:
        printf("UNKNOWN, ...");
        break;
    }
    printf("\n");
}

typedef unsigned int (*Curl_setopt_t)(void* data, unsigned int tag, ...);

CURLcode curl_easy_setopt(CURL* data, CURLoption tag, long parameter)
{
    printf("==== curl_easy_setopt(..., ");//, %ld)\n", getOptName(tag), parameter);
    printOptName(tag,parameter);
    if(!data)
        return 43;
    Curl_setopt_t Curl_setopt_f = (Curl_setopt_t)dlsym(RTLD_NEXT, "curl_easy_setopt");
    unsigned int ret = Curl_setopt_f(data, tag, parameter);
    return ret;
}