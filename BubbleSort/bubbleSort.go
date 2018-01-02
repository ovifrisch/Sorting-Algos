package main

import "fmt"

func print(list []int) {
	for i := 0; i < len(list); i++ {
		fmt.Print(list[i], " ")
	}
	fmt.Println()
}

func bubbleSort(list []int) {
	for i := 0; i < len(list); i++ {
		for j := 0; j < len(list) - 1; j++ {
			if (list[j] > list[j + 1]) {
				temp := list[j]
				list[j] = list[j + 1]
				list[j + 1] = temp
			}
		}
	}
}

func main() {
	list := []int{5, 4, 3, 2, 1}
	bubbleSort(list)
	print(list)
}


//Compile command is go run bubbleSort.go
