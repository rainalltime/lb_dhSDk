#pragma once

// lb_dhSDk.h : lb_dhSDk.DLL ����ͷ�ļ�

#if !defined(AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_)
#define AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// Clb_dhSDkApp : �й�ʵ�ֵ���Ϣ������� lb_dhSDk.cpp��

class Clb_dhSDkApp : public COleControlModule
{
public:
	Clb_dhSDkApp();
	BOOL InitInstance();
	int ExitInstance(); 

};
void g_SetWndStaticText(CWnd * pWnd);
CString ConvertString(CString strText);
extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

#endif