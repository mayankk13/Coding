package main

import "fmt"

func infixToPostfix(str string) string {
	// operator precedence
	prec := map[byte]int{
		'^': 3,
		'*': 2,
		'/': 2,
		'+': 1,
		'-': 1,
	}

	stack := []byte{}
	res := []byte{}

	for i := 0; i < len(str); i++ {
		ch := str[i]

		// if operand, add to result
		if (ch >= 'a' && ch <= 'z') ||
			(ch >= 'A' && ch <= 'Z') ||
			(ch >= '0' && ch <= '9') {
			res = append(res, ch)
		} else if ch == '(' {
			stack = append(stack, ch)
		} else if ch == ')' {
			// pop until '('
			for len(stack) > 0 && stack[len(stack)-1] != '(' {
				res = append(res, stack[len(stack)-1])
				stack = stack[:len(stack)-1]
			}

			// pop '('
			stack = stack[:len(stack)-1]
		} else {
			// operator
			for len(stack) > 0 && stack[len(stack)-1] != '(' &&
				prec[ch] <= prec[stack[len(stack)-1]] {
				res = append(res, stack[len(stack)-1])
				stack = stack[:len(stack)-1]
			}

			// push current operator
			stack = append(stack, ch)
		}
	}
	// pop remaining operators
	for len(stack) > 0 {
		res = append(res, stack[len(stack)-1])
		stack = stack[:len(stack)-1]
	}

	return string(res)
}

func main() {
	str := "a+b*c"

	res := infixToPostfix(str)
	fmt.Println(res)

}
