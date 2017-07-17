#pragma once
#include "lb_dhSDKdlg.h"
#pragma once

// lb_dhSDk.h : lb_dhSDk.DLL 的主头文件

#if !defined(AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_)
#define AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_
#endif
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// lb_dhSDkCtrl.h : Clb_dhSDkCtrl ActiveX 控件类的声明。


// Clb_dhSDkCtrl : 有关实现的信息，请参阅 lb_dhSDkCtrl.cpp。

class Clb_dhSDkCtrl : public COleControl
{
	DECLARE_DYNCREATE(Clb_dhSDkCtrl)

// 构造函数
public:
	Clb_dhSDkCtrl();
	lb_dhSDKdlg m_masterDlg;

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~Clb_dhSDkCtrl();

	DECLARE_OLECREATE_EX(Clb_dhSDkCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(Clb_dhSDkCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(Clb_dhSDkCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(Clb_dhSDkCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg BSTR CallLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);
	afx_msg BSTR CallLogout();
	afx_msg BSTR CallPlay(SHORT channelSelected, SHORT playMode);//播放通道0~（maxchannel-1），播放模式0-1
	afx_msg BSTR CallStopPlay(SHORT screenSelected);
	afx_msg BSTR CallPTZUpStart();
	afx_msg void CallPTZUpStop();;
	afx_msg BSTR CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart);
	afx_msg BSTR CallSetSpeed(SHORT SpeedLevel);
// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidCallSetSpeed = 8L,
		dispidCallPTZCommand = 7L,
		dispidCallPTZUpStop = 6L,
		dispidCallPTZUpStart = 5L,
		dispidCallStopPlay = 4L,
		dispidCallPlay = 3L,
		dispidCallLogout = 2L,
		dispidCallLogin = 1L,
		dispidCallLongin = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
protected:

	
	
	

};

