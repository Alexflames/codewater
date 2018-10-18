extrn ExitProcess :proc,
      MessageBoxA :proc,
    GetUserNameA :proc,
    GetComputerNameA :proc,
    GetTempPathA :proc,
    GetVersionExA :proc,
    wsprintfA :proc

.data
cap db '<заголовок окна>', 0
fmt db 'Username: %s',0Ah,
       'Computer name: %s', 0Ah,
       'TMP Path: %s', 0Ah,
       'OS version: %d.%d.%d', 0

.const
szMAX_COMP_NAME equ 16
szUNLEN equ 257
szMAX_PATH equ 261

.code
OSVERSIONINFO struct
    dwOSVersionInfoSize dword ?
    dwMajorVersion      dword ?
    dwMinorVersion      dword ?
    dwBuildNumber       dword ?
    dwPlatformId        dword ?
    szCSDVersion        byte 128 dup(?)
OSVERSIONINFO ends

Start proc
  local _msg[1024]                 :byte,
    _username[szUNLEN]         :byte,
    _compname[szMAX_COMP_NAME] :byte,
    _temppath[szMAX_PATH]      :byte,
    _v                         :OSVERSIONINFO,
    _size                      :dword
    
  sub RSP, 8*5          ; Подготовка стека под 5 аргументов
  and SPL, 0F0h

  mov _size, szUNLEN      
  lea RCX, _username
  lea RDX, _size
  call GetUserNameA

  mov _size, szMAX_COMP_NAME
  lea RCX, _compname
  lea RDX, _size
  call GetComputerNameA

  mov _size, szMAX_PATH
  lea RDX, _temppath      ; В обратном
  lea RCX, _size        ; порядке

  call GetTempPathA

  xor AL, AL          ; очищаем регистр AL
  mov RCX, size _v        ; занесем в регистр RCX размер экземпляра _v
  lea RDI, _v
  rep stos byte ptr [RDI]       ; применим stos для всех полей структуры (обнуление)

  mov _v.dwOSVersionInfoSize, size _v
  lea RCX, _v
  call GetVersionExA

  lea RCX, _msg
  lea RDX, fmt
  lea R8, _username
  lea R9, _compname
  lea RAX, _temppath
  mov [RSP + 20h], RAX
  mov RAX, qword ptr _v.dwMajorVersion
  mov [RSP + 28h], RAX
  mov RAX, qword ptr _v.dwMinorVersion
  mov [RSP + 30h], RAX
  mov RAX, qword ptr _v.dwBuildNumber
  mov [RSP + 38h], RAX
  call wsprintfA

  xor RCX, RCX
  xor R9, R9
  lea RDX, _msg
  lea R8, cap
  call MessageBoxA

  xor RCX, RCX          ; Аргумент ExitProcess - ноль

  call ExitProcess              ; завершение
Start endp
end