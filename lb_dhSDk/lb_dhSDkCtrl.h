#pragma once
#include "lb_dhSDKdlg.h"
#pragma once

// lb_dhSDk.h : lb_dhSDk.DLL ����ͷ�ļ�

#if !defined(AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_)
#define AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_
#endif
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// lb_dhSDkCtrl.h : Clb_dhSDkCtrl ActiveX �ؼ����������


// Clb_dhSDkCtrl : �й�ʵ�ֵ���Ϣ������� lb_dhSDkCtrl.cpp��

class Clb_dhSDkCtrl : public COleControl
{
	DECLARE_DYNCREATE(Clb_dhSDkCtrl)

// ���캯��
public:
	Clb_dhSDkCtrl();
	lb_dhSDKdlg m_masterDlg;

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~Clb_dhSDkCtrl();

	DECLARE_OLECREATE_EX(Clb_dhSDkCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(Clb_dhSDkCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(Clb_dhSDkCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(Clb_dhSDkCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	afx_msg BSTR CallLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);
	afx_msg BSTR CallLogout();
	afx_msg BSTR CallPlay(SHORT channelSelected, SHORT playMode);//����ͨ��0~��maxchannel-1��������ģʽ0-1
	afx_msg BSTR CallStopPlay(SHORT screenSelected);
	afx_msg BSTR CallPTZUpStart();
	afx_msg void CallPTZUpStop();;
	afx_msg BSTR CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart);
	afx_msg BSTR CallSetSpeed(SHORT SpeedLevel);
// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
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

