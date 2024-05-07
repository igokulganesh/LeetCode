#include <bits/stdc++.h>

using namespace std;

/*
Approach: Brute Force Method
Time: O(n^2)
Space: O(1)
*/
int maxArea(vector<int> &height)
{
	int max_area = 0;

	for (int i = 0; i < height.size(); i++)
	{
		for (int j = i + 1; j < height.size(); j++)
		{
			max_area = max(max_area, (j - i) * min(height[i], height[j]));
		}
	}

	return max_area;
}

/*
Approach: Two Pointers
Time: O(n)
Space: O(1)
*/
int maxArea(vector<int> &height)
{
	int left = 0, right = height.size() - 1;
	int max_area = 0;

	while (left < right)
	{
		max_area = max(max_area, (right - left) * min(height[left], height[right]));

		if (height[left] < height[right])
			left++;
		else
			right--;
	}

	return max_area;
}