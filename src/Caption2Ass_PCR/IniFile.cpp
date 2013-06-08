//------------------------------------------------------------------------------
//IniFile.cpp
//------------------------------------------------------------------------------
//ini�t�@�C������

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include "IniFile.h"

extern long assSWF0offset;
extern long assSWF5offset;
extern long assSWF7offset;
extern long assSWF9offset;
extern long assSWF11offset;
extern TCHAR *passType;
extern TCHAR *passComment1;
extern TCHAR *passComment2;
extern TCHAR *passComment3;
extern long assPlayResX;
extern long assPlayResY;
extern TCHAR *passDefaultFontname;
extern long assDefaultFontsize;
extern TCHAR *passDefaultStyle;
extern TCHAR *passBoxFontname;
extern long assBoxFontsize;
extern TCHAR *passBoxStyle;
extern TCHAR *passRubiFontname;
extern long assRubiFontsize;
extern TCHAR *passRubiStyle;

//ini�t�@�C���p�X���擾
void GetPrivateProfilePath(TCHAR* pIniFilePath)
{
    TCHAR wkPath[_MAX_PATH];
    TCHAR wkDrive[_MAX_DRIVE];
    TCHAR wkDir[_MAX_DIR];
    TCHAR wkFileName[_MAX_FNAME];
    TCHAR wkExt[_MAX_EXT];
    DWORD dwRet;

    //������
    memset(wkPath, 0x00, sizeof(wkPath));
    memset(wkDrive, 0x00, sizeof(wkDrive));
    memset(wkDir, 0x00, sizeof(wkDir));
    memset(wkExt, 0x00, sizeof(wkExt));
    dwRet = 0;

    //���s���̃v���Z�X�̃t���p�X�����擾����
    dwRet = GetModuleFileName(NULL, wkPath, sizeof(wkPath));
    if (dwRet == 0) {
    //�G���[�����Ȃ�(�ȗ�)
    }

    //�t���p�X���𕪊�����
    _splitpath_s(wkPath, wkDrive, _MAX_DRIVE, wkDir, _MAX_DIR, wkFileName, _MAX_FNAME, wkExt, _MAX_EXT);

    _tcscat_s(pIniFilePath, _MAX_DRIVE, wkDrive);
    _tcscat_s(pIniFilePath, _MAX_DIR  , wkDir);
    _tcscat_s(pIniFilePath, _MAX_FNAME, wkFileName);
    _tcscat_s(pIniFilePath, _MAX_EXT  , _T(".ini"));
    return;
}

//PrivateProfile�t�@�C������ǂݍ���
int IniFileRead(TCHAR* passType)
{
    int iStrLen = 256;
    passComment1 = new TCHAR[iStrLen];
    memset(passComment1, 0, sizeof(TCHAR) * iStrLen);
    passComment2 = new TCHAR[iStrLen];
    memset(passComment2, 0, sizeof(TCHAR) * iStrLen);
    passComment3 = new TCHAR[iStrLen];
    memset(passComment3, 0, sizeof(TCHAR) * iStrLen);
    passDefaultFontname = new TCHAR[iStrLen];
    memset(passDefaultFontname, 0, sizeof(TCHAR) * iStrLen);
    passDefaultStyle = new TCHAR[iStrLen];
    memset(passDefaultStyle, 0, sizeof(TCHAR) * iStrLen);
    passBoxFontname = new TCHAR[iStrLen];
    memset(passBoxFontname, 0, sizeof(TCHAR) * iStrLen);
    passBoxStyle = new TCHAR[iStrLen];
    memset(passBoxStyle, 0, sizeof(TCHAR) * iStrLen);
    passRubiFontname = new TCHAR[iStrLen];
    memset(passRubiFontname, 0, sizeof(TCHAR) * iStrLen);
    passRubiStyle = new TCHAR[iStrLen];
    memset(passRubiStyle, 0, sizeof(TCHAR) * iStrLen);

    //ini�t�@�C���p�X�擾
    TCHAR pIniFilePath[_MAX_PATH];
    memset(pIniFilePath, 0x00, sizeof(pIniFilePath));

    GetPrivateProfilePath(pIniFilePath);
    // Open ini File
    FILE *fp = NULL;
    if (_tfopen_s(&fp, pIniFilePath, _T("r")) || !fp) {
        if (_tfopen_s(&fp, pIniFilePath, _T("wb")) || !fp)
            return -1;
        fprintf(fp, "%s", DEFAULT_INI);
    }
    fclose(fp);
    // Caption offset of SWF-Mode
    assSWF0offset=GetPrivateProfileInt(_T("SWFModeOffset"),_T("SWF0offset"),0,pIniFilePath);
    assSWF5offset=GetPrivateProfileInt(_T("SWFModeOffset"),_T("SWF5offset"),0,pIniFilePath);
    assSWF7offset=GetPrivateProfileInt(_T("SWFModeOffset"),_T("SWF7offset"),0,pIniFilePath);
    assSWF9offset=GetPrivateProfileInt(_T("SWFModeOffset"),_T("SWF9offset"),0,pIniFilePath);
    assSWF11offset=GetPrivateProfileInt(_T("SWFModeOffset"),_T("SWF11offset"),0,pIniFilePath);

    // ass header infomation
    TCHAR *tmpBuff;
    tmpBuff = new TCHAR[iStrLen];
    memset(tmpBuff, 0, sizeof(TCHAR) * iStrLen);
    WCHAR str[1024] = {0};

    GetPrivateProfileString(passType,_T("Comment1"),NULL,tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passComment1, 1024, NULL, NULL);
    GetPrivateProfileString(passType,_T("Comment2"),NULL,tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passComment2, 1024, NULL, NULL);
    GetPrivateProfileString(passType,_T("Comment3"),NULL,tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passComment3, 1024, NULL, NULL);
    assPlayResX=GetPrivateProfileInt(passType,_T("PlayResX"),1920,pIniFilePath);
    assPlayResY=GetPrivateProfileInt(passType,_T("PlayResY"),1080,pIniFilePath);

    GetPrivateProfileString(passType,_T("DefaultFontname"),_T("MS UI Gothic"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passDefaultFontname, 1024, NULL, NULL);
    assDefaultFontsize=GetPrivateProfileInt(passType,_T("DefaultFontsize"),90,pIniFilePath);
    GetPrivateProfileString(passType,_T("DefaultStyle"),_T("&H00FFFFFF,&H000000FF,&H00000000,&H00000000,0,0,0,0,100,100,15,0,1,2,2,1,10,10,10,0"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passDefaultStyle, 1024, NULL, NULL);

    GetPrivateProfileString(passType,_T("BoxFontname"),_T("MS UI Gothic"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passBoxFontname, 1024, NULL, NULL);
    assBoxFontsize=GetPrivateProfileInt(passType,_T("BoxFontsize"),90,pIniFilePath);
    GetPrivateProfileString(passType,_T("BoxStyle"),_T("&HFFFFFFFF,&H000000FF,&H00FFFFFF,&H00FFFFFF,0,0,0,0,100,100,0,0,1,2,2,2,10,10,10,0"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passBoxStyle, 1024, NULL, NULL);

    GetPrivateProfileString(passType,_T("RubiFontname"),_T("MS UI Gothic"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passRubiFontname, 1024, NULL, NULL);
    assRubiFontsize=GetPrivateProfileInt(passType,_T("RubiFontsize"),50,pIniFilePath);
    GetPrivateProfileString(passType,_T("RubiStyle"),_T("&H00FFFFFF,&H000000FF,&H00000000,&H00000000,0,0,0,0,100,100,0,0,1,2,2,1,10,10,10,0"),tmpBuff,iStrLen,pIniFilePath);
    MultiByteToWideChar(932, 0, tmpBuff, -1, str, 1024);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, passRubiStyle, 1024, NULL, NULL);

    return 0;
}
