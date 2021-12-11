package main

import "fmt"

func existeSumaMenosUno(arr []int) (r bool) {
	r = false
	n := 0
	N := len(arr)
	s := 0

	for N > n {
		n, r, s = n+1, r || s+arr[n] == -1, s+arr[n]
	}
	return
}

func main() {
	var A []int = []int{}

	fmt.Println(existeSumaMenosUno(A))
}
