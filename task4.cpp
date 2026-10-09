/*
Задание 4. Ввести категорию A/B/C, возраст 18..80, стаж, количество случаев и признак расширенного покрытия 0/1.
Через switch задать базу 300/450/650. Проверить, что стаж не превышает age-18.
Затем последовательно применить: возраст <25 — +20%, стаж <2 — +25%, cases>=2 — +40%.
Если cases==0 и стаж>=5, после надбавок уменьшить сумму на 10%.
Расширенное покрытие добавляет фиксированные 80. Вывести все применённые правила и итог.
Это учебная модель, а не реальный страховой расчёт.
*/





#include <iostream>
#include <string>
#include <clocale>

using namespace std;

int main() {
    setlocale (LC_ALL, "Russian");

    char category;
    int exp, age, accidents;
    string cover;


    cout << "Введите категорию латиницей (A, B, C): ";
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
        cout << "Количество страховых случаев введены неверно!";
    }

    cout << "Есть ли у вас расширенное покрытие (Да/Нет): ";
    cin >> cover;


    if (cover == "ДА" || cover == "да" || cover == "Да" || cover == "дА" || cover == "lf") {
        cover = "ДА";
    } else if (cover == "Нет" || cover == "НЕт" || cover == "НЕТ" ||
        cover == "нЕТ" || cover == "неТ" || cover == "ytn") {
        cover = "НЕТ";
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

    if (cover == "ДА") {
        basic_cost += 80;
    }

    cout << "Итоговая стоимость: " << basic_cost << "$";

    return 0;
}