#include <thread>
#include <iostream>

auto primecheck(uint32_t num) -> bool {

	for (auto i = 2u; i < num; i++) {

		if (num % i == 0) {

			return false;
		}
	}

	return true;
}

auto main() -> int {

	std::cout << "Check Type" << "\n";
	std::cout << "1 = To check if a specific number prime" << "\n";
	std::cout << "2 = Get all prime numbers in specified range eg 0-100.." << "\n";

	auto iMode = 0u;
	auto iNum = 0u;
	auto iNumLast = 0u;

	bool bExit = false;

	std::cin >> iMode;

	while (true) {

		switch (iMode) {
		case 1:
			std::cout << "input number: ";
			std::cin >> iNum;
			primecheck(iNum) ? std::cout << iNum << " is prime\n" : std::cout << iNum << " Is not Prime\n";
			break;
		case 2:
			std::cout << "input starting number: ";
			std::cin >> iNum;
			std::cout << "input ending number: ";
			std::cin >> iNumLast;
			for (auto i = iNum; i < iNumLast; i++) 
				if (primecheck(i))
					std::cout << i << std::endl;
			std::cout << "are prime numbers" "\n";
			bExit = true;
			break;
		}

		if (bExit)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	system("pause");
	return 0;
}