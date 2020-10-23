#pragma once

template <class ItemType>
class HSort
{

private:
	int swapCount = 0;
	int compCount = 0;
public:
	template<class ItemType>
	void ReheapDown(ItemType elements[], int root, int bottom)
		// Post: Heap property is restored.
	{
		int maxChild;
		int rightChild;
		int leftChild;

		leftChild = root * 2 + 1;
		rightChild = root * 2 + 2;
		compCount++;
		if (leftChild <= bottom)
		{
			compCount++;
			if (leftChild == bottom)
				maxChild = leftChild;
			else
			{
				compCount++;
				if (elements[leftChild] <= elements[rightChild])
					maxChild = rightChild;
				else
					maxChild = leftChild;
			}
			compCount++;
			if (elements[root] < elements[maxChild])
			{
				Swap(elements[root], elements[maxChild]);
				ReheapDown(elements, maxChild, bottom);
			}
		}
	}

	template<class ItemType>
	void HeapSort(ItemType values[], int numValues)
		// Pre:  Struct HeapType is available.
		// Post: The elements in the array values are sorted by key.
	{
		int index;

		// Convert the array of values into a heap.
		for (index = numValues / 2 - 1; index >= 0; index--)
			ReheapDown(values, index, numValues - 1);

		// Sort the array.
		for (index = numValues - 1; index >= 1; index--)
		{
			swapCount++;
			Swap(values[0], values[index]);
			ReheapDown(values, 0, index - 1);
		}
	}
	//return private member
	int SwapCounterP() {
		return swapCount;
	}
	//return private member
	int CompCounterP() {
		return compCount;
	}
	//reset private members
	int ResetCounters() {
		swapCount = 0;
		compCount = 0;
		return 0;
	}

};