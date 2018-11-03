#!/bin/bash
# Script que descompacta de Gzip e compacta em Bzip2

NAME="`echo $1 | cut -f1 -d'.'`.pdf"
zcat $1 > "/tmp/$NAME"

