// lb_dhSDk.cpp : Clb_dhSDkApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "lb_dhSDk.h"
#include "lb_dhSDKdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientDemoApp


/////////////////////////////////////////////////////////////////////////////
// CClientDemoApp construction

CString ConvertString(CString strText)
{
	char *val = new char[200];
	CString strIniPath, strRet;

	memset(val, 0, 200);
	GetPrivateProfileString("String", strText, "",
		val, 200, "langchn.ini");
	strRet = val;
	if (strRet.GetLength() == 0)
	{
		//If there is no corresponding string in ini file then set it to be default value(English)
		strRet = strText;
	}
	delete val;
	return strRet;
}
//Set static text in dialogux box (English->current language)  
void g_SetWndStaticText(CWnd * pWnd)
{
	CString strCaption, strText;

	//Set main widnow title 
	pWnd->GetWindowText(strCaption);
	if (strCaption.GetLength()>0)
	{
		strText = ConvertString(strCaption);
		pWnd->SetWindowText(strText);
	}

	//Set small window title 
	CWnd * pChild = pWnd->GetWindow(GW_CHILD);
	CString strClassName;
	while (pChild)
	{
		//////////////////////////////////////////////////////////////////////////		
		//Added by Jackbin 2005-03-11
		strClassName = ((CRuntimeClass*)pChild->GetRuntimeClass())->m_lpszClassName;
		if (strClassName == "CEdit")
		{
			//The next small window 
			pChild = pChild->GetWindow(GW_HWNDNEXT);
			continue;
		}

		//////////////////////////////////////////////////////////////////////////	

		//Set current language text in small window
		pChild->GetWindowText(strCaption);
		strText = ConvertString(strCaption);
		pChild->SetWindowText(strText);

		//The next small window 
		pChild = pChild->GetWindow(GW_HWNDNEXT);
	}
}

Clb_dhSDkApp::Clb_dhSDkApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}




Clb_dhSDkApp theApp;

const GUID CDECL _tlid = { 0xD957F52F, 0x4777, 0x4553, { 0x84, 0x1E, 0x51, 0xF7, 0xA5, 0x49, 0x15, 0x57 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// Clb_dhSDkApp::InitInstance - DLL 初始化

BOOL Clb_dhSDkApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
//		AfxEnableControlContainer();
//
//		// Standard initialization
//		// If you are not using these features and wish to reduce the size
//		//  of your final executable, you should remove from the following
//		//  the specific initialization routines you do not need.
//#if _MSC_VER <= 1200 // MFC 6.0 or earlier
//#ifdef _AFXDLL
//		Enable3dControls();			// Call this when using MFC in a shared DLL
//#else
//		Enable3dControlsStatic();	// Call this when linking to MFC statically
//#endif
//#endif
//		lb_dhSDKdlg dlg;
//		m_pMainWnd = &dlg;
//		int nResponse = dlg.DoModal();
//		if (nResponse == IDOK)
//		{
//			// TODO: Place code here to handle when the dialog is
//			//  dismissed with OK
//		}
//		else if (nResponse == IDCANCEL)
//		{
//			// TODO: Place code here to handle when the dialog is
//			//  dismissed with Cancel
//		}
//
//		// Since the dialog has been closed, return FALSE so that we exit the
//		//  application, rather than start the application's message pump.
////		return FALSE;
//		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// Clb_dhSDkApp::ExitInstance - DLL 终止

int Clb_dhSDkApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
