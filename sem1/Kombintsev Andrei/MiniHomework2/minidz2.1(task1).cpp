

#include <iostream>
#include <string>



int notationeighteen(int number) {
    std::string minus =("");
    
    if (number < 0) { 
         minus.append ("-");
        number = number * (-1);
    }
    std::cout << minus << std::hex << number << '\n'; //уффф читыыы эта штука мсама переводит из 10 в 16 сист, такая же есть для 8 сист, но это уже слишком
    return 0;
}
int  notationeight(int number) {
    std::string minus =("");

    if (number < 0) {
        minus.append("-");
        number = number * (-1);
    }
    int numbL = 0;//переменная для ответа тут огн будет храниться
    int k = 1; //разряд числа
    while (number != 0) {

        numbL += number % 8 * k;
        number = number / 8;
        k *= 10;
    }
    std::cout << minus << numbL;
    return 0;
}

int main()
{
    int numbchoose = 0;
    int number = 0;
    std::cout << "Enter the number to convert to 16 or 8 number system:\n";
    std::cin >> number;
    std::cout << "\n";
    std::cout << "To which number system do you want to convert the number 0 - 8th or 1 - 16th\n";
    std::cin >> numbchoose;
    if (numbchoose == 0) {
       int answer =notationeight(number);
       
    }
    else if (numbchoose == 1) {
      int answer =notationeighteen(number);
        
    }
    else { std::cout << "ERROR TRY  GAIN\n"; }
    
}