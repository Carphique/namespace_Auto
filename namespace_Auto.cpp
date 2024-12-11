#include <iostream>
#include <ctime>

using namespace std;

namespace first {
    class Auto {
        int speed;
        int size; 
    public:
        Auto() {
            speed = rand() % 400 + 100; // швидкість у діапазоні [100, 500]
            size = rand() % 4 + 1;      // розмір у діапазоні [1, 4]
        }

        // геттери для отримання значень полів
        int getSpeed() const {
            return speed;
        }

        int getSize() const {
            return size;
        }
    };
}

namespace second {
    class Auto {
        int speed;
        int size;
    public:
        // конструктор, який ініціалізує випадкові значення для speed і size
        Auto() {
            speed = rand() % 400 + 100; // швидкість у діапазоні [100, 500]
            size = rand() % 4 + 1;      // розмір у діапазоні [1, 4]
        }

        // конструктор копіювання з об'єкта класу "автомобіль" із першого неймспейсу
        Auto(const first::Auto& obj) {
            speed = obj.getSpeed();
            size = obj.getSize();
        }

        void PrintInfo() const {
            cout << "Speed of your car: " << speed << " km/h" << endl;
            cout << "Size of your car: " << size << endl;
        }
    };
}

using namespace first;
using namespace second;

int main() {

    // створення об'єкта класу "автомобіль" з першого неймспейсу
    first::Auto obj1;

    // створення об'єкта класу "автомобіль" з другого неймспейсу на основі першого
    second::Auto obj2(obj1);

    // вивід інформації
    obj2.PrintInfo();
}