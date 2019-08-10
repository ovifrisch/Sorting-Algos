import sys
sys.path.append('../Test')
from PythonTest import test

def quicksort(lst):
	if (len(lst) < 2):
		return lst
	pivot = lst[0]

	lessers = [x for x in lst[1:] if x <= pivot]
	greaters = [x for x in lst[1:] if x > pivot]
	
	return quicksort(lessers) + [pivot] + quicksort(greaters)
	

print(test(quicksort))

