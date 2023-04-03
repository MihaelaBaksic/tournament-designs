#include <type_traits>
#include <memory>
#include "element.h"

#ifndef H_CELL
#define H_CELL


template <class T, class U>
class Cell
{
    static_assert(std::is_base_of<Element, T>::value, "T must inherit from Element");
    static_assert(std::is_base_of<Element, U>::value, "U must inherit from Element");

    public:
        int tmp;


    private:
        std::unique_ptr<T> left;
        std::unique_ptr<U> right;
};


#endif // !H_CELL#define H_CELL



