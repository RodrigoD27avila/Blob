#!/bin/bash
# Script para achar números perfeitos
CONT=0
for X in $(seq 2 $1); do
	for Y in $(seq 2 $(($X / 2))); do
		if [ $(($X % $Y))  == 0 ]; then
			CONT=$(($CONT + $Y))
		fi	
	done
	if [ $(($CONT + 1)) == $X ]; then
		echo "$X é perfeito"
	fi
	CONT=0
done

