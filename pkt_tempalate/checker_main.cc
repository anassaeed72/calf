#include "checker.cc"
#include <iostream>
using namespace std;
// gcc checker_main.cc  -std=c++17
// it has to be c++17 else wont work

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

    // std::wcout << is_superset_of<ipheader, fivetuple>::value;
    // std::wcout << is_superset_of<ipheaderC, fivetuple>::value;
    // std::wcout << is_superset_of<fivetuple, ipheader>::value;
    static_assert(is_superset_of<t1, t1>::value, "err");
    static_assert(is_superset_of<ipheader, fivetuple>::value, "err");
    static_assert(is_superset_of<ipheaderC, fivetuple>::value, "err");

    // std::cout << is_superset_of<t1, t1>;


}
