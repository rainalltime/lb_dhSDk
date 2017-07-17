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
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallPlay", dispidCallPlay, CallPlay, VT_BSTR, VTS_I2 VTS_I2)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallStopPlay", dispidCallStopPlay, CallStopPlay, VT_BSTR, VTS_I2)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallPTZUpStart", dispidCallPTZUpStart, CallPTZUpStart, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallPTZUpStop", dispidCallPTZUpStop, CallPTZUpStop, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallPTZCommand", dispidCallPTZCommand, CallPTZCommand, VT_BSTR, VTS_UI2 VTS_BOOL)
	DISP_FUNCTION_ID(Clb_dhSDkCtrl, "CallSetSpeed", dispidCallSetSpeed, CallSetSpeed, VT_BSTR, VTS_I2)
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

	m_masterDlg.m_DvrUserName.SetString( _T(userName));
	m_masterDlg.m_DvrPassword.SetString( _T(password));
	m_masterDlg.m_DvrPort=port;
	m_masterDlg.UpdateData(false);

	DWORD   dwIP= inet_addr(ip);
	unsigned   char   *pIP = (unsigned   char*)&dwIP;
	m_masterDlg.m_DvrIPAddr.SetAddress(*pIP, *(pIP + 1), *(pIP + 2), *(pIP + 3));
	isSuccessControl = ControlUnknown;
	m_masterDlg.OnBTLogin();
	m_masterDlg.m_nChannelCount;//ͨ����
	strResult.Format("{\"MaxChannelCount\":\"%d\",\"IsSuccess\":\"%d\"}", m_masterDlg.m_nChannelCount, isSuccessControl);//��дjson
	isSuccessControl = ControlUnknown;
	return strResult.AllocSysString();
}
BSTR Clb_dhSDkCtrl::CallLogout()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	// TODO:  �ڴ���ӵ��ȴ���������
	isSuccessControl = ControlUnknown;
	m_masterDlg.OnBTLeave();
	strResult.Format("{\"IsSuccess\":\"d%\"}", isSuccessControl);
	isSuccessControl = ControlUnknown;
	return strResult.AllocSysString();
}
BSTR Clb_dhSDkCtrl::CallPlay(SHORT channelSelected, SHORT playMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	//m_masterDlg.m_comboDispNum.SetCurSel(0);
	m_masterDlg.m_comboChannel.SetCurSel(channelSelected);
	m_masterDlg.m_comboChannel.SetCurSel(playMode);
	m_masterDlg.UpdateData(false);
	isSuccessControl = ControlUnknown;
	m_masterDlg.OnBUTTONPlay();
	strResult.Format("{\"IsSuccess\":\"d%\"}", isSuccessControl);
	isSuccessControl = ControlUnknown;
	return strResult.AllocSysString();
}


BSTR Clb_dhSDkCtrl::CallStopPlay(SHORT screenSelected)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;


	// TODO: �ڴ���ӵ��ȴ���������
	m_masterDlg.m_comboDispNum.SetCurSel(screenSelected);
	m_masterDlg.UpdateData(false);
	isSuccessControl = ControlUnknown;
	m_masterDlg.OnButtonStop();
	strResult.Format("{\"IsSuccess\":\"d%\"}", isSuccessControl);
	isSuccessControl = ControlUnknown;
	return strResult.AllocSysString();
}


BSTR Clb_dhSDkCtrl::CallPTZUpStart()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	m_masterDlg.PtzControl(DH_PTZ_DOWN_CONTROL,0);
	return strResult.AllocSysString();
}


void Clb_dhSDkCtrl::CallPTZUpStop()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_masterDlg.PtzControl(DH_PTZ_DOWN_CONTROL, 1);
	// TODO: �ڴ���ӵ��ȴ���������
}


BSTR Clb_dhSDkCtrl::CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	isSuccessControl = ControlUnknown;
	m_masterDlg.PtzControl(type, StopOrStart);
	strResult.Format("{\"IsSuccess\":\"d%\"}", isSuccessControl);
	isSuccessControl=ControlUnknown;
	return strResult.AllocSysString();
}


BSTR Clb_dhSDkCtrl::CallSetSpeed(SHORT SpeedLevel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	strResult.Format("{\"IsSuccess\":\"d%\"}",  m_masterDlg.m_comboPTZData.SetCurSel(SpeedLevel - 1));
	return strResult.AllocSysString();
}
