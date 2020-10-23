#pragma once
template <class ItemType>
void Split2(ItemType values[], int first, int last,
	int& splitPt1, int& splitPt2)
{
	ItemType splitVal = values[(first + last) / 2];
	bool onCorrectSide;
	do
	{
		onCorrectSide = true;
		//comparison 
		while (onCorrectSide)      // Move first toward last.
			//comparision 
			if (values[first] >= splitVal)
				onCorrectSide = false;
			else
				first++;

		onCorrectSide = true;
		//comparison
		while (onCorrectSide)          // Move last toward first.
			if (values[last] <= splitVal)
				onCorrectSide = false;
			else
				last--;
		//comparison 
		if (first <= last)
		{
			//swap
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	//comparison
	} while (first <= last);

	splitPt1 = first;
	splitPt2 = last;
}

template <class ItemType>
void QuickSort2(ItemType values[], int first, int last)
{
	//comparision 
	if (first < last)
	{
		int splitPt1;
		int splitPt2;

		Split2(values, first, last, splitPt1, splitPt2);
		// values[first]..values[splitPt2] <= splitVal
		// values[splitPt1+1]..values[last] > splitVal
		//comparison 
		if (splitPt1 < last)
			QuickSort2(values, splitPt1, last);
		
		//comparison 
		if (first < splitPt2)
			QuickSort2(values, first, splitPt2);
	}
}

