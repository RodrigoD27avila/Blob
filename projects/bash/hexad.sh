for x in {0..15}; do 
	let R=$RANDOM%17 && printf `echo $R 16 o p | dc`' '
	done 
printf '\n'
