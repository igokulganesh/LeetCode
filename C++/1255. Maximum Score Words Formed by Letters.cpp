#include <bits/stdc++.h>

using namespace std ; 

unordered_map<string, int> m ; 

vector<int> alphabet ; 

void backTrack(string & s)
{
	for(int i = 0 ; i < s.size() ; i++)
		alphabet[s[i]-'a']++ ; 
}

bool canInclude(string & s, bool canReduse = false)
{	
	vector<int> v = alphabet ;

	for(int i = 0 ; i < s.size() ; i++)
	{
		if(v[s[i]-'a'] == 0)
			return false ; 
		v[s[i]-'a']-- ; 
	}

	if(canReduse)
		alphabet = v ; 

	return true ; 
}

int maxScoreWords(vector<string>& words, int i, vector<int> & dp)
{
	if(i == words.size())
		return 0 ; 

	if(dp[i] == -1)
	{

		if(!canInclude(words[i]))
			dp[i] = maxScoreWords(words, i+1, dp) ; 

		else
		{

			int exclude = maxScoreWords(words, i+1, dp);
			canInclude(words[i], true);
			int include = maxScoreWords(words, i+1, dp) + m[words[i]] ;
			backTrack(words[i]) ; 

			dp[i] = max(include, exclude);
		}
	}

	return dp[i] ;  
}


int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
{
	vector<int> dp(words.size()+1, -1);
	alphabet = vector<int>(26, 0);
	for(int i = 0 ; i < words.size() ; i++)
	{
		m[words[i]] = 0 ; 
		for(int j = 0 ; j < words[i].size() ; j++)
		{
			m[words[i]] += score[words[i][j]-'a'] ; 
		}
	}

	for(int i = 0 ; i < letters.size() ; i++)
		alphabet[letters[i]-'a']++ ; 
	
	return maxScoreWords(words, 0, dp); 

}