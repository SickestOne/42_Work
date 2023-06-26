#include <stdio.h>
/*The to_lower function is a helper function that converts an uppercase character c to its lowercase equivalent. 
 It uses ASCII arithmetic to achieve this by adding the difference between lowercase 'a' and uppercase 'A' to the uppercase character.*/

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	return (c);
}


/*The get_digit function is another helper function used to get the numeric value of a character c in a given base digits_in_base. 
 It first determines the maximum valid character for the given base (max_digit). If the base is less than or equal to 10, 
 it calculates the maximum digit by adding the base to the ASCII value of '0'. 
 If the base is greater than 10, it calculates the maximum digit by subtracting 10 from the base and adding it to the ASCII value of 'a'.

The function then checks if the character c falls within the valid range for digits in the given base. 
If c is a digit character ('0' to '9') and it is less than or equal to the maximum valid digit, it returns the numeric value of the digit by subtracting the ASCII value of '0'. If c is a lowercase letter ('a' to 'f') and it is less than or equal to the maximum valid digit, it returns the numeric value of the letter by subtracting the ASCII value of 'a' and adding 10. If c is not a valid digit in the given base, it returns -1.*/

int get_digit(char c, int digits_in_base)
{
	int max_digit;
	if (digits_in_base <= 10)
		max_digit = digits_in_base + '0';
	else
		max_digit = digits_in_base - 10 + 'a';

	if (c >= '0' && c <= '9' && c <= max_digit)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && c <= max_digit)
		return (10 + c - 'a');
	else
		return (-1);
}

/*If the first character of the string is '-', it sets sign to -1 to indicate a negative number and 
advances the pointer str to the next character.
The function then enters a loop that continues until a non-digit character or 
an invalid character for the given base is encountered. 

Within the loop, it calls to_lower to convert the current character to lowercase and passes it, 
along with str_base, to get_digit to get the numeric value of the character.

If the returned digit value is valid (not -1), it updates the result by multiplying it by the base and adding the current digit value multiplied by the sign. 
It then advances the str pointer to the next character.
Once the loop ends, the function returns the final calculated result, which represents the converted integer value.*/

int ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int digit;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
	{
		result = result * str_base;
		result = result + (digit * sign);
		++str;
	}
	return (result);
}
