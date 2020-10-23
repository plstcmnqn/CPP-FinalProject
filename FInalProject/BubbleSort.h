#pragma once
template<class ItemType>
class BSort
{

private:
	int swapCount;
	int compCount;



public: 
	template<class ItemType>
	void BubbleUp(ItemType values[], int startIndex, int endIndex)
		// Post: Adjacent pairs that are out of order have been 
		//       switched between values[startIndex]..values[endIndex]
		//       beginning at values[endIndex].
	{
		for (int index = endIndex; index > startIndex; index--) {
			compCount++;
			if (values[index] < values[index - 1]) {
				swapCount++;
				Swap(values[index], values[index - 1]);
			}
		}
	}

	template<class ItemType>
	void BubbleSort(ItemType values[], int numValues)
		// Post: The elements in the array values are sorted by key.
	{
		int current = 0;

		while (current < numValues - 1)
		{
			compCount++;
			BubbleUp(values, current, numValues - 1);
			current++;
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