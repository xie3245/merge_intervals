#include<Interval.hxx>

namespace merge
{

using namespace std;

static bool have_no_overlap(const Interval& lhs, const Interval& rhs) noexcept
{
	return lhs.m_upper < rhs.m_lower; 
}

vector<Interval> Interval::merge(const vector<Interval>& list_to_merge)
{
	if(list_to_merge.size() < 2)
	{
		return list_to_merge;
	}

	vector<Interval> sorted = list_to_merge;
	std::sort(sorted.begin(), sorted.end());

	vector<Interval> merged {};
	Interval anchor = sorted.front();
	for(const auto& itr : sorted)
	{
		if(have_no_overlap(anchor, itr))
		{
			merged.push_back(anchor);
			anchor = itr;
		}
		else
		{
			anchor.m_upper = std::max(anchor.m_upper, itr.m_upper);
		}
	}
	merged.push_back(anchor);
	return merged;
}
}
