#!/usr/bin/python
# coding: utf-8
 
import sys
 
class lzw_encoder:
    """
        Classe usada para codificar um arquivo usando 
        o algoritmo LZW. Está é uma implementação de 
        exemplo que não leva em conta a representação
        binária do arquivo de saída nem o estouro do 
        tamanho do dicionário. Este código foi baseado nas
        informações contidas em 
        http://pt.wikipedia.org/wiki/LZW
    """
    def __init__(self):
        """
            Faz a carga inicial do dicionário com os 256
            caracteres ASCII possíveis.
        """
        self.next_code = 0
        self.dictionary = dict()
        for i in range(0,256):
            self.add_to_dictionary(chr(i))
    def add_to_dictionary(self, str):
        """
            Cria um novo código para uma dada "string" e a
            insere sob esse código no dicionário
        """
        self.dictionary[str] = self.next_code
        self.next_code = self.next_code + 1
    def encode(self, str):
        """
            Corpo do algoritmo. lê sequencialmente os 
            caracteres e cria as cadeias a serem inseridas 
            no dicionário, emitindo os respectivos códigos
            no arquivo de saída (representado pela lista "ret"
        """
        ret = [] # inicializa a lista (arquivo de saída)
        buffer = '' # inicializa o acumulador de caracteres lidos
        for i in range(0, len(str)):
            c = str[i]
            # enquanto a cadeia atual existir no dicionário, 
            # continuamos acresncentando caracteres a ela
            if len(buffer) == 0 or self.dictionary.has_key(buffer + c):
                buffer = buffer + str(c)
            else:
                # quando encontramos a maior cadeia presente
                # emitimos o código dessa cadeia e criamos uma 
                # nova cadeia, acrescentando o último 
                # caractere lido.
                code = self.dictionary[buffer]
                self.add_to_dictionary(buffer + c)
                buffer = c
                ret = ret + [code]
        if buffer:
            ret = ret + [self.dictionary[buffer]]
        return ret
 
class lzw_decoder:
    """
        Classe usada para decodificar um arquivo 
        codificado com LZW. Segue as mesmas restrições 
        da classe  lzw_encoder
    """
    def __init__(self):
        """
            Faz a carga inicial do dicionário com os 256
            caracteres ASCII possíveis.
        """
        self.next_code = 0
        self.dictionary = dict()
        for i in range(0,256):
            self.add_to_dictionary(chr(i))
    def add_to_dictionary(self, str):
        """
            Cria um novo código para uma dada "string" e a
            insere sob esse código no dicionário
        """
        self.dictionary[self.next_code] = str
        self.next_code = self.next_code + 1
    def decode(self, symbols):
        """
            Decodifica o arquivo. Emite sequêncialmente
            as cadeias correspondentes aos códigos lidos.
            Caso a concatenação dos códigos lidos não 
            corresponda a uma cadeia existente, acrescenta no
            dicionário como uma nova cadeia.
        """
        last_symbol = symbols[0]
        ret = self.dictionary[last_symbol]
        for symbol in symbols[1:]:
            if self.dictionary.has_key(symbol):
                current = self.dictionary[symbol]
                previous = self.dictionary[last_symbol]
                to_add = current[0]
                self.add_to_dictionary(previous + to_add)
                ret = ret + current
            else:
                previous = self.dictionary[last_symbol]
                to_add = previous[0]
                self.add_to_dictionary(previous + to_add)
                ret = ret + previous + to_add
            last_symbol = symbol
        return ret
 
if __name__ == "__main__":

    nome = sys.argv[1]
    fin = open (nome, 'rb')
    fout = open (nome + '.pyllz', 'wb+')
    encoder = lzw_encoder()
    encoded = encoder.encode(fin.read())
    fout.write(''.join(str(v) for v in encoded))
    fin.close ()
    fout.close ()
    
    #decoder = lzw_decoder()
    #decoded = decoder.decode(encoded)
    #print ('decoded:', decoded)

