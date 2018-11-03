package main

import ( "fmt"
		 "os")

func main() {
	fmt.Println("MAP")
	defer fmt.Println("EXIT")

const myfolder = "myfolder"

if _, err := os.Stat(myfolder); err != nil {
	os.Mkdir(myfolder, 666)
} else {
	fmt.Printf("%v", err);
}

}
