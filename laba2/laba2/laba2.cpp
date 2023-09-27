#include <iostream>
#include <cmath>

class Point { //Класс точки
public:
    Point(int x, int y, int z) //Конструктор
        : _x(x), _y(y), _z(z) {}

    //Набор геттеров координат точки
    int getX() const { return _x; }
    int getY() const { return _y; }
    int getZ() const { return _z; }

private:
    //Координаты точки
    int _x;
    int _y;
    int _z;
};

class Vector { //Класс вектора
public:
    Vector(int x1, int y1, int z1, int x2, int y2, int z2) //Конструктор по координатам
        : _x1(x1), _y1(y1), _z1(z1), _x2(x2), _y2(y2), _z2(z2) {}

    Vector(const Point& startPoint, const Point& endPoint) //Конструктор по точкам
        : _x1(startPoint.getX()), _y1(startPoint.getY()), _z1(startPoint.getZ()),
        _x2(endPoint.getX()), _y2(endPoint.getY()), _z2(endPoint.getZ()) {}

    Vector operator+(const Vector& other) const { //Оператор суммы векторов
        return Vector(_x1 + other._x1, _y1 + other._y1, _z1 + other._z1,
            _x2 + other._x2, _y2 + other._y2, _z2 + other._z2);
    }

    Vector operator-(const Vector& other) const { //Оператор разности векторов
        return Vector(_x1 - other._x1, _y1 - other._y1, _z1 - other._z1,
            _x2 - other._x2, _y2 - other._y2, _z2 - other._z2);
    }

    Vector operator-() const { //Оператор обратного вектора
        return Vector(-_x1, -_y1, -_z1, -_x2, -_y2, -_z2);
    }

    Vector normalize() const { //Нормализация вектора (получение единичного)
        double len = length();
        if (len == 0) {
            return Vector(0, 0, 0, 0, 0, 0);
        }
        return Vector(_x1 / len, _y1 / len, _z1 / len, _x2 / len, _y2 / len, _z2 / len);
    }

    double scalarProduct(const Vector& other) const { //Скалрное произведение
        return _x1 * other._x1 + _y1 * other._y1 + _z1 * other._z1;
    }

    Vector crossProduct(const Vector& other) const { //Векторное произведение
        int x = _y1 * other._z1 - _z1 * other._y1;
        int y = _z1 * other._x1 - _x1 * other._z1;
        int z = _x1 * other._y1 - _y1 * other._x1;
        return Vector(0, 0, 0, x, y, z);
    }

    double length() const { //Вычисление длинны вектора
        return sqrt((_x2 - _x1) * (_x2 - _x1) + (_y2 - _y1) * (_y2 - _y1) + (_z2 - _z1) * (_z2 - _z1));
    }

    bool isCollinear(const Vector& other) const { //Проверка на коллинеарность
        Vector cross = crossProduct(other);
        return cross.getX1() == 0 && cross.getY1() == 0 && cross.getZ1() == 0;
    }

    bool isCoplanar(const Vector& v2, const Vector& v3) const { //Проверка на компланарность
        Vector cross1 = crossProduct(v2);
        double scalar = cross1.scalarProduct(v3);
        return scalar == 0;
    }

    double distance(const Vector& other) const { //Поиск расстояния между векторами
        double dx = _x2 - other._x2;
        double dy = _y2 - other._y2;
        double dz = _z2 - other._z2;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    double angle(const Vector& other) const { //Поиск угла между векторами
        double dot = scalarProduct(other);
        double len1 = length();
        double len2 = other.length();
        return acos(dot / (len1 * len2));
    }

    //Набор геттеров координат векторов
    int getX1() const { return _x1; }
    int getY1() const { return _y1; }
    int getZ1() const { return _z1; }
    int getX2() const { return _x2; }
    int getY2() const { return _y2; }
    int getZ2() const { return _z2; }

private:
    //Координаты вектора
    int _x1;
    int _y1;
    int _z1;
    int _x2;
    int _y2;
    int _z2;
};

int main() {
    //Ввод векторов из кода
    /*
    Point startPoint(1, 2, 3);
    Point endPoint(4, 5, 6);
    Point anotherEndPoint(7, 8, 9);

    Vector vector1(1, 2, 3, 4, 5, 6);
    Vector vector2(startPoint, endPoint);
    Vector vector3(startPoint, anotherEndPoint);
    */

    //Ввод векторов с клавиатуры
    int x1, y1, z1, x2, y2, z2;

    std::cout << "Enter first vector:" << std::endl;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Vector vector1(x1, y1, z1, x2, y2, z2);

    std::cout << "Enter second vector:" << std::endl;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Point startPoint(x1, y1, z1);
    Point endPoint(x2, y2, z2);
    Vector vector2(startPoint, endPoint);

    std::cout << "Enter third vector:" << std::endl;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Point startPoint2(x1, y1, z1);
    Point endPoint2(x2, y2, z2);
    Vector vector3(startPoint2, endPoint2);

    //Вычисления с векторами (Создаём где нужно объекты класса Vector, либо обычные переменные double/boolean)
    Vector sum = vector1 + vector2;
    Vector difference = vector1 - vector2;
    Vector negation = -vector1;
    Vector unitVector = vector1.normalize();
    double scalarProduct = vector1.scalarProduct(vector2);
    Vector crossProduct = vector1.crossProduct(vector2);
    double vectorLength = vector1.length();
    bool collinear = vector1.isCollinear(vector2);
    bool coplanar = vector1.isCoplanar(vector2, vector3);
    double distanceBetweenVectors = vector1.distance(vector2);
    double angleBetweenVectors = vector1.angle(vector2);

    //Консольный интерфейс
    int myCase = 1;
    while (myCase != 0)
    {
        std::cout << "0 - if you want to go out" << std::endl;
        std::cout << "1 - if you want to add vectors 1 and 2" << std::endl;
        std::cout << "2 - if you want to subtract vectors 1 and 2" << std::endl;
        std::cout << "3 - if you want to get the inverse vector 1" << std::endl;
        std::cout << "4 - if you want to construct a unit vector 1" << std::endl;
        std::cout << "5 - if you want to get the scalar product of vectors 1 and 2" << std::endl;
        std::cout << "6 - if you want to get the cross product of vectors 1 and 2" << std::endl;
        std::cout << "7 - if you want to get the length of vector 1" << std::endl;
        std::cout << "8 - if you want to check collinearity of vectors 1 and 2" << std::endl;
        std::cout << "9 - if you want to check the coplanarity of vectors 1, 2 and 3" << std::endl;
        std::cout << "10 - if you want to find the distance between vectors 1 and 2" << std::endl;
        std::cout << "11 - if you want to find the angle between vectors 1 and 2" << std::endl;

        std::cin >> myCase;

        switch (myCase)
        {
        case 1:
            std::cout << "Sum: (" << sum.getX1() << ", " << sum.getY1() << ", " << sum.getZ1() << ") -> ("
                << sum.getX2() << ", " << sum.getY2() << ", " << sum.getZ2() << ")" << std::endl;
            break;
        case 2:
            std::cout << "Difference: (" << difference.getX1() << ", " << difference.getY1() << ", " << difference.getZ1() << ") -> ("
                << difference.getX2() << ", " << difference.getY2() << ", " << difference.getZ2() << ")" << std::endl;
            break;
        case 3:
            std::cout << "Negation: (" << negation.getX1() << ", " << negation.getY1() << ", " << negation.getZ1() << ") -> ("
                << negation.getX2() << ", " << negation.getY2() << ", " << negation.getZ2() << ")" << std::endl;
            break;
        case 4:
            std::cout << "Unit Vector: (" << unitVector.getX1() << ", " << unitVector.getY1() << ", " << unitVector.getZ1() << ") -> ("
                << unitVector.getX2() << ", " << unitVector.getY2() << ", " << unitVector.getZ2() << ")" << std::endl;
            break;
        case 5:
            std::cout << "Scalar Product: " << scalarProduct << std::endl;
            break;
        case 6:
            std::cout << "Cross Product: (" << crossProduct.getX1() << ", " << crossProduct.getY1() << ", " << crossProduct.getZ1() << ") -> ("
                << crossProduct.getX2() << ", " << crossProduct.getY2() << ", " << crossProduct.getZ2() << ")" << std::endl;
            break;
        case 7:;
            std::cout << "Vector Length: " << vectorLength << std::endl;
            break;
        case 8:
            std::cout << "Collinear: " << collinear << std::endl;
            break;
        case 9:
            std::cout << "Coplanar: " << coplanar << std::endl;
            break;
        case 10:
            std::cout << "Distance Between Vectors: " << distanceBetweenVectors << std::endl;
            break;
        case 11:
            std::cout << "Angle Between Vectors: " << angleBetweenVectors << " radians" << std::endl;
            break;
        default:
            std::cout << " " << std::endl;
            break;
        }
    };

    return 0;
}