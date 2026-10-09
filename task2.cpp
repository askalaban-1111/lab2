/*Задание 2. Ввести базовую стоимость, количество страховых случаев за год и стаж.
 *При двух и более случаях увеличить стоимость на 40%.
 *Если случаев 0 и стаж не меньше 5 лет, после остальных расчётов дать скидку 10%.
 *Если оба правила неприменимы, стоимость не менять. Отрицательные значения считать ошибкой.
 */

#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double basic_cost = 300;
    int accidents;
    int exp;

    cout << "Введите количесво страховых случаев и стаж: ";
    if (!(cin >> accidents >> exp)) {
        cout << "Некорректный ввод (количество инцедентов и стаж должны быть целыми числами)";
        return 1;
    }

    if (exp < 0 || accidents < 0) {
        cout << "Отрицательные значения недопустимы";
        return 1;
    }

    if (accidents >= 2) {
        basic_cost *= 1.4;
    }
    if (accidents == 0 && exp >= 5) {
        basic_cost = basic_cost * 0.9;
    }

    cout << "Финальная цена: " << basic_cost;
return 0;
}
