#ifndef INTERVAL_MERGE_INTERVAL_HXX
#define INTERVAL_MERGE_INTERVAL_HXX

#include<cstdint>
#include<algorithm>

namespace merge
{
struct Interval final
{
	using Type = uint32_t;

	Interval(const Type lower_bound, const Type upper_bound) noexcept:
		m_lower(std::min(lower_bound, upper_bound)), m_upper(std::max(lower_bound, upper_bound))
	{

	}

	Interval(const Interval&) noexcept = default;
	Interval& operator=(const Interval&) noexcept = default;

	Interval(Interval&&) noexcept = default;
	Interval& operator=(Interval&&) noexcept = default;

	Type m_lower;
	Type m_upper;
};
}

#endif