package main

import "fmt"

func main() {
	s1 := "Rodrigo"

	c := []rune(s1)
	c[0] = 'r'

	s2 := string(c)

	fmt.Println(s1)
	fmt.Println(s2)
}
