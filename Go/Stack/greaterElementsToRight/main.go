package main

import "fmt"

func countNGE(arr, indices []int) []int {
	n := len(arr)
	res := []int{}

	for _, idx := range indices {
		count := 0

		for j := idx + 1; j < n; j++ {
			if arr[j] > arr[idx] {
				count++
			}
		}
		res = append(res, count)
	}

	return res
}

func main() {
	arr := []int{3, 4, 2, 7, 5, 8, 10, 6}
	indices := []int{0, 5}

	res := countNGE(arr, indices)
	fmt.Println(res)
}
