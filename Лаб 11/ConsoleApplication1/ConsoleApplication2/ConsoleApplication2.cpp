﻿#include <iostream>
#include <queue>
#include <stack>
#include <windows.h>

//Написать функцию вывода количества вершин дерева, являющихся левыми дочерними вершинами (ко-рень дерева не учитывать).
using namespace std;
struct Tree          //дерево
{
	int key;         //ключ
	char text[5];    //текст - не более 4 букв
	Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);       //Создание дерева
Tree* list(int i, char* s);       //Создание нового элемента
Tree* insertElem(Tree* Root, int key, char* s);  //Добавление нового элемента
Tree* search(Tree* n, int key);   //Поиск элемента по ключу 
Tree* delet(Tree* Root, int key); //Удаление элемента по ключу
void view(Tree* t, int level);    //Вывод дерева 

int countRightLeaves(Tree* root) {
	if (root == nullptr) {
		return 0;
	}
	int count = 0;
	if (root->Right != nullptr && root->Right->Left == nullptr && root->Right->Right == nullptr) {
		count++;
	}
	count += countRightLeaves(root->Left) + countRightLeaves(root->Right);
	return count;
}

int countEvenKeys(Tree* root) {
	if (root == nullptr) {
		return 0;
	}

	int count = 0;
	if (root->key % 2 == 0) {
		count++;
	}

	count += countEvenKeys(root->Left);
	count += countEvenKeys(root->Right);

	return count;
}

int countAllNodesToRightOfRoot(Tree* root) {
	if (!root || (!root->Left && !root->Right)) {
		// если корень дерева не существует или является листом,
		// то нет элементов слева от корня
		return 0;
	}

	int count = 0;
	stack<Tree*> s;
	Tree* current = root->Right;

	while (current || !s.empty()) {
		if (current) {
			s.push(current);
			count++;
			current = current->Right;
		}
		else {
			current = s.top();
			s.pop();
			current = current->Left;
		}
	}

	return count;
}


//int check_right(Tree* tree) //количества вершин дерева, являющихся левыми дочерними вершинами
//{
//	static int sum = 0;
//	if (tree->Right != NULL)
//	{
//		if (tree->Right->Right != NULL)
//		{
//			sum++;
//		}
//		check_right(tree->Right);
//	}
//	if (tree->Left != NULL)
//		check_right(tree->Left);
//
//	return sum;
//}


int countAllNodesToLeftOfRoot(Tree* root) {
	if (!root || (!root->Left && !root->Right)) {
		// если корень дерева не существует или является листом,
		// то нет элементов слева от корня
		return 0;
	}

	int count = 0;
	stack<Tree*> s;
	Tree* current = root->Left;

	while (current || !s.empty()) {
		if (current) {
			s.push(current);
			count++;
			current = current->Left;
		}
		else {
			current = s.top();
			s.pop();
			current = current->Right;
		}
	}

	return count;
}



int least_count(Tree* tree) //функция вывода количества листьев данного дерева
{
	static int sum = 0;
	if ((tree->Left == nullptr) && (tree->Right == nullptr))
		sum += 1;
	else
	{
		if (tree->Left) least_count(tree->Left);
		if (tree->Right) least_count(tree->Right);
	}

	return sum;
}

Tree* Root = NULL; 	//указатель корня

void main()
{
	setlocale(0, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int key, choice, n;
	Tree* rc; char s[5], letter;
	for (;;)
	{
		cout << "1 -	создание дерева\n";
		cout << "2 -	добавление элемента\n";
		cout << "3 -	поиск по ключу\n";
		cout << "4 -	удаление элемента\n";
		cout << "5 -	вывод дерева\n";
		cout << "8 -	выход\n";
		cout << "9 -	вывод количества вершин дерева, являющихся левыми дочерними вершинами \n";
		cout << "10 -	вывод количества листьев данного дерева \n";
		cout << "11 -	вывод количества листьев дерева, являющихся правыми дочерними вершинами \n";
		cout << "12 -	вывод количества узлов с четными ключами.\n";
		cout << "ваш выбор?\n";
		cin >> choice;
		cout << "\n";
		switch (choice)
		{
		case 1:  Root = makeTree(Root);	break;
		case 2:  cout << "\nВведите ключ: "; cin >> key;
			cout << "Введите символ: "; cin >> s;
			insertElem(Root, key, s); break;
		case 3:  cout << "\nВведите ключ: ";  cin >> key;
			rc = search(Root, key);
			cout << "Найденный символ= ";
			puts(rc->text); break;
		case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
			Root = delet(Root, key);  break;
		case 5:  if (Root->key >= 0)
		{
			view(Root, 0);
		}
			  else cout << "Дерево пустое\n"; break;
		case 8:  exit(0);
		case 9: { static int k = 0;
			cout << "Количество левых дочерних вершин = " << countAllNodesToLeftOfRoot(Root) << endl;
			break;
		}
		case 10: {
			static int co = 0;
			int f = least_count(Root);
			cout << "Количество листьев = " << f - co << endl;
			co = f;
			break;
		}
		case 11: { static int k = 0;
			cout << "Количество правых дочерних листьев = " << countRightLeaves(Root) << endl;
			break;
		}
		case 12: {
			cout << "Количество ущлов с чётными номерами = " << countEvenKeys(Root) << endl;
			break;
		}
		}
	}
}

Tree* makeTree(Tree* Root)    //Создание дерева
{
	int key; char s[5];
	cout << "Конец ввода - отрицательное число\n\n";
	if (Root == NULL)	// если дерево не создано
	{
		cout << "Введите ключ корня: "; cin >> key;
		cout << "Введите символ корня: "; cin >> s;
		Root = list(key, s);	// установка указателя на корень
	}
	while (1)                //добавление элементов
	{
		cout << "\nВведите ключ: ";  cin >> key;
		if (key < 0) break;       //признак выхода (ключ < 0)   
		cout << "Введите символ: ";  cin >> s;
		insertElem(Root, key, s);
	}
	return Root;
}

Tree* list(int i, char* s)     //Создание нового элемента
{
	Tree* t = new Tree[sizeof(Tree)];
	t->key = i;
	for (i = 0; i < 5; i++)
		*((t->text) + i) = *(s + i);
	t->Left = t->Right = NULL;
	return t;
}
Tree* insertElem(Tree* t, int key, char* s)  //Добавление нового элемента
{
	Tree* Prev = 0;	     // Prev - элемент перед текущим
	int find = 0;        // признак поиска
	while (t && !find)
	{
		Prev = t;
		if (key == t->key)
			find = 1;	   //ключи должны быть уникальны
		else
			if (key < t->key) t = t->Left;
			else t = t->Right;
	}
	if (!find)              //найдено место с адресом Prev
	{
		t = list(key, s);           //создается новый узел 
		if (key < Prev->key)  // и присоединяется либо 
			Prev->Left = t;    //переход на левую ветвь,
		else
			Prev->Right = t;   // либо на правую 
	}
	return t;
}

Tree* delet(Tree* Root, int key)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
	// R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = Root;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)//поиск элемента и его родителя 
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->Left;
		else
			Del = Del->Right;
	}
	if (Del == NULL)              // элемент не найден
	{
		puts("\nНет такого ключа");
		return Root;
	}
	if (Del->Right == NULL) // поиск элемента R для замены
		R = Del->Left;
	else
		if (Del->Left == NULL)
			R = Del->Right;
		else
		{
			Prev_R = Del; //поиск самого правого элемента в левом поддереве
			R = Del->Left;
			while (R->Right != NULL)
			{
				Prev_R = R;
				R = R->Right;
			}
			if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
				R->Right = Del->Right;
			else
			{
				R->Right = Del->Right;
				Prev_R->Right = R->Left;
				R->Left = Prev_R;
			}
		}
	if (Del == Root) Root = R;	//удаление корня и замена его на R
	else
		// поддерево R присоединяется к родителю удаляемого узла
		if (Del->key < Prev_Del->key)
			Prev_Del->Left = R; // на левую ветвь 
		else
			Prev_Del->Right = R;	// на правую ветвь
	int tmp = Del->key;
	cout << "\nУдален элемент с ключом " << tmp << endl;
	delete Del;
	return Root;
}

Tree* search(Tree* n, int key)  //Поиск элемента по ключу 
{
	Tree* rc = n;
	if (rc != NULL)
	{
		if (key < (key, n->key))
			rc = search(n->Left, key);
		else
			if (key > (key, n->key))
				rc = search(n->Right, key);
	}
	else
		cout << "Нет такого элемента\n";
	return rc;
}


void view(Tree* t, int level) //Вывод дерева 
{
	if (t)
	{
		view(t->Right, level + 1);	//вывод правого поддерева
		for (int i = 0; i < level; i++)
			cout << "   ";
		int tm = t->key;
		cout << tm << ' ';
		puts(t->text);
		view(t->Left, level + 1);	//вывод левого поддерева
	}
}