import sys
sys.path.append('../Test')
from PythonTest import test

def bubble_sort(nums):
	for i in range(len(nums)):
		for j in range(i+1, len(nums)):
			if (nums[j] < nums[i]):
				temp = nums[i]
				nums[i] = nums[j]
				nums[j] = temp
	return nums


print(test(bubble_sort))