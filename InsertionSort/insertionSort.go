package main
import "fmt"

func insertionSort(list []int) {
	for i := 0; i < len(list); i++ {
		for j := i; j > 0; j-- {
			if (list[j] < list[j - 1]) {
				temp := list[j - 1]
				list[j - 1] = list[j]
				list[j] = temp
			}
		}
	}
}

func print(list []int) {
	for i := 0; i < len(list); i++ {
		fmt.Print(list[i], " ")
	}
	fmt.Println()
}

func main() {
	list := []int{5, 9, 3, 7, 4, 1, 2, 13, 55}
	insertionSort(list)
	print(list)
}
