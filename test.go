package main

import (
	"fmt"
	"time"
)

func out() {
	for i := 0; i < 10; i++ {
		time.Sleep(time.Millisecond * 100)
		fmt.Println(i)
	}
}

func main() {
	go out()
	out()
}
