; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBHMNumberPropPage
LastTemplate=CEdit
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "BHMNumber.h"
CDK=Y

ClassCount=3
Class1=CBHMNumberCtrl
Class2=CBHMNumberPropPage

ResourceCount=2
LastPage=0
Resource1=IDD_ABOUTBOX_BHMNUMBER
Class3=CBHMNumEdit
Resource2=IDD_PROPPAGE_BHMNUMBER

[CLS:CBHMNumberCtrl]
Type=0
HeaderFile=BHMNumberCtl.h
ImplementationFile=BHMNumberCtl.cpp
Filter=W
BaseClass=COleControl
VirtualFilter=wWC
LastObject=CBHMNumberCtrl

[CLS:CBHMNumberPropPage]
Type=0
HeaderFile=BHMNumberPpg.h
ImplementationFile=BHMNumberPpg.cpp
Filter=D
LastObject=CBHMNumberPropPage
BaseClass=COlePropertyPage
VirtualFilter=idWC

[DLG:IDD_ABOUTBOX_BHMNUMBER]
Type=1
Class=?
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_PROPPAGE_BHMNUMBER]
Type=1
Class=CBHMNumberPropPage
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_COMBO_APPEARANCE,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO_ALIGNMENT,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_COMBO_DISPLAYMASK,combobox,1344340226
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_MASK,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_VALUE,edit,1350639744

[CLS:CBHMNumEdit]
Type=0
HeaderFile=BHMNumEdit.h
ImplementationFile=BHMNumEdit.cpp
BaseClass=CNumEdit
Filter=W
VirtualFilter=WC
LastObject=CBHMNumEdit

