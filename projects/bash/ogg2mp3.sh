#!/bin/sh
# ogg2mp3.sh
# Rodrigo D'avila
#Script para converter músicas de ogg para mp3
VERSION=0.1

for I in $1*.ogg; do
		
		echo "Preparando para encodar $I"
		sleep 2

		#Converte para .wav
		mplayer -ao pcm -vc null -vo null "$I" &> ~/.ogg2mp3.inf
    	
		#pega informações do arquivo
		GENRE=$(echo `cat ~/.ogg2mp3.inf | grep Genre | cut -f2 -d:` | tr '[A-Z]' '[a-z]' | tr ' ' '_' | tr '/' '-')
    		NAME=$(echo `cat ~/.ogg2mp3.inf | grep Name | cut -f2 -d: | tr '[A-Z]' '[a-z]' | tr ' ' '_' | tr '/' '-'`)
    		ARTIST=$(echo `cat ~/.ogg2mp3.inf | grep Artist | cut -f2 -d:` | tr '[A-Z]' '[a-z]' | tr ' ' '_' | tr '/' '-')
    		ALBUM=$(echo `cat ~/.ogg2mp3.inf | grep Album | cut -f2 -d:` | tr '[A-Z]' '[a-z]' | tr ' ' '_' | tr '/' '-')
		FILE=$(echo $NAME\($ALBUM\))

		#encoda para mp3
		lame --tt "$NAME" --ta "$ARTIST" --tl "$ALBUM" --tg "$GENRE" audiodump.wav -o $FILE.mp3

		#move o mp3 para o path de $1
		mv $FILE.mp3 $1

		#remove o audiodump.wav
		rm audiodump.wav
done



