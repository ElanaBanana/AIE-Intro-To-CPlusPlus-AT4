#include "ShoppingList.h"
#include "Item.h"
#include "String.h"
#include <iostream>

ShoppingList::ShoppingList()
{
	//default constructor
}

ShoppingList::ShoppingList(std::vector<Item*> items)
{
	int len = items.size();
	
	//for every item provided, create a new instace in listItems
	//and a corresponding bool value in the obtained list

	for (int i = 0; i < len; i++) 
	{
		listItems.push_back(items[i]);
		obtained.push_back(false);
	}

	//after items have been added, sort list in alphabetical order
	SortList(0, len-1);

	//for (Item* i : items)
	//{
	//	listItems.push_back(i);
	//	obtained.push_back(false);
	//}
}

const std::vector<Item*> ShoppingList::GetList() const
{
	return listItems;
}

const std::vector<bool> ShoppingList::GetObtained() const
{
	return obtained;
}

const Item* ShoppingList::GetListItem(int index)
{
	return listItems[index];
}

const std::vector<bool> ShoppingList::GetCheckList()
{
	return obtained;
}

void ShoppingList::ItemObtained(Item* item, bool check)
{//check can be true OR false

	//std::cout << item << std::endl;
	//std::cout << item->GetName()->CStr() << std::endl;

	int len = listItems.size(); //size of shopping list
	//const char* name2 = item->GetName()->CStr();
	for (int i = 0; i < len; i++)
	{
		//check shopping list for item
		//if item exists and it hasn't been checked, change obtained status
		if ((*listItems[i] == *item) && this->obtained[i] != check) {
			this->obtained[i] = check;
			return;
		}
		
	}
	//std::cout << "Item is not on shopping list" << std::endl;
	return;

}

//sorting items using quicksort
void ShoppingList::SortList(int start, int end)
{
	if (start < end)
	{
		int pivotIndex = Partition(start, end);

		//smaller goes to the left, 
		//higher goes to the right
		SortList(start, pivotIndex - 1);
		SortList(pivotIndex + 1, end);
	}
}

int ShoppingList::Partition(int start, int end)
{
	//pick the pivot, last item
	Item* pivot = listItems[end];
	Item* temp;
	//Index of smaller element/ the right position of pivot (larger than pivot)
	int rightOfPivot = start - 1;

	for (int i = start; i <= end; i++)
	{
		//if the current element is smaller than the pivot, swap 
		if (String::alphabetComparison(*(listItems[i]->GetName()), *(pivot->GetName())))
		{
			//incremental index right
			rightOfPivot++;
			temp = listItems[rightOfPivot];
			listItems[rightOfPivot] = listItems[i];
			listItems[i] = temp;
		}
	}

	//swap pivot with right
	temp = listItems[rightOfPivot + 1];
	listItems[rightOfPivot + 1] = listItems[end];
	listItems[end] = temp;

	temp = nullptr; //clean up

	return (rightOfPivot + 1);
}

int ShoppingList::SearchList(String* search) const
{
	//start search for entire list
	int left = 0;
	int right = listItems.size() - 1;

	//cut down with binary search
	while (left <= right)
	{
		int middle = (left + right) / 2;

		//if middle value == our search value
		if (*listItems[middle]->GetName() == *search)
		{
			return middle;
		}
		//if middle comes before search value
		if (String::alphabetComparison(*listItems[middle]->GetName(), *search)) 
		{
			//set left to be just after middle value
			left = middle + 1;
		}
		//if middle comes after search value 
		if (String::alphabetComparison(*search, *listItems[middle]->GetName()))
		{
			//set right to be just after the middle
			right = middle - 1;
		}
	}
	//if it is never found
	return -1;
}

void ShoppingList::PrintAll(bool printStatus) const
{
	int count = 0;
	for (Item* i : listItems)
	{//for every item in shoppinglist, print out name and if it has been obtained
		std::cout << "		Item " << count+1 << ": ";
		i->GetName()->WriteToConsole();
		//if I want to print out the obtained status of items
		if (printStatus == true)
		{
			//if obtained print Y
			if (obtained[count] == true)
			{
				std::cout << "   " << "Obtained" << std::endl;
			}
			else
			{
				std::cout << "   " << "Not Obtained" << std::endl;
			}
		}
		else
		{
			std::cout << "\n";
		}
		count++;
	}
}

ShoppingList::~ShoppingList()
{
	//int len = listItems.size();
	//for (int i = 0; i < len; i++) {
	//	delete listItems.at(i); //deletes all instances of dynamically allocated items in the list
	//}
	while (!listItems.empty())
	{ //while the list is not empty
		delete listItems.back();
		listItems.pop_back();
	}
	listItems.clear();
	//delete[] obtained;
}
