#!/usr/bin/env escript
%% -*- erlang -*-
%%! -smp enable -sname factorial -mnesia debug verbose

main([Args]) ->
	try
		N = list_to_integer(Args),
		F = fac(N),
		io:format("factorial ~w = ~w\n", [N, F])
	catch
		_:_ ->
			usage()
	end;

main(_) ->
	usage().

usage() ->
	io:format("USAGE: factorial <integer>\n"),
	halt(1).

fac(0) -> 1;
fac(N) -> N * fac(N-1).
