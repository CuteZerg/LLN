#include "LLN.h"


void coin_flip(int iterations)
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(0, 1);
	auto coin = bind(distribution, generator);


	int heads = 0;
	int longest_heads_series_tmp = 0;
	int longest_heads_series = 0;
	int tails = 0;
	for (int i = 0; i < iterations; i++)
	{
		if (coin() == 0)
		{
			heads++;
			longest_heads_series_tmp++;
		}
		else
		{
			tails++;
			if (longest_heads_series_tmp > longest_heads_series)
				longest_heads_series = longest_heads_series_tmp;
			longest_heads_series_tmp = 0;
		}
	}

	std::cout << "���������� �� " << iterations << " ������������� �������:\n";
	std::cout << "���� ����� " << heads << " ���\n";
	std::cout << "����� ������ " << tails << " ���\n";
	std::cout << "������ �������� ���������� ��������� ���� � �����: " << abs(heads - tails) << std::endl;
	std::cout << "������� ��������� ����: " << (double)heads / iterations << std::endl;
	std::cout << "������������� ����������� ��������� ����: 0.5" << std::endl;
	std::cout << "����� ������� ����� �� ����� ������� �� " << longest_heads_series << " �����" << std::endl;
	std::cout << "������������� �������� ��������� ����� �����: " << log(iterations) / log(2.0);
}


