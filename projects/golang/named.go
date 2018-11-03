package main

import "fmt"

func foo() (a, b int) {
	a,b = 1,11
	return
}

func main() {
	fmt.Println(foo())
}
