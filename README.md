# TechProgLab1

### Лабораторная работа № 1

​	Требуется реализовать динамическую библиотеку, обладающую заданной функциональностью, а также отдельное приложение с пользовательским интерфейсом, использующее эту динамическую библиотеку и позволяющее пользователю воспользоваться её функциональностью.

##### 35 вариант

Вычисление формулы Байеса.





В первую очередь была реализована библиотека. 

##### Заголовочный файл BayesLib.h

```c++
#pragma once

#ifdef BAYESLIB_EXPORTS
#define BAYESLIB_API __declspec(dllexport)
#else
#define BAYESLIB_API __declspec(dllimport)
#endif

extern "C" BAYESLIB_API double BAYES(double Pa, double Pb, double PbIFa);
```

##### Файл с кодом библиотеки BayesLib.cpp

```C++
#include "pch.h" 
#include <utility>
#include <limits.h>
#include "BayesLib.h"

double BAYES(double Pa, double Pb, double PbIFa)
{
    return PbIFa * Pa / Pb;
}
```

Далее было реализовано приложени, применяющее эту библиотеку. 

##### Файл BayesClient.cpp

```C++

#include <iostream>
#include <string>
#include "BAYESLib.h"

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const std::string ABOUT_MESSAGE = "Bayes";
const std::string CONTINUE_MESSAGE =
"Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE =
"Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input double>";
const std::string OUT_OF_BOUNDS_MESSAGE =
"This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";

void ClearInputStream(std::istream& in)
{
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}

int Seek(std::istream& in)
{
	while (in.peek() != EOLN && SKIP_CHARACTERS.find((char)in.peek()) != std::string::npos)
	{
		in.get();
	}
	return in.peek();
}

bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " [" << LEFT_BOUND << ", " << RIGHT_BOUND << "]" << std::endl;
	}
	return ok;
}

double ReadDouble(std::istream& in)
{
	std::cout << INPUT_MESSAGE;
	double ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || !CheckBounds(ans))
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans;
}

bool NeedContinue(std::istream& in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR && ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}

int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		double Pa = ReadDouble(std::cin);
		double Pb = ReadDouble(std::cin);
		double PaIFb = ReadDouble(std::cin);
		std::cout << OUTPUT_MESSAGE << BAYES(Pa, Pb, PaIFb) << std::endl;
		cont = NeedContinue(std::cin);
	}
	return 0;
}
```
