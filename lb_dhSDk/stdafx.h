#if !defined(AFX_STDAFX_H__D30A0C81_2AD3_4EFC_8E13_A06D790FC362__INCLUDED_)
#define AFX_STDAFX_H__D30A0C81_2AD3_4EFC_8E13_A06D790FC362__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��
#define _ATL_NO_AUTOMATIC_NAMESPACE             // ���������Ƴ�ͻ

#include <afxctl.h>         // ActiveX �ؼ��� MFC ֧��
#include <afxext.h>         // MFC ��չ
#include <afxdisp.h>        // MFC Automation classes
#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

// �����ϣ��ʹ�� MFC ���ݿ��࣬
//  ��ɾ����������������ļ�
#ifndef _WIN64

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC ���ݿ���
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO ���ݿ���
#endif // _AFX_NO_DAO_SUPPORT

#endif // _WIN64
#include <afxcontrolbars.h>

#endif