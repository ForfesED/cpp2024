// //ГИПОТЕЗА СИРАКУЗ
//

#include <iostream>

int main()
{
    int long long number = 0;
    std::cout << "Enter your number > 0\n";
    std::cin >> number;
    std::cout << "\n";
    if (number < 1) { std::cout << "EROOR\n"; }
    else {
        while (number != 1) {
            if (number % 2 == 0) { number /= 2; \
                std::cout << number << " Action %2==0\n";
            }
            else { number = (number * 3 + 1) / 2; 
            std::cout << number << " Action %2!=0\n";
            }

        }

        std::cout << number << "\n";
    }

}

