#ifndef __SORT_H__
#define __SORT_H__

#include<iostream>
using namespace std;
#include<assert.h>

//�м��ȷ���˼·
//��������
void InsertSort(int* a, int size)
{
	for (int i = 0; i<size - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > a[end + 1])
		{
			a[end + 1] = a[end];
			a[end] = tmp;
			--end;
		}
	}
}

void PrintSort(int *a, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void AdjustDown(int* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		//���ӽڵ��е����ֵ
		if (child + 1 < size&&a[child + 1] > a[child])
		{
			++child;
		}

		//������ӽڵ���ڸ��ڵ㽻��
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

//������
void HeapSort(int* a, int size)
{
	//����
	for (int i = (size-2)/2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	//������
	for (int i = 0; i < size; i++)
	{
		swap(a[0], a[size - 1 - i]);
		AdjustDown(a, size - 1 - i, 0);
	}
}

//ѡ������
void ChoiceSort(int* a,int size)
{
	assert(a);
	int min, max;
	for (int i = 0; i < size/2; i++)
	{
		min = i;
		max = size - 1 - i;
		for (int j = i+1; j < size; j++)//������С��һ��ֵ�����ֵ����
		{
			if (a[min] > a[j])
				min = j;

			if (a[max] < a[size-j-1])
				max = size-j-1;
		}
		if (min != i)
		{
			swap(a[i], a[min]);

			if (max == i)//���max�ڵ�һ��λ�þͻᱻ���ߣ�������Ҫ���»�����,�ض��򵽽������λ��
			{
				max = min;
			}
		}
		if (max !=size-1-i)
		swap(a[max], a[size - 1 - i]);
	}
}

//ϣ������
void shellsort1(int a[], int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i<n-gap; i++)//С��n-gap��ûһ�������Ƚ�һ��
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end]>a[end + gap])
			{
				a[end + gap] = a[end];
				a[end] = tmp;

				end = end - gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void shellsort(int a[], int n)
{
	int i, j, gap;

	for (gap = n / 2; gap > 0; gap /= 2)
	for (i = gap; i < n; i++)
	for (j = i - gap; j >= 0 && a[j] > a[j + gap]; j -= gap)//�������ںϵ�һ��
		swap(a[j], a[j + gap]);
}

//�Ż���ð������
void Bubble(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool judge = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				judge = true;
			}
		}
		if (!judge)
		{
			return;
		}
	}
}

//��������
void QuickSort(int* a, int left,int right)
{
	if (left < right)
	{
		int low = left;
		int high = right;
		int key = a[low];
		while (low < high)
		{
			//���ұ��ҵ���һ��С�ڻ�����λ��
			while (low< high && a[high]> key)
				high--;
			a[low] = a[high];

			//������ҵ���һ�����ڼ�����λ��
			while (low < high && a[low] < key)
				low++;
			a[high] = a[low];
		}
		a[low] = key;
		QuickSort(a, left, low - 1);
		QuickSort(a, low + 1, right);

	}

}

void testQuickSort()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 9, 8 };
	QuickSort(a, 0,sizeof(a) / sizeof(a[0])-1);
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}

void testBubble()
{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 8};
	Bubble(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}

void testshellsort1()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	shellsort1(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}

void testChoiceSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ChoiceSort(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}


void testHeapSort()
{
	int a[] = { 3, 2, 5, 5, 6, 7, 6, 4, 1, 8, 0, 9 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}

void testInsertSort()
{
	int a[] = { 3, 2, 5, 5, 6, 7, 6, 4, 1, 8, 0, 9 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));
}




#endif //__SORT_H__