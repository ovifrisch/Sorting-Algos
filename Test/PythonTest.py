
import random

def gen_nums(n):
	nums = []
	for i in range(n):
		nums.append(random.randint(0, 100))
	return nums

def test(sorter):
	nums = sorter(gen_nums(20))

	for i in range(1, len(nums)):
		if (nums[i] < nums[i-1]):
			return False
	return True