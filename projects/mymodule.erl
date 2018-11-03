-module(mymodule).
-export([myfunction/1]).

myfunction({dobro, Num}) ->
    Num * 2;

myfunction({triplo, Num}) ->
    Num * 3;

myfunction({Y, _}) ->
    {Y,nao,existe}.
