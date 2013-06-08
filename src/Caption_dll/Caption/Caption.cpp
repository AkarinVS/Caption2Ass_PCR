// Caption.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include <Windows.h>
#include "CaptionDef.h"
#include "ColorDef.h"
#include "ARIB8CharDecode.h"
#include "CaptionMain.h"
#include "Caption.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

CCaptionMain* g_sys = NULL;

//DLL�̏�����
//�߂�l�F�G���[�R�[�h
DWORD WINAPI InitializeCP()
{
	if( g_sys != NULL ){
		return ERR_INIT;
	}
// mark10als
//	g_sys = new CCaptionMain;
	BOOL bUNICODE = FALSE;
	g_sys = new CCaptionMain(bUNICODE);
// mark10als
	return NO_ERR;
}
// mark10als
//DLL�̏����� UNICODE�Ή�
//�߂�l�F�G���[�R�[�h
DWORD WINAPI InitializeUNICODE()
{
	if( g_sys != NULL ){
		return ERR_INIT;
	}
	BOOL bUNICODE = TRUE;
	g_sys = new CCaptionMain(bUNICODE);
	return NO_ERR;
}
// mark10als

//DLL�̊J��
//�߂�l�F�G���[�R�[�h
DWORD WINAPI UnInitializeCP()
{
	if( g_sys != NULL ){
		delete g_sys;
		g_sys = NULL;
	}
	return NO_ERR;
}

DWORD WINAPI AddTSPacketCP(BYTE* pbPacket)
{
	if( g_sys == NULL ){
		return ERR_NOT_INIT;
	}
	return g_sys->AddTSPacket(pbPacket);
}

DWORD WINAPI ClearCP()
{
	if( g_sys == NULL ){
		return ERR_NOT_INIT;
	}
	return g_sys->Clear();
}

DWORD WINAPI GetTagInfoCP(LANG_TAG_INFO_DLL** ppList, DWORD* pdwListCount)
{
	if( g_sys == NULL ){
		return ERR_NOT_INIT;
	}
	return g_sys->GetTagInfo(ppList, pdwListCount);
}

DWORD WINAPI GetCaptionDataCP(unsigned char ucLangTag, CAPTION_DATA_DLL** ppList, DWORD* pdwListCount)
{
	if( g_sys == NULL ){
		return ERR_NOT_INIT;
	}
	return g_sys->GetCaptionData(ucLangTag, ppList, pdwListCount);
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

