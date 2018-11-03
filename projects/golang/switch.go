package main

import "fmt"

func main() {
	switch 10 {
	case 0, 1, 2, 3, 4, 5, 6, 7, 8, 9: fallthrough
	case 10:
		fmt.Println("é 10 ou 0")
		break
	default:
		break
	}
}
