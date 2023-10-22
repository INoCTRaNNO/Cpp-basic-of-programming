#include <iostream>
#include <vector>

// Структура для представления члена многочлена
struct Term {
    int coefficient;  // Коэффициент
    int exponent;     // Показатель степени
};

// Функция для приведения подобных членов многочлена
std::vector<Term> combineLikeTerms(const std::vector<Term>& polynomial) {
    std::vector<Term> result;
    std::vector<int> exponents;

    for (const Term& term : polynomial) {
        // Проверяем, есть ли уже член с таким показателем степени
        auto it = std::find(exponents.begin(), exponents.end(), term.exponent);
        if (it != exponents.end()) {
            // Член с таким показателем степени уже существует, добавляем коэффициент к нему
            int index = std::distance(exponents.begin(), it);
            result[index].coefficient += term.coefficient;
        }
        else {
            // Член с таким показателем степени еще не существует, добавляем его в результат
            result.push_back(term);
            exponents.push_back(term.exponent);
        }
    }

    return result;
}

int main() {
    // Создаем многочлен
    std::vector<Term> polynomial = { {2, 3}, {-4, 2}, {3, 1}, {1, 3}, {5, 2}, {-2, 1} };

    // Приводим подобные члены
    std::vector<Term> result = combineLikeTerms(polynomial);

    // Выводим результат
    std::cout << "Многочлен после приведения подобных членов: ";
    for (const Term& term : result) {
        std::cout << term.coefficient << "x^" << term.exponent << " ";
    }
    std::cout << std::endl;

    return 0;
}