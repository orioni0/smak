#include <cstddef> // для size_t

template <typename T, unsigned N>
class Array {
public:
    // Конструктор, заполняющий массив значением value
    explicit Array(const T& value = T()) {
        fill(value);
    }

    // Конструктор копирования
    Array(const Array& other) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = other.data[i];
        }
    }

    // Деструктор (не требуется, так как используем встроенные типы данных)

    // Оператор присваивания
    Array& operator=(const Array& other) {
        if (this != &other) {
            for (size_t i = 0; i < N; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Возвращает размер массива
    size_t size() const {
        return N;
    }

    // Операторы доступа по индексу
    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    // Получение первого элемента
    T& front() {
        return data[0];
    }

    const T& front() const {
        return data[0];
    }

    // Получение последнего элемента
    T& back() {
        return data[N - 1];
    }

    const T& back() const {
        return data[N - 1];
    }

    // Проверка, пустой ли массив
    bool empty() const {
        return N == 0;
    }

    // Заполнение массива значением value
    void fill(const T& value) {
        for (size_t i = 0; i < N; ++i) {
            data[i] = value;
        }
    }

private:
    T data[N]; // Массив данных
};