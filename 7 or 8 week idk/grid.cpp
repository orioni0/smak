#include <array>
#include <cstddef>
#include <iostream>
#include <cstdio>
#include <new>

/*template<typename Element_Type, std::size_t N, typename First>
void variadic_fill(std::array<Element_Type, N>& arr, First f)
{
    arr[N - 1] = f;
}

template<typename Element_Type, std::size_t N, typename First, typename ... Rest>
void variadic_fill(std::array<Element_Type, N>& arr, First f, Rest ... rest)
{
    arr[N - sizeof...(Rest) - 1] = f;
    variadic_fill<>(arr, rest...);
}


template<typename First_Val_T, typename ... Rest_Vals_T>
std::array<First_Val_T, sizeof...(Rest_Vals_T) + 1> make_array_from_variadic(
    First_Val_T f, Rest_Vals_T ... rest
)
{
    std::array<First_Val_T, sizeof...(Rest_Vals_T) + 1> arr;
    variadic_fill<First_Val_T, sizeof...(Rest_Vals_T) + 1>(arr, f, rest...);
    return arr;
}*/
template<typename T, unsigned Dim>
class Grid;

template<typename T>
class Grid<T, 1> final
{
public:
    using value_type = T;
    using size_type = size_t;
    Grid(Grid const&) = delete;
    Grid(Grid&&) = delete;
    Grid& operator=(Grid&) = delete;
    Grid& operator=(Grid&&) = delete;

private:
    T* m_data;
    size_t m_size;
public:
    Grid(T const &t) : m_size(1)
    {
        m_data = ::operator new(sizeof(T));
        new(m_data) T(t);
    }

    Grid(size_type size) : m_size(size)
    {
        m_data = ::operator new(sizeof(T) * size);
        for(size_t i = 0; i < size; ++i)
        {
            new(m_data + i) T();
        }
    }

    Grid(size_type size, T const &t)
    {
        m_data = static_cast<T*>(::operator new(sizeof(T) * size));
        for(size_type i = 0; i < size; ++i)
        {
            new(m_data + i) T(t);
        }
    }

    Grid& operator=(T const& t)
    {
        for (size_type i = 0; i < m_size; ++i) m_data[i] = t;
        return *this;
    }

    T& operator[](size_type idx)
    {
        return m_data[idx];
    }

    std::array<size_type, 1> get_size()
    {
        std::array<size_type, 1> size_arr;
        size_arr[0] = m_size;
        return size_arr;
    }
};

template<typename T, unsigned Dim>
class Grid final
{
public:
    static_assert(Dim > 0);
    using value_type = T;
    using size_type = unsigned;
private:
    Grid<T, Dim - 1>* m_data;
    size_type m_size;
public:
    template<typename First, typename ... Rest>
    Grid(First first, Rest ... rest) : m_size(first)
    {
        m_data = static_cast<Grid<T, Dim - 1>*>(::operator new(sizeof(Grid<T, Dim - 1>)*first));
        for(size_type i = 0; i < first; ++i)
        {
            new(m_data + i) Grid<T, Dim - 1>(rest ...);
        }
    }

    Grid(const T& t) : m_size(1)
    {
        m_data = ::operator new(sizeof(Grid<T, Dim - 1>));
        new(m_data) Grid<T, Dim - 1>();
    }

    Grid(Grid const&) = delete;
    Grid(Grid&&) = delete;
    Grid& operator=(Grid&) = delete;
    Grid& operator=(Grid&&) = delete;

    Grid& operator=(T const& t)
    {
        for(size_type i = 0; i < m_size; ++i)
        {
            m_data[i] = t;
        }
        return *this;
    }

    Grid<T, Dim - 1>& operator[](size_type idx)
    {
        return m_data[idx];
    }
}; 



int main()
{
    Grid<int, 3> grid(2, 2, 2, -2);
    grid[0][1][0] = 1;
    std::cout << grid[0][1][0] << " " << grid[1][1][1] << "\n";
}
