extrn ExitProcess :proc,
      MessageBoxA :proc

.data
caption db '64-bit hello!', 0
message db 'Hello World!',  0

.code
Start proc
  sub RSP, 8*5					; ���������� �����: 32 �� 4 ���������, 
								; 8 ��� ����������� ��������
								
  xor RCX, RCX					; <=> 0.  � MASMx86-64,
  lea RDX, message				; � ������������ � ����������� __fastcall,
  lea R8, caption				; ��� ����������� �������� �������� ���������� � �������� RCX, 
  xor R9, R9					; RDX, R8 � R9 ��������������

  call MessageBoxA

  xor RCX, RCX					; �������� ExitProcess - ����

  call ExitProcess              ; ����������
Start endp
end