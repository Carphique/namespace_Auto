#include <iostream>
#include <ctime>

using namespace std;

namespace first {
    class Auto {
        int speed;
        int size; 
    public:
        Auto() {
            speed = rand() % 400 + 100; // �������� � ������� [100, 500]
            size = rand() % 4 + 1;      // ����� � ������� [1, 4]
        }

        // ������� ��� ��������� ������� ����
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
        // �����������, ���� �������� �������� �������� ��� speed � size
        Auto() {
            speed = rand() % 400 + 100; // �������� � ������� [100, 500]
            size = rand() % 4 + 1;      // ����� � ������� [1, 4]
        }

        // ����������� ��������� � ��'���� ����� "���������" �� ������� ����������
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

    // ��������� ��'���� ����� "���������" � ������� ����������
    first::Auto obj1;

    // ��������� ��'���� ����� "���������" � ������� ���������� �� ����� �������
    second::Auto obj2(obj1);

    // ���� ����������
    obj2.PrintInfo();
}