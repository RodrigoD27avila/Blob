#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/thread/xtime.hpp>

const int MAX = 100;

int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX];

int porcentagem = 0;

void multiplica()
{
	int soma;	

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			soma = 0;
			for (int k = 0; k < MAX; k++) {
				soma += A[i][k] * B[k][j];
			}

			C[i][j] = soma;
		}
		if (i % (MAX / 100) == 0) porcentagem++;
	}
}

void barra_de_progresso()
{
	int atual = 0;
	while (porcentagem != 100) {
		if (atual != porcentagem) {
			if (porcentagem % 10 == 0) {
				std::cout << "\b\b" << porcentagem << '%';
			}
			else std::cout << '=' << std::flush;

			atual++;
		}
	}
}

int main()
{
	boost::thread tMultiplica(&multiplica);
	boost::thread tProgresso(&barra_de_progresso);

	boost::xtime inicio, fim;
	boost::xtime_get(&inicio, boost::TIME_UTC);

	std::cout << "Iniciando a multiplicação de matrizes" << std::endl;

	tMultiplica.join();
	tProgresso.join();

	boost::xtime_get(&fim, boost::TIME_UTC);

	std::cout << "\n\nProcesso terminado em " <<
		(fim.sec - inicio.sec) << " segundos" << std::endl;

	return 0;
}
