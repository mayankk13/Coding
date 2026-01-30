package main

import "fmt"

func dfs(node int, adj [][]int, visited []bool, result *[]int) {
	visited[node] = true
	*result = append(*result, node)

	for _, neighbor := range adj[node] {
		if !visited[neighbor] {
			dfs(neighbor, adj, visited, result)
		}
	}
}

func dfsOfGraph(V int, adj [][]int) []int {
	result := []int{}
	visited := make([]bool, V)

	// Start DFS from node 0
	dfs(0, adj, visited, &result)

	return result
}

func main() {
	V := 5
	adj := make([][]int, V)

	// adding edges
	adj[0] = []int{2, 3, 1}
	adj[1] = []int{0}
	adj[2] = []int{0, 4}
	adj[3] = []int{0}
	adj[4] = []int{2}

	dfs := dfsOfGraph(V, adj)
	for _, val := range dfs {
		fmt.Printf("%d ", val)
	}
}
