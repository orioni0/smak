#include <iostream>
#include <memory>
#include <cassert>

template <typename T>
class Grid {
public:
    using value_type = T;
    using size_type = unsigned;

private:
    std::unique_ptr<T[]> data;
    size_type y_size, x_size;

public:
    // Конструктор для неявного преобразования типов
    Grid(T const& t)
        : data(new T[1]), y_size(1), x_size(1) {
        data[0] = t;
    }

    // Конструктор с размерами сетки
    Grid(size_type y_size, size_type x_size)
        : data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) {}

    // Конструктор с размерами сетки и значением заполнения
    Grid(size_type y_size, size_type x_size, T const& t)
        : data(new T[y_size * x_size]), y_size(y_size), x_size(x_size) {
        fill(t);
    }

    // Конструктор копирования
    Grid(Grid<T> const& other)
        : data(new T[other.y_size * other.x_size]), y_size(other.y_size), x_size(other.x_size) {
        std::copy(other.data.get(), other.data.get() + y_size * x_size, data.get());
    }

    // Конструктор перемещения
    Grid(Grid<T>&& other) noexcept
        : data(std::move(other.data)), y_size(other.y_size), x_size(other.x_size) {
        other.y_size = 0;
        other.x_size = 0;
    }

    // Оператор копирующего присваивания
    Grid<T>& operator=(Grid<T> const& other) {
        if (this != &other) {
            if (y_size != other.y_size || x_size != other.x_size) {
                data.reset(new T[other.y_size * other.x_size]);
                y_size = other.y_size;
                x_size = other.x_size;
            }
            std::copy(other.data.get(), other.data.get() + y_size * x_size, data.get());
        }
        return *this;
    }

    // Оператор перемещающего присваивания
    Grid<T>& operator=(Grid<T>&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
            y_size = other.y_size;
            x_size = other.x_size;
            other.y_size = 0;
            other.x_size = 0;
        }
        return *this;
    }

    // Индексирование для получения элемента
    T& operator()(size_type y_idx, size_type x_idx) {
        return data[y_idx * x_size + x_idx];
    }

    T operator()(size_type y_idx, size_type x_idx) const {
        return data[y_idx * x_size + x_idx];
    }

    // Оператор присваивания значений
    Grid<T>& operator=(T const& t) {
        for (auto it = data.get(), end = data.get() + x_size * y_size; it != end; ++it) {
            *it = t;
        }
        return *this;
    }

    size_type get_y_size() const { return y_size; }
    size_type get_x_size() const { return x_size; }

    // Оператор индексации для двумерного доступа
    T* operator[](size_type y_idx) {
        return data.get() + y_idx * x_size;
    }

    // Заполнение сетки значением
    void fill(const T& value) {
        for (size_type i = 0; i < y_size * x_size; ++i) {
            data[i] = value;
        }
    }
};

// Пример использования
int main() {
    Grid<float> g(3, 2, 0.0f);
    assert(3 == g.get_y_size());
    assert(2 == g.get_x_size());

    using gsize_t = Grid<int>::size_type;
    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(0.0f == g[y_idx][x_idx]);

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            g[y_idx][x_idx] = 1.0f;

    for (gsize_t y_idx = 0; y_idx != g.get_y_size(); ++y_idx)
        for (gsize_t x_idx = 0; x_idx != g.get_x_size(); ++x_idx)
            assert(1.0f == g(y_idx, x_idx));

    return 0;
}