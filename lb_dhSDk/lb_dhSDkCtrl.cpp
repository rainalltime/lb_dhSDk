// lb_dhSDkCtrl.cpp : Clb_dhSDkCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "lb_dhSDk.h"
#include "lb_dhSDkCtrl.h"
#include "lb_dhSDkPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(Clb_dhSDkCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(Clb_dhSDkCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(Clb_dhSDkCtrl, COleControl)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallLogin", dispidCallLogin, CallLogin, VT_BSTR, VTS_BSTR VTS_UI2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallLogout", dispidCallLogout, CallLogout, VT_BSTR, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(Clb_dhSDkCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(Clb_dhSDkCtrl, 1)
	PROPPAGEID(Clb_dhSDkPropPage::guid)
END_PROPPAGEIDS(Clb_dhSDkCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(Clb_dhSDkCtrl, "LB_DHSDK.lb_dhSDkCtrl.1",
	0xff15a064, 0x10df, 0x46d8, 0xbb, 0x42, 0x8b, 0xec, 0x5d, 0x39, 0x53, 0x70)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(Clb_dhSDkCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_Dlb_dhSDk = { 0x1A016936, 0x64F7, 0x4986, { 0xB4, 0x70, 0x17, 0xC6, 0xF2, 0xD6, 0xAF, 0xEA } };
const IID IID_Dlb_dhSDkEvents = { 0xA7B41738, 0x2E19, 0x494C, { 0x9F, 0x33, 0xB9, 0xB3, 0x83, 0xFC, 0x2A, 0x6D } };

// �ؼ�������Ϣ

static const DWORD _dwlb_dhSDkOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(Clb_dhSDkCtrl, IDS_LB_DHSDK, _dwlb_dhSDkOleMisc)

// Clb_dhSDkCtrl::Clb_dhSDkCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� Clb_dhSDkCtrl ��ϵͳע�����

BOOL Clb_dhSDkCtrl::Clb_dhSDkCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LB_DHSDK,
			IDB_LB_DHSDK,
			afxRegApartmentThreading,
			_dwlb_dhSDkOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// Clb_dhSDkCtrl::Clb_dhSDkCtrl - ���캯��

Clb_dhSDkCtrl::Clb_dhSDkCtrl()
{
	InitializeIIDs(&IID_Dlb_dhSDk, &IID_Dlb_dhSDkEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// Clb_dhSDkCtrl::~Clb_dhSDkCtrl - ��������

Clb_dhSDkCtrl::~Clb_dhSDkCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// Clb_dhSDkCtrl::OnDraw - ��ͼ����

void Clb_dhSDkCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// Clb_dhSDkCtrl::DoPropExchange - �־���֧��

void Clb_dhSDkCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// Clb_dhSDkCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void Clb_dhSDkCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// Clb_dhSDkCtrl::AboutBox - ���û���ʾ�����ڡ���

void Clb_dhSDkCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_LB_DHSDK);
	dlgAbout.DoModal();
}


// Clb_dhSDkCtrl ��Ϣ�������


int Clb_dhSDkCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_masterDlg.Create(IDD_CLIENTDEMO_DIALOG, this);

	return 0;
}


void Clb_dhSDkCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	RECT activeXRect;
	GetClientRect(&activeXRect);
	m_masterDlg.MoveWindow(&activeXRect);
}


//�ṩ��js����
//��Ҫ���ڵ�¼
//�ĸ������ֱ����DVRip��ַ��DVR�˿ںţ���¼������¼���롣

BSTR Clb_dhSDkCtrl::CallLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
	BOOL bValid = UpdateData(TRUE);	//Get interface input 
	if (bValid)
	{
		int err = 0;	//Storage the possible error return value.
		char *pchDVRIP;
		CString strDvrIP =ip;
		pchDVRIP = (LPSTR)(LPCSTR)strDvrIP;
		WORD wDVRPort = (WORD)port;
		char *pchUserName = (LPSTR)(LPCSTR)userName;
		char *pchPassword = (LPSTR)(LPCSTR)password;
		NET_DEVICEINFO_Ex deviceInfo = { 0 };
		//Call log in interface 
		long lRet = CLIENT_LoginEx2(pchDVRIP, wDVRPort, pchUserName,
			pchPassword, EM_LOGIN_SPEC_CAP_TCP, NULL,
			&deviceInfo, &err);
		if (0 != lRet)
		{
			m_masterDlg.m_LoginID = lRet;
			m_masterDlg.GetDlgItem(IDC_BT_Login)->EnableWindow(FALSE);
			m_masterDlg.GetDlgItem(IDC_BT_Leave)->EnableWindow(TRUE);
			m_masterDlg.GetDlgItem(IDC_BUTTON_Play)->EnableWindow(TRUE);
			//Device channel and channel dropdown menu 
			int nRetLen = 0;
			NET_DEV_CHN_COUNT_INFO stuChn = { sizeof(NET_DEV_CHN_COUNT_INFO) };
			stuChn.stuVideoIn.dwSize = sizeof(stuChn.stuVideoIn);
			stuChn.stuVideoOut.dwSize = sizeof(stuChn.stuVideoOut);
			CLIENT_QueryDevState(lRet, DH_DEVSTATE_DEV_CHN_COUNT, (char*)&stuChn, stuChn.dwSize, &nRetLen);
			m_masterDlg.m_nChannelCount = __max(deviceInfo.nChanNum, stuChn.stuVideoIn.nMaxTotal);
			//m_nChannelCount = (int)deviceInfo.byChanNum;
			int nIndex = 0;
			m_masterDlg.m_comboChannel.ResetContent();
			for (int i = 0; i<m_masterDlg.m_nChannelCount; i++)
			{
				CString str;
				str.Format("%d", i + 1);
				nIndex = m_masterDlg.m_comboChannel.AddString(str);
				m_masterDlg.m_comboChannel.SetItemData(nIndex, i);
			}
			if (0 < m_masterDlg.m_comboChannel.GetCount())
			{
				nIndex = m_masterDlg.m_comboChannel.AddString(ConvertString("Multi_Preview"));
				m_masterDlg.m_comboChannel.SetItemData(nIndex, -1);
				m_masterDlg.m_comboChannel.SetCurSel(0);
			}
			strResult = "��½�ɹ�";
		}
		else
		{
			//Display log in failure reason 
			//m_masterDlg.ShowLoginErrorReason(err);
	strResult.Format("��¼ʧ�ܣ�ʧ�ܴ��ţ�%d,����ʧ�ܵ�ԭ��", err);
			if (1 == err)		strResult+="Invalid password!";
			else if (2 == err)	strResult+="Invalid account!";
			else if (3 == err)	strResult+="Timeout!";
			else if (4 == err)	strResult+="The user has logged in!";
			else if (5 == err)	strResult+="The user has been locked!";
			else if (6 == err)	strResult+="The user has listed into illegal!";
			else if (7 == err)	strResult+="The system is busy!";
			else if (9 == err)	strResult+="You Can't find the network server!";
			else	strResult+= "Login failed!";
		}
	}
	return strResult.AllocSysString();
}


BSTR Clb_dhSDkCtrl::CallLogout()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}
