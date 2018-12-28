def quicksort(lst):
	if (len(lst) < 2):
		return lst
	pivot = lst[0]

	lessers = [x for x in lst[1:] if x <= pivot]
	greaters = [x for x in lst[1:] if x > pivot]
	
	return quicksort(lessers) + [pivot] + quicksort(greaters)
	

if __name__ == "__main__":
	lst = [4, 7, 2, 9, 7, 3, 5, 7]
	lst2 = [1, 1, 1, 1, 1]
	print(quicksort(lst2))

