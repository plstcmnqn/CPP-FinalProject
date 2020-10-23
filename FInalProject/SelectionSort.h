#pragma once


template<class ItemType> 
class SSort {



	//counter variables 
private:
	int swapCount;
	int compCount;
	
public:
	


	template<class ItemType>
	int MinIndex(ItemType values[], int startIndex, int endIndex)
		// Post: Returns the index of the smallest value in
		//       values[startIndex]..values[endIndex].
	{
		int indexOfMin = startIndex;
		for (int index = startIndex + 1; index <= endIndex; index++) {
			compCount++;
			if (values[index] < values[indexOfMin])
				indexOfMin = index;
			
		}
		return indexOfMin;
	}


	template<class ItemType>
	void SelectionSort(ItemType values[], int numValues)
		// Post: The elements in the array values are sorted by key.
	{
		int endIndex = numValues - 1;
		
		for (int current = 0; current < endIndex; current++) {
			swapCount++;

			Swap(values[current],
				values[MinIndex(values, current, endIndex)]);
		}
	}
	int SwapCounterP() {
		return swapCount;
	
	}
	int CompCounterP() {
		return compCount;
	}
	int ResetCounters() {
		swapCount = 0;
		compCount = 0;
		return 0; 
	}
	
};