#include <iostream>

using namespace std;

int *key, *p, *leftt, *rightt,root=0,i = 0;;

void bst_inorder(int x)
{
	if (x == 0)
		return;

	int current = root;
	int pre;
	while (current != 0)
	{
		if (leftt[current] == 0)
		{
			cout << key[current] << " ";
			current = rightt[current];
		}
		else
		{
			pre = leftt[current];
			while (rightt[pre] != 0 && rightt[pre] != current)
			{
				pre = rightt[pre];
			}
			if (rightt[pre] == 0)
			{
				rightt[pre] = current;
				current = leftt[current];
			}
			else
			{
				rightt[pre] = 0;
				cout << key[current] << " ";
				current = rightt[current];
			}
		}
	}
	/*if (x != 0)
	{
		bst_inorder(leftt[x]);
		cout << key[x]<<" ";
		bst_inorder(rightt[x]);
	}*/
}

void bst_insert(int z)
{
	i++;
	key[i] = z;

	int x = root;//wiercholek drzewa
	int y=0;
	int k = key[i];//k nowy element
	while (x != 0)
	{
		y = x;
		if (k < key[y])
		{
			x = leftt[y];
		}
		else
		{
			x = rightt[y];
		}
	}

	p[i] = y; // y jest ojcem nowego elementu
	if (y == 0)
	{
		root = i;//gdy drzewo by³oby puste
	}

	else
	{
		if (k < key[y])
		{
			leftt[y] = i;//przypisanie dziecka do lewego korzenia
		}
		else
		{
			rightt[y] = i;//przypisanie dziecka do prawego korzenia
		}
	}
}

int bst_member(int k)
{
	int x = root;
	while (x != 0 && k != key[x])
	{
		if (k < key[x])
		{
			x = leftt[x];
		}
		else
		{
			x = rightt[x];
		}
	}
	return x;
}

int bst_max(int x)
{
	while (rightt[x] != 0)
	{
		x = rightt[x];
	}
	return x;
}

int bst_min(int x)
{
	while (leftt[x] != 0)
	{
		x = leftt[x];
	}
	return x;
}

int bst_succesor(int x)
{
	int y = 0;
	if (rightt[x] != 0)
	{
		y = bst_min(rightt[x]);
	}
	else
	{
		y = p[x];
		while (y != 0 && x == rightt[y])
		{
			x = y;
			y = p[x];
		}
	}
	return y;
}

int main()
{
	int x,k;
    std::cout << "Podaj wielkosc zbioru: ";
	cin >> x;
	p = new int [x+1];
	leftt = new int [x+1];
	rightt = new int [x+1];
	key = new int [x+1];
	char choice = 1;
	for (x + 1; x > 0; x--)
	{
		p[x] = 0;
		leftt[x] = 0;
		rightt[x] = 0;
	}
	cout << "1: Bst-INORDER\n";
	cout << "2: Bst-INSERT\n";
	cout << "3: Bst-MEMBER\n";
	cout << "4: Bst-MAX\n";
	cout << "5: Bst-MIN\n";
	cout << "6: Bst:SUCCESSOR\n";
	cout << "7: Bst:DELETE\n";
	cout << "0: Exit\n";
	while (choice != 48)
	{
		cin >> choice;
		switch (choice)
		{
		case 49:
		{
			bst_inorder(root);
			cout << endl;
		}
		break;
		case 50:
		{
			cout << "Podaj liczbe: ";
			cin >> x;
			bst_insert(x);
		}
		break;
		case 51:
		{
			cout << "Podaj liczbe: ";
			cin >> x;
			k=bst_member(x);
			if (key[k] == x)
			{
				cout << "ta liczba znajduje sie w indeksie: "<<k<<endl;
			}
			else
			{
				cout << "nie ma takiej liczby w drzewie\n";
			}
		}
		break;
		case 52:
		{
			cout << "Max: " << key[bst_max(root)]<<endl;
		}
		break;
		case 53:
		{
			cout << "Min: " << key[bst_min(root)]<<endl;

		}
		break;
		case 54:
		{
			cout << "Podaj index liczby: ";
			cin >> x;
			k = bst_succesor(x);
			if (k != 0)
				cout << "Nastepna liczba znajduje sie w intexie: " << k << "\n";
			else
				cout << "Blad\n";
		}
		break;
		case 55:
		{

		}
		break;
		case 48:
		break;
		default:
			cout << "Bledna opcja " << endl;
			break;
		}
	}
}
