package main

import "fmt"

func Sol() {
	var n, m int
	fmt.Scan(&n, &m)
	a := make([]int, m)
	for i:= 0; i < m; i++ {
		fmt.Scan(&a[i])
	}

	ok := true
	for i:= 1; i < m; i++ {
		if a[i] <= a[i - 1] {ok = false}
	}

	if !ok {
		fmt.Println(1) 
		return
	}

	mx := 1
	for i:= 0; i < m; i++ {
		mx = max(mx, a[i])
	}

	fmt.Println(n - mx + 1)
}

func main() {
	var tc int
	fmt.Scan(&tc)
	for tc > 0 {
		Sol()
		tc--
	}
}
