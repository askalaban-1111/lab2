#include <iostream>
using namespace std;
int main () {
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
