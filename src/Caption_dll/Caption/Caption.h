#ifndef __CAPTION_H__
#define __CAPTION_H__

#include "CaptionDef.h"

#ifdef __cplusplus
extern "C" {
#endif

//DLL�̏�����
//�߂�l�F�G���[�R�[�h
__declspec(dllexport)
DWORD WINAPI InitializeCP();

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

#ifdef __cplusplus
}
#endif

#endif