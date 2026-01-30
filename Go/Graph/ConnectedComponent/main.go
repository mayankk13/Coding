package main

import "fmt"

func dfs(node int, adj [][]int, visited []bool, curr *[]int) {
	visited[node] = true
	*curr = append(*curr, node)

	for _, neighbor := range adj[node] {
		if !visited[neighbor] {
			dfs(neighbor, adj, visited, curr)
		}
	}
}

func getComponents(V int, edges [][]int) [][]int {
	result := [][]int{}
	visited := make([]bool, V)

	// create adjacency list
	adj := make([][]int, V)
	for _, e := range edges {
		u, v := e[0], e[1]
		adj[u] = append(adj[u], v)
		adj[v] = append(adj[v], u)
	}

	// find connected componets
	for i := 0; i < V; i++ {
		if !visited[i] {
			curr := []int{}
			dfs(i, adj, visited, &curr)
			result = append(result, curr)
		}
	}

	return result
}

func main() {
	V := 5
	edges := [][]int{
		{0, 1},
		{1, 2},
		{3, 4},
	}

	components := getComponents(V, edges)
	for _, comp := range components {
		fmt.Println(comp)
	}
}
