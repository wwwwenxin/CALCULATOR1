
// CACULATOR.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCACULATORApp:
// �йش����ʵ�֣������ CACULATOR.cpp
//

class CCACULATORApp : public CWinApp
{
public:
	CCACULATORApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCACULATORApp theApp;