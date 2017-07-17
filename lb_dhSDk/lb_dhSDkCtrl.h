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


	////所有接口的返回类型均为字符串，已经格式化成json。
	//登录函数//四个参数分别代表DVRip地址，DVR端口号，登录名，登录密码。
	afx_msg BSTR CallLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);//返回值MaxChannelCount最大通道数，IsSuccess是否成功-2（未知、未调用）-1（失败）0（成功）
	//登出函数
	afx_msg BSTR CallLogout();//返回值IsSuccess是否成功-2（未知、未调用）-1（失败）0（成功）
	//播放函数//播放通道0~（maxchannel-1），播放模式0-1（）
	afx_msg BSTR CallPlay(SHORT channelSelected, SHORT playMode);//IsSuccess是否成功，-2（未知、未调用）-1（失败）0（成功）
	//停止播放函数//要停止的屏幕，n个屏幕则参数0~（n-1）
	afx_msg BSTR CallStopPlay(SHORT screenSelected=0);//IsSuccess是否成功0（成功）
	//设置云台速度函数//速度级别1-8
	afx_msg BSTR CallSetSpeed(SHORT SpeedLevel);//IsSuccess是否成功，-2（特殊失败）-1（失败）0（成功）
	//云台控制//type控制类型参照type详细说明，StopOrStart开始还是结束。例1：StopOrStart=false，type=0则云台会一直往上移动.例2：StopOrStart=true，type=0则云台会停止往上移动.
	afx_msg BSTR CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart = true);////IsSuccess是否成功，-2（未知、未调用）-1（失败）0（成功）
	/*type详细说明
0	// 上
1	// 下
2	// 左
3	// 右
4	// 变倍+
5	// 变倍-
6	// 调焦+
7	// 调焦-
8	// 光圈+
9	// 光圈-
10	// 转至预置点
11	// 设置
12	// 删除
13	// 点间巡航
14	// 灯光雨刷
	
32	// 左上
33	// 右上
34	// 左下
35	// 右下
36	// 加入预置点到巡航 巡航线路 预置点值
37	// 删除巡航中预置点 巡航线路 预置点值
38	// 清除巡航 巡航线路
39	// 开始水平旋转
40	// 停止水平旋转
41	// 设置左边界
42	// 设置右边界
43	// 开始线扫
44	// 停止线扫
45	// 设置模式开始    模式线路
46	// 设置模式结束    模式线路
47	// 运行模式    模式线路
48	// 停止模式    模式线路
49	// 清除模式    模式线路
50	// 翻转命令
51	// 快速定位 水平坐标(8192) 垂直坐标(8192) 变倍(4)
52	// 辅助开关开 辅助点(param4对应 PTZ_CONTROL_AUXILIARY,param1、param2、param3无效,dwStop设置为FALSE)
53	// 辅助开关关 辅助点(param4对应 PTZ_CONTROL_AUXILIARY,param1、param2、param3无效,dwStop设置为FALSE)
54	// 打开球机菜单
55	// 关闭菜单
56	// 菜单确定
57	// 菜单取消
58	// 菜单上
59	// 菜单下
60	// 菜单左
61	// 菜单右
	
64	// 报警联动云台 parm1：报警输入通道；parm2：报警联动类型1-预置点2-线扫3-巡航；parm3：联动值,如预置点号
65	// 矩阵切换 parm1：监视器号(视频输出号)；parm2：视频输入号；parm3：矩阵号
66	// 灯光控制器
67	// 三维精确定位 parm1：水平角度(0~3600)；parm2：垂直坐标(0~900)；parm3：变倍(1~128)
68	// 三维定位重设零位
69	// 绝对移动控制命令,param4对应结构 PTZ_CONTROL_ABSOLUTELY
70	// 持续移动控制命令,param4对应结构 PTZ_CONTROL_CONTINUOUSLY
71	// 云台控制命令,以一定速度转到预置位点,parm4对应结构PTZ_CONTROL_GOTOPRESET
	
73	// 设置可视域(param4对应结构 PTZ_VIEW_RANGE_INFO)
74	// 绝对聚焦(param4对应结构PTZ_FOCUS_ABSOLUTELY)
75	// 水平扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
76	// 垂直扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
77	// 设定绝对焦距、聚焦值,param1为焦距,范围:[0,255],param2为聚焦,范围:[0,255],param3、param4无效
78	// 控制鱼眼电子云台,param4对应结构 PTZ_CONTROL_SET_FISHEYE_EPTZ  
79	// 轨道机开始控制(param4对应结构体为 PTZ_CONTROL_SET_TRACK_CONTROL,dwStop传FALSE, param1、param2、param3无效)
80	// 轨道机停止控制(param4对应结构体为 PTZ_CONTROL_SET_TRACK_CONTROL,dwStop传FALSE,param1、param2、param3无效)
81	// 云台重启命令(param1、param2、param3 param4 均无效,dwStop设置为FALSE)
82	// 云台连续移动,枪球联动专用,param4对应结构 PTZ_CONTROL_INTELLI_TRACKMOVE
83	// 设置区域聚焦参数(param4对应结构体为PTZ_CONTROL_SET_FOCUS_REGION,dwStop传FALSE,param1、param2、param3无效)
84	// 暂停线扫(param1、param2、param3param4均无效，dwStop设置为FALSE)
	
112	// 上 + TELE param1=速度(1-8),下同
113	// 下 + TELE
114	// 左 + TELE
115	// 右 + TELE
116	// 左上 + TELE
117	// 左下 + TELE
118	// 右上 + TELE
119	// 右下 + TELE
120	// 上 + WIDE param1=速度(1-8),下同
121	// 下 + WIDE
122	// 左 + WIDE
123	// 右 + WIDE
124	// 左上 + WIDE
125	// 左下 + WIDE
126	// 右上 + WIDE
127	// 右下 + WIDE
128	// 最大命令值
	*/
	afx_msg BSTR CallPTZUpStart();
	afx_msg void CallPTZUpStop();;

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

