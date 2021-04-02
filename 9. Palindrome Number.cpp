bool isPalindrome(int x) 
{
	if(x < 0)
		return false ; 

	long actual = x ; 
	long reverse = 0 ;  
	
	while(x)
	{
		reverse = (reverse * 10) + x%10 ; 
		x /= 10 ;  
	}

	return actual == reverse ; 
}