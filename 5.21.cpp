#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Medicine {
    string name;
    string country;
    double price;
    string composition;
    string recommendations;
};

void printTable(const vector<Medicine>& medicines) {
    cout << setw(20) << "Наименование"
         << setw(20) << "Страна-производитель"
         << setw(10) << "Цена"
         << setw(40) << "Состав"
         << setw(40) << "Рекомендации" << endl;

    for (const Medicine& medicine : medicines) {
        cout << setw(20) << medicine.name
             << setw(20) << medicine.country
             << setw(10) << medicine.price
             << setw(40) << medicine.composition
             << setw(40) << medicine.recommendations << endl;
    }
}

int main() {
    vector<Medicine> medicines = {
        {"Аспирин", "Россия", 50.00, "Ацетилсалициловая кислота", "По 0,5 г 1-2 раза в день после еды"},
        {"Нурофен", "США", 100.00, "Ибупрофен", "Дозировка зависит от возраста и веса пациента. Не применяется при язвенной болезни желудка"},
        {"Цитрамон", "Германия", 75.00, "Ацетилсалициловая кислота, парацетамол, кофеин", "По 1-2 таблетки 2-3 раза в день после еды"}
    };

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Вывести все товары" << endl;
        cout << "2. Вывести информацию о товаре" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите пункт меню: ";
        cin >> choice;

        switch (choice) {
            case 1:
                printTable(medicines);
                break;
            case 2: {
                int index;
                cout << "Введите номер товара: ";
                cin >> index;

                if (index >= 0 && index < medicines.size()) {
                    const Medicine& medicine = medicines[index];
                    cout << "Наименование: " << medicine.name << endl;
                    cout << "Страна-производитель: " << medicine.country << endl;
                    cout << "Цена: " << medicine.price << endl;
                    cout << "Состав: " << medicine.composition << endl;
                    cout << "Рекомендации: " << medicine.recommendations << endl;
                } else {
                    cout << "Товар с таким номером не найден" << endl;
                }

                break;
            }
            case 0:
                cout << "До свидания!" << endl;
                break;
            default:
                cout << "Некорректный пункт меню" << endl;
                break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}

