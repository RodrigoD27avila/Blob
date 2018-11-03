
#!/bin/bash
#    Convert OGG to MP3 so you can listen on those "mp3 players" as iPOD
#
#    Copyright (C) 2007  Thomaz de Oliveira dos Reis thor27 AT gmail.com
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#Get latest Parameter
for last do a=0
done

#If output is a file, you cannot have more than 1 file as input...
if [ ! -d "$last" ] && (( $# > 2 ))
then
 echo $0: Target \'$last\' is not a directory >/dev/stderr
 exit 1
fi

if [ "$1" == "-r" ] || [ "$1" == "-R" ] #Recursive flag
then
 RECURSIVE=1
 shift
else
 RECURSIVE=0
fi

while (( $# > 1 )) #Main loop
do
 if [ -d "$1" ] #Recursive support WARNING!!! INFINITE LOOP POSSIBLE, USE WITH CAUTION!!
 then
  if [ "$RECURSIVE" = "1" ] 
  then
   OUTPUT=` echo $last/${1##*/} | tr -s '/'`
   if [ ! -d "$OUTPUT" ]
   then
    if ! mkdir "$OUTPUT"
    then
     echo Could not create directory \'$OUTPUT\' >/dev/stderr
    fi
   fi
   $0 -r "$1"/* "$OUTPUT" # Recursive call
  else
   echo Ignoring $1: is a directory >/dev/stderr
  fi
 else
  if [ -d "$last" ] #if output is a directory, you need to get the filename from $1
  then 
   OUTPUT=$last/`echo ${1##*/} | sed 's/[Oo][Gg][Gg]$/mp3/g'`
  else 
   OUTPUT=$last  #if not, the filename is already given...
  fi
  
  echo $1 ' -> ' $OUTPUT 
  oggdec "$1" -o /dev/stdout -Q | lame -f - "$OUTPUT" --quiet #that does the magic ;) 
 fi 
 
 shift #removes $1, $2 is now $1
done

exit 0
