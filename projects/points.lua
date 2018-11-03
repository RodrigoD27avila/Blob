for n = -1.0, 1.0, 0.2 do
	print(string.format("%.1ff, 1.0f, 1.0f,", n))
	print(string.format("1.0f, %.1ff, 1.0f,", n))
	print(string.format("1.0f, 1.0f, %.1ff,", n))
	
	print(string.format("%.1ff, -1.0f, -1.0f,", n))
	print(string.format("-1.0f, %.1ff, -1.0f,", n))
	print(string.format("-1.0f, -1.0f, %.1ff,", n))
	
	print(string.format("%.1ff, 1.0f, -1.0f,", n))
	print(string.format("-1.0f, %.1ff, -1.0f,", n))
	print(string.format("-1.0f, 1.0f, %.1ff,", n))
	
	print(string.format("%.1ff, 1.0f, 1.0f,", n))
	print(string.format("-1.0f, %.1ff, 1.0f,", n))
	print(string.format("-1.0f, 1.0f, %.1ff,", n))
	
	print(string.format("%.1ff, -1.0f, -1.0f,", n))
	print(string.format("1.0f, %.1ff,-1.0f,", n))
	print(string.format("1.0f, -1.0f, %.1ff,", n))
	
	print(string.format("%.1ff, -1.0f,  1.0f,", n))
	print(string.format("-1.0f, %.1ff, 1.0f,", n))
	print(string.format("-1.0f, -1.0f, %.1ff,", n))
end
