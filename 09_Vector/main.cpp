#include "Vector.h"
#include "Vector.cpp"


int main(){
    Vector<int> a;
    printf("01: Push back(add data to end of arr)\n");
	printf("02: Push front(add data at first of arr\n");
	printf("03: Insert(add data to a specific index)\n");
	printf("04: Pop(delete last index)\n");
	printf("05: Delete(delete data of a specific index)\n");
	printf("06: Search(find first index that have a specific data)\n");
	printf("07: Size(get size of arr)\n");
	printf("08: Swap(swap two index)\n");
	printf("09: Reverse(reverse all arr)\n");
	printf("10: Sort(sort arr based on amount)\n");
	printf("11: Print arr\n");
	printf("12: exit\n\n");
	int i = -1;
	while (i != 0)
	{
		scanf("%d", &i);
		getchar();
        int num;
        int index1, index2;
		switch (i)
		{
		case 1:
            cout << "input data: ";
            cin >> num;
			a.push_back(num);
			break;
		case 2:
            cout << "input data: ";
            cin >> num;
			a.push_front(num);
			break;
		case 3:
            cout << "input index and data: ";
            cin >> index1 >> num;
			a.insert(index1, num);
			break;
		case 4:
			a.pop();
			break;
		case 5:
            cout << "input index: ";
            cin >> index1;
			a.Delete(index1);
			break;
		case 6:
            cout << "input data: ";
            cin >> num;
			a.search(num);
			break;
		case 7:
			cout << "size of array is: " << a.size() << endl;
			break;
		case 8:
            cout << "input two indexes: ";
            cin >> index1 >> index2;
			a.swap(index1, index2);
			break;
		case 9:
			a.reverse();
            break;
        case 10:
            a.sort();
            break;
        case 11:
            cout << a << endl;
            break;
        case 12:
            exit(0);
		}
	}
}