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
STD_OUTPUT_HANDLE equ -11       ;Номер стандартного потока вывода в WinAPI
STD_INPUT_HANDLE equ -10		;Номер стандартного потока ввода в WinAPI
CONST1 equ 12
CONST2 equ 11

.code
STACKALLOC macro arg
  push R15						;Выберем регистр (любой, кроме используемых по соглашению),
								;в котором будет храниться указатель на «старый» стек
  mov R15, RSP					;Поместим в выбранный регистр значение RSP.
  sub RSP, 8*4					;Освободим место под 4 обязательных аргумента в стеке
  if arg						;Если число аргументов макроса не равно нулю, то освободим место и для них
    sub RSP, 8*arg
  endif
  and SPL, 0F0h					;Выровняем стек (регистр SPL) по 16-байтовой границе
endm

STACKFREE macro
  mov RSP, R15
  pop R15
endm

NULL_FIFTH_ARG macro
	mov qword ptr [RSP + 32], 0 ;заносит 0, начиная с 32-го байта стека
endm

;==========================================================================
;Процедура вывода строки
;Выводит строку-аргумент в поток консоли.
;Регистры, которые требуется сохранить: RAX, RCX, RDX, R8, R9, R10, R11.
;Аргументы: указатель на начало строки (qword-переменная string).
;Процедура не возвращает значений.
;Очистка стека производится внутри процедуры.

PrintString proc uses RAX RCX RDX R8 R9, string: qword
  local bytesWritten: qword     ; Введем локальную переменную bytesWritten для аргумента 
								; lpNumberOfCharsWritten функции записи
  STACKALLOC 1					; Выделим место в стеке под 4 регистра WriteConsoleA и ещё 
								; под один qword для пятого аргумента
  mov RCX, string				; Поместим в регистр первого аргумента указатель на выводимую строку 
  call lstrlenA					; и получим ее длину при помощи вызова lstrlenA. Длина строки будет помещена в RAX.

  mov RCX, hStdOutput			; Поместим все необходимые аргументы в соответствующие регистры. 
  mov RDX, string				; В качестве дескриптора потока вывода используем hStdOutput.
  mov R8, RAX
  lea R9, bytesWritten
  NULL_FIFTH_ARG				; Обнулим значение пятого аргумента (lpReserved) 
  
  call  WriteConsoleA
  STACKFREE
  ret 8							; Вернемся в основную программу, очищая стек от одного аргумента 
PrintString endp
;==========================================================================
; Процедура чтения знакового числа из строки
; Считывает строку и переводит ее в знаковое число.

; Регистры, которые требуется сохранить: RBX, RCX, RDX, R8, R9, R10, R11.
; Процедура не принимает аргументов.
; Процедура возвращает в RAX прочитанное знаковое число, а в R10 - статус (успешность чтения).
; Очистка стека производится внутри процедуры.

ReadString proc uses RBX RCX RDX R8 R9 R11
  local readStr[64]: byte,      ; строка, в которую будут занесены считанные символы
		bytesRead:   dword      ; bytesRead - число прочитанных символов
  STACKALLOC 1					; Выделим место в стеке под регистры ReadConsoleA и ещё под один qword
  ;Разместим все необходимые аргументы для вызова ReadConsoleA. lpInputControl (пятый аргумент) установим в 0
  mov RCX, hStdInput
  lea RDX, readStr
  mov R8, 64
  lea R9, bytesRead
  NULL_FIFTH_ARG
  call ReadConsoleA

  xor RCX, RCX					; Сбросим RCX
  mov ECX, bytesRead			; Переместим в ECX число прочитанных байт
  sub ECX, 2					; Вычтем из него 2: избавимся от символов переноса строки и возврата каретки
  mov readStr[RCX], 0           ; Сделаем строку нуль-терминированной
  xor RBX, RBX
  mov R8, 1						; Степени десятки
  stringread:
	dec RCX
	js scanningComplete         ; RCX меньше нуля
	xor RAX, RAX				; будем хранить очередную цифру
	mov AL, readStr[RCX]        ; поместим очередной символ
	cmp AL, '-'
	jne eval
	neg RBX
	jmp scanningComplete
	eval:
	  cmp AL, 30h					; Проверка, является ли десятичным числом
	  jl error
	  cmp AL, 39h
	  jg error					; Если нет, то перейдем на метку error. 
	; Иначе получим число из кода символа и прибавим его к RBX. Увеличим RAX в 10 раз для записи
	; следующей цифры в следующем разряде. Затем перейдем на метку прохода по строке.
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
;Процедура вывода знакового числа
;Выводит число в консоль.

;Регистры, которые требуется сохранить: RAX, RCX, RDX, R8, R9, R10, R11.
;Аргументы: число для вывода размера qword.
;Процедура не возвращает значений.
;Очистка стека производится внутри процедуры.
PrintSignedNumber proc uses RAX RCX RDX R8 R9 R10 R11, sum: qword
  local numberStr[22]: byte	    ; Выводимая строка

  xor R8, R8                    ; Обнулим регистр-счетчик для строки. Пусть это R8
  mov RAX, sum
  bt sum, 63                    ; проверка старшего бита
  jnc printSignedOutput
	mov numberStr[0], '-'       ; первый символ - минус
	inc R8
	neg RAX
  printSignedOutput:
  mov RBX, 10					; для деления
  xor RCX, RCX					; далее запишем длину строки
  printSignedDivision:
	xor RDX, RDX				; остаток в RDX
	div RBX						
	add RDX, '0' 
	push RDX
	inc RCX
	cmp RAX, 0
	jne printSignedDivision
  ; Перенос в стек
  printSignedNumToStack:
  pop RDX						; символ цифры будет в DL
  mov numberStr[R8], DL			; заносим символ в строку
  inc R8
  loop printSignedNumToStack
  mov numberStr[R8], 0			; нуль-терминатор
  lea RAX, numberStr
  push RAX
  call PrintString
  ret 8							; очищаем стек от одного аргумента
PrintSignedNumber endp
;===========================================================================
;Чтобы успеть прочитать результат, выведем на экран строку 'Press any key to exit...' 
;и будем ожидать ввода одного символа. Таким образом мы реализуем некий аналог getch().

;Регистры, которые требуется сохранить: RAX, RCX, RDX, R8, R9, R10, R11.
;Процедура не принимает аргументов.
;Процедура не возвращает значения.
;Очистка стека производится внутри процедуры.
AwaitInput proc
  local readStr: byte,		
		bytesRead: dword
  STACKALLOC 1					; Выровняем стек
  lea RAX, interfacePress		; Заносим указатель на строку
  push RAX						; Передача параметра через стек
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
  mov RCX, STD_OUTPUT_HANDLE    ; Установим номер потока вывода как первый аргумент функции
  call GetStdHandle             ; Возвращаемое значение в RAX
  mov hStdOutput, RAX			; Поместим значение дескриптора в RAX
  ; Повторим те же действия для потока ввода
  mov RCX, STD_INPUT_HANDLE     ; Установим номер потока ввода как первый аргумент функции
  call GetStdHandle             ; Возвращаемое значение в RAX
  mov hStdInput, RAX			; Поместим значение дескриптора в RAX

  lea RAX, interfaceA			; Заносим указатель на строку
  push RAX						; Передача параметра через стек
  call PrintString				; Вывод строки
  
  call ReadString
  cmp R10, 0
  jnz fine
	lea RAX, interfaceBadChar	; Заносим указатель на строку
    push RAX					; Передача параметра через стек
    call PrintString			; Вывод строки
	jmp finish
  fine:
  mov R8, CONST2				; R8 = CONST2
  sub R8, RAX					; R8 = CONST2 - A
  lea RAX, interfaceB			; Заносим указатель на строку
  push RAX						; Передача параметра через стек
  call PrintString				; Вывод строки

  call ReadString
  cmp R10, 0
  jnz fine2
	lea RAX, interfaceBadChar	; Заносим указатель на строку
    push RAX					; Передача параметра через стек
    call PrintString			; Вывод строки
	jmp finish
  fine2:
  sub R8, RAX					; R8 = CONST2 - A - B

  push R9
  mov R9, CONST1
  add R9, R8
  mov R8, R9					; R8 = CONST1 + (CONST2 - A - B)
  pop R9

  lea RAX, interfaceSum			; Заносим указатель на строку
  push RAX						; Передача параметра через стек
  call PrintString				; Вывод строки

  push R8
  call PrintSignedNumber

  call AwaitInput

  finish:
  xor RCX, RCX					; Аргумент ExitProcess - ноль
  call ExitProcess              ; завершение
Start endp
end