import java.util.*;

class mergesort {
	public static void main(String args[]) {
		ArrayList<Integer> myArr = new ArrayList<Integer>();
		myArr.add(5);
		myArr.add(4);
		myArr.add(3);
		mergeSort(myArr, 0, myArr.size() - 1);
		print(myArr);
	}

	private static <T extends Comparable> void mergeSort(List<T> list, int start, int end) {
		if (start >= end) return;
		int middle = (start + end) / 2;
		mergeSort(list, start, middle);
		mergeSort(list, middle + 1, end);
		merge(list, start, middle, middle + 1, end);

	}

	private static <T extends Comparable> void merge(List<T> list, int leftStart, int leftEnd, int rightStart, int rightEnd) {
		int length = rightEnd - leftStart + 1;
		int left = leftStart;
		int right = rightStart;
		ArrayList<T> temp = new ArrayList<T>();

		for (int i = 0; i < length; i++) {
			if (right > rightEnd) {
				temp.add(list.get(left++));
			}
			else if (left > leftEnd) {
				temp.add(list.get(right++));
			}
			else if (list.get(left).compareTo(list.get(right)) <= 0) {
				temp.add(list.get(left++));
			}
			else {
				temp.add(list.get(right++));
			}
		}

		for (int i = 0; i < length; i++) {
			list.set(leftStart++, temp.get(i));
		}
	}

	private static void print(List<?> list) {
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println();
	}

}
