
// ServerTest.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CServerTestApp:
// �� Ŭ������ ������ ���ؼ��� ServerTest.cpp�� �����Ͻʽÿ�.
//

class CServerTestApp : public CWinApp
{
public:
	CServerTestApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CServerTestApp theApp;