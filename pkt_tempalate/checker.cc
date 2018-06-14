#include <tuple>
#include <type_traits>

#include <tuple>
#include <type_traits>

// template <typename T, typename... Ts>
// constexpr bool contains = (std::is_same<T, Ts>{} || ...);

// template <typename Subset, typename Set>
// constexpr bool is_subset_of = false;

// template <typename... Ts, typename... Us>
// constexpr bool is_subset_of<std::tuple<Ts...>, std::tuple<Us...>> = (contains<Ts, Us...> && ...);

// check if lhs is the superset of rhs


template <typename...>
struct is_one_of;

template <typename F>
struct is_one_of<F>
{
	static constexpr bool value = false;
};

template <typename F, typename S, typename... T>
struct is_one_of<F, S, T...>
{
	static constexpr bool value = std::is_same<F, S>::value
		|| is_one_of<F, T...>::value;
};

template <typename F, typename... T>
struct is_one_of<F, std::tuple<T...>>
{
	static constexpr bool value = is_one_of<F, T...>::value;
};

template <typename Lhs, typename Rhs>
struct is_superset_of;

template <typename Tuple, typename T, typename... Ts>
struct is_superset_of<Tuple, std::tuple<T, Ts...>>
{
	static const bool value = is_one_of<T, Tuple>::value && is_superset_of<Tuple, std::tuple<Ts...>>::value;
};

template <typename Tuple>
struct is_superset_of<Tuple, std::tuple<>>
{
	static const bool value = true;
};

