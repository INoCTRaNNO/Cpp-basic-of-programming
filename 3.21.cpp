//3.21 Уравнение для пятиклассников представляет собой строку длиной 5 символов. Второй символ строки является либо знаком «+» (плюс) либо «-« (минус), четвёртый символ — знак «=» (равно). Из первого, третьего и пятого символов ровно два являются цифрами из диапазона от 0 до 9, и один – буквой x, обозначающей неизвестное. 
//Требуется написать программу, которая позволит решить данное уравнение относительно x.

#include <iostream>
#include <string>

int isX(std::string);

int main() {
    std::string equation;
    std::cout << "Введите уравнение: ";
    std::cin >> equation;

    if (equation.length() == 5 && (equation[1] == '+' || equation[1] == '-') && equation[3] == '=' && isX(equation) == 1) {
        char first = equation[0];
        char operatorSymbol = equation[1];
        char third = equation[2];
        char fifth = equation[4];

        int result;
        if (first == 'x') {
            result = (operatorSymbol == '+') ? (fifth - '0') - (third - '0') : (third - '0') - (fifth - '0');
        }
        else if (third == 'x') {
            result = (operatorSymbol == '+') ? (fifth - '0') - (first - '0') : (first - '0') - (fifth - '0');
        }
        else {
            result = (operatorSymbol == '+') ? (first - '0') + (third - '0') : (first - '0') - (third - '0');
        }

        std::cout << "Значение x равно: " << result << std::endl;
    }
    else {
        std::cout << "Некорректное уравнение!" << std::endl;
    }

    return 0;
}
int isX(std::string s) {
    int count = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == 'x') {
            count++;
        }
    }
    return count;
}