#include <iostream>

    template <typename T>
    class Array3d
    {
        public:
            Array3d(int dim1, int dim2, int dim3) : _dim1(dim1), _dim2(dim2), _dim3(dim3) //Конструктор
            {
                _linearray = new T[dim1 * dim2 * dim3];
            }

            ~Array3d() //Деструктор
            {
                delete[] _linearray; //Т.к. массив динамический - всё удаляем
            }

            T& operator()(int i, int j, int k) //Через круглые скобки сразу обращаемся к нужному элементу
            {
                return _linearray[k * (_dim1 * _dim2) + i * _dim1 + j];
            }

            T getValue(int i, int j, int k)
            {
                return _linearray[k * (_dim1 * _dim2) + i * _dim1 + j];
            }

            void setValue(int i, int j, int k, const T& data)
            {
                _linearray[k * (_dim1 * _dim2) + i * _dim1 + j] = data;
            }

            Array3d(const Array3d& array3D) = delete;

            Array3d& operator=(const Array3d& array3D) = delete;

            void npones() {fill(1);} //Заполнить массив единицами

            void npzeros() {fill(0);} //Заполнить массив нулями

            void npfill(int num) {fill(num);} //Заполнить массив каким-то числом

            void Print() //Вывод всего массива
            {
                for (int i = 0; i < _dim1; i++)
                {
                    for (int j = 0; j < _dim2; j++)
                    {
                        for (int k = 0; k < _dim3; k++)
                        {
                            std::cout << _linearray[(i, j, k)] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }
            }

        private:
            T* _linearray;

            int _dim1, _dim2, _dim3;

            void fill(int number)
            {
                for (int i = 0; i < _dim1; i++)
                {
                    for (int j = 0; j < _dim2; j++)
                    {
                        for (int k = 0; k < _dim3; k++)
                        {
                            _linearray[(i, j, k)] = number;
                        }
                    }
                }
            }
    };

int main()
{
    Array3d<int> array3D(3, 3, 3);

    array3D(1, 2, 1) = 121;

    array3D.setValue(1, 2, 3, 4);

    std::cout << array3D(1, 2, 1) << std::endl;

    array3D.setValue(1, 2, 3, 4);

    array3D.Print();
    return 0;
}