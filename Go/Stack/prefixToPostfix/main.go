package main

import "fmt"

func preToPost(str string) string {
	stack := []string{}

	for i := len(str) - 1; i >= 0; i-- {
		ch := str[i]

		// in case of operator
		if (ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9') {
			stack = append(stack, string(ch))
		} else {
			// operator
			// pop two operands
			op1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			op2 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			// combine in postfix order
			newExp := op1 + op2 + string(ch)
			stack = append(stack, newExp)
		}
	}

	return stack[len(stack)-1]
}

func main() {
	str := "*-A/BC-/AKL"

	res := preToPost(str)
	fmt.Printf(res)
}
