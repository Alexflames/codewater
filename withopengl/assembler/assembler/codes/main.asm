extrn ExitProcess :proc,
      MessageBoxA :proc

.data
caption db '64-bit hello!', 0
message db 'Hello World!',  0

.code
Start proc
  sub RSP, 8*5					; ѕодготовка стека: 32 на 4 аргумента, 
								; 8 дл€ правильного смещени€
								
  xor RCX, RCX					; <=> 0.  ¬ MASMx86-64,
  lea RDX, message				; в соответствии с соглашением __fastcall,
  lea R8, caption				; нам потребуетс€ передать значени€ аргументов в регистры RCX, 
  xor R9, R9					; RDX, R8 и R9 соответственно

  call MessageBoxA

  xor RCX, RCX					; јргумент ExitProcess - ноль

  call ExitProcess              ; завершение
Start endp
end