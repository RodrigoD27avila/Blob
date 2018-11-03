-module(fib).
-export([fibonnaci/1]).

fibonnaci(0) -> 1;
fibonnaci(1) -> 1;
fibonnaci(N) -> fibonnaci(N-1)+fibonnaci(N-2).
