// lb_dhSDkPropPage.cpp : Clb_dhSDkPropPage 属性页类的实现。

#include "stdafx.h"
#include "lb_dhSDk.h"
#include "lb_dhSDkPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(Clb_dhSDkPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(Clb_dhSDkPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(Clb_dhSDkPropPage, "LB_DHSDK.lb_dhSDkPropPage.1",
	0x52923b0, 0x3bb1, 0x4bd9, 0x9e, 0x48, 0x44, 0x9e, 0x75, 0xb3, 0x24, 0xad)

// Clb_dhSDkPropPage::Clb_dhSDkPropPageFactory::UpdateRegistry -
// 添加或移除 Clb_dhSDkPropPage 的系统注册表项

BOOL Clb_dhSDkPropPage::Clb_dhSDkPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LB_DHSDK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// Clb_dhSDkPropPage::Clb_dhSDkPropPage - 构造函数

Clb_dhSDkPropPage::Clb_dhSDkPropPage() :
	COlePropertyPage(IDD, IDS_LB_DHSDK_PPG_CAPTION)
{
}

// Clb_dhSDkPropPage::DoDataExchange - 在页和属性间移动数据

void Clb_dhSDkPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// Clb_dhSDkPropPage 消息处理程序
