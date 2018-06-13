#include "checker.cc"
#include <iostream>
using namespace std;
int main()
{
    using t1 = std::tuple<int, double>;
    using t2 = std::tuple<double, int>;
    using t3 = std::tuple<int, double, char>;
    using fivetuple = std::tuple<uint32_t, uint32_t, uint16_t, uint16_t, uint8_t>;

    using ipheader = std::tuple<int, uint32_t, uint32_t, uint16_t, uint16_t, uint8_t>;

    using ipheaderC = std::tuple<int, fivetuple>;

    // static_assert(is_subset_of<t1, t1>, "err");
    // static_assert(is_subset_of<t1, t2>, "err");
    // static_assert(is_subset_of<t2, t1>, "err");
    // static_assert(is_subset_of<t2, t3>, "err");
    // static_assert(!is_subset_of<t3, t2>, "err");


    // static_assert(is_subset_of<t1, t2>, "err");
    // static_assert(is_subset_of<fivetuple, ipheader>, "err");

    std::wcout << is_subset_of<ipheader, fivetuple>;
    std::wcout << is_subset_of<ipheaderC, fivetuple>;
    std::wcout << is_subset_of<fivetuple, ipheader>;
}
