#include <iostream>
#include <cmath>

class Integral //Класс интеграла
{
public:
    Integral(double a, double b, double step, double accuracy) //Конструктор
        : _a(a), _b(b), _step(step), _accuracy(accuracy) {}

    virtual double calc(double f(double)) = 0; //Функция виртуальная, так как дальше будет меняться в производных классах
    
protected:
    //Края интегрирования, шаг и точность вычислений
    double _a;
    double _b;
    double _step;
    double _accuracy;
};

class Trapz : public Integral //Производный класс подсчёта интеграла методом трапеций
{
public:
    Trapz(double a, double b, double step, double accuracy) //Базовый конструктор
        : Integral(a, b, step, accuracy) {}

    double calc(double f(double)) override //Переписываем calc на вычисление методом трапеций
    {
        double addition = 0;

        for (double x = _a + _step; x < _b; x += _step)
        {
            addition += f(x);
        }
        return (_step / 2) * (f(_a) + 2 * addition + f(_b));
    }
};

class Simpson : public Integral //Производный класс подсчёта интеграла методом Симпсона
{
public:
    Simpson(double a, double b, double step, double accuracy) //Базовый конструктор
        : Integral(a, b, step, accuracy) {}

    double calc(double f(double)) override //Переписываем calc на вычисление методом Симпсона
    {
        double evenAddition = 0;
        double oddAddition = 0;

        for (double x = _a + 2 * _step; x < _b; x += 2 * _step)
        {
            evenAddition += f(x);
        }

        for (double x = _a + _step; x < _b; x += 2 * _step)
        {
            oddAddition += f(x);
        }

        return (_step / 3) * (f(_a) + 2 * evenAddition + 4 * oddAddition + f(_b));
    }
};

double myFunction(double x) //Функция, которую будет интегрировать 
{
    return x * x;
}

int main()
{
    double a = 0; //Начальная граница интегрирования
    double b = 1; //Конечная граница интегрирования
    double step = 0.01; //Шаг интегрирования
    double accuracy = 0.0001; //Точность

    //Создаём объекты классов Trapz и Simpson
    Trapz trapzCalculator(a, b, step, accuracy);
    Simpson simpsonCalculator(a, b, step, accuracy);

    //Вызовем для них соответствующие методы calc
    double resultTrapz = trapzCalculator.calc(myFunction);
    double resultSimpson = simpsonCalculator.calc(myFunction);

    //Вывод результата
    std::cout << "Trapz: " << resultTrapz << std::endl;
    std::cout << "Simpson: " << resultSimpson << std::endl;

    return 0;
}