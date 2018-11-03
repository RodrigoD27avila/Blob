#!/bin/bash
# Script para achar números perfeitos
for X in 6 28 496 8128 33550336 8589869056 137438691328; do
    printf "1 "
    for ((Y=2; Y<=$(($X / 2)); Y++)); do
		if [ $(($X % $Y)) == 0 ]; then
				printf "$Y "
		fi	
	done
    echo -e "\n$X é perfeito!!\n"
done

