#pragma once
#pragma once

// lb_dhSDk.h : lb_dhSDk.DLL 的主头文件

#if !defined(AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_)
#define AFX_CLIENTDEMO_H__98F68F83_D38E_403B_9EEA_0C951855AD74__INCLUDED_
#endif
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// lb_dhSDkPropPage.h : Clb_dhSDkPropPage 属性页类的声明。


// Clb_dhSDkPropPage : 有关实现的信息，请参阅 lb_dhSDkPropPage.cpp。

class Clb_dhSDkPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(Clb_dhSDkPropPage)
	DECLARE_OLECREATE_EX(Clb_dhSDkPropPage)

// 构造函数
public:
	Clb_dhSDkPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_LB_DHSDK };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};


