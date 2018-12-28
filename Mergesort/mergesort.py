

def merge(a, b):
	pos_a = pos_b = 0
	res = []
	while (pos_a < len(a) or pos_b < len(b)):
		if (pos_a == len(a)):
			res.append(b[pos_b])
			pos_b += 1
		elif (pos_b == len(b)):
			res.append(a[pos_a])
			pos_a += 1
		else:
			if (a[pos_a] < b[pos_b]):
				res.append(a[pos_a])
				pos_a += 1
			else:
				res.append(b[pos_b])
				pos_b += 1
	return res

def mergesort(lst):
	if (len(lst) < 2):
		return lst

	idx = len(lst) // 2
	return merge(mergesort(lst[0:idx]), mergesort(lst[idx:]))




if __name__ == "__main__":
	lst = [3, 6, 1, 3, 9, 6, 78, 32]
	print(mergesort(lst))	
