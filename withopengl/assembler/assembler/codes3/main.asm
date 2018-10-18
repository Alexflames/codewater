extrn ExitProcess :proc,
      MessageBoxA :proc,
	  GetStdHandle :proc,
	  WriteConsoleA :proc,
	  ReadConsoleA :proc,
	  lstrlenA :proc

.data
hStdInput qword ?
hStdOutput qword ?
;sum dw ?
interfaceA db 'a = ', 0
interfaceB db 'b = ', 0
interfaceSum db 'F = 12 + (11 - a - b) = ', 0
interfaceBadChar db 'Invalid character', 0
interfacePress db 0Ah, 0Dh, 'Press any key to exit...', 0

.const
STD_OUTPUT_HANDLE equ -11       ;����� ������������ ������ ������ � WinAPI
STD_INPUT_HANDLE equ -10		;����� ������������ ������ ����� � WinAPI
CONST1 equ 12
CONST2 equ 11

.code
STACKALLOC macro arg
  push R15						;������� ������� (�����, ����� ������������ �� ����������),
								;� ������� ����� ��������� ��������� �� ������� ����
  mov R15, RSP					;�������� � ��������� ������� �������� RSP.
  sub RSP, 8*4					;��������� ����� ��� 4 ������������ ��������� � �����
  if arg						;���� ����� ���������� ������� �� ����� ����, �� ��������� ����� � ��� ���
    sub RSP, 8*arg
  endif
  and SPL, 0F0h					;��������� ���� (������� SPL) �� 16-�������� �������
endm

STACKFREE macro
  mov RSP, R15
  pop R15
endm

NULL_FIFTH_ARG macro
	mov qword ptr [RSP + 32], 0 ;������� 0, ������� � 32-�� ����� �����
endm

;==========================================================================
;��������� ������ ������
;������� ������-�������� � ����� �������.
;��������, ������� ��������� ���������: RAX, RCX, RDX, R8, R9, R10, R11.
;���������: ��������� �� ������ ������ (qword-���������� string).
;��������� �� ���������� ��������.
;������� ����� ������������ ������ ���������.

PrintString proc uses RAX RCX RDX R8 R9, string: qword
  local bytesWritten: qword     ; ������ ��������� ���������� bytesWritten ��� ��������� 
								; lpNumberOfCharsWritten ������� ������
  STACKALLOC 1					; ������� ����� � ����� ��� 4 �������� WriteConsoleA � ��� 
								; ��� ���� qword ��� ������ ���������
  mov RCX, string				; �������� � ������� ������� ��������� ��������� �� ��������� ������ 
  call lstrlenA					; � ������� �� ����� ��� ������ ������ lstrlenA. ����� ������ ����� �������� � RAX.

  mov RCX, hStdOutput			; �������� ��� ����������� ��������� � ��������������� ��������. 
  mov RDX, string				; � �������� ����������� ������ ������ ���������� hStdOutput.
  mov R8, RAX
  lea R9, bytesWritten
  NULL_FIFTH_ARG				; ������� �������� ������ ��������� (lpReserved) 
  
  call  WriteConsoleA
  STACKFREE
  ret 8							; �������� � �������� ���������, ������ ���� �� ������ ��������� 
PrintString endp
;==========================================================================
; ��������� ������ ��������� ����� �� ������
; ��������� ������ � ��������� �� � �������� �����.

; ��������, ������� ��������� ���������: RBX, RCX, RDX, R8, R9, R10, R11.
; ��������� �� ��������� ����������.
; ��������� ���������� � RAX ����������� �������� �����, � � R10 - ������ (���������� ������).
; ������� ����� ������������ ������ ���������.

ReadString proc uses RBX RCX RDX R8 R9 R11
  local readStr[64]: byte,      ; ������, � ������� ����� �������� ��������� �������
		bytesRead:   dword      ; bytesRead - ����� ����������� ��������
  STACKALLOC 1					; ������� ����� � ����� ��� �������� ReadConsoleA � ��� ��� ���� qword
  ;��������� ��� ����������� ��������� ��� ������ ReadConsoleA. lpInputControl (����� ��������) ��������� � 0
  mov RCX, hStdInput
  lea RDX, readStr
  mov R8, 64
  lea R9, bytesRead
  NULL_FIFTH_ARG
  call ReadConsoleA

  xor RCX, RCX					; ������� RCX
  mov ECX, bytesRead			; ���������� � ECX ����� ����������� ����
  sub ECX, 2					; ������ �� ���� 2: ��������� �� �������� �������� ������ � �������� �������
  mov readStr[RCX], 0           ; ������� ������ ����-���������������
  xor RBX, RBX
  mov R8, 1						; ������� �������
  stringread:
	dec RCX
	js scanningComplete         ; RCX ������ ����
	xor RAX, RAX				; ����� ������� ��������� �����
	mov AL, readStr[RCX]        ; �������� ��������� ������
	cmp AL, '-'
	jne eval
	neg RBX
	jmp scanningComplete
	eval:
	  cmp AL, 30h					; ��������, �������� �� ���������� ������
	  jl error
	  cmp AL, 39h
	  jg error					; ���� ���, �� �������� �� ����� error. 
	; ����� ������� ����� �� ���� ������� � �������� ��� � RBX. �������� RAX � 10 ��� ��� ������
	; ��������� ����� � ��������� �������. ����� �������� �� ����� ������� �� ������.
	sub RAX, 30h
	mul R8
	add RBX, RAX
	mov RAX, 10
	mul R8
	mov R8, RAX
	jmp stringread
	error:
	xor R10, R10
	STACKFREE
	ret
	scanningComplete:
	mov R10, 1
	mov RAX, RBX
	STACKFREE
	ret
ReadString endp
;===========================================================================
;��������� ������ ��������� �����
;������� ����� � �������.

;��������, ������� ��������� ���������: RAX, RCX, RDX, R8, R9, R10, R11.
;���������: ����� ��� ������ ������� qword.
;��������� �� ���������� ��������.
;������� ����� ������������ ������ ���������.
PrintSignedNumber proc uses RAX RCX RDX R8 R9 R10 R11, sum: qword
  local numberStr[22]: byte	    ; ��������� ������

  xor R8, R8                    ; ������� �������-������� ��� ������. ����� ��� R8
  mov RAX, sum
  bt sum, 63                    ; �������� �������� ����
  jnc printSignedOutput
	mov numberStr[0], '-'       ; ������ ������ - �����
	inc R8
	neg RAX
  printSignedOutput:
  mov RBX, 10					; ��� �������
  xor RCX, RCX					; ����� ������� ����� ������
  printSignedDivision:
	xor RDX, RDX				; ������� � RDX
	div RBX						
	add RDX, '0' 
	push RDX
	inc RCX
	cmp RAX, 0
	jne printSignedDivision
  ; ������� � ����
  printSignedNumToStack:
  pop RDX						; ������ ����� ����� � DL
  mov numberStr[R8], DL			; ������� ������ � ������
  inc R8
  loop printSignedNumToStack
  mov numberStr[R8], 0			; ����-����������
  lea RAX, numberStr
  push RAX
  call PrintString
  ret 8							; ������� ���� �� ������ ���������
PrintSignedNumber endp
;===========================================================================
;����� ������ ��������� ���������, ������� �� ����� ������ 'Press any key to exit...' 
;� ����� ������� ����� ������ �������. ����� ������� �� ��������� ����� ������ getch().

;��������, ������� ��������� ���������: RAX, RCX, RDX, R8, R9, R10, R11.
;��������� �� ��������� ����������.
;��������� �� ���������� ��������.
;������� ����� ������������ ������ ���������.
AwaitInput proc
  local readStr: byte,		
		bytesRead: dword
  STACKALLOC 1					; ��������� ����
  lea RAX, interfacePress		; ������� ��������� �� ������
  push RAX						; �������� ��������� ����� ����
  call PrintString

  mov RCX, hStdInput
  lea RDX, readStr
  mov R8, 1
  lea R9, bytesRead
  NULL_FIFTH_ARG
  call ReadConsoleA
  STACKFREE
  ret
AwaitInput endp
;===========================================================================

Start proc
  STACKALLOC
  mov RCX, STD_OUTPUT_HANDLE    ; ��������� ����� ������ ������ ��� ������ �������� �������
  call GetStdHandle             ; ������������ �������� � RAX
  mov hStdOutput, RAX			; �������� �������� ����������� � RAX
  ; �������� �� �� �������� ��� ������ �����
  mov RCX, STD_INPUT_HANDLE     ; ��������� ����� ������ ����� ��� ������ �������� �������
  call GetStdHandle             ; ������������ �������� � RAX
  mov hStdInput, RAX			; �������� �������� ����������� � RAX

  lea RAX, interfaceA			; ������� ��������� �� ������
  push RAX						; �������� ��������� ����� ����
  call PrintString				; ����� ������
  
  call ReadString
  cmp R10, 0
  jnz fine
	lea RAX, interfaceBadChar	; ������� ��������� �� ������
    push RAX					; �������� ��������� ����� ����
    call PrintString			; ����� ������
	jmp finish
  fine:
  mov R8, CONST2				; R8 = CONST2
  sub R8, RAX					; R8 = CONST2 - A
  lea RAX, interfaceB			; ������� ��������� �� ������
  push RAX						; �������� ��������� ����� ����
  call PrintString				; ����� ������

  call ReadString
  cmp R10, 0
  jnz fine2
	lea RAX, interfaceBadChar	; ������� ��������� �� ������
    push RAX					; �������� ��������� ����� ����
    call PrintString			; ����� ������
	jmp finish
  fine2:
  sub R8, RAX					; R8 = CONST2 - A - B

  push R9
  mov R9, CONST1
  add R9, R8
  mov R8, R9					; R8 = CONST1 + (CONST2 - A - B)
  pop R9

  lea RAX, interfaceSum			; ������� ��������� �� ������
  push RAX						; �������� ��������� ����� ����
  call PrintString				; ����� ������

  push R8
  call PrintSignedNumber

  call AwaitInput

  finish:
  xor RCX, RCX					; �������� ExitProcess - ����
  call ExitProcess              ; ����������
Start endp
end