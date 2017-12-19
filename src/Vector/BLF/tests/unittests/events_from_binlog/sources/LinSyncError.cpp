#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <stdio.h>
#define STRICT
#include <windows.h>

#include "binlog.h"

int main(int argc, char** argv)
{
    /* create file */
    LPCTSTR pFileName = _T("test_LinSyncError.blf");
    HANDLE hFile = BLCreateFile(pFileName, GENERIC_WRITE);
    if (hFile == INVALID_HANDLE_VALUE) {
        return -1;
    }

    /* set write options */
    if (!BLSetWriteOptions(hFile, BL_COMPRESSION_NONE, 0)) {
        return -1;
    }

    /* define object */
    VBLLINSyncError obj;
    memset(&obj, 0, sizeof(VBLLINSyncError));

    /* VBLLINSyncError */
    obj.mChannel = 0x1111;
    obj.mDummy = 0x2222;
    obj.mTimeDiff[0] = 0x3333;
    obj.mTimeDiff[1] = 0x4444;
    obj.mTimeDiff[2] = 0x5555;
    obj.mTimeDiff[3] = 0x6666;

    /* VBLObjectHeader */
    obj.mHeader.mObjectFlags = BL_OBJ_FLAG_TIME_ONE_NANS;
    obj.mHeader.mClientIndex = 0x1111;
    obj.mHeader.mObjectVersion = 0;
    obj.mHeader.mObjectTimeStamp = 0x2222222222222222;

    /* VBLObjectHeaderBase */
    obj.mHeader.mBase.mSignature = BL_OBJ_SIGNATURE;
    obj.mHeader.mBase.mHeaderSize = sizeof(obj.mHeader);
    obj.mHeader.mBase.mHeaderVersion = 1;
    obj.mHeader.mBase.mObjectSize = sizeof(VBLLINSyncError);
    obj.mHeader.mBase.mObjectType = BL_OBJ_TYPE_LIN_SYN_ERROR;

    /* write object */
    if (!BLWriteObject(hFile, &obj.mHeader.mBase)) {
        return -1;
    }

    /* write object again */
    if (!BLWriteObject(hFile, &obj.mHeader.mBase)) {
        return -1;
    }

    /* close handle */
    if (!BLCloseHandle(hFile)) {
        return -1;
    }

    return 0;
}
