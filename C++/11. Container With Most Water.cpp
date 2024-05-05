#include <vector>

using namespace std;

// Brutte Force Method
int maxArea(vector<int> &height)
{
	int res = 0;

	for (int i = 0; i < height.size(); i++)
	{
		for (int j = i + 1; j < height.size(); j++)
		{
			res = max(res, min(height[i], height[j]) * (j - i));
		}
	}

	return res;
}

// Optimal Apporach
int maxArea(vector<int> &height)
{
	int res = 0;
	int low = 0, high = height.size() - 1;

	while (low < high)
	{
		res = max(res, (high - low) * min(height[low], height[high]));

		if (height[low] < height[high])
			low++;
		else
			high--;
	}

	return res;
}
