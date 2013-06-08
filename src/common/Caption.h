//------------------------------------------------------------------------------
// Caption.h
//------------------------------------------------------------------------------
#ifndef __CAPTION_H__
#define __CAPTION_H__

#include "CaptionDef.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CAPTION_EXPORTS

//DLL�̏�����
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI InitializeCP();

//DLL�̏����� UNICODE�Ή�
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI InitializeUNICODE();

//DLL�̊J��
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI UnInitializeCP();

//188�o�C�gTS1�p�P�b�g
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI AddTSPacketCP(BYTE* pbPacket);

//�����f�[�^�N���A
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI ClearCP();

//�������擾
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI GetTagInfoCP(LANG_TAG_INFO_DLL** ppList, DWORD* pdwListCount);

//�����f�[�^�{���擾
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI GetCaptionDataCP(unsigned char ucLangTag, CAPTION_DATA_DLL** ppList, DWORD* pdwListCount);

#else /* CAPTION_EXPORTS */

typedef DWORD (WINAPI* InitializeCP)();

typedef DWORD (WINAPI* InitializeUNICODECP)();

typedef DWORD (WINAPI* UnInitializeCP)();

typedef DWORD (WINAPI* AddTSPacketCP)(BYTE* pbPacket);

typedef DWORD (WINAPI* ClearCP)();

typedef DWORD (WINAPI* GetTagInfoCP)(LANG_TAG_INFO_DLL** ppList, DWORD* pdwListCount);

typedef DWORD (WINAPI* GetCaptionDataCP)(unsigned char ucLangTag, CAPTION_DATA_DLL** ppList, DWORD* pdwListCount);

#endif /* CAPTION_EXPORTS */

#ifdef __cplusplus
}
#endif

#endif // __CAPTION_H__
