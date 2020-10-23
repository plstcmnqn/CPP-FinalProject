#pragma once
template <class S>
class Qsort {

	//counter variables 
	int swapCount = 0;
	int compCount = 0;




public: 
	template <class S>
	void Counter(S swapNum) {
		int sCount = +swapNum;


	}

	template <class ItemType>
	void Split(ItemType values[], int first, int last, int& splitPoint)
	{
		ItemType splitVal = values[first];
		int saveFirst = first;
		bool onCorrectSide;
		first++;
		do
		{
			onCorrectSide = true;
			while (onCorrectSide) {        // Move first toward last.
				compCount++;
				if (values[first] > splitVal)
					onCorrectSide = false;
				else
				{
					first++;
					onCorrectSide = (first <= last);
				}
			}
			onCorrectSide = (first <= last);
			while (onCorrectSide) {   // Move last toward first.

				compCount++;
				if (values[last] <= splitVal)
					onCorrectSide = false;
				else
				{
					last--;
					onCorrectSide = (first <= last);
				}
			}
			//comparison
				compCount++;
			if (first < last)
			{
				swapCount++;
				Swap(values[first], values[last]);
				first++;
				last--;
			}
			//comparison
			compCount++;
		} while (first <= last);

		splitPoint = last;
		swapCount++;
		Swap(values[saveFirst], values[splitPoint]);
	}


	template<class ItemType>
	void QuickSort(ItemType values[], int first, int last)
	{
		//comparison 
		compCount++;
		if (first < last)
		{
			int splitPoint;

			Split(values, first, last, splitPoint);
			// values[first]..values[splitPoint-1] <= splitVal
			// values[splitPoint] = splitVal
			// values[splitPoint+1]..values[last] > splitVal

			QuickSort(values, first, splitPoint - 1);
			QuickSort(values, splitPoint + 1, last);
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