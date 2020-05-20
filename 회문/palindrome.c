#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
//2020.05.20~21 
//Palindrome which doesn't count blanks and chracters except alphabets

void check(char str[]) {
		
		int i = 0,k=0;
		char result[100] = { '0' };
		int len = strlen(str);
		int count = 0;
		int str_len = 0; //which is 1 less than real string length

		int  j = 0;
		int original_arr[100] = { 0 };
		memmove(original_arr, str, sizeof(char)*len);
//-------------------------------------------------1.Start Deleting Blanks-------------------------------------
		
		for (i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				k = i;
				j = i;

				while (str[j] == ' ')
				{
					j++;
				}

				while (str[j])
				{
					str[k] = str[j];
					str[j] = ' ';
					j++;
					k++;
				}
			}

		}

		str_len = len - 1; //string length - 1 
		 
		while (*(str + (str_len -= 1)) == ' ');  //Check blanks at the end
		for (i = 0,j=0; i<=str_len && j < len; i++, j++) 
		{
			result[j] = str[i];
		}

//-------------------------------------------------1.Finish deleting blanks-------------------------------------
//--------------------------------------------2.Start deleting characters except alphabets--------------------------
		for (i = 0; i < len; i++) {
			if (!((result[i] >= 65 && result[i] <= 90) || (result[i] >= 97 && result[i] <= 122)))
			{
				for (j = i; j < len; ++j) {
					result[j] = result[j + 1];
				}
			}
		}
//--------------------------------------------2.Finish deleting characters except alphabets---------------------------
//-------------------------------------------3.Start From capital to lower case ---------------------------------
		for (i = 0; i < len; i++)
		{
			if ((result[i] >= 65 && result[i] <= 90))
				result[i] += 32;

		}
//-------------------------------------------3.FInish From capital to lower case---------------------------------
		len = strlen(result);
		for (i = 0; i <len/2; i++) {
			
			if (result[i] != result[len - i - 1])
			{
				printf("%s is not palindrome.\n", original_arr);
				return;
			}
		}
		printf("%s is palindrome.\n", original_arr);
	
		return;
	}


int main()
{
	char str1[20] = "Madam I'm Adam.";
	char str2[70] = "Doc, note : I dissent. A fast never prevents a fatness. I diet on cod.";
	char str3[30] = "Was it a car or a cat I saw?";
	char str4[30] = "Madaam";
	check(str1);
	check(str2);
	check(str3);
	check(str4);
	getchar();
	return 0;
}