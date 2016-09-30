#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Base_Array.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

void printOut();
void array_test();
void queue_test();
void stack_test();
void fixed_array_test();
void base_array_test();

int main()
{

	array_test();
	
	queue_test();

	stack_test();

	fixed_array_test();

	base_array_test();

}

void base_array_test()
{
	Base_Array<int> barr1 (11, 9);
	barr1.set(5, 12);
	std::cout << barr1.get(5) << std::endl;
	std::cout << barr1.find(12) << std::endl;
	std::cout << barr1.find(9) << std::endl;
	std::cout << barr1.find(9, 3) << std::endl;
	std::cout << barr1.find(9, 5) << std::endl;
	std::cout << barr1.find(9, 7) << std::endl;
	std::cout << barr1.find(8) << std::endl;
	Base_Array<int> barr2 (7, 3);
	std::cout << barr2[3] << std::endl << std::endl;
		
	std::cout << barr1.size() << std::endl;
	std::cout << barr2.size() << std::endl;
	barr2 = barr1;
	for(int i = 0; i < barr1.size(); i++)
	{
		std::cout << barr1[i] << barr2[i] << std::endl;
	}
	std::cout << barr1.size() << std::endl;
	std::cout << barr2.size() << std::endl << std::endl << std::endl;

}

void fixed_array_test()
{
	Fixed_Array<int, 7> fa1 (9);
	fa1[3] = 5;
	std::cout << fa1[3] << std::endl;
	std::cout << fa1.max_size() << std::endl;

	Fixed_Array<int, 7> fa2;
	std::cout << fa2.max_size() << std::endl;
	fa2 = fa1;
	Fixed_Array<int, 7> fa3 (fa1);
	
	std::cout << fa1.max_size() << std::endl;
	std::cout << fa2.max_size() << std::endl;
	std::cout << fa3.max_size() << std::endl;
	
	std::cout << fa1[3] << fa2[3] << fa3[3] << std::endl;
	std::cout << fa1[4] << fa2[4] << fa3[4] << std::endl;
	
}

void array_test()
{
	Array<int> arr1 (11, 9);
	arr1.set(5, 12);
	std::cout << arr1.get(5) << std::endl;
	std::cout << arr1.find(12) << std::endl;
	std::cout << arr1.find(9) << std::endl;
	std::cout << arr1.find(9, 3) << std::endl;
	std::cout << arr1.find(9, 5) << std::endl;
	std::cout << arr1.find(9, 7) << std::endl;
	std::cout << arr1.find(8) << std::endl;
	Array<int> arr2 (7, 3);
	std::cout << arr2[3] << std::endl << std::endl;
		
	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl;
	arr2 = arr1;
	for(int i = 0; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << arr2[i] << std::endl;
	}
	std::cout << arr1.size() << std::endl;
	std::cout << arr2.size() << std::endl << std::endl << std::endl;
	
}

void queue_test()
{	
	Queue<int> q1;
	
	for(int i = 0; i < 16; i++)
	{
		q1.enqueue(i);
	}
	
	std::cout << q1.size() << std::endl;
	std::cout << q1.is_empty() << std::endl << std::endl;
	std::cout << "Printing queue:" << std::endl;
	while(!q1.is_empty())
	{
		std::cout << q1.dequeue();
	}
	std::cout << std::endl << "Queue Printed" << std::endl << std::endl;
	std::cout << q1.size() << std::endl;
	std::cout << q1.is_empty() << std::endl << std::endl;
	
	for(int i = 7; i < 72; i++)
	{
		q1.enqueue(i);
	}
	
	std::cout << q1.size() << std::endl;
	std::cout << q1.is_empty() << std::endl;
	std::cout << "Clearing..." << std::endl;
	
	q1.clear();
	
	std::cout << q1.size() << std::endl;
	std::cout << q1.is_empty() << std::endl << std::endl;
}

void stack_test()
{
	Stack <int> s1;
	Stack <int> s2;
	for(int i = 0; i < 7; i++)
	{
		s1.push(i);
	}
	s2 = s1;
	Stack <int> s3 (s1);
	Stack <int> s4 (s1);
	std::cout << "First Stack" << std::endl;
	while(!s1.is_empty())
	{
		std::cout << s1.size() << std::endl;
		std::cout << s1.top() << std::endl;	
		s1.pop();
	}
	std::cout << s1.size() << std::endl;

	std::cout << "Second Stack" << std::endl;
	while(!s2.is_empty())
	{
		std::cout << s2.size() << std::endl;
		std::cout << s2.top() << std::endl;	
		s2.pop();
	}
	std::cout << s2.size() << std::endl;

	std::cout << "Third Stack" << std::endl;
	while(!s3.is_empty())
	{
		std::cout << s3.size() << std::endl;
		std::cout << s3.top() << std::endl;	
		s3.pop();
	}
	std::cout << s3.size() << std::endl;
	
	s4.clear();
	std::cout << "Fourth Stack" << std::endl;
	while(!s4.is_empty())
	{
		std::cout << s4.size() << std::endl;
		std::cout << s4.top() << std::endl;	
		s4.pop();
	}
	std::cout << s4.size() << std::endl;
	
	Stack<int> s5 (s4);
}

void printOut()
{
	
}
