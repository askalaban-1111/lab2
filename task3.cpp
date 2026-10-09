/*Задание 3. Ввести код условной категории A/B/C, возраст и стаж. Ч
 *ерез switch задать базовую стоимость: 300, 450, 650.
 *Затем при возрасте <25 добавить 20%, при стаже <2 — ещё 25%.
 *Проверить согласованность стажа и возраста. Вывести категорию и итоговую учебную стоимость.
 */

#include <iostream>
#include <clocale>

using namespace std;

int main () {
    setlocale (LC_ALL, "Russian");

    char category;
    int exp;
    int age;

    cout << "Ваша категория (A, B, C): ";
    cin >> category;
    category = toupper (category);

    if (!(category == 'A' || category == 'B' || category == 'C')) {
        cout << "Некорректный ввод категории";
        return 1;
    }

    cout << "Ваш стаж: ";
    cin >> exp;

    cout << "Ваш возраст: ";
    cin >> age;

   if (exp > age - 16) {
       cout << "Возраст и стаж не согласованы!" << endl;
       return 1;
   }

   double base_cost;

   switch (category) {
       case 'A': base_cost = 300;
           break;

       case 'B': base_cost = 450;
           break;

       case 'C': base_cost = 650;
           break;
   }

    if (age < 25) {
        base_cost *= 1.2;
    }

    if (exp < 2) {
        base_cost *= 1.25;
    }
cout << "Финальная цена: " << base_cost;
    return 0;
}
