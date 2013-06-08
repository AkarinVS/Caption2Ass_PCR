#pragma once

#define ERR_FALSE FALSE //�ėp�G���[
#define NO_ERR TRUE //����

#define ERR_INIT		10
#define ERR_NOT_INIT	11
#define ERR_SIZE		12

#define ERR_NEED_NEXT_PACKET 13 //����TS�p�P�b�g����Ȃ��Ɖ�͂ł��Ȃ�
#define ERR_CAN_NOT_ANALYZ 14 //�{����TS�p�P�b�g�H��͕s�\
#define ERR_NOT_FIRST 15 //�ŏ���TS�p�P�b�g������
#define ERR_INVALID_PACKET 16 //�{����TS�p�P�b�g�H�p�P�b�g���ŉ��Ă邩��

#define CHANGE_VERSION 20
#define NO_ERR_TAG_INFO 21
#define NO_ERR_CAPTION 22

#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#define RESET_JD_SYSTEMTIME(p)  { if(p) { *p.wYear = 1991; *p.wMonth = 12; *p.wDay = 31; *p.wHour = 0; *p.wMinute = 0; *p.wSecond = 0; *p.wMilliseconds = 0; *p.wDayOfWeek = 0; } }
#define RESET_MJD_SYSTEMTIME(p)  { if(p) { *p.wYear = 1858; *p.wMonth = 11; *p.wDay = 17; *p.wHour = 0; *p.wMinute = 0; *p.wSecond = 0; *p.wMilliseconds = 0; *p.wDayOfWeek = 0; } }


class CCaptionMain
{
public:
	typedef struct _LANG_TAG_INFO{
		unsigned char ucLangTag;
		unsigned char ucDMF;
		unsigned char ucDC;
		char szISOLangCode[4];
		unsigned char ucFormat;
		unsigned char ucTCS;
		unsigned char ucRollupMode;
		//=�I�y���[�^�[�̏���
		_LANG_TAG_INFO & operator= (const _LANG_TAG_INFO & o) {
			ucLangTag=o.ucLangTag;
			ucDMF = o.ucDMF;
			ucDC = o.ucDC;
			memcpy(szISOLangCode, o.szISOLangCode, 4 );
			ucFormat = o.ucFormat;
			ucTCS = o.ucTCS;
			ucRollupMode = o.ucRollupMode;
			return *this;
		};
	}LANG_TAG_INFO;

public:
	CCaptionMain(BOOL bUNICODE);
	~CCaptionMain(void);

	DWORD AddTSPacket(BYTE* pbPacket);
	DWORD Clear();

	DWORD GetTagInfo(LANG_TAG_INFO_DLL** ppList, DWORD* pdwListCount);
	DWORD GetCaptionData(unsigned char ucLangTag, CAPTION_DATA_DLL** ppList, DWORD* pdwListCount);

protected:
	typedef struct _PAYLOAD_DATA{
		BYTE bBuff[188];
		WORD wSize;
	} PAYLOAD_DATA;
	vector<PAYLOAD_DATA*> m_PayloadList;

	map<WORD, LANG_TAG_INFO> m_LangTagList;

	typedef struct _CAPTION_LIST{
		WORD wGroupID;
		vector<CAPTION_DATA> CaptionList;
	}CAPTION_LIST;
	map<WORD, CAPTION_LIST> m_CaptionMap;

	unsigned char m_ucVersion;

	int m_iLastCounter;
	BOOL m_bAnalyz;
	DWORD m_dwNowReadSize;
	DWORD m_dwNeedSize;

	LANG_TAG_INFO_DLL* m_pLangList;
	DWORD m_dwLangListCount;
	CAPTION_DATA_DLL* m_pCapList;
	DWORD m_dwCapListCount;

protected:
	DWORD GetTagInfo(vector<CCaptionMain::LANG_TAG_INFO>* pList);
	DWORD GetCaptionData(unsigned char ucLangTag, vector<CAPTION_DATA>* pList);

	DWORD ParseListData();
	DWORD ParseCaption(BYTE* pbBuff, DWORD dwSize);
	DWORD ParseCaptionManagementData(BYTE* pbBuff, DWORD dwSize, vector<CAPTION_DATA>* pCaptionList);
	DWORD ParseCaptionData(BYTE* pbBuff, DWORD dwSize, vector<CAPTION_DATA>* pCaptionList);
	DWORD ParseUnitData(BYTE* pbBuff, DWORD dwSize, DWORD* pdwReadSize, vector<CAPTION_DATA>* pCaptionList);

	BOOL InsertCaptionList(WORD wGroupID, vector<CAPTION_DATA>* pCaptionList);
};
