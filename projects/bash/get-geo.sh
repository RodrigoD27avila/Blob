#!/bin/bash
# getgeo
# 
# Uso      : getgeo <ip/host>
# Autor    : Vinicius Della Libera artedogesto [at] gmail.com
# Site     : http://get-geo.sf.net
# Descricao: Procura a localidade fisica de um IP, mas nem sempre acerta.
#

[ "$1" = "" -o "$1" = "--help" ] && { echo -e "Procura a localidade fisica de um IP, mas nem sempre acerta.\nUso: $0 <ip/host>" ; exit; }

tmp="getgeo.tmp"
echo "ips="$1""|lynx -source -post-data -accept_all_cookies http://www.maxmind.com/app/lookup_city |grep -A 20 "Area Code" > $tmp

# Estado
state="`sed ':;10q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# Cidade
city="`sed ':;11q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# Codigo do pais
country_code="`sed ':;7q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# Pais 
country="`sed ':;8q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# CEP
cep="`sed ':;12q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# ISP 
isp="`sed ':;15q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
# Organizacao
organization="`sed ':;16q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"

# Latitude
latmap1="`sed ':;13q;$!d' $tmp | sed 's/^.*">//;s/<\/.*$//'`"
latmap2="`sed ':;14q;$!d' $tmp |sed 's/^.*">//;s/<\/.*$//'`"

rm getgeo.tmp

echo "IP/Host: $1"
echo "Estado: $state"
echo "Cidade: $city"
echo "Pais: $country ($country_code)"
echo "CEP: $cep"
echo "ISP: $isp"
echo "Organizacao: $organization"
echo "Latitude: $latmap1, $latmap2" 
echo "Aproximadamente: http://maps.google.com/maps?q=${latmap1},${latmap2}"
