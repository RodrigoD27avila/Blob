package main

import "fmt"

func sum(a int, b int) int {
	return a+b
}

func main() {
	if s := sum(10, 20); s < 100 {
		fmt.Println("menor")
	} else {
		fmt.Println("maior ou igual")
	}

	if true && false || true {
		fmt.Println("true")
	}

	if ! false {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}
