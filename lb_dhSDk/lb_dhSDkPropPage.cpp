// lb_dhSDkPropPage.cpp : Clb_dhSDkPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "lb_dhSDk.h"
#include "lb_dhSDkPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(Clb_dhSDkPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(Clb_dhSDkPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(Clb_dhSDkPropPage, "LB_DHSDK.lb_dhSDkPropPage.1",
	0x52923b0, 0x3bb1, 0x4bd9, 0x9e, 0x48, 0x44, 0x9e, 0x75, 0xb3, 0x24, 0xad)

// Clb_dhSDkPropPage::Clb_dhSDkPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� Clb_dhSDkPropPage ��ϵͳע�����

BOOL Clb_dhSDkPropPage::Clb_dhSDkPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LB_DHSDK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// Clb_dhSDkPropPage::Clb_dhSDkPropPage - ���캯��

Clb_dhSDkPropPage::Clb_dhSDkPropPage() :
	COlePropertyPage(IDD, IDS_LB_DHSDK_PPG_CAPTION)
{
}

// Clb_dhSDkPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void Clb_dhSDkPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// Clb_dhSDkPropPage ��Ϣ�������
