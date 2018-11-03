#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;

int Map( char c ) {
	string arr[] = {"oqz", "ij", "abc", "def", "gh", "kl", "mn", "prs", "tuv", "wxy"};
	for( int i = 0; i < 10; i ++ )
		for( int j = 0; j < arr[i].length(); j ++ )
			if( arr[i][j] == c )
				return i;
	return 0;
}

struct Trie {
	Trie* children[10];
	int mark;
	Trie() {
		for( int i = 0; i < 10; i ++ )
			children[i] = NULL;
		mark = -1;
	}
	void Add(const char* s, int id) {
		if( s[0] == 0 ) {
			mark = id;
		} else {
			if( children[Map(s[0])] == NULL )
				children[Map(s[0])] = new Trie;
			children[Map(s[0])]->Add(s+1, id);
		}
	}
	~Trie() {
		for( int i = 0; i < 10; i ++ )
			if( children[i] != NULL )
				delete children[i];
	}
};

Trie* trie;
char phone_number[100];
char arr[50000][55];
int mat[101];
int mat2[101];

int solve( int idx, int& L ) {
	if( phone_number[idx] == 0 ) {
		L = 0;
		return true;
	}
	int& result = mat[idx];
	if( result == -1 ) {
		result = -2;
		mat2[idx] = 1000;
		Trie* node = trie;
		for( int i = idx; phone_number[i] != 0 && node != NULL; i ++ ) {
			node = node->children[phone_number[i]-'0'];
			int LL;
			if( node != NULL && node->mark != -1 && solve( i + 1, LL ) != -2 )
				if( LL + 1 < mat2[idx] )
				{
					result = node->mark;
					mat2[idx] = LL + 1;
				}
		}
	}
	L = mat2[idx];
	return result;
}

string GetSolution( int idx ) {
	if( phone_number[idx] == 0 )
		return "";
	int L;
	return string( arr[solve(idx, L)]) + string(" ") + GetSolution( idx + strlen(arr[solve(idx, L)]));
}

int main() {
	while( scanf("%s", phone_number), strcmp(phone_number, "-1") != 0 ) {
		trie = new Trie;
		int n;
		scanf("%d", &n);
		for( int i = 0; i < n; i ++ ) {
			scanf("%s", arr[i]);
			trie->Add(arr[i], i);
		}
		memset( mat, -1, sizeof mat );
		int L;
		if( solve(0, L) == -2 )
			cout << "No solution." << endl;
		else
			cout << GetSolution(0) << endl;
		delete trie;
	}
	return 0;
}
