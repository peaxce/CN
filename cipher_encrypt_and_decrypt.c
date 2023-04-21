#include<stdio.h>
#include<ctype.h>
int main()
{
  char text[500], ch, text1[500],ch1;
  int key,i;
  printf("Enter a message to encrypt: ");
  scanf("%s", text);
  printf("Enter the key: ");
  scanf("%d", & key);
//Encryption of input
  for (i = 0; text[i] != '\0'; ++i) 
  {
    ch = text[i];
	if (isalnum(ch)){	
	
	    if (islower(ch)) 
		{
	    	ch = (ch - 'a'  + key) % 26 + 'a' ;
	    }
	    else if (isupper(ch)) 
		{
	        ch = (ch - 'A' + key) % 26+ 'A';
	    }
	    else if (isdigit(ch))
	    {
	    	ch = (ch - '0'+key)% 10 + '0';
		}
	    else 
		{
	      printf("Invalid Message");
	    }
	}
    text[i] = ch;
  }
  printf("Encrypted message: %s\n", text);
  //Decryption of input
  for (i = 0; text[i] != '\0'; ++i) 
  {
    ch1 = text[i];
	if (isalnum(ch)){	
	
	    if (islower(ch1)) 
		{
	    	ch1 = (ch1 - 'a'  + (26-key)) % 26 + 'a' ;
	    }
	    else if (isupper(ch1)) 
		{
	        ch1 = (ch1 - 'A' + (26-key)) % 26+ 'A';
	    }
	    else if (isdigit(ch1))
	    {
	    	ch1 = (ch1 - '0'+(10-key))% 10 + '0';
		}
	    else 
		{
	      printf("Invalid Message");
	    }
	}
    text1[i] = ch1;
  }
  printf("Decrypted message: %s", text1); 
   
  return 0;
}

