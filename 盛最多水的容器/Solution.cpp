#include "pch.h"
#include "Solution.h"


Solution::Solution()
{
}


Solution::~Solution()
{
}

int Solution::maxArea(vector<int>& height) {
	int i = height.size();
	int p = 0;
	int q = i - 1;
	int max;
	if (height[p] <= height[q])
	{
		max = height[p] * (q - p);
	}
	else
	{
		max = height[q] * (q - p);
	}
	for (; p != q;)
	{
		if (height[p] <= height[q])
		{
			p++;
			if (height[p] <= height[q])
			{
				if ((height[p] * (q - p)) >= max)
					max = height[p] * (q - p);
			}
			else
			{
				if ((height[q] * (q - p)) >= max)
					max = height[q] * (q - p);
			}
		}
		else
		{
			q--;
			if (height[p] <= height[q])
			{
				if ((height[p] * (q - p)) >= max)
					max = height[p] * (q - p);
			}
			else
			{
				if ((height[q] * (q - p)) >= max)
					max = height[q] * (q - p);
			}
		}
	}
	return max;
}