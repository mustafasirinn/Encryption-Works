#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    if(argc !=2 ){
        printf("Usage: ./caesar keyword\n");
        return 1;
    }
    for(int i=0, n=strlen(argv[1]);i<n;i++){
        if(isalpha(argv[1][i])==0){
            printf("Usage: ./caesar keyword\n");
            return 1;
        }
    }

    int m=strlen(argv[1]);
    string text = get_string("Plaintext: ");
    int n=strlen(text);
    int key[n], j=0;

    for(int i=0; i<n ; i++){
        if(text[i]!=' '){
            key[i] = shift(argv[1][j%m]);
            j++;
        }
        else
            key[i] = 0;
    }
    

    for(int i=0; i<n; i++){
        if(text[i]>=65 && text[i]<=90){
            text[i] -= 65;
            text[i] = (text[i] + key[i])%26 + 65;
        }
        if (text[i]>=97 && text[i]<=122){
            text[i] -= 97;
            text[i] = (text[i] + key[i])%26 + 97;
        }           
    }
    printf("ciphertext: %s\n",text);

    return 0;  
}

int shift(char c){
    if((int)c>=65 && (int)c<=90)
        return (int)c-65;
    else
        return (int)c-97;
}