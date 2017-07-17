// lb_dhSDkCtrl.cpp : Clb_dhSDkCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "lb_dhSDk.h"
#include "lb_dhSDkCtrl.h"
#include "lb_dhSDkPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(Clb_dhSDkCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(Clb_dhSDkCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// 调度映射

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

// 事件映射

BEGIN_EVENT_MAP(Clb_dhSDkCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(Clb_dhSDkCtrl, 1)
	PROPPAGEID(Clb_dhSDkPropPage::guid)
END_PROPPAGEIDS(Clb_dhSDkCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(Clb_dhSDkCtrl, "LB_DHSDK.lb_dhSDkCtrl.1",
	0xff15a064, 0x10df, 0x46d8, 0xbb, 0x42, 0x8b, 0xec, 0x5d, 0x39, 0x53, 0x70)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(Clb_dhSDkCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_Dlb_dhSDk = { 0x1A016936, 0x64F7, 0x4986, { 0xB4, 0x70, 0x17, 0xC6, 0xF2, 0xD6, 0xAF, 0xEA } };
const IID IID_Dlb_dhSDkEvents = { 0xA7B41738, 0x2E19, 0x494C, { 0x9F, 0x33, 0xB9, 0xB3, 0x83, 0xFC, 0x2A, 0x6D } };

// 控件类型信息

static const DWORD _dwlb_dhSDkOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(Clb_dhSDkCtrl, IDS_LB_DHSDK, _dwlb_dhSDkOleMisc)

// Clb_dhSDkCtrl::Clb_dhSDkCtrlFactory::UpdateRegistry -
// 添加或移除 Clb_dhSDkCtrl 的系统注册表项

BOOL Clb_dhSDkCtrl::Clb_dhSDkCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// Clb_dhSDkCtrl::Clb_dhSDkCtrl - 构造函数

Clb_dhSDkCtrl::Clb_dhSDkCtrl()
{
	InitializeIIDs(&IID_Dlb_dhSDk, &IID_Dlb_dhSDkEvents);
	// TODO:  在此初始化控件的实例数据。
}

// Clb_dhSDkCtrl::~Clb_dhSDkCtrl - 析构函数

Clb_dhSDkCtrl::~Clb_dhSDkCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// Clb_dhSDkCtrl::OnDraw - 绘图函数

void Clb_dhSDkCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// Clb_dhSDkCtrl::DoPropExchange - 持久性支持

void Clb_dhSDkCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// Clb_dhSDkCtrl::OnResetState - 将控件重置为默认状态

void Clb_dhSDkCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// Clb_dhSDkCtrl::AboutBox - 向用户显示“关于”框

void Clb_dhSDkCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_LB_DHSDK);
	dlgAbout.DoModal();
}


// Clb_dhSDkCtrl 消息处理程序


int Clb_dhSDkCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	m_masterDlg.Create(IDD_CLIENTDEMO_DIALOG, this);

	return 0;
}


void Clb_dhSDkCtrl::OnSize(UINT nType, int cx, int cy)
{
	COleControl::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	RECT activeXRect;
	GetClientRect(&activeXRect);
	m_masterDlg.MoveWindow(&activeXRect);
}


//提供给js调用
//主要用于登录
//四个参数分别代表DVRip地址，DVR端口号，登录名，登录密码。

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
	m_masterDlg.m_nChannelCount;//通道数
	strResult.Format("{\"MaxChannelCount\":\"%d\",\"IsSuccess\":\"%d\"}", m_masterDlg.m_nChannelCount, isSuccessControl);//手写json
	isSuccessControl = ControlUnknown;
	return strResult.AllocSysString();
}
BSTR Clb_dhSDkCtrl::CallLogout()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	// TODO:  在此添加调度处理程序代码
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

	// TODO: 在此添加调度处理程序代码
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


	// TODO: 在此添加调度处理程序代码
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

	// TODO: 在此添加调度处理程序代码
	m_masterDlg.PtzControl(DH_PTZ_DOWN_CONTROL,0);
	return strResult.AllocSysString();
}


void Clb_dhSDkCtrl::CallPTZUpStop()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_masterDlg.PtzControl(DH_PTZ_DOWN_CONTROL, 1);
	// TODO: 在此添加调度处理程序代码
}


BSTR Clb_dhSDkCtrl::CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: 在此添加调度处理程序代码
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

	// TODO: 在此添加调度处理程序代码
	strResult.Format("{\"IsSuccess\":\"d%\"}",  m_masterDlg.m_comboPTZData.SetCurSel(SpeedLevel - 1));
	return strResult.AllocSysString();
}
