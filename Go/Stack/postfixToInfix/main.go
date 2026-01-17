package main

import "fmt"

func postToInfix(str string) string {
	stack := []string{}

	for i := 0; i < len(str); i++ {
		ch := str[i]

		// operand - push to stack
		if (ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9') {
			stack = append(stack, string(ch))
		} else {
			op2 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			op1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			newExp := "(" + op1 + string(ch) + op2 + ")"
			stack = append(stack, newExp)
		}
	}
	return stack[len(stack)-1]
}

func main() {
	str := "AB+CD-*"

	res := postToInfix(str)
	fmt.Println(res)
}
