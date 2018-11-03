#include <array>
#include <algorithm>
#include <iostream>

template<class Matrix, class Value>
static inline void fill_matrix(Matrix &m, Value &&v)
{
	for (auto &a : m) {
		for (auto & b : a) {
			b = v;
		}
	}
}

template<class Matrix>
static inline void print_matrix(Matrix &m)
{
	for (auto &a : m) {
		for (auto & b : a) {
			std::cout << b << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	std::array<std::array<char, 16>, 4> matrix1;
	std::array<std::array<char, 16>, 6> matrix2;

	matrix1[0][0]  = 'O'; matrix1[1][0]  = 'N'; matrix1[2][0]  = 'U'; matrix1[3][0]  = 'E';
	matrix1[0][1]  = ' '; matrix1[1][1]  = 'T'; matrix1[2][1]  = 'E'; matrix1[3][1]  = 'S';
	matrix1[0][2]  = 'Q'; matrix1[1][2]  = 'E'; matrix1[2][2]  = ' '; matrix1[3][2]  = 'C';
	matrix1[0][3]  = 'U'; matrix1[1][3]  = ' '; matrix1[2][3]  = 'E'; matrix1[3][3]  = 'O';
	matrix1[0][4]  = 'E'; matrix1[1][4]  = 'E'; matrix1[2][4]  = ' '; matrix1[3][4]  = 'N';
	matrix1[0][5]  = ' '; matrix1[1][5]  = 'S'; matrix1[2][5]  = 'R'; matrix1[3][5]  = 'D';
	matrix1[0][6]  = 'E'; matrix1[1][6]  = 'C'; matrix1[2][6]  = 'U'; matrix1[3][6]  = 'E';
	matrix1[0][7]  = ' '; matrix1[1][7]  = 'O'; matrix1[2][7]  = 'I'; matrix1[3][7]  = 'M';
	matrix1[0][8]  = 'B'; matrix1[1][8]  = 'N'; matrix1[2][8]  = 'M'; matrix1[3][8]  = 'O';
	matrix1[0][9]  = 'O'; matrix1[1][9]  = 'D'; matrix1[2][9]  = ' '; matrix1[3][9]  = 'S';
	matrix1[0][10] = 'M'; matrix1[1][10] = 'E'; matrix1[2][10] = 'A'; matrix1[3][10] = ' ';
	matrix1[0][11] = ' '; matrix1[1][11] = ','; matrix1[2][11] = ' '; matrix1[3][11] = 'T';
	matrix1[0][12] = 'A'; matrix1[1][12] = ' '; matrix1[2][12] = 'N'; matrix1[3][12] = 'B';
	matrix1[0][13] = ' '; matrix1[1][13] = 'O'; matrix1[2][13] = 'O'; matrix1[3][13] = ' ';
	matrix1[0][14] = 'G'; matrix1[1][14] = ' '; matrix1[2][14] = 'S'; matrix1[3][14] = '=';
	matrix1[0][15] = 'E'; matrix1[1][15] = 'Q'; matrix1[2][15] = ' '; matrix1[3][15] = ')';


	fill_matrix(matrix2, ' ');


	int l =0, c = 0;
	for (unsigned  i = 0; i < matrix1.size(); i++) {
		for (unsigned j=0; j < matrix1[i].size(); j++) {
	
		if (j==15) {
			l += 1;
		}

		if (c == 16) {
			c = 0;
		}
	
		if (i==0 && j==14) {
			l += 1;
			c =  0;
			std::cout << "1\n";
		}

		if (i==1 && j==3) {
			l+=1;
			c =  0;
			std::cout << "2\n";
		}

		if (i==1 && j ==15) {
			l+= 1;
			c = 0;
			std::cout << "3\n";
		}

		if (i==2 && j==2) {
			l+=1;
			c =  0;
			std::cout << "4\n";
		}

		matrix2[l][c++] = matrix1[i][j];

		}
	}
	
	print_matrix(matrix1);
	std::cout << '\n';
	print_matrix(matrix2);
}
