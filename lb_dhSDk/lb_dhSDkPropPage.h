#pragma once
#pragma once

// lb_dhSDk.h : lb_dhSDk.DLL ����ͷ�ļ�

#if !defined(AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_)
#define AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_
#endif
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// lb_dhSDkPropPage.h : Clb_dhSDkPropPage ����ҳ���������


// Clb_dhSDkPropPage : �й�ʵ�ֵ���Ϣ������� lb_dhSDkPropPage.cpp��

class Clb_dhSDkPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(Clb_dhSDkPropPage)
	DECLARE_OLECREATE_EX(Clb_dhSDkPropPage)

// ���캯��
public:
	Clb_dhSDkPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LB_DHSDK };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};


