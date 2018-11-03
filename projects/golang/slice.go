package main

import "fmt"

func main() {
	a := []int{10, 20, 30, 40}
	b := a[1:]
	c := append(b, 10, 20, 30, 40, 50 ,60)
	fmt.Println(c, len(c), cap(c))
}
