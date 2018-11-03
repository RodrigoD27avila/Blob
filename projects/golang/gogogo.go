package main

import "fmt"

func teste() int {
	if 20 < 10 {
		return 10
	} else {
		return 9
	}
}

func main() {
	var a, b, c, d int
	a = 100
	b, c, d = 10, 20, 30

	teste()

	fmt.Println(a, b, c, d)
}
