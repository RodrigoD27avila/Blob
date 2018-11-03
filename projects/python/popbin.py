#!/usr/bin/python
# -*- coding: utf-8 -*-


#variáveis
dicfile = {} #dicionário que vai conter os caracteres e suas ocorrências
file = open('/home/rdapache/numperf') #arquivo a ser aberto
filelist = list(file.read()) #atribuição tranforma o arquivo em lista de caracteres
file.close() #fecha arquivo

contchar = 0 #numera a quantidade de ocorrências do caracter
charr = '' #começa o caracter em nulo

#loop até a lista acabar
while 1:
		#verifica se ainda contém algo em filelist
		if (len(filelist) <= 0):
				break #sai loop
		x = 0
		#atribui à charr o primeiro caracter da lista
		charr = filelist[0]
		#loop até a ocorrência do caracter acabar
		while 1:
			#caso haja caracteres únicos ou o caracter não tem mais ocorrência sai do loop
			if (x >= len(filelist)):
					break #sai loop
			#se charr tem careacter igual entra no if
			if (charr == filelist[x]):
					#caso seja igual remove o caracter
					filelist.pop(x)
					#soma quantas vezes houve a ocorrência do caracter
					contchar = contchar + 1
					#não soma nada ao x caso o caracter seja igual porque a lista também diminui
					continue
			#soma 1 ao x caso não ache caracter igual
			x = x + 1
		#cria chave com o nome do caracter e coloca quantas vezes ele ocorreu
		dicfile[charr] = contchar
		#zera número de ocorrências para mais uma rodada
		contchar = 0
		#caso a lista fique vazia sai do loop
		if (len(filelist) == 0):
				break #sai loop
#imprime o dicionário
print (dicfile)




