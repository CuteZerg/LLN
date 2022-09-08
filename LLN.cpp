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

	std::cout << "Статистика за " << iterations << " подбрасываний монетки:\n";
	std::cout << "Орел выпал " << heads << " раз\n";
	std::cout << "Решка выпала " << tails << " раз\n";
	std::cout << "Модуль разности количества выпадений орла и решки: " << abs(heads - tails) << std::endl;
	std::cout << "Частота выпадения орла: " << (double)heads / iterations << std::endl;
	std::cout << "Теоретическая вероятность выпадения орла: 0.5" << std::endl;
	std::cout << "Самая длинная серия из орлов состоит из " << longest_heads_series << " орлов" << std::endl;
	std::cout << "Теоретическая наиболее вероятная длина серии: " << log(iterations) / log(2.0);
}


