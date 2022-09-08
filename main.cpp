#include "LLN.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int flag = 0;
	int iterations;

	std::cout.precision(12);

	while (true)
	{
		std::cout << "Введите количество итераций: ";
		std::cin >> iterations;
		std::cout << std::endl;
		coin_flip(iterations);
		std::cout << "\n\nДля выхода из программы введите 0, для продолжения введите 1: ";
		std::cin >> flag;
		if (flag == 0)
			break;
	}
	return 0;
}