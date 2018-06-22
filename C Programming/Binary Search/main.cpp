#include <iostream>

using namespace std;

int BinarySearchV1(int *arr, int num, int min, int max);
//int BinarySearchV2(int *arr, int num, int min, int max);

int main()
{
    int target = 13;

    int arr[5] = {10, 12, 15, 19, 21};

    int result = BinarySearchV1(arr, target, 0, 4);
	
	if (result >= 0)
	{
		cout << "Found target : " << target << " at index : " << result << endl;
	}
	else
	{
		cout << "Did not find target : " << target << endl;
	}
	system("pause");
    return 0;
}

int BinarySearchV1(int *arr, int num, int min, int max)
{
	if (max < min) return -1;

	int mid = (min + max) / 2;
	if (arr[mid] == num)
	{
		return mid;
	}
	else
	{
		if (arr[mid] < num)
		{
			if (min == max) return -1;

			return BinarySearchV1(arr, num, mid + 1, max);
		}
		else if (arr[mid] > num)
		{
			if (min == max) return -1;

			return BinarySearchV1(arr, num, min, mid - 1);
		}
	}
}


//int BinarySearchV2(int *arr, int num, int min, int max)
//{
//    if (max < min) return ~(max + 1);
//
//    int mid = (min + max)/2;
//    if (arr[mid] == num)
//    {
//        return mid;
//    }
//    else 
//    {
//        if (arr[mid] < num) 
//        {
//			if (mid == max) return ~max;
//            if (min == max) return ~(mid + 1);
//
//            return BinarySearchV2(arr, num, mid + 1, max);
//        }
//        else if (arr[mid] > num) 
//        {
//			if (mid == 0) return ~0;
//            if (min == max) return ~(mid + 1);
//
//            return BinarySearchV2(arr, num, min, mid - 1);
//        }
//    }
//}