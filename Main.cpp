#include <iostream>
#include <algorithm>
using namespace std;
//------ 1111111 ---------
//struct IOutput { 
//	virtual void Show() = 0;
//	virtual void Show(string info) = 0;
//};
// 


// ------ 2222222 ---------
//struct IMath {
//	virtual int Max() = 0;
//	virtual int Min() = 0;
//	virtual float Avg() = 0;
//	virtual bool Search(int valueToSearch) = 0;
//};

struct ISort {
	virtual void SortAsc() = 0;
	virtual void SortDesc() = 0;
	virtual void SortByParam(bool isAsc) = 0;
};

class Array : public ISort
{
protected:
	int* array;
	int size;

public:
	Array() = default;
	Array(int arr[], int s) {
		size = s;
		array = new int[size];
		for (int i = 0; i < size; i++)
	{
			array[i] = arr[i];
		}
	}
	~Array()
	{
		delete[] array;
	}

	void Show()
	{
		cout << " Elements -> \t";
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " - ";
		}
		cout << endl;
	}
	void Show(string info)
	{
		cout << info << endl;
		Show();
	}

	int Max() {
		int max = array[0];
		for (int i = 0; i < size; i++)
		{
			if (max < array[i])
			{
				max = array[i];
			}
		}
		return max;
	}
	int Min() {
		int min = array[0];
		for (int i = 0; i < size; i++)
		{
			if (min > array[i])
			{
				min = array[i];
			}
		}
		return min;
	}
	float Avg()
	{
		int num = 0;
		for (int i = 0; i < size; i++)
		{
			num += array[i];
		}
		return num / size;
	}
	bool Search(int valueToSearch)
	{
		for (int i = 0; i < size; i++)
		{
			if (valueToSearch == array[i])
			{
				return true;
			}
		}
		return false;
	}

	void SortAsc() {
		sort(array, array + size);
		cout << "Sort )";
		for (int i = 0; i < size; i++)
		{
			cout << "\t" << array[i];
		}
		cout << endl;
	}
	void SortDesc() {
		sort(array, array + size, greater<int>());
		cout << "Sort )";
		for (int i = 0; i < size; i++)
		{
			cout << "\t" << array[i];
		}
		cout << endl;
	}
	void SortByParam(bool isAsc) {
		if (isAsc) {
			SortAsc();  
		}
		else {
			SortDesc(); 
		}
	}
};




int main() {
	
	int arr[]{ 1 ,2 ,3, 4, 5, };
	int size = 5;

	Array Myarr(arr, size);

	/*------ 1111111 ---------
	cout << " - Check -" << endl;
	Myarr.Show();
	cout << " - Check -" << endl;
	Myarr.Show("| Message |");*/

	/*-------- 2222222 --------
	cout << Myarr.Min() << endl;
	cout << " ---------------- " << endl;
	cout << Myarr.Search(6) << endl;*/

	Myarr.SortByParam(false);
}



















