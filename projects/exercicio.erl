-module(exercicio).
-export([area_retangulo/2, factorial/1, nota_aluno/4, invert_list/1]).

area_retangulo(W, H) -> W * H.

factorial(0) -> 1;
factorial(N) -> N * factorial(N-1).

nota_aluno(Nome, Nota1, Nota2, Nota3) ->
	io:format("~s~n", [Nome]),
	io:format("Media: ~f~n", [(Nota1+Nota2+Nota3)/3]),
	ok.

invert_list([]) -> [];
invert_list([H|T]) -> invert_list(T) ++ [H].


