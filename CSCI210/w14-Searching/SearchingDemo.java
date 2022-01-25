import java.util.Arrays;
import java.util.Random;

class SearchingDemo {

    public static int binarySearch(int[] arr, int value) {
        int i = 0;
        int j = arr.length - 1;
        int mid;
        while (i <= j) {
            mid = (i + j) / 2;
            if (arr[mid] > value)
                j = mid - 1;
            else if (arr[mid] < value)
                i = mid + 1;
            else
                return mid;
        }
        return -1;
    }

    public static int linearSearch(int[] arr, int value) {
        int index = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == value)
                return i;
        }
        return index;
    }

    public static void testSearchMethod(int[] arr, int index, boolean isLinear) {
        long startTime;
        if (isLinear) {
            startTime = System.currentTimeMillis();
            System.out.println("Linear Search in small array for value " + arr[index] + " at index " + index + ".\n"
                    + "Index found: " + linearSearch(arr, arr[index]) + ", Time: "
                    + (System.currentTimeMillis() - startTime) + " ms");
        } else {
            int[] temp = arr.clone();
            startTime = System.currentTimeMillis();
            Arrays.sort(temp);
            System.out.println("Binary Search in small sorted array for value " + temp[index] + " at index " + index
                    + ".\n" + "Index found: " + binarySearch(temp, temp[index]) + ", Time including sorting: "
                    + (System.currentTimeMillis() - startTime) + " ms");
        }
    }

    public static void main(String[] args) {
        //the idea of filling with random values is to force the binary
        //search to sort the array first
        //the upper bound of the rand.nextInt is large to try and avoid duplication
        Random rand = new Random();
        int[] testArraySmall = new int[1000];
        for (int i = 0; i < testArraySmall.length; i++) {
            testArraySmall[i] = rand.nextInt(Integer.MAX_VALUE);
        }
        int[] testArrayMedium = new int[10000];
        for (int i = 0; i < testArrayMedium.length; i++) {
            testArrayMedium[i] = rand.nextInt(Integer.MAX_VALUE);
        }

        int[] testArrayLarge = new int[100000];
        for (int i = 0; i < testArrayLarge.length; i++) {
            testArrayLarge[i] = rand.nextInt(Integer.MAX_VALUE);
        }

        //linear searches, small array
        testSearchMethod(testArraySmall, 0, true);
        testSearchMethod(testArraySmall, testArraySmall.length / 2, true);
        testSearchMethod(testArraySmall, testArraySmall.length - 1, true);
        System.out.println("=====");

        //linear seaches, medium array
        testSearchMethod(testArrayMedium, 0, true);
        testSearchMethod(testArrayMedium, testArrayMedium.length / 2, true);
        testSearchMethod(testArrayMedium, testArrayMedium.length - 1, true);
        System.out.println("=====");

        //linear seaches, large array
        testSearchMethod(testArrayLarge, 0, true);
        testSearchMethod(testArrayLarge, testArrayLarge.length / 2, true);
        testSearchMethod(testArrayLarge, testArrayLarge.length - 1, true);
        System.out.println("=====");

        //binary searches, small array
        testSearchMethod(testArraySmall, 0, false);
        testSearchMethod(testArraySmall, testArraySmall.length / 2, false);
        testSearchMethod(testArraySmall, testArraySmall.length - 1, false);
        System.out.println("=====");

        //binary searches, medium array
        testSearchMethod(testArrayMedium, 0, false);
        testSearchMethod(testArrayMedium, testArrayMedium.length / 2, false);
        testSearchMethod(testArrayMedium, testArrayMedium.length - 1, false);
        System.out.println("=====");

        //binary searches, large array
        testSearchMethod(testArrayLarge, 0, false);
        testSearchMethod(testArrayLarge, testArrayLarge.length / 2, false);
        testSearchMethod(testArrayLarge, testArrayLarge.length - 1, false);
    }

}