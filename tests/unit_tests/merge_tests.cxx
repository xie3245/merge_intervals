#include<catch.hpp>
#include<Interval.hxx>

TEST_CASE("Interval Class")
{
	using namespace merge;

	SECTION("construction")
	{
		const Interval interval {45, 32};
		REQUIRE(interval.m_lower == 32);
		REQUIRE(interval.m_upper == 45);
	}
}