#include <iostream>

using namespace std;

int main() {
    char category;
    int exp, age, accidents, cover;


    cout << "Введите категорию (A, B, C): ";
    cin >> category;

    category = toupper(category);

    if (!(category == 'A' || category == 'B' || category == 'C')) {
        cout << "Категория введена неверно!";
        return 1;
    }

    cout << "Введите стаж (Полных лет): ";
    cin >> exp;

    cout << "Введите возраст (Полных лет): ";
    cin >> age;

    if (exp < 0 || age < 0) {
        cout << "Возраст или стаж введены неверно!";
        return 1;
    } else if (exp > age - 18) {
        cout << "Категория и возраст не согласованы!";
        return 1;
    }

    cout << "Введите количество страховых случаев: ";
    cin >> accidents;

    if (accidents < 0) {
        cout << "Количесвто страховых случаев введены неверно!";
    }

    cout << "Есть ли у вас расширенное покрытие (Да - 1/Нет - 2): ";
    cin >> cover;

    if (!(cover == 1 || cover == 2)) {
        cout << "Значения введены неверно";
        return 1;
    }

    double basic_cost;

    switch (category) {
        case 'A': basic_cost = 300; break;
        case 'B': basic_cost = 450; break;
        case 'C': basic_cost = 650; break;
    }

    if (age < 25) {
        basic_cost *= 1.2;
    }

    if (exp < 2) {
        basic_cost *= 1.25;
    }

    if (accidents >= 2) {
        basic_cost *= 1.4;
    }

    if (accidents == 0 && exp >= 5) {
        basic_cost *= 0.9;
    }

    if (cover == 1) {
        basic_cost += 80;
    }

    cout << "Итоговая стоимость: " << basic_cost;

    return 0;
}