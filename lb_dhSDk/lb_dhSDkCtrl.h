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


	////���нӿڵķ������;�Ϊ�ַ������Ѿ���ʽ����json��
	//��¼����//�ĸ������ֱ����DVRip��ַ��DVR�˿ںţ���¼������¼���롣
	afx_msg BSTR CallLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);//����ֵMaxChannelCount���ͨ������IsSuccess�Ƿ�ɹ�-2��δ֪��δ���ã�-1��ʧ�ܣ�0���ɹ���
	//�ǳ�����
	afx_msg BSTR CallLogout();//����ֵIsSuccess�Ƿ�ɹ�-2��δ֪��δ���ã�-1��ʧ�ܣ�0���ɹ���
	//���ź���//����ͨ��0~��maxchannel-1��������ģʽ0-1����
	afx_msg BSTR CallPlay(SHORT channelSelected, SHORT playMode);//IsSuccess�Ƿ�ɹ���-2��δ֪��δ���ã�-1��ʧ�ܣ�0���ɹ���
	//ֹͣ���ź���//Ҫֹͣ����Ļ��n����Ļ�����0~��n-1��
	afx_msg BSTR CallStopPlay(SHORT screenSelected=0);//IsSuccess�Ƿ�ɹ�0���ɹ���
	//������̨�ٶȺ���//�ٶȼ���1-8
	afx_msg BSTR CallSetSpeed(SHORT SpeedLevel);//IsSuccess�Ƿ�ɹ���-2������ʧ�ܣ�-1��ʧ�ܣ�0���ɹ���
	//��̨����//type�������Ͳ���type��ϸ˵����StopOrStart��ʼ���ǽ�������1��StopOrStart=false��type=0����̨��һֱ�����ƶ�.��2��StopOrStart=true��type=0����̨��ֹͣ�����ƶ�.
	afx_msg BSTR CallPTZCommand(USHORT type, VARIANT_BOOL StopOrStart = true);////IsSuccess�Ƿ�ɹ���-2��δ֪��δ���ã�-1��ʧ�ܣ�0���ɹ���
	/*type��ϸ˵��
0	// ��
1	// ��
2	// ��
3	// ��
4	// �䱶+
5	// �䱶-
6	// ����+
7	// ����-
8	// ��Ȧ+
9	// ��Ȧ-
10	// ת��Ԥ�õ�
11	// ����
12	// ɾ��
13	// ���Ѳ��
14	// �ƹ���ˢ
	
32	// ����
33	// ����
34	// ����
35	// ����
36	// ����Ԥ�õ㵽Ѳ�� Ѳ����· Ԥ�õ�ֵ
37	// ɾ��Ѳ����Ԥ�õ� Ѳ����· Ԥ�õ�ֵ
38	// ���Ѳ�� Ѳ����·
39	// ��ʼˮƽ��ת
40	// ֹͣˮƽ��ת
41	// ������߽�
42	// �����ұ߽�
43	// ��ʼ��ɨ
44	// ֹͣ��ɨ
45	// ����ģʽ��ʼ    ģʽ��·
46	// ����ģʽ����    ģʽ��·
47	// ����ģʽ    ģʽ��·
48	// ֹͣģʽ    ģʽ��·
49	// ���ģʽ    ģʽ��·
50	// ��ת����
51	// ���ٶ�λ ˮƽ����(8192) ��ֱ����(8192) �䱶(4)
52	// �������ؿ� ������(param4��Ӧ PTZ_CONTROL_AUXILIARY,param1��param2��param3��Ч,dwStop����ΪFALSE)
53	// �������ع� ������(param4��Ӧ PTZ_CONTROL_AUXILIARY,param1��param2��param3��Ч,dwStop����ΪFALSE)
54	// ������˵�
55	// �رղ˵�
56	// �˵�ȷ��
57	// �˵�ȡ��
58	// �˵���
59	// �˵���
60	// �˵���
61	// �˵���
	
64	// ����������̨ parm1����������ͨ����parm2��������������1-Ԥ�õ�2-��ɨ3-Ѳ����parm3������ֵ,��Ԥ�õ��
65	// �����л� parm1����������(��Ƶ�����)��parm2����Ƶ����ţ�parm3�������
66	// �ƹ������
67	// ��ά��ȷ��λ parm1��ˮƽ�Ƕ�(0~3600)��parm2����ֱ����(0~900)��parm3���䱶(1~128)
68	// ��ά��λ������λ
69	// �����ƶ���������,param4��Ӧ�ṹ PTZ_CONTROL_ABSOLUTELY
70	// �����ƶ���������,param4��Ӧ�ṹ PTZ_CONTROL_CONTINUOUSLY
71	// ��̨��������,��һ���ٶ�ת��Ԥ��λ��,parm4��Ӧ�ṹPTZ_CONTROL_GOTOPRESET
	
73	// ���ÿ�����(param4��Ӧ�ṹ PTZ_VIEW_RANGE_INFO)
74	// ���Ծ۽�(param4��Ӧ�ṹPTZ_FOCUS_ABSOLUTELY)
75	// ˮƽ��ɨ(param4��ӦPTZ_CONTROL_SECTORSCAN,param1��param2��param3��Ч)
76	// ��ֱ��ɨ(param4��ӦPTZ_CONTROL_SECTORSCAN,param1��param2��param3��Ч)
77	// �趨���Խ��ࡢ�۽�ֵ,param1Ϊ����,��Χ:[0,255],param2Ϊ�۽�,��Χ:[0,255],param3��param4��Ч
78	// �������۵�����̨,param4��Ӧ�ṹ PTZ_CONTROL_SET_FISHEYE_EPTZ  
79	// �������ʼ����(param4��Ӧ�ṹ��Ϊ PTZ_CONTROL_SET_TRACK_CONTROL,dwStop��FALSE, param1��param2��param3��Ч)
80	// �����ֹͣ����(param4��Ӧ�ṹ��Ϊ PTZ_CONTROL_SET_TRACK_CONTROL,dwStop��FALSE,param1��param2��param3��Ч)
81	// ��̨��������(param1��param2��param3 param4 ����Ч,dwStop����ΪFALSE)
82	// ��̨�����ƶ�,ǹ������ר��,param4��Ӧ�ṹ PTZ_CONTROL_INTELLI_TRACKMOVE
83	// ��������۽�����(param4��Ӧ�ṹ��ΪPTZ_CONTROL_SET_FOCUS_REGION,dwStop��FALSE,param1��param2��param3��Ч)
84	// ��ͣ��ɨ(param1��param2��param3param4����Ч��dwStop����ΪFALSE)
	
112	// �� + TELE param1=�ٶ�(1-8),��ͬ
113	// �� + TELE
114	// �� + TELE
115	// �� + TELE
116	// ���� + TELE
117	// ���� + TELE
118	// ���� + TELE
119	// ���� + TELE
120	// �� + WIDE param1=�ٶ�(1-8),��ͬ
121	// �� + WIDE
122	// �� + WIDE
123	// �� + WIDE
124	// ���� + WIDE
125	// ���� + WIDE
126	// ���� + WIDE
127	// ���� + WIDE
128	// �������ֵ
	*/
	afx_msg BSTR CallPTZUpStart();
	afx_msg void CallPTZUpStop();;

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

