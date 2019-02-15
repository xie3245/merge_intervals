#include<catch.hpp>
#include<Interval.hxx>
#include<vector>
#include<iostream>

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

TEST_CASE("Sorting and Merging")
{
	using namespace merge;
	using namespace std;

	const vector<Interval> given_list
	{
		{25, 30},
		{2, 19},
		{14, 23},
		{4, 8}
	};

	const vector<Interval> sorted_list
	{		
		{2, 19},
		{4, 8},
		{14, 23},
		{25, 30}
	};

	const vector<Interval> merged_list
	{
		{2, 23},
		{25, 30}
	};

	SECTION("sorting")
	{
		auto sorted = given_list;
		std::sort(sorted.begin(), sorted.end());
		REQUIRE(sorted == sorted_list);
	}

	SECTION("merge empty")
	{
		auto merged = Interval::merge(vector<Interval>{});
		REQUIRE(merged.empty());
	}

	SECTION("merge one")
	{
		vector<Interval> input
		{
			{1, 100}
		};

		auto merged = Interval::merge(input);
		REQUIRE(merged == input);
	}

	SECTION("identical intervals")
	{
		auto merged = Interval::merge(vector<Interval>{{1, 100}, {1, 100}, {1, 100}, {1, 100}});
		REQUIRE(merged == vector<Interval>{{1, 100}});
	}

	SECTION("given interval")
	{ 
		auto merged = Interval::merge(given_list);
		REQUIRE(merged == merged_list);
	}

	SECTION("non-overlapping intervals")
	{
		std::vector<Interval> intv_list
		{
			{25, 30},
			{2, 14},
			{15, 23},
		};
 
		auto merged = Interval::merge(intv_list);
		std::sort(intv_list.begin(), intv_list.end());
		REQUIRE(merged == intv_list);
	}
}