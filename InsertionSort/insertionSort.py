import random
import sys
sys.path.append('../Test')
from PythonTest import test

def insertion_sort(nums):
	for i in range(1, len(nums)):
		if (nums[i] >= nums[i-1]):
			continue
		j = i
		while (j > 0 and nums[j] < nums[j-1]):
			temp = nums[j]
			nums[j] = nums[j-1]
			nums[j-1] -= temp
			j-=1
	return nums

print(test(insertion_sort))