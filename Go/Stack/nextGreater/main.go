package main

import "fmt"

func reverse(arr []int) []int {
	n := len(arr)

	i := 0
	j := n - 1

	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}

	return arr
}

func nextGreater(arr []int) []int {
	n := len(arr)
	res := []int{}
	stack := []int{}

	for i := n - 1; i >= 0; i-- {

		// case 1: if stack is empty, no next greater element to the right
		if len(stack) == 0 {
			res = append(res, -1)
		} else if len(stack) != 0 && stack[len(stack)-1] > arr[i] {
			// case 2: if top of stack is greater than curr, thats NGE
			res = append(res, stack[len(stack)-1])
		} else if len(stack) > 0 && stack[len(stack)-1] <= arr[i] {
			// Case 3: If stack top <= current element
			for len(stack) != 0 && stack[len(stack)-1] <= arr[i] {
				stack = stack[:len(stack)-1]
			}

			if len(stack) == 0 {
				res = append(res, -1)
			} else if len(stack) > 0 && stack[len(stack)-1] > arr[i] {
				res = append(res, stack[len(stack)-1])
			}
		}
		stack = append(stack, arr[i])
	}
	res = reverse(res)

	return res
}

func main() {
	arr := []int{1, 3, 2, 4} // O/P - [3, 4, 4, -1]

	res := nextGreater(arr)
	fmt.Println(res)
}
