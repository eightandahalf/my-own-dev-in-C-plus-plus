; Listing generated by Microsoft (R) Optimizing Compiler Version 19.32.31332.0 

include listing.inc

INCLUDELIB MSVCRTD
INCLUDELIB OLDNAMES

msvcjmc	SEGMENT
__13941059_Math@cpp DB 01H
msvcjmc	ENDS
PUBLIC	?Log@@YAPEBDPEBD@Z				; Log
PUBLIC	?Multiply@@YAHHH@Z				; Multiply
PUBLIC	__JustMyCode_Default
PUBLIC	??_C@_08EOBDLMOI@Multiply@			; `string'
EXTRN	__CheckForDebuggerJustMyCode:PROC
;	COMDAT pdata
pdata	SEGMENT
$pdata$?Log@@YAPEBDPEBD@Z DD imagerel $LN3
	DD	imagerel $LN3+37
	DD	imagerel $unwind$?Log@@YAPEBDPEBD@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?Multiply@@YAHHH@Z DD imagerel $LN3
	DD	imagerel $LN3+53
	DD	imagerel $unwind$?Multiply@@YAHHH@Z
pdata	ENDS
;	COMDAT ??_C@_08EOBDLMOI@Multiply@
CONST	SEGMENT
??_C@_08EOBDLMOI@Multiply@ DB 'Multiply', 00H		; `string'
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?Multiply@@YAHHH@Z DD 025031201H
	DD	0b20d2312H
	DD	05009H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?Log@@YAPEBDPEBD@Z DD 025030f01H
	DD	0b20a230fH
	DD	05006H
xdata	ENDS
; Function compile flags: /Odt
;	COMDAT __JustMyCode_Default
_TEXT	SEGMENT
__JustMyCode_Default PROC				; COMDAT
	ret	0
__JustMyCode_Default ENDP
_TEXT	ENDS
; Function compile flags: /Odtp /ZI
;	COMDAT ?Multiply@@YAHHH@Z
_TEXT	SEGMENT
a$ = 80
b$ = 88
?Multiply@@YAHHH@Z PROC					; Multiply, COMDAT
; File E:\Programming\C++\Cherno_compiler\Cherno_compiler\Math.cpp
; Line 6
$LN3:
	mov	DWORD PTR [rsp+16], edx
	mov	DWORD PTR [rsp+8], ecx
	push	rbp
	sub	rsp, 96					; 00000060H
	lea	rbp, QWORD PTR [rsp+32]
	lea	rcx, OFFSET FLAT:__13941059_Math@cpp
	call	__CheckForDebuggerJustMyCode
; Line 7
	lea	rcx, OFFSET FLAT:??_C@_08EOBDLMOI@Multiply@
	call	?Log@@YAPEBDPEBD@Z			; Log
; Line 8
	mov	eax, 10
; Line 9
	lea	rsp, QWORD PTR [rbp+64]
	pop	rbp
	ret	0
?Multiply@@YAHHH@Z ENDP					; Multiply
_TEXT	ENDS
; Function compile flags: /Odtp /ZI
;	COMDAT ?Log@@YAPEBDPEBD@Z
_TEXT	SEGMENT
message$ = 80
?Log@@YAPEBDPEBD@Z PROC					; Log, COMDAT
; File E:\Programming\C++\Cherno_compiler\Cherno_compiler\Math.cpp
; Line 2
$LN3:
	mov	QWORD PTR [rsp+8], rcx
	push	rbp
	sub	rsp, 96					; 00000060H
	lea	rbp, QWORD PTR [rsp+32]
	lea	rcx, OFFSET FLAT:__13941059_Math@cpp
	call	__CheckForDebuggerJustMyCode
; Line 3
	mov	rax, QWORD PTR message$[rbp]
; Line 4
	lea	rsp, QWORD PTR [rbp+64]
	pop	rbp
	ret	0
?Log@@YAPEBDPEBD@Z ENDP					; Log
_TEXT	ENDS
END