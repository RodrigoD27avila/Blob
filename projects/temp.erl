-module(temp).
-export([convert/2]).

convert({fahrenheit, Temp}, celsius) ->
	{celsius, (Temp - 32) / 1.8};

convert({celsius, Temp}, fahrenheit) ->
	{fahrenheit, (Temp * 1.8) + 32};

convert({kelvin, Temp}, celsius) ->
	{celsius, Temp - 273.15};

convert({celsius, Temp}, kelvin) ->
	{kelvin, Temp + 273.15}.
