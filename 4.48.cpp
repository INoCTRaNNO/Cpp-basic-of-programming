#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string lastName;
    string initials;
    string phoneNumber;
};

int main() {
    // Создаем массив структур Employee и заполняем его данными о сотрудниках
    Employee employees[3];

    employees[0].lastName = "Иванов";
    employees[0].initials = "И.И.";
    employees[0].phoneNumber = "+7 (111) 111-11-11";

    employees[1].lastName = "Петров";
    employees[1].initials = "П.П.";
    employees[1].phoneNumber = "+7 (222) 222-22-22";

    employees[2].lastName = "Сидоров";
    employees[2].initials = "С.С.";
    employees[2].phoneNumber = "+7 (333) 333-33-33";

    // Запрашиваем фамилию и инициалы сотрудника у пользователя
    string lastName;
    string initials;

    cout << "Введите фамилию и инициалы сотрудника (например, Иванов И.И.): ";
    cin >> lastName >> initials;

    // Ищем сотрудника в массиве
    bool found = false;
    string phoneNumber;

    for (int i = 0; i < 3; i++) {
        if (employees[i].lastName == lastName && employees[i].initials == initials) {
            found = true;
            phoneNumber = employees[i].phoneNumber;
            break;
        }
    }

    // Выводим результат
    if (found) {
        cout << "Номер телефона: " << phoneNumber << endl;
    } else {
        cout << "Сотрудник не найден" << endl;
    }

    return 0;
}
