#include <iostream>

using namespace std;
int main() {

    setlocale(LC_ALL, "russian");
    int age;
    int experience;

    cout << "Введите возраст водителя: ";
    cin >> age;
    cout << "Введите стаж водителя: ";
    cin >> experience;

    if (age < 18 || age > 80 || experience < 0 || experience > (age - 18)) {
       cout << "Ошибка ввода" << endl;
    } else {
        double cost = 300;

        if (age < 25) {
            cost = cost * 1.2;
        }
        if (experience < 2) {
            cost = cost * 1.25;
        }
        cout << "Итоговая стоймость: " << cost << endl;
    }
    return 0;
}