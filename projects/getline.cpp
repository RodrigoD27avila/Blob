#include <iostream>

int main()
{
	std::string nome;
	char *apelido = new char[100];



	std::cout << "Digite seu nome: ";
	std::getline(std::cin, nome);
	std::cout << "Digite seu apelido: ";
	std::cin.getline(apelido, 100);

	std::cout << "Olá " << nome << std::endl;
	std::cout << "Olá " << apelido << std::endl;

	delete[] apelido;
}
