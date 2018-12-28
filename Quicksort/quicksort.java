import java.util.*;

class quicksort {
	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(5);
		list.add(5);
		list.add(5);
		list.add(5);
		list.add(5);
		list.add(5);
		quicksort(list, 0, list.size() - 1);
		print(list);
	}

	private static <T extends Comparable> void quicksort(List<T> list, int left, int right) {
		if (right <= left) return;
		int start = left;

		ArrayList<T> temp = new ArrayList<T>();
		T pivot = list.get(left);

		for (int i = left + 1; i <= right; i++) {
			if (list.get(i).compareTo(pivot) <= 0) {
				temp.add(list.get(i));
			}
		}

		int posPivot = left + temp.size();
		temp.add(pivot);

		for (int i = left + 1; i <= right; i++) {
			if (list.get(i).compareTo(pivot) > 0) {
				temp.add(list.get(i));
			}
		}

		for (int i = 0; i < temp.size(); i++) {
			list.set(start++, temp.get(i));
		}

		quicksort(list, left, posPivot - 1);
		quicksort(list, posPivot + 1, right);
	}

	private static void print(List<?> list) {
		for (int i = 0; i < list.size(); i++) {
			System.out.print(list.get(i) + " ");
		}
		System.out.println();
	}
}



/*

Note: Must be compiled with -Xlint:unchecked option

*/
