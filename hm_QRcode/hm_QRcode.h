
// hm_QRcode.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Chm_QRcodeApp: 
// �йش����ʵ�֣������ hm_QRcode.cpp
//

class Chm_QRcodeApp : public CWinApp
{
public:
	Chm_QRcodeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Chm_QRcodeApp theApp;