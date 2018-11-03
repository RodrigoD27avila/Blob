#!/bin/bash
# mdisk.sh

green(){
	 printf "\e[1;32m$1\e[0;39;49m"
}

yellow(){
	 printf "\e[1;33m$1\e[0;39;49m"
}

red(){
	printf "\e[1;31m$1\e[0;39;49m"
}

printf "["

for i in $(seq 50); do
	if (( $i <= 30 )) ; then
		green "#"
	fi

	if (( $i > 45  )); then
		red "#"
		continue
	fi

	if (( $i > 30 )); then
		yellow "#"
	fi

done

printf "]\n"
