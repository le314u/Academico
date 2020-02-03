
data segment
	grid db 9 dup(0)
	player db 0
	win db 0
	temp db 0

	;Traduzido
	newGameQuest db "Quer uma revanche? ([s]im  [n]ao)$"
	welcome db "Tic Tac Toe Game - By Oz Elentok Modificado Lucas e Thales$"
	separator db "---|---|---$"
	enterLoc db "Digite (1-9) para selecionar a jogada$"
	turnMessageX db "Player1[X] turno$"
	turnMessageO db "Player2[O] turno$"
	tieMessage db "Um empate entre os dois jogadores!$"
	winMessage db " foi o vencedor$"
	inDigitError db "Esta posição ja foi preenchida$"
	inError db "Não é um digito valido$"
	newline db 0Dh,0Ah,'$'    

	;Variaveis 
	NPlayer1 db "Player1$"	;7caracteres + $
	NPlayer2 db "Player2$"	;7caracteres + $
	SPlayer1 db "O",0ch		;2caracter [0]Simbolo [1]FB Color
	SPlayer2 db "X",0bh 	;2caracter [0]Simbolo [1]FB Color
	Tabuleiro db 70h

	;Tmp
	Contador db 00h

	;Mensagens de Menu
	menu1 db "[1]-Alterar nome do Jogador 1$"
	menu2 db "[2]-Alterar nome do Jogador 2$"
	menu3 db "[3]-Escolher o símbolo e cor do caractere do Jogador 1$"
	menu4 db "[4]-Escolher o símbolo e cor do caractere do Jogador 2$"
	menu5 db "[5]-Escolher a cor do tabuleiro$"     
	menu6 db "[6]-Iniciar jogo.$"     
	menu7 db "[7]-Sair$"
	msgSimbolo db "Troca Simbolo$"
	trocaCor db "Digite o numero correspondente a cor:$"
	msgSimboloF db "Digite o simbolo Referente a Cor da Letra :$"
	msgCorTabuleiro db "Digite o simbolo Referente a Cor de Fundo :$"

	;Tabela Cor
	Cor0 db "   [0]   ";0000 "0"-30
	Cor1 db "   [1]   ";0001 "1"-30
	Cor2 db "   [2]   ";0010 "2"-30
	Cor3 db "   [3]   ";0011 "3"-30
	Cor4 db "   [4]   ";0100 "4"-30
	Cor5 db "   [5]   ";0101 "5"-30
	Cor6 db "   [6]   ";0110 "6"-30
	Cor7 db "   [7]   ";0111 "7"-30
	Cor8 db "   [8]   ";1000 "8"-30 
	Cor9 db "   [9]   ";1001 "9"-30 
	CorA db "   [a]   ";1010 "A"-37 -57
	CorB db "   [b]   ";1011 "B"-37 -57 
	CorC db "   [c]   ";1100 "C"-37 -57 
	CorD db "   [d]   ";1101 "D"-37 -57 
	CorE db "   [e]   ";1110 "E"-37 -57
	CorF db "   [f]   ";1111 "F"-37 -57
ends

stack segment
	dw 128 dup(0)
ends

code segment
start:
	mov ax, data
	mov ds, ax
	mov es, ax

	inicio:;Se revanche for sim sempre chama o menu
	call menu;Chama o Menu
	;Swap
	;Assim que escolher iniciar o jogo faz as trocas de simbolo e nome
		call swap
	newGame:
	call initiateGrid
	mov player, 10b ; 2 dec
	mov win, 0
	mov cx, 9
	gameAgain:
		call clearScreen
		lea dx, welcome
		call printString
		lea dx, newline
		call printString
		lea dx, enterLoc
		call printString
		lea dx, newline
		call printString
		call printString
		call printGrid
		mov al, player
		cmp al, 1
		je p2turn
			; previous player was 2
			shr player, 1; 0010b --> 0001b;
			lea dx, turnMessageX
			call printString
			lea dx, newline
			call printString
			jmp endPlayerSwitch
		p2turn:; previous player was 1
			shl player, 1; 0001b --> 0010b
			lea dx, turnMessageO
			call printString
			lea dx, newline
			call printString
			
		endPlayerSwitch:
		call Colorir; Colore o Tabuleiro
		call getMove; bx will point to the right board postiton at the end of getMove
			mov dl, player
			cmp dl, 1
			jne p2move
			;seta simbolo player 1
				push bx;Empilha bx
				lea dx,SPlayer1;Endereço do SimboloPlayer
				mov bx,dx;Bx aponta para Dx
				mov dl,[bx];dh = SPlayer1
				pop bx;desempilha bx
			;mov dl, 'X'
			jmp contMoves
			p2move:
			;seta simbolo player 2
				push bx;Empilha bx
				lea dx,SPlayer2;Endereço do SimboloPlayer
				mov bx,dx;Bx aponta para Dx
				mov dl,[bx];dh = SPlayer1
				pop bx;desempilha bx
			;mov dl, 'O'
		contMoves:
		mov [bx], dl
		cmp cx, 5 ; no need to check before the 5th turn
		jg noWinCheck
		call checkWin
		cmp win, 1
		je won
		noWinCheck:
		loop gameAgain
		
	;tie, cx = 0 at this point and no player has won
	 call clearScreen
	 lea dx, welcome
	 call printString
	 lea dx, newline
	 call printString
	 call printString
	 call printString
	 call printGrid
	 lea dx, tieMessage
	 call printString
	 lea dx, newline
	 call printString
	 jmp askForNewGame
	 
	won:; current player has won
	 call clearScreen
	 lea dx, welcome
	 call printString
	 lea dx, newline
	 call printString
	 call printString
	 call printString
	 call printGrid

	 mov dl, player;Verifica quem foi o ultimo jogador
	 cmp dl,1h;Se o ultimo jogador foi 1
	 jne set2
	 ;Printa o nome do jogador que venceu
	 	;Player1
	 	lea dx,NPlayer1
	 jmp fimset
	 set2:
	 	;Player2
	 	lea dx,NPlayer2
	 fimset:
	 	call printString;Printa o nome do jogador
	 lea dx, winMessage;Troquei a ordem
	 call printString
	 lea dx, newline
	 call printString
	 	;Evita que os valores dos registradores sejam perdidos
	 	lea bx,Contador ;Evita que a função Colorir Acabe com o vencedor
	 	mov bx,[bx]
	 	push bx	
	 call Colorir;Colore
	 call PrintaVencedor;Colore


	askForNewGame:
	 mov dx,data;Evitando bug 
	 mov ds,dx; voltando paara Segmento de dados
	 lea dx, newGameQuest; ask for another game
	 call printString
	 lea dx, newline
	 call printString

	 input:
	 call getChar
	 ;So aceita S ou N
		 cmp al, 's'; mudei para s
		 je inicio
		 cmp al, 'S'; mudei para S
		 je inicio
		 cmp al, 'n'; mudei para s
		 je Fim
		 cmp al, 'N'; mudei para S
		 je Fim
		 ;Não digitou algo valido
		 jmp input
	 
	;sof:
	;mov ax, 4c00h
	;int 21h

;-------------------------------------------;
; Sets ah = 01
; Input char into al;
getChar:
	mov ah, 01
	int 21h
	ret
;-------------------------------------------;	
; Sets ah = 02
; Output char from dl
; Sets ah to last char output
putChar:
	mov ah, 02
	int 21h
	ret
;-------------------------------------------;
; Sets ah = 09
; Outputs string from dx
; Sets al = 24h
printString:
	mov ah, 09
	int 21h
	ret
;-------------------------------------------;
; Clears the screen
; ah = 0 at the end
clearScreen:
  mov ah, 0fh
  int 10h
  mov ah, 0
  int 10h
  
  ; evitando bugs
  mov ah, 06h    ; Scroll up function
  xor al, al     ; Clear entire screen
  xor cx, cx     ; Upper left corner CH=row, CL=column
  mov dx, 184fh  ; lower right corner DH=row, DL=column 
  mov bh, 07h    ; BLACK, GRAY
  int 10h
  
  
	;Apaga a tela
	;mov ah, 0fh
	;int 10h
	;mov ah, 0
	;int 10h

	ret
	
;-------------------------------------------;
; Gets location that can be used
; after successfuly geting the location:
; al - will hold the place number(0 - 8)
; bx - will hold the positon(bx[al])
getMove:
	call getChar; al = getchar()
	call isValidDigit
	cmp ah, 1
	je contCheckTaken
	mov dl, 0dh
	call putChar
	lea dx, inError
	call printString
	lea dx, newline
	call printString
	jmp getMove
	
	contCheckTaken: ; Checks this: if(grid[al] > '9'), grid[al] == 'O' or 'X'
	lea bx, grid	
	sub al, '1'
	mov ah, 0
	add bx, ax
	mov al, [bx]
	cmp al, '9'
	jng finishGetMove
	mov dl, 0dh
	call putChar
	lea dx, inDigitError
	call printString
	lea dx, newline
	call printString
	jmp getMove
	finishGetMove:
	lea dx, newline
	call printString
	ret
	
;-------------------------------------------;
; Initiates the grid from '1' to '9'
; Uses bx, al, cx
initiateGrid:
	lea bx, grid
	mov al, '1'
	mov cx, 9
	initNextTa:
	mov [bx], al
	inc al
	inc bx
	loop initNextTa
	ret
	
;-------------------------------------------;
; checks if a char in al is a digit
; DOESN'T include '0'
; if is Digit, ah = 1, else ah = 0
isValidDigit:
	mov ah, 0
	cmp al, '1'
	jl sofIsDigit
	cmp al, '9'
	jg sofIsDigit
	mov ah, 1h
	sofIsDigit:
	ret
	
	
;-------------------------------------------;	
; Outputs the 3x3 grid
; uses bx, dl, dx
printGrid:
	lea bx, grid
	call printRow
	lea dx, separator
	call printString
	lea dx, newline
	call printString
	call printRow
	lea dx, separator
	call printString
	lea dx, newline
	call printString
	call printRow
	ret

;-------------------------------------------;
; Outputs a single row of the grid
; Uses bx as the first number in the row
; At the end:
; dl = third cell on row
; bx += 3, for the next row
; dx points to newline
printRow:

	;First Cell
	mov dl, ' '
	call putChar
	mov dl, [bx]
	call putChar
	mov dl, ' '
	call putChar
	mov dl, '|'
	call putChar
	inc bx
	
	;Second Cell
	mov dl, ' '
	call putChar
	mov dl, [bx]
	call putChar
	mov dl, ' '
	call putChar
	mov dl, '|'
	call putChar
	inc bx
	
	;Third Cell
	mov dl, ' '
	call putChar
	mov dl, [bx]
	call putChar
	inc bx
	
	lea dx, newline
	call printString
	ret
	
;-------------------------------------------;	
; Returns 1 in al if a player won
; 1 for win, 0 for no win
; Changes bx
checkWin:
	lea si, grid
	call checkDiagonal
	cmp win, 1
	je endCheckWin
	call checkRows
	cmp win, 1
	je endCheckWin
	call CheckColumns
	endCheckWin:
	ret
	
;-------------------------------------------;	
checkDiagonal:
	;DiagonalLtR
	mov bx, si
	mov al, [bx]
	add bx, 4	;grid[0] ---> grid[4]
	cmp al, [bx]
	jne diagonalRtL
	add bx, 4	;grid[4] ---> grid[8]
	cmp al, [bx]
	jne diagonalRtL
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],01h;
		pop bx
	ret
	
	diagonalRtL:
	mov bx, si
	add bx, 2	;grid[0] ---> grid[2]
	mov al, [bx]
	add bx, 2	;grid[2] ---> grid[4]
	cmp al, [bx]
	jne endCheckDiagonal
	add bx, 2	;grid[4] ---> grid[6]
	cmp al, [bx]
	jne endCheckDiagonal
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],02h;
		pop bx
	endCheckDiagonal:
	ret
	
;-------------------------------------------;
checkRows:	
	;firstRow
	mov bx, si; --->grid[0]
	mov al, [bx]
	inc bx		;grid[0] ---> grid[1]
	cmp al, [bx]
	jne secondRow
	inc bx		;grid[1] ---> grid[2]
	cmp al, [bx]
	jne secondRow
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],03h;
		pop bx
	ret
	
	secondRow:
	mov bx, si; --->grid[0]
	add bx, 3	;grid[0] ---> grid[3]
	mov al, [bx]
	inc bx	;grid[3] ---> grid[4]
	cmp al, [bx]
	jne thirdRow
	inc bx	;grid[4] ---> grid[5]
	cmp al, [bx]
	jne thirdRow
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],04h;
		pop bx
	ret
	
	thirdRow:
	mov bx, si; --->grid[0]
	add bx, 6;grid[0] ---> grid[6]
	mov al, [bx]
	inc bx	;grid[6] ---> grid[7]
	cmp al, [bx]
	jne endCheckRows
	inc bx	;grid[7] ---> grid[8]
	cmp al, [bx]
	jne endCheckRows
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],05h;
		pop bx
	endCheckRows:
	ret
	
;-------------------------------------------;	
CheckColumns:
	;firstColumn
	mov bx, si; --->grid[0]
	mov al, [bx]
	add bx, 3	;grid[0] ---> grid[3]
	cmp al, [bx]
	jne secondColumn
	add bx, 3	;grid[3] ---> grid[6]
	cmp al, [bx]
	jne secondColumn
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],06h;
		pop bx
	ret
	
	secondColumn:
	mov bx, si; --->grid[0]
	inc bx	;grid[0] ---> grid[1]
	mov al, [bx]
	add bx, 3	;grid[1] ---> grid[4]
	cmp al, [bx]
	jne thirdColumn
	add bx, 3	;grid[4] ---> grid[7]
	cmp al, [bx]
	jne thirdColumn
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],07h;
		pop bx
	ret
	
	thirdColumn:
	mov bx, si; --->grid[0]
	add bx, 2	;grid[0] ---> grid[2]
	mov al, [bx]
	add bx, 3	;grid[2] ---> grid[5]
	cmp al, [bx]
	jne endCheckColumns
	add bx, 3	;grid[5] ---> grid[8]
	cmp al, [bx]
	jne endCheckColumns
	mov win, 1
	;Configurando  onde ganhou
		push bx
		lea bx,Contador;
		mov [bx],08h;
		pop bx
	endCheckColumns:
	ret
	





;#Minhas Funções
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;------------------------------------------------------------------------------
MsgDigitoInvalido:
	push dx
		;PulaLinha
			lea dx,newline;
			call printString
		;Msg Error
			lea dx,inError;
			call printString
		;PulaLinha
			lea dx,newline;
			call printString
	pop dx
ret
;-------------------------------------------;
;Chama as 7 Msg's de menu 
printaMenu:

	;[1]-Alterar nome do Jogador 1
	lea dx, menu1
	call printString
	lea dx, newline
	call printString

	;[2]-Alterar nome do Jogador 2
	lea dx, menu2
	call printString
	lea dx, newline
	call printString
	
	;[3]-Escolher o símbolo e cor do caractere do Jogador 1
	lea dx, menu3
	call printString
	lea dx, newline
	call printString
	
	;[4]-Escolher o símbolo e cor do caractere do Jogador 2
	lea dx, menu4
	call printString
	lea dx, newline
	call printString
	
	;[5]-Escolher a cor do tabuleiro     
	lea dx, menu5
	call printString
	lea dx, newline
	call printString
	
	;[6]-Iniciar jogo.     
	lea dx, menu6
	call printString
	lea dx, newline
	call printString
	
	;[7]-Sair 
	lea dx, menu7
	call printString
	lea dx, newline
	call printString

ret

;-------------------------------------------;
swap:
	;Variavel Contador = 0
		lea bx,Contador;
		mov [bx],00h;Seta Contador como 1
	;Player 1
		;Troca Nome
			;Contador=0
			mov cx,00h;Contador = 0

			LoopSetaValores1:
				;Ax = NPlayer1[Contador]
					lea dx, NPlayer1
					mov bx,dx 	;Bx aponta para inicio do vetor NPlayer1
					add bx,cx 	;Aponta para NPlayer1[Contador]
					mov ax,[bx]	;Ax = NPlayer1[Contador]

				;Msg[Contador] = Ax
					lea dx, turnMessageX
					mov bx,dx 	;Bx aponta para inicio do vetor turnMessageX
					add bx,cx 	;Aponta para turnMessageX[Contador]
					mov [bx],ax	;turnMessageX[Contador] = Ax

				add cx,1h 	;Contador ++
				cmp cx,6h	;if(cx!=6)	
				jne LoopSetaValores1 ;Faz Loop se diferente

		;Troca Simbolo
			;Ax=SPlayer1
				lea ax, SPlayer1;
				mov bx,ax 	;Bx recebe endereço SPlayer1
				mov ax,[bx] ;Ax recebe conteudo de SPlayer1[0]

			;turnMessageX[9] = Ax
				lea dx,turnMessageX;
				mov bx,dx	;Bx recebe endereço de turnMessageX
				add cx,2h 	;Contador += 2
				add bx,cx 	;turnMessageX[Contador]
				mov [bx],al ;turnMessageX[Contador] = Ax

	;Player 2
		mov cx,00h;Contador = 0
		LoopSetaValores2:
			;Ax = NPlayer2[Contador]
				lea dx, NPlayer2
				mov bx,dx 	;Bx aponta para inicio do vetor NPlayer1
				add bx,cx 	;Aponta para NPlayer2[Contador]
				mov ax,[bx]	;Ax = NPlayer2[Contador]

			;Msg[Contador] = Ax
				lea dx, turnMessageO
				mov bx,dx 	;Bx aponta para inicio do vetor turnMessageO
				add bx,cx 	;Aponta para turnMessageO[Contador]
				mov [bx],ax	;turnMessageO[Contador] = Ax

			add cx,1h 	;Cotnador ++
			cmp cx,6h	;if(cx!=6)	
			jne LoopSetaValores2 ;Faz Loop se diferente

		;Troca Simbolo
			;Ax=SPlayer2
				lea ax, SPlayer2;
				mov bx,ax 	;Bx recebe endereço SPlayer2
				mov ax,[bx] ;Ax recebe conteudo de SPlayer2[0]

			;turnMessageX[9] = Ax
				lea dx,turnMessageO;	
				mov bx,dx	;Bx recebe endereço de turnMessageO
				add cx,2h 	;Contador += 2
				add bx,cx 	;turnMessageX[Contador]
				mov [bx],al ;turnMessageX[Contador] = Ax
ret
;-------------------------------------------;
menu:
	;Limpa a tela
		call clearScreen

	;Printa o Menu
		call printaMenu

	;Pega um Digito Valido do buffer
		valida:
		call getChar

		;Se Menor
		cmp al, '1'
		jl valida	

		;Se Maior
		cmp al, '7'
		jg valida

	;Seleciona uma função
	;switch (al)
		cmp al,'1'
		je f1

		cmp al,'2'
		je f2

		cmp al,'3'
		je f3

		cmp al,'4'
		je f4

		cmp al,'5'
		je f5

		cmp al,'7'
		jne next
		jmp fim; Aponta para o fim do segmento de codigos o que se torna melhor que INT 20H que apenas retorna para o sistema
		
		next:
		cmp al,'6'
		jne valida;
		ret;retorna a chamada de função	e começa o jogo

		f1:
		push 0101h;Variavel de parametro	
				  ; 01 do da parte alta é para não atrapalhar na hora de escrever no buffer
		call NomePlayer
		jmp menu

		f2:
		push 0102h;Variavel de parametro
		call NomePlayer
		jmp menu

		f3:
		push 0101h;Variavel de parametro
		call SimboloPlayer
		jmp menu

		f4:
		push 0102h;variavel de parametro
		call SimboloPlayer
		jmp menu

		f5:call CorTabuleiro
		jmp menu

;-------------------------------------------
 NomePlayer:

 	;limpa a tela
 		call clearScreen

 	;Pega as variaveis do parametro
		pop ax;endereço retorno
		pop dx;Pega o parametro
		push ax;
		push dx;

	;Switch para mensagen
		cmp dl,1h;se igual a 1 mostra a msg1
		jne msg2
		lea dx,menu1
	 	jmp msgs1
	 	msg2:
	 	lea dx,menu2
 		
 		;Mostra o que a função faz
 			msgs1:
			call printString
			lea dx, newline
			call printString

	;Preenche Vetor
		pop dx;
		cmp dl,1h;if(Player1)	else(Player2)
		jne nplay2
	 	lea dx,NPlayer1
	 	jmp trocanome
	 	nplay2:
	 	lea dx,NPlayer2
	 	trocanome:
	 	mov bx,dx;Pega a posição inicial do vetor
	 	mov cx,7;Limita a string a 7 caracteres

	 	loop1:;Roda até pegar a string inteira
		 	call getChar ; Pega o buffer
		 	cmp al,0dh ;Se for um enter acaba a string
		 	je preenche;if( buff = Enter) preencher com zero
		 	mov [bx],al ; Passa o buffer para a memoria
		 	add bx,1 ; passa para o proximo vetor da string
		 	sub cx,1h; contador--
		 	cmp cx,0h; if(contador = 0)
		 	je fimloop1
		 	jmp loop1;loop
		 
		 		;preencher com 'espaço' até 7caracteres
		 		preenche:
		 		mov [bx],20h;Prencher com espaço
		 		add bx,1 ; passa para o proximo vetor da string
		 		sub cx,1h; contador--
		 		cmp cx,0h; if(contador = 0)
		 		jne preenche
		 	fimloop1:mov [bx],24h ;Final da string
		 	ret
		


;-------------------------------------------
 SimboloPlayer:

 	;limpa a tela
 		call clearScreen

 	;Pega as variaveis do parametro
		pop ax;endereço retorno
		pop dx;Pega o parametro
		push ax;
		push dx;

	;Switch para mensagen
		cmp dl,1h;se igual a 1 mostra a msg3
		jne msg4
		lea dx,menu3 
	 	jmp msgs2
	 	msg4:
	 	lea dx,menu4;Caso contrario mostra a msg4
 		
 		;Mostra o que a função faz
 			msgs2:
			call printString
			lea dx, newline
			call printString
			lea dx,msgSimbolo
			call printString
			lea dx, newline
			call printString

		;Seleciona Player
			pop dx;Parametro if(dx == Player1 || dx== player2)

			;SPlayer1
			cmp dl,1h
			jne splay2
		 	lea dx,SPlayer1
		 	jmp trocasimb

		 	;SPlayer2
		 	splay2:
		 	lea dx,SPlayer2

		;Troca o Simbolo
		 	trocasimb:
		 	mov bx,dx;Posição da variavel na memoria
			call getChar ; Pega o buffer

			;Não aceita  numero de 1 a 9 como simbolo pois ocorre conflito com o grid
				;if diferente SPlayer1
					push bx;Evita que a posição de Sp player na memoria seja perdida
					lea bx,Splayer1
					mov bx,[bx];Simbolo do Player1
					cmp al,bl;Simbolo = Simbolo 1
					pop bx ;Retorna para bx a posição da variavel Splayer na memoria
					jne DiferenteSimboloP1
						call MsgDigitoInvalido
						jmp trocasimb
					DiferenteSimboloP1:

				;if diferente SPlayer2
					push bx;Evita que a posição de Sp player na memoria seja perdida
					lea bx,Splayer2
					mov bx,[bx];Simbolo do Player2
					cmp al,bl;Simbolo = Simbolo 2
					pop bx;Retorna para bx a posição da variavel Splayer na memoria
					jne DiferenteSimboloP2
						call MsgDigitoInvalido
						jmp trocasimb
					DiferenteSimboloP2:

				;if [al < ascii(1) ]
					cmp al,31h;31 equivale a 1 em ascII
					jl SemConflitoGrid

					;if [al > ascii(9) ]
						cmp al,39h;30 equivale a 1 em ascII
						jg SemConflitoGrid

						;Caso esteja ente 31h e 39h
							call MsgDigitoInvalido
							jmp trocasimb

			SemConflitoGrid:
				mov [bx],al ; Passa o buffer para a memoria

		push dx;Parametro ja tratado ou seja endereço da variavel

	 	;Mostra Tabela de Cores
	 		;Limpa Tela
		 		call clearScreen
		 	;Tabela de Cor
				call PrintaTabelaCor
			
			PegaCor:
		 	;Pula Linha
				lea dx,newline
				call printString
			;Mensagem Fore
		 		lea dx,msgSimboloF
				call printString
			;Pega Cor
				call getChar ; Pega o buffer

				;Trata o valor
					call TratamentoCor;
					pop ax;Retorno da funçao
					cmp al,0FFh; if(retorno == FF)
					je PegaCor;

			;Seta Cor
				pop bx;Endereço de Splayer1 || Splayer2
				add bx,1;Aponta para o proximo endereço da memoria  OBS [0]=Simbolo  [1]=Cor
				mov [bx],al ;Passa o buffer para a memoria
	 	ret

;-------------------------------------------
PrintaTabelaCor:

	mov ah,13h;Codigo Interrupção
	mov al,1;
	mov cx,9;Size da msg a ser printada
	mov bh,0h;Pagina 0
	mov dx,0h;H=Linha  L=Coluna

	;Printa a cor0
		mov bl,0Fh	;Cor
		lea bp,Cor0
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor1
		mov bl,1Fh	;Cor
		lea bp,Cor1
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor2
		mov bl,2Fh	;Cor
		lea bp,Cor2
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor3
		mov bl,3Fh	;Cor
		lea bp,Cor3
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor4
		mov bl,4Fh	;Cor
		lea bp,Cor4
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor5
		mov bl,5Fh	;Cor
		lea bp,Cor5
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor6
		mov bl,6Fh	;Cor
		lea bp,Cor6
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor7
		mov bl,7Fh	;Cor
		lea bp,Cor7
		int 10h;Interrupçao
		mov dl,0h;Seta Inicio da proxima linha para printar um ao lado do outro
		add dh,1h;Muda a Linha proxima linha
		
	;Printa a cor8
		mov bl,80h	;Cor
		lea bp,Cor8
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a cor9
		mov bl,90h	;Cor
		lea bp,Cor9
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corA
		mov bl,0A0h	;Cor
		lea bp,CorA
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corB
		mov bl,0B0h	;Cor
		lea bp,CorB
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corC
		mov bl,0C0h	;Cor
		lea bp,CorC
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corD
		mov bl,0D0h	;Cor
		lea bp,CorD
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corE
		mov bl,0E0h	;Cor
		lea bp,CorE
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro

	;Printa a corF
		mov bl,0F0h	;Cor
		lea bp,CorF
		int 10h;Interrupçao
		add dl,9h;Para printar um ao lado do outro
ret

 ;-------------------------------------------
 CorTabuleiro:
  	lea dx,Tabuleiro
	;Mostra Tabela de Cores
		 		;Limpa Tela
			 		call clearScreen
			 	;Tabela de Cor
					call PrintaTabelaCor
				
				PegaCorTabuleiro:
			 	;Pula Linha
					lea dx,newline
					call printString
				;Mensagem Fore
			 		lea dx,msgCorTabuleiro
					call printString
				;Pega Cor
					call getChar ; Pega o buffer

					;Trata o valor
						call TratamentoCor;
						pop ax;Retorno da funçao
						cmp al,0FFh; if(retorno == FF)
						je PegaCorTabuleiro;
						shl al,04h
						;shiftleft cor

				;Seta Cor do tabuleiro em 
					lea bx,Tabuleiro;Endereço de Splayer1 
					;add bx,1;Aponta para o proximo endereço da memoria 
					mov [bx],al ;Passa o buffer para a memoria

					;lea bx,SPlayer2;Endereço de Splayer2
					;add bx,1;Aponta para o proximo endereço da memoria
					;mov [bx],al ;Passa o buffer para a memoria

		 	ret
;-------------------------------------------
 PrintSimbCor:
 	pop ax;Desempilha endereço de retorno
 	pop bx;Pega o parametro da função
 	push ax;Endereço de Retorno da função
  	mov ax,0113h;Codigode interrupção
  	mov bl,28;Seta Cor
  	mov cx,1h;1 é o offset do simbolo
  	cmp bl,1h;if(jogador=1)
  	jne PrintSimbCor2
  	;Player1
  		lea bp,SPlayer1
  		jmp FimPrintSimbCor
  	PrintSimbCor2:
  	;Player2
  		lea bp,SPlayer2

  	FimPrintSimbCor:
  	mov bx,bp;Passa O endereço da variavel para bx
  	add bx,1h;Aponta para o proximo digito de cor
  	mov bl,[bx];bl = SPlayer[2]; Referente a cor
  	mov bh,0h;Pagina 0
  	int 10h;Printa



;-------------------------------------------
TratamentoCor:
	
	;Valido é de 30-39,41-46,61-66
		cmp al,30h ;if(al<30)
		jl invalido;

		;30<=x<=39 é valido
		cmp al,39h
		jle validoNumero ;if(al<=39)

		;39<x<41 é invalido
		cmp al,41h
		jl invalido;if(al<41)

		;41<=x<=46 é valido
		cmp al,46h
		jle validoLetraMi;if(al<=46)

		;46<x<61 é invalido
		cmp al,61h
		jl invalido;if(al<61)

		;61<=x<=66 é valido
		cmp al,66h
		jle validoLetraMa;if(al<=6)

		invalido:
			;Mensagem de erro
			call MsgDigitoInvalido
			mov al,0FFh;Definido como erro
			pop dx;Enderço de retorno
			push ax;Empilha uma variavel de retorno 
			push dx;Endereço de retorno
			ret

		validoNumero:
			sub al,30h;
			pop dx;Enderço de retorno
			push ax;Empilha uma variavel de retorno 
			push dx;Endereço de retorno
			ret

		validoLetraMi:
			sub al,37h;
			pop dx;Enderço de retorno
			push ax;Empilha uma variavel de retorno 
			push dx;Endereço de retorno
			ret

		validoLetraMa:
			sub al,57h;
			pop dx;Enderço de retorno
			push ax;Empilha uma variavel de retorno 
			push dx;Endereço de retorno
			ret


;-------------------------------------------
SelecionaCorPlayer:
	mov bx,data;Seta Segmento de Data
	mov ds,bx;Seta Segmento de Data
	;Tratando dados.
		;Dx=Contador
			lea bx,Contador ;Endereco Contador
			mov dx,[bx]		;Inicializa
			mov dh,00h		;Evita Erros
			add [bx],01h	;Add 1 ao COntado

			;Dx=Grid[Contador]
				lea bx,grid
				add bx,dx
				mov dx,[bx]

		;Bx=SPlayer1[1]
			lea bx,SPlayer1
			mov bx,[bx]

			;if(Player1)	
				cmp dl,bl
				je PegaCorForeP1

		;Bx=SPlayer2[2]
				lea bx,SPlayer2
				mov bx,[bx]

			;else(Player2)
				cmp dl,bl
				je PegaCorForeP2

		;Diferente de Splay1 && SPlayer2
		mov ax,00h;
		jmp PegaCorBack

		;Pega Cor Player 1
		PegaCorForeP1:
			lea bx,SPlayer1
			add bx,01h		;Vai para a segunda posição
			mov ax,[bx]
			jmp PegaCorBack

		;Pega Cor Player 2
		PegaCorForeP2:
			lea bx,SPlayer2
			add bx,01h		;Vai para a segunda posição
			mov ax,[bx]
			jmp PegaCorBack

	 	;Pegando Cor Back
 		PegaCorBack: 
			lea bx, Tabuleiro ; carrega endereço da variável
			mov bx, [bx] ; carrega conteúdo
            ;shl bx,04h ; fazendo shift left para aglutinar as cores fore e background
			add bx, ax ; bx tem o conteúdo da cor

	pop ax;Endereço de Retorno
	push bx;Retorno Cor Fore Aglutinada ao Back
	push ax;Endereço de retorno
	ret


;------------------------------------------------------------------------------
Colorir:
	
	;0b800h:0000 Inicio Terminal
	;De um para o Outro aumenta "A"
		;0b81eh:0000 Tabuleiro linha 1 (3 para digito 1 para #)*3
		;0b828h:Linha tabuleiro
		;0b832h:0000 Tabuleiro linha 2 (3 para digito 1 para #)*3
		;0b83ch:Linha tabuleiro
		;0b846h:0000 Tabuleiro linha 3 (3 para digito 1 para #)*3
		;0b850h:Linha tabuleiro

	lea bx,Contador ;
	mov [bx],0h		;Inicializa
	mov dx,Data		;Dx tem segmento de Dado
	mov ax,0b81eh	;Ax tem segmento da 1 Linha do terminal
	mov	cx,0003h	;Tem 3 linhas


	;Colore Tabuleiro
		Tabu:
			;Seta o segmento
				mov di, 01h 	;vai colorir no segmento de memória Ds+Di
				mov ds, ax		;Ds agora aponta para o terminal
			push cx;			;Guarda o Indice do Maior Loop
			mov cx,0003h			;3 Celulas

			linha:	
				;Seleciona Cor de Acordo com o player
					push ax;Manter Valores dos registradores
					push dx;Manter Valores dos registradores
					call SelecionaCorPlayer
					pop bx;Carrega Cor
					pop dx;Manter Valores dos registradores
					pop ax;Manter Valores dos registradores
					mov ds,ax;Seta o Segmento para o mesmo  antes de chamar a função

				;Colore uma celula
					;Espaço
						mov [di], bl	; 4b Back 4b Fore
				    	add di, 2h		; skip over next ascii code in vga memory.
				    ;Simbolo
				    	mov [di], bl	; 4b Back 4b Fore
				    	add di, 2h		; skip over next ascii code in vga memory.
				    ;Espaço
				    	mov [di], bl	; 4b Back 4b Fore
				    	add di, 2h		; skip over next ascii code in vga memory.
			 		
			 		cmp cx,1h;Verifica se chegou no Fim da Linha
			 		je UltimaColuna1

			 	;Colore Haste do tabuleiro
		 			;Pega Cor
						push di 			;Empilha Di
						mov ds,dx			;Seta Segmento Dado
						lea bx,Tabuleiro	;Endereço da Variavel
						mov bx,[bx]			;Bl = Cor
						shl bx,04h			;Seta a cor  pois osbits msb representam o back 
						mov ds,ax			;Seta Tela 
						pop di 				;Desempilha Di
			 		mov [di], bl	; 4b Back 4b Fore
			 		add di,2h;Pula '|'

			 		UltimaColuna1:
		 	loop linha

		 	
		 	;Verifica se chegou na ultima linha
			 	pop cx
			 	push cx
			 	cmp cx,1h;
			 	je UltimaLinha

		 	;Seta --------- "divisão de Linha"----------
			 	add ax,0Ah	;Aponta para a proxima linha
			 	mov ds,ax	;Seta a tela
			 	mov di,01h	;vai colorir no segmento de memória Ds+Di
			 	mov cx,0ch;

			 	;Pega Cor
						push di 			;Empilha Di
						mov ds,dx			;Seta Segmento Dado
						lea bx,Tabuleiro	;Endereço da Variavel
						mov bx,[bx]			;Bl = Cor
						shl bx,04h			;Seta a cor  pois osbits msb representam o back 
						mov ds,ax			;Seta Tela 
						pop di 				;Desempilha Di
			 		mov [di], bl	; 4b Back 4b Fore

				;Colore
				 	Pontilhado:
				 		cmp cx,1h;
				 		je UltimaColuna2
				 		mov [di], bl	; 4b Back 4b Fore
						add di, 2h		; skip over next ascii code in vga memory.
					loop Pontilhado
				UltimaColuna2:
			 	add ax,0Ah	;Aponta para a proxima linha
			 	mov ds,ax	;Volta o endereço de segmento
			 	UltimaLinha:
			pop cx		;Volta para CX o Indice do FOR mais superior
		loop Tabu

		mov ds,dx;Recupera o segmento de dados da memoria
	ret

;------------------------------------------------------------------------------
PrintaVencedor:
;0b800h:0000 Inicio Terminal
	;De um para o Outro aumenta "A"
		;0b81eh:0000 Tabuleiro linha 1 (3 para digito 1 para #)*3
		;0b828h:Linha tabuleiro
		;0b832h:0000 Tabuleiro linha 2 (3 para digito 1 para #)*3
		;0b83ch:Linha tabuleiro
		;0b846h:0000 Tabuleiro linha 3 (3 para digito 1 para #)*3
		;0b850h:Linha tabuleiro

	;Pega Variavel de parametro
	pop ax
	pop dx
	push ax
	push dx

	mov dx,Data;Seta Segmento de data
	mov ds,dx;Seta Segmento de data

	
	;Pega a cor do Simbo Player 1 ou 2
	lea bx,player ;
	mov dx,[bx];

		cmp dl,01h;
		je CorFP1
		jmp CorFP2

		CorFP1:;Pega cor do Fore
			lea bx,SPlayer1 ;
			add bx,01h;
			mov dx,[bx];
			jmp FimCorFore;

		CorFP2:;Pega cor do Fore
			lea bx,SPlayer2 ;
			add bx,01h;
			mov dx,[bx];
			jmp FimCorFore;

	FimCorFore:

	lea bx,Tabuleiro ;
	mov bx,[bx];Pega a cor do tabuleiro
	not BL;Cor antagonica ao tabuleiro
	sub bl,0FH; Evita erro pois o Primeiro digito sempre sera 0 que negado Da F
	add bl,dl;Junta fore com back
	pop dx;Parametro , onde foi a vitoria
	mov bh,dl;Junta tudo em BX 

	;Bl Tem Onde foi a vitoria
	;Bh Tem a cor do Tabuleiro

	

	mov dx,0b81eh	;Ax tem segmento da 1 Linha do terminal

	cmp bh,01h
		je Vencedor1
	cmp bh,02h
		je Vencedor2
	cmp bh,03h
		je Vencedor3
	cmp bh,04h
		je Vencedor4
	cmp bh,05h
		je Vencedor5
	cmp bh,06h
		je Vencedor6
	cmp bh,07h
		je Vencedor7
	cmp bh,08h
		je Vencedor8
	ret;Se chegou aqui então bugou


	Vencedor1:;Diagonal Principal

	mov di, 01h 	;vai colorir no segmento de memória Ds+Di
	mov ds, dx		;Ds agora aponta para o terminal

		;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.

		;Celula do Meio
			add dx,0Ah	;Dx tem segmento do terminal
			add dx,0Ah	;Dx tem segmento do terminal
			add di, 2h	; skip over next ascii code in vga memory.
			mov ds,dx	;Atualiza Ds
		   
		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.

		;Ultima Celula
			add dx,0Ah	;Dx tem segmento do terminal
			add dx,0Ah	;Dx tem segmento do terminal
			add di, 2h	; skip over next ascii code in vga memory.
			mov ds,dx	;Atualiza Ds
		 
		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.	
		ret


	Vencedor2:;Diagonal Secundaria
		mov di, 15h 	;vai colorir no segmento de memória Ds+Di
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.

		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		sub di, 2h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.

		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		sub di, 2h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds
		
		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	sub di, 2h		; skip over next ascii code in vga memory.
		ret

	Vencedor3:;Primeira linha
		mov di, 01h 	;vai colorir no segmento de memória Ds+Di
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h
		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
	Vencedor4:;Segunda Linha
		mov di, 01h 	;vai colorir no segmento de memória Ds+Di
		add dx,	0Ah
		add dx,	0Ah		;Aponta para a segunda linha
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h
		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
			
	Vencedor5:;Terceira Linha
		mov di, 01h 	;vai colorir no segmento de memória Ds+Di
		add dx,	0Ah
		add dx,	0Ah
		add dx,	0Ah
		add dx,	0Ah		;Aponta para a terceira linha
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		add di, 2h
		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
			
			
	Vencedor6:;Primeira Coluna
		mov di, 01h 	;vai colorir no segmento de memória Ds+Di
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.

		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di, 01h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    	
		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di, 01h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
			
	Vencedor7:;Segunda Coluna
		mov di, 09h 	;vai colorir no segmento de memória Ds+Di
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.

		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di, 09h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    	
		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di, 09h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
			
	Vencedor8:;Terceira Coluna
		mov di, 11h 	;vai colorir no segmento de memória Ds+Di
		mov ds, dx		;Ds agora aponta para o terminal

			mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.

		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di,11h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		   ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    	
		add dx,0Ah	;Dx tem segmento do terminal
		add dx,0Ah	;Dx tem segmento do terminal
		mov di,11h	; skip over next ascii code in vga memory.
		mov ds,dx	;Atualiza Ds

		    ;Colore uma celula
			;Espaço
				mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Simbolo
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		    ;Espaço
		    	mov [di], bl	; 4b Back 4b Fore
		    	add di, 2h		; skip over next ascii code in vga memory.
		ret
			




Fim:;Sai da aplicação evitando que a pessoa rode denovo e continue de onde parou
ends 
end start

