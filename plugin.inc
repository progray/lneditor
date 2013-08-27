INTERFACE_VER			EQU		00030000h
TXTINTERFACE_VER		EQU		00010000h

MAX_STRINGLEN			equ		4096
;�������
E_ERROR					EQU		-1
E_NOMEM				EQU		1
E_OVERMEM				EQU		2
E_NOTENOUGHBUFF		EQU		3
E_FILEACCESSERROR		EQU		4
E_FATALERROR			EQU		5
E_WRONGFORMAT		EQU		6
E_FILECREATEERROR		EQU		7
E_FILEREADERROR			EQU		8
E_FILEWRITEERROR		EQU		9
E_INVALIDPARAMETER		EQU		0aH
E_PLUGINERROR			EQU		0bH
E_ANALYSISFAILED			EQU		0CH

E_LINENOTEXIST			EQU		100h
E_LINETOOLONG			EQU		101h
E_CODEFAILED			EQU		102H
E_LINENOTMATCH			EQU		103H
E_LINEDENIED			EQU		104H

WLT_CUSTOM				EQU		10000H
WLT_LOADMELERR		EQU		10001h
WLT_BATCHEXPERR		EQU		10002H
WLT_BATCHIMPERR		EQU		10003H
WLT_UPDATEERR			EQU		10004h

;Return Information of GetText
RI_SUC_LINEONLY			EQU		1	;�ı�����ȡ���ڴ��У���Ҫ�����������ӵ��б�����
;RI_SUC_LISTADDED			EQU		2	;�ı������ӵ��б�����
;RI_SUC_THLINE			EQU		3	;�Ѵ����̸߳����ı���ȡ���ڴ��У������������д�����Ӧ��Ϣ�������ӵ��б���
;RI_SUC_THLIST			EQU		4	;�Ѵ����̸߳����ı����ӵ��б����У������������д���������Ϣ

RI_FAIL_FORMAT			EQU		100h	;�ű���ʽ����
RI_FAIL_MEM				EQU		101h	;�ڴ����
RI_FAIL_ERRORCS			EQU		102h	;�޷������û����õı���
RI_FAIL_UNK				EQU		0ffffh	;δ֪����

;Match Result
MR_YES					EQU		5
MR_MAYBE				EQU		3
MR_NO					EQU		0
MR_ERR					EQU		-1

;Memory Type for strings
MT_EVERYSTRING			EQU		3	;�ɲ��ȫȨ�����ַ���������д��
MT_POINTERONLY			EQU		4	;��ָ���ַ����Ĵ洢��ʽ��ÿ���ַ����ĵ�ַ�����������������ַ�������

;nCharSet��
CS_UNKNOWN			EQU		0
CS_GBK					EQU		936
CS_SJIS					EQU		932
CS_BIG5					EQU		950
CS_UTF8					EQU		65001
CS_UNICODE				EQU		-1

;nStringType��
ST_CUSTOM				EQU		0
ST_ENDWITHZERO			EQU		1
ST_PASCAL2				EQU		2
ST_PASCAL4				EQU		3
ST_SPECLEN				EQU		4	;��lpStreamIndex.nStringLen��������
ST_TXTENDA				EQU		10h
ST_TXTENDW				EQU		11h

;UI״̬
UIS_GUI					EQU		00000000H
UIS_CONSOLE				EQU		00000001H
UIS_IDLE					EQU		00000000H
UIS_BUSY					EQU		00000002H

_StreamEntry struct
	lpStart				dd		?	;�ַ�����ʼ
	nStringLen			dd		?	;�ַ�������(���ֽڼ���)����ѡ
	lpInformation			dd		?	;�ַ���������Ϣ����ѡ��������ڴ��������ͷ�
_StreamEntry ends

;�ļ���Ϣ
_FileInfo struct
	lpszName			dd		?						;�ļ���(��·��)
	hFile				dd		?						;�ļ�������þ��ֱ���ű��رղŻ��ͷš�
	
	lpStream			dd		?						;�ļ�ֱ�Ӷ����ڴ���ָ�룬�������MIC_NOPREREAD���ԣ���ָ�벻�ᱻ�Զ���д��

	nMemoryType			dd		?						;�ַ���������д��ʽ������μ�MT_XXX��˵����

	lpTextIndex			dd		?						;���ı��ַ���������ָ�롣�����е��ַ�����ʾ���б����С�
	lpStreamIndex		dd		?						;��ѡ��ԭʼ�ű��ַ���������ָ�룬ָ��_StreamEntry���顣��ΪPOINTERONLY�洢���ͣ�������롣
	;����������ʹ�õ��ڴ������VirtualAlloc(0,...)���롣
	
	nStringType			dd		?						;�ַ������͡���C�ַ�����PASCAL�ַ����ȡ��μ�ST_XXX��
	nStreamSize			dd		?						;�ļ����ȡ�
	nLine				dd		?						;�ı�������
	
	bReadOnly			dd		?						;ָ�����ļ��Ƿ�Ϊֻ�����Ƿ����б�����ࣩ
	nCharSet			dd		?						;ָʾ�����ļ����ַ�������Ϊ�����ַ������û������趨����������������д��
	
	lpCustom			dd		?						;�������ʹ�á�������ڴ�ɷ��ڴ˴���
	Reserved			dd		2		dup(?)
_FileInfo ends

;�������
MIC_CUSTOMEDIT			EQU		00000001H	;�Ǳ�׼�����������_Functions�еĺ���
MIC_CUSTOMTXTPROC		EQU		00000002H	;���ı�ר�ò����������TXT���˺�����
MIC_NOPREREAD			EQU		00000004H	;����ҪԤ�Ƚ��ļ������ڴ�
MIC_CUSTOMGUI			EQU		00000008H	;�����˽���
MIC_CUSTOMCONFIG		EQU		00000010H	;�Զ���ѡ��

MIC_NOBATCHEXP			EQU		00010000H	;��֧����������
MIC_NOBATCHIMP			EQU		00020000H	;��֧����������
MIC_NOHALFANGLE		EQU		00040000H	;��֧�ְ���ַ�

_MelInfo2 struct
	nInterfaceVer			dd		?			;�ӿڰ汾
	nCharacteristic			dd		?			;���������Ϣ
_MelInfo2 ends

_MefInfo2 struct
	nInterfaceVer			dd		?			;�ӿڰ汾
	nCharacteristic			dd		?			;���������Ϣ
_MefInfo2 ends

;�˵���Ĵ�������������OpenScript֮ǰ������һЩ�����������Ϊֱ�ӵ��á����ɱ�������ء�
_Functions struct
	OpenScript			dd		?	;10001
	LoadScript			dd		?
	SaveScript			dd		?
	SaveAs				dd		?
	CloseScipt			dd		?
	SetCode				dd		?
	ExportTxt			dd		?
	ImportTxt			dd		?
	Exit				dd		?
	dd	?
	Undo				dd		?
	Redo				dd		?
	Modify				dd		?
	PrevLine			dd		?
	NextLine			dd		?
	MarkLine			dd		?
	PrevMark			dd		?
	NextMark			dd		?
	Find				dd		?
	Replace				dd		?
	SummaryFind			dd		?
	GotoLine			dd		?
	dd	?
	SetFont				dd		?
	SetBackground		dd		?
	CustomUI			dd		?
	RecoverUI			dd		?
	dd	?
	ExportAll			dd		?
	ImportAll			dd		?
	SummaryFindAll		dd		?
	dd	?
	Config				dd		?
	dd	?
	About				dd		?
	dd	?
	ToFull				dd		?
	ToHalf				dd		?
	UnmarkAll			dd		?
	Progress			dd		?		;10040
	TxtFilter			dd		?
	Reserved			dd		10		dup(?)
_Functions ends

;�ɲ��ʵ�ּ��׹��ܵĺ���
_SimpFunc struct
	GetText		dd		?	;���ű��еĴ��ı���FileInfo�ṹҪ��д��
	SaveText	dd		?	;��ѡ�������ļ��������ʵ����ͨ��lpStream��nStreamSizeĬ�ϱ���
	ModifyLine	dd		?	;���޸ĵ���д��ű�
	SetLine		dd		?	;��ѡ���ڴ��е�һ���ı����ú�������֮������ʾ���༭����
	RetLine		dd		?	;��ѡ���༭���е�һ���ı����ú�������֮����д���ڴ���
	Release		dd		?	;��ѡ���ͷ����з�����ڴ棨ֻ�����˹��ܣ�
	GetStr		dd		?	;��Streamָ��λ�û�ȡ�ַ���
_SimpFunc ends

;���ı��ű���ר�ô������������ɲ������
_TxtFunc	struct
	IsLineAdding	dd		?	;��Ĭ��GetText�����е���
	TrimLineHead	dd		?	;��Ĭ��GetText�����е���
_TxtFunc ends

_Handles struct
	hWinMain	dd		?
	hList1		dd		?
	hList2		dd		?
	hEdit1		dd		?
	hEdit2		dd		?
	hStatus		dd		?
_Handles ends

;�����е�Ԥ�����������ݵĽṹ
_PreData struct
	hGlobalHeap		dd		?	;ȫ�ֶ�
	
	lpszConfigFile	dd		?	;�����ļ���������ȫ·��
	lpConfigs		dd		?	;����
	
	lpMenuFuncs		dd		?	;�˵�������ָ�룬ָ��_Functions�ṹ
	lpSimpFuncs		dd		?	;���״���������ָ�룬ָ��_SimpFunc�ṹ
	lpTxtFuncs		dd		?	;���ı�����������ָ�룬ָ��_TxtFunc�ṹ
	
	lpHandles		dd		?	;���ھ���б�ָ�룬ָ��_Handles�ṹ
	lpCmdOptions	dd		?
_PreData ends

_StCmdOption struct
	lpszName		dd		?
	lpszSName		dd		?
	lpszValue		dd		?
_StCmdOption ends

_StCmdOptions struct
	ScriptName		_StCmdOption		<>
	Code1			_StCmdOption		<>
	Code2			_StCmdOption		<>
	Line			_StCmdOption		<>
	Plugin			_StCmdOption		<>
	Filter			_StCmdOption		<>
	Import			_StCmdOption		<>
	Export			_StCmdOption		<>
	ScDir			_StCmdOption		<>
	TxtDir			_StCmdOption		<>
	NewDir			_StCmdOption		<>
_StCmdOptions ends

;Used in _ReplaceCharsW
RCH_ENTERS			EQU		1
RCH_TOESCAPE		EQU		10000H
RCH_FROMESCAPE	EQU		00000h