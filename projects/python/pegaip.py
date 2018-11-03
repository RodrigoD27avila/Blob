#!/usr/bin/env python
#Programa que pega ip externo da maquina

from BeautifulSoup import BeautifulSoup
import urllib2


pub_ip = urllib2.urlopen('http://meuip.datahouse.com.br/').read() #abre site
soup = BeautifulSoup(pub_ip) #armazena o conteudo em html
ips = soup.findAll('title') #procura por tags

for ip in ips:
	ipexterno = str(ip)
#----------------

print (ipexterno[41:54])

