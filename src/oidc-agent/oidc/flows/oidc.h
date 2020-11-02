#ifndef OIDC_H
#define OIDC_H

#include "account/account.h"
#include "ipc/pipe.h"

#define TOKENPARSEMODE_SAVE_AT 0x01
#define TOKENPARSEMODE_SAVE_AT_IF(X) ((X) ? 0x01 : 0)
#define TOKENPARSEMODE_RETURN_AT 0x02
#define TOKENPARSEMODE_RETURN_ID 0x04

char* generatePostData(char* k1, char* v1, ...);
char* generatePostDataFromList(list_t* list);
char* parseTokenResponse(const unsigned char mode, const char* res,
                         struct oidc_account* a, struct ipcPipe pipes,
                         const unsigned char refreshFlow);
char* parseTokenResponseCallbacks(
    const unsigned char mode, const char* res, struct oidc_account* a,
    void (*errorHandling)(const char*, const char*), struct ipcPipe pipes,
    const unsigned char refreshFlow);

#endif  // OIDC_H
