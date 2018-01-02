import java.util.*;

class heapsort {
	public static void main(String args[]) {
		ArrayList<Integer> myArr = new ArrayList<Integer>();
		myArr.add(0);
		myArr.add(5);
		myArr.add(4);
		myArr.add(3);
		heapsort(myArr);
		print(myArr);
	}

	private static void print(List<?> list) {
		for (int i = 1; i < list.size(); i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println();
	}

	private static <T extends Comparable> void heapsort(List<T> list) {
		buildHeap(list);
		int heapSize = list.size();
		for (int i = 1; i < list.size(); i++) {
			T last = list.get(heapSize - 1);
			list.set(heapSize - 1, list.get(1));
			list.set(1, last);
			percolateDown(list, 1, --heapSize);
		}
	}

	private static <T extends Comparable> void buildHeap(List<T> list) {
		for (int i = (list.size() - 1) / 2; i > 0; i--) {
			percolateDown(list, i, list.size());
		}
	}

	private static <T extends Comparable> void percolateDown(List<T> list, int hole, int currentSize) {
		T temp = list.get(hole);
		int child;

		for (; hole * 2 <= currentSize - 1; hole = child) {
			child = hole * 2;
			if (child != currentSize - 1 && list.get(child + 1).compareTo(list.get(child)) > 0) {
				++child;
			}
			if (list.get(child).compareTo(temp) > 0) {
				list.set(hole, list.get(child));
			}
			else {
				break;
			}
		}
		list.set(hole, temp);
	}
}

