      include \masm32\include\windows.inc
      include \masm32\include\masm32.inc      
      include \masm32\include\gdi32.inc
      include \masm32\include\user32.inc
      include \masm32\include\kernel32.inc
      include \masm32\include\Comctl32.inc
      include \masm32\include\comdlg32.inc
      include \masm32\include\shell32.inc
      include \masm32\include\oleaut32.inc
      include \masm32\include\msvcrt.inc
      include \masm32\include\shlwapi.inc
      include \masm32\macros\macros.asm
      include \masm32\macros\strings.mac

      includelib \masm32\lib\masm32.lib
      includelib \masm32\lib\gdi32.lib
      includelib \masm32\lib\user32.lib
      includelib \masm32\lib\kernel32.lib
      includelib \masm32\lib\Comctl32.lib
      includelib \masm32\lib\comdlg32.lib
      includelib \masm32\lib\shell32.lib
      includelib \masm32\lib\oleaut32.lib
      includelib \masm32\lib\shlwapi.lib
      includelib \masm32\lib\msvcrt.lib
      
	include \masm32\lneditor\export.inc
	include \masm32\lneditor\rsrc.inc
	include \masm32\lneditor\plugin.inc
	include \masm32\lneditor\config.inc

	includelib \masm32\lneditor\lnedit.lib

ModifyLine proto :dword,:dword
SaveText proto :dword
Release proto :dword
_memcpy proto
_IsEncode proto :dword
_Encode proto :dword,:dword
_CmpStrOut proto :dword

YukaStruct struct
	lpRes		dd		?
	nResLen		dd		?
	lpPrg		dd		?
	nPrgLen		dd		?
	lpCmd		dd		?
	nCmdLen		dd		?
	lpUnk		dd		?
	nUnkLen		dd		?
	nUnkVals	dd		3 dup (?)
YukaStruct ends

YukaHeader struct
	Magic		db		8 dup (?)
	Version		dd		?
	HeaderLen	dd		?
	Resv		dd		?
	ResOff		dd		?
	ResSize		dd		?
	PrgOff		dd		?
	PrgCount	dd		?
	CmdOff		dd		?
	CmdCount	dd		?
	UnkOff		dd		?
	UnkCount	dd		?
	UnkVals		dd		3 dup (?)
YukaHeader ends

.data?
	hInstance		dd		?
	hGlobalHeap		dd		?

.data
	szStrOut		db		'StrOut',0
	szStrOutNWC	db		'StrOutNW',0
	
	szHeader		db		'yks',0,'1.0',0,1,0,0,0,40h,0,0,0,0,0,0,0
	
	
		