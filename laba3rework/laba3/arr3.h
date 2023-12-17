#pragma once
#include <vector>

namespace MyArrays {
    template<typename T>
    class Array3d {

    private:
        int dim0;
        int dim1;
        int dim2;
        std::vector<T> arr;

    public:

        Array3d(int dim0, int dim1, int dim2) : dim0(dim0), dim1(dim1), dim2(dim2) {
            arr.resize(dim0 * dim1 * dim2);
        }


        T& operator()(int i, int j, int k) {
            return arr[i * dim1 * dim2 + j * dim2 + k];
        }

        void SetValues0(int i, std::vector<std::vector<T>> values) {
            for (int j = 0; j < dim1; j++) {
                for (int k = 0; k < dim2; k++) {
                    arr[i * dim1 * dim2 + j * dim2 + k] = values[j][k];
                }
            }
        }
        void SetValues1(int j, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                for (int k = 0; k < dim2; k++) {
                    arr[i * dim1 * dim2 + j * dim2 + k] = values[i][k];
                }
            }
        }
        void SetValues2(int k, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    arr[i * dim1 * dim2 + j * dim2 + k] = values[i][j];
                }
            }
        }
        void SetValues01(int i, int j, std::vector<std::vector<T>> values) {
            for (int k = 0; k < dim2; k++) {
                arr[i * dim1 * dim2 + j * dim2 + k] = values[k];
            }
        }
        void SetValues02(int i, int k, std::vector<std::vector<T>> values) {
            for (int j = 0; j < dim1; j++) {
                arr[i * dim1 * dim2 + j * dim2 + k] = values[j];
            }
        }
        void SetValues12(int j, int k, std::vector<std::vector<T>> values) {
            for (int i = 0; i < dim0; i++) {
                arr[i * dim1 * dim2 + j * dim2 + k] = values[i];
            }
        }



        std::vector<T> GetValues0(int i) {
            std::vector<T> slice(dim1 * dim2);
            for (int j = 0; j < dim1; j++) {
                for (int k = 0; k < dim2; k++) {
                    slice[j * dim2 + k] = arr[i * dim1 * dim2 + j * dim2 + k];
                }
            }
            return slice;
        }
        std::vector<T> GetValues1(int j) {
            std::vector<T> slice(dim0 * dim2);
            for (int i = 0; i < dim0; i++) {
                for (int k = 0; k < dim2; k++) {
                    slice[i * dim2 + k] = arr[i * dim1 * dim2 + j * dim2 + k];
                }
            }
            return slice;
        }
        std::vector<T> GetValues2(int k) {
            std::vector<T> slice(dim0 * dim1);
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    slice[i * dim1 + j] = arr[i * dim1 * dim2 + j * dim2 + k];
                }
            }
            return slice;
        }
        std::vector<T> GetValues01(int i, int j) {
            std::vector<T> slice(dim2);
            for (int k = 0; k < dim2; k++) {
                slice[k] = arr[i * dim1 * dim2 + j * dim2 + k];
            }
            return slice;
        }
        std::vector<T> GetValues02(int i, int k) {
            std::vector<T> slice(dim1);
            for (int j = 0; j < dim1; j++) {
                slice[j] = arr[i * dim1 * dim2 + j * dim2 + k];
            }
            return slice;
        }
        std::vector<T> GetValues12(int j, int k) {
            std::vector<T> slice(dim0);
            for (int i = 0; i < dim0; i++) {
                slice[i] = arr[i * dim1 * dim2 + j * dim2 + k];
            }
            return slice;
        }



        void fill(T value) {
            for (int i = 0; i < dim0; i++) {
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        arr[i * dim1 * dim2 + j * dim2 + k] = value;
                    }
                }
            }
        }
        void ones() {
            fill(1);
        }
        void zeros() {
            fill(0);
        }



        void Print() {
            for (int i = 0; i < dim0; i++) {
                std::cout << "Слой " << i << ":" << std::endl;
                for (int j = 0; j < dim1; j++) {
                    for (int k = 0; k < dim2; k++) {
                        std::cout << arr[i * dim1 * dim2 + j * dim2 + k] << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }
    };
}