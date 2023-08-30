#include "Tree.h"


int main()
{



	
	int mcounter = 0;
	int b = 0;
	char z = '\n';
	do
	{
		if (mcounter > 0)
		{
			cin.clear();

			cout << "To continue Press Enter\n";

			cin.get(z);
			cin.clear();
			cin.get(z);
			system("cls");
		}
		int Symbolcounter = 0;
		char *prevstring = nullptr;
		char *currentstring = nullptr;
		/*Tree <int, int>s;*/ //нужно создать динамическое дерево
		Tree<int, int>*s;
		s = new Tree<int, int>();
		/*int counter = 1;*/
		int a = 0;

		cout << "Enter string\n";
		cin.clear();
		mcounter++;//лічильник для меню
		int counter = 1;
		char currentSymbol = '0';
		cin.get(currentSymbol);
		while (currentSymbol != '\n')//за один проход оно смещается на следующий символ
		{

			a = currentSymbol;


			s->Add(counter, a);

			Symbolcounter++;




			prevstring = currentstring;

			currentstring = new char[Symbolcounter + 1];
			if (prevstring != nullptr)
				strcpy(currentstring, prevstring);

			currentstring[Symbolcounter - 1] = currentSymbol;
			currentstring[Symbolcounter] = '\0';
			delete[]prevstring;






			cin.get(currentSymbol);//сюда входит следующий символ без первого и т.д.
								   /*a = currentSymbol;*/

		}

		do {
			do {

				cout << "Choose option:\n";
				cout << "1.Show all symbols and their amount in string\n";
				cout << "2.Search amount of symbols by symbol\n";
				cout << "3.Show current string\n";
				cout << "4.Enter new string\n";
				cout << "0.Exit\n";
				cin >> b;
			} while (b < 1 && b>3 && b == 100);
			switch (b)
			{
			case 1:
			{
				s->Print();

				system("pause");
				break;
			}
			case 2: //цей кейс я не зміг обмежити введенням тільки одного символу. Маю проблеми або з потоками, або з типами даних
			{
				cin.clear();
				int tmp;
				cout << "This is your string: " << currentstring << "\n";
				cout << "Enter symbol which you want to find\n";
				char tmpsymb = '\0';
				cin >> tmpsymb;

				tmp = tmpsymb;
				if (s->Exist(tmp))
				{

					cout << "Your string " << "\"" << currentstring << "\"" << " contain ";
					cout << "symbol: \"" << tmpsymb << "\" " << *(s->Find(tmp)); (*(s->Find(tmp)) == 1) ? cout << " time\n" : cout << " times \n";
					/*cout << *(s.Find(tmp)) << endl;*/
					system("pause");
				}
				else
				{
					cout << "your string doesn't contain this symbol\n";
					system("pause");
				}

				break;
			}
			case 3:
				cout <<"Your string:"<<"\""<< currentstring<<"\"" << "\n";
				system("pause");
			}

			if (b == 4 || b == 0)
			{

				delete[]s;

				break;
			}

			/*} while (b != 0);*/
		} while (true);
		delete[]currentstring;
		if (b == 0)
			break;
	} while (true);

	system("pause");
	return 0;
}