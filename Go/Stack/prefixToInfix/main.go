package main

import "fmt"

func preToInfix(str string) string {
	stack := []string{}

	for i := len(str) - 1; i >= 0; i-- {
		ch := str[i]

		if (ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9') {
			stack = append(stack, string(ch))
		} else {
			op1 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			op2 := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			newExp := "(" + op1 + string(ch) + op2 + ")"
			stack = append(stack, newExp)
		}
	}

	return stack[len(stack)-1]

}

func main() {
	str := "*-A/BC-/AKL"

	res := preToInfix(str)
	fmt.Println(res)
}
