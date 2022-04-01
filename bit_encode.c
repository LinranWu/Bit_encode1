/*BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE STRICTLY ADHERED TO THE TENURES OF THE OHIO STATE UNIVERSITY’S ACADEMIC INTEGRITY POLICY WITH RESPECT TO THIS ASSIGNMENT. */
/*student name: Linran Wu*/

#include <stdio.h>
/*function prototype*/
char create_key();
unsigned char rotate_right(unsigned char);
unsigned char rotate_left(unsigned char);
unsigned int get_string(unsigned char* d_ptr);
int formattedprint(unsigned char* d_ptr, unsigned int length);
int cipher(unsigned char* d_ptr, unsigned int key, unsigned int length);

int main()
{
	/*This program works as an elementary level bit stream cipher that is an encryption algorithm that encrypts 1 byte of plain text at a time.*/
	/*student name: Linran*/
	unsigned char text[201];	/*this is where to store the text string*/
	unsigned int key,length;
	/*get input value of text and put its length to variable length*/	
	length = get_string(text);
	/*print what was the input from keyboard and its hex value*/
	#ifdef PROMPT
	printf("\n%s\n\nhex encoding:",text);
	formattedprint(text,length);
	#endif
	/*create key from 4-digit of key input*/
	key = create_key();
	/*cipher the char array as desired*/
	cipher(text,key,length);
	/*print the hex value of ciphered char array*/
	#ifdef PROMPT
	printf("\nhex cipthertext: ");
	#endif
	formattedprint(text,length);
	return 0;
}

/*passed a character array, cipher the character array using xor that value with a keyy and proper rotaion*/
int cipher(unsigned char* d_ptr, unsigned int key,unsigned int length)
{
	int i=0; /*counter*/
	for(;i<length;i++)	/*cipher each char in the char array*/
	{
		*(d_ptr+i) = *(d_ptr+i) ^ key;
		/*rotate left odd # of values and rotate right even # of values*/
		if((i % 2) == 0)
		{
			*(d_ptr+i)=rotate_left(*(d_ptr+i));
		}else
		{
			*(d_ptr+i)=rotate_right(*(d_ptr+i));
		}
		
	}
	return 0;
}

/*passed a single hexadecimal value and return to the calling function that value rotated 1 position right*/
unsigned char rotate_right(unsigned char c)
{
	const unsigned char first_digit = 128;
	unsigned char result;
	if ((c % 2) == 0)	/*if end with 0, just shift right*/
	{
		result = c >> 1;
	} else		/*if end with 1, shift to top*/
	{
		result = c >> 1;
		result = result | first_digit;
	}
	return result;
}

/*passed a single hexadecimal value and return to the calling function that value rotated 1 position left*/
unsigned char rotate_left(unsigned char c)
{

	const unsigned char eight_digit = 255;
	const unsigned char last_digit = 1;
	unsigned char result;
	if (c >= 0x80)		/* if starts with 1, append 1*/
	{
		result = c << 1;
		result = result | last_digit;
		result = result & eight_digit;
	} else		/*if starts with 0, just shift*/
	{
		result = c << 1;
	}
	return result;
}

/*given a character array, print it on the screen in its hexdecimal value with the format of ten value per trow*/
int formattedprint(unsigned char* d_ptr,unsigned int length)
{
	int i=0;		/*counter*/
	do	/*print an array of characters with formatted spacing*/
	{	/*print 10 values then column*/
		#ifdef PROMPT
		if((i % 10) == 0)
		{
			printf("\n\n\t");
		}
		#endif
		printf("%02x ",*(d_ptr+i));
		i++;
	}while(i<length);
	printf("\n");
	return 0;
}

/* read in the 4 digits of the key and return the 8-bit key*/
char create_key()
{	
	char c;		/*character from getchar*/
	unsigned int key = 0;
	unsigned int temp = 0;
	int i = 3;
	const unsigned char one = 1;
	#ifdef PROMPT
	printf("\nenter 4-bit key: ");		/*prompt to enter 4-bit key*/
	#endif
	while(i >= 0)		/*convert the 4 entering char to desired binary integer */
	{
		key = key << 1;
		if((c=getchar()) == '1')
		{
			key = key | one;
		}	
		i--;
	}
	temp = temp | key;		/*convert 4-bit key to 8bit key*/
	key = key << 4;
	key = key | temp;
	return key;

}

/*passed a single depointer of a character array, read in value from keyboard and put in the array, and return the length of the string*/
unsigned int get_string(unsigned char* d_ptr)
{
	int c,i = 0;	/*c being charactor got from getchar, i is a counter*/
	#ifdef PROMPT
	printf("\nenter cleartext: ");		/*prompt to enter text*/
	#endif
	while((c=getchar()) != '\n')		/*store each char to the char array*/
	{
		*(d_ptr+i++) = c;
	}
	*(d_ptr+i)='\0';		/*terminate the string*/
	return i;
}

