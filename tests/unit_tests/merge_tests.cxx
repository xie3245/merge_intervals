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

	SECTION("operator less than")
	{
		const Interval anchor {9, 22};
		const Interval is_less {5, 19};
		const Interval is_not_less {100, 200};

		REQUIRE(is_less < anchor);
		REQUIRE_FALSE(is_not_less < anchor);
	}

	SECTION("operator equal")
	{
		const Interval anchor {9, 22};
		const Interval is_equal {9, 22};
		const Interval is_not_equal {9, 200};

		REQUIRE(is_equal == anchor);
		REQUIRE_FALSE(is_not_equal == anchor);
	}
}