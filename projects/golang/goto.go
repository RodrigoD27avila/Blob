package main

func fail() int {
	if 10 > 9 {
		goto ExitWithFail
	}
	return 0
ExitWithFail:
	return -1
}

func main() {
	fail()
}
