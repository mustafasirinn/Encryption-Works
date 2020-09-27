#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    	if(argc !=2 ){
        	printf("Usage: ./caesar key\n");
        	return 1;
    	}
    	for(int i=0, n=strlen(argv[1]);i<n;i++){
    		if(isdigit(argv[1][i])==0){
    			printf("Usage: ./caesar key\n");
    			return 1;
    		}
    	}

    	int key = atoi(argv[1]);
	string text = get_string("plaintext: ");

	for(int i=0, n=strlen(text); i<n; i++){
        	if(text[i]>=65 && text[i]<=90){
            		text[i] -= 65;
            		text[i] = (text[i] + key)%26 + 65;
        	}
        	if (text[i]>=97 && text[i]<=122){
            		text[i] -= 97;
            		text[i] = (text[i] + key)%26 + 97;
        	}    
	}

    	printf("ciphertext: %s\n",text);
    	return 0;  
}

