#!/bin/bash
# Script para achar números perfeitos

#
# Um número é reconhecido como perfeito, quando a soma dos seus divisores com resto 
# zero é igual a ele mesmo (!!o divisor não pode ser ele mesmo!!) EX= 6 é perfeito 
# porque {6 / 1 = 6 e resto = 0}; {6 / 2 = 3 e resto = 0}; {6 / 3 = 2 e resto = 0}
# ou seja 1 + 2 + 3 = 6
#
if [ $# -eq 0 ]; then
		exit
fi
# variáveis de início de script
CONT=0
VETNUM="1"
# loop de 2 até o valor de $1
for X in $(seq 2 $1); do
# loop de 2 até o valor de X / 2
	for Y in $(seq 2 $(($X / 2))); do
# verifica se a divisão de X por Y tem resto = 0
		if [ $(($X % $Y)) == 0 ]; then
# se o resto for igual a zero COUNT acumula o valor do número
			CONT=$(($CONT + $Y))
# e VETNUM os números que o resto era igual a zero
			VETNUM=$(echo "$VETNUM $Y")
		fi	#fim if %
	done #fim for Y
# verifica se COUNT é igual X 
	if [ $(($CONT + 1)) == $X ]; then
# se for imprime o número dizendo que ele é perfeito
		echo "$X é perfeito!!"
# e imprime os seus divisores de resto igual a zero
		echo "$VETNUM"
	fi #fim fi COUNT
# zera as variáveis	
    CONT=0
	VETNUM="1"
done #fim for X

