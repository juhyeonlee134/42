#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	/* My test code */
    Array<float> arrF;
    Array<float> org(10);
    for (std::size_t index = 0; index < org.size(); index++)
    {
        org[index] = rand();
    }
    arrF = org;
    for (std::size_t index = 0; index < org.size(); index++)
    {
        std::cout << index << " : " << org[index] << " | " << arrF[index] << '\n';
    }
    Array<float> dst(1);
    dst = org;
    Array<float> zero;
    Array<float> copyZero = zero;
    std::cout << zero.size() << ' ' << copyZero.size() << '\n';

    Array<double> arrD(2);
    std::cout << arrD.size() << '\n';
    arrD[0] = 1.2345;
    arrD[1] = 9.8765;
    try
    {
		// std::cout << arrD[-1] << '\n';
        std::cout << arrD[0] << '\n';
        std::cout << arrD[1] << '\n';
        // std::cout << arrD[2] << '\n';
    }
	catch(std::exception & e)
	{
		std::cout << e.what() << '\n';
	}
	Array<std::string> arrStr(3);
	arrStr[0] = "aaa";
	arrStr[1] = "bbb";
	arrStr[2] = "ccc";
	std::cout << arrStr[0] << ' ' << arrStr[1] << ' ' << arrStr[2] << '\n';
    return 0;
}