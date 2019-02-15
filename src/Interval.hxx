#ifndef INTERVAL_MERGE_INTERVAL_HXX
#define INTERVAL_MERGE_INTERVAL_HXX

#include<cstdint>
#include<algorithm>
#include<vector>

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

	inline bool operator<(const Interval& other) const noexcept
	{
		return (m_lower < other.m_lower);
	}

	inline bool operator==(const Interval& other) const noexcept
	{
		return (m_lower == other.m_lower) && (m_upper == other.m_upper);
	}

	static std::vector<Interval> merge(const std::vector<Interval>& intv_list);

	Type m_lower;
	Type m_upper;
};
}

#endif