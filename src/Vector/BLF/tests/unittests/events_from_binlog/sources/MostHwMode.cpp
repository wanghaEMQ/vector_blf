#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <stdio.h>
#define STRICT
#include <windows.h>

#include "binlog.h"

int main(int argc, char** argv)
{
    /* create file */
    LPCTSTR pFileName = _T("test_MostHwMode.blf");
    HANDLE hFile = BLCreateFile(pFileName, GENERIC_WRITE);
    if (hFile == INVALID_HANDLE_VALUE) {
        return -1;
    }

    /* set write options */
    if (!BLSetWriteOptions(hFile, BL_COMPRESSION_NONE, 0)) {
        return -1;
    }

    /* define object */
    VBLMOSTHWMode obj;
    memset(&obj, 0, sizeof(VBLMOSTHWMode));

    /* VBLMOSTHWMode */
    obj.mChannel = 0x1111;
    obj.mDummy1 = 0x2222;
    obj.mHWMode = 0x3333;
    obj.mHWModeMask = 0x4444;

    /* VBLObjectHeader2 */
    obj.mHeader.mObjectFlags = BL_OBJ_FLAG_TIME_ONE_NANS;
    obj.mHeader.mTimeStampStatus = 0x22;
    obj.mHeader.mReserved1 = 0x33;
    obj.mHeader.mObjectVersion = 0;
    obj.mHeader.mObjectTimeStamp = 0x4444444444444444;
    obj.mHeader.mOriginalTimeStamp = 0x5555555555555555;

    /* VBLObjectHeaderBase */
    obj.mHeader.mBase.mSignature = BL_OBJ_SIGNATURE;
    obj.mHeader.mBase.mHeaderSize = sizeof(obj.mHeader);
    obj.mHeader.mBase.mHeaderVersion = 1;
    obj.mHeader.mBase.mObjectSize = sizeof(VBLMOSTHWMode);
    obj.mHeader.mBase.mObjectType = BL_OBJ_TYPE_MOST_HWMODE;

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
