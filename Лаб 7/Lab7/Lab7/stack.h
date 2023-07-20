#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <unordered_set>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

struct STACK {
	int data;
	STACK* head;
	STACK* next;
};

void AddEl(int elem, STACK* stack);
int TakeFromStack(STACK* stack);
void PrintStack(STACK* stack);
void ToFile(STACK* stack);
void FromFile(STACK* stack);
void fillStack(std::stack<int>& Stack, const std::stack<int>& Stack1, const std::stack<int>& Stack2);
void clear(STACK* stack);

void DeleteSameHelp(STACK* stack, int point);
