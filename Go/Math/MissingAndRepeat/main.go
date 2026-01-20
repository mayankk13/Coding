package main

import "fmt"

func findTwoElement(arr []int) []int {
	n := len(arr)
	mp := make(map[int]int, n)
	missing := -1
	repeat := -1

	for i := 1; i <= len(arr); i++ {
		mp[i] = 0
	}

	for i := 0; i < len(arr); i++ {
		mp[arr[i]]++
	}

	for key, val := range mp {
		if val > 1 {
			repeat = key
		}

		if val == 0 {
			missing = key
		}
	}

	return []int{repeat, missing}
}

func main() {
	arr := []int{1, 3, 3}
	res := findTwoElement(arr)

	fmt.Println(res)
}
