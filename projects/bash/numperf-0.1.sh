#!/bin/bash
# Script para achar números perfeitos
CONT=0
for X in $(seq 1 $1); do
	for Y in $(seq 1 $X); do
		if [ $X == $Y ]; then
			continue;
		fi

		if [ $(($X % $Y))  == 0 ]; then
			CONT=$(($CONT + $Y))
		fi	
	done
	if [ $CONT == $X ]; then
		echo "$X é perfeito"
	fi
	CONT=$((0))
done

