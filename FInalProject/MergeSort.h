#pragma once
template <class ItemType> 
class MSort {

	//counter variables 
private:
	int swapCount = 0;
	int compCount = 0;


public:

	template<class ItemType>
	void Merge(ItemType values[], int leftFirst, int leftLast,
		int rightFirst, int rightLast)
		// Post: values[leftFirst]..values[leftLast] and 
		//       values[rightFirst]..values[rightLast] have been merged.
		//       values[leftFirst]..values[rightLast] is now sorted.
	{
		
		ItemType tempArray[SIZE2];
		int index = leftFirst;
		int saveFirst = leftFirst;

		while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
		{
			compCount++;
			if (values[leftFirst] < values[rightFirst])
			{
				tempArray[index] = values[leftFirst];
				leftFirst++;
			}
			else
			{
				tempArray[index] = values[rightFirst];
				rightFirst++;
			}
			index++;
		}

		while (leftFirst <= leftLast)
			// Copy remaining items from left half.

		{
			compCount++;
			tempArray[index] = values[leftFirst];
			leftFirst++;
			index++;
		}

		while (rightFirst <= rightLast)
			// Copy remaining items from right half.
		{
			compCount++;
			tempArray[index] = values[rightFirst];
			rightFirst++;
			index++;
		}

		for (index = saveFirst; index <= rightLast; index++) {

			values[index] = tempArray[index];
		}
	}
	template<class ItemType>
	//correct limit on mergesort
	void MergeSort(ItemType values[], int first, int last)
		// Post: The elements in values are sorted by key.
	{
		compCount++;
		if (first < last)
		{
			int middle = (first + last) / 2;
			MergeSort(values, first, middle);
			MergeSort(values, middle + 1, last);
			Merge(values, first, middle, middle + 1, last);
		}
	}
	int SwapCounterP() {
		return swapCount;
	}
	//return private counter integer 
	int CompCounterP() {
		return compCount;
	}
	int ResetCounters() {
		swapCount = 0;
		compCount = 0;
		return 0;
	}

};