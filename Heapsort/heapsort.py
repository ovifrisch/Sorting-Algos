import heapq
import random
import sys
sys.path.append('../Test')
from PythonTest import test

def build_heap(nums):
	heapq.heapify(nums)

def heapsort(nums):
	heapq.heapify(nums)
	res = []
	while (nums):
		res.append(heapq.heappop(nums))
	return res


print(test(heapsort))