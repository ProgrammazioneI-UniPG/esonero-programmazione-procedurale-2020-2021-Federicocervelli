#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

//void encryptDecrypt(char *input, char *output, char *key) {
//	
//	
//}

int main () {
    char baseStr[128];
    printf("Inserisci la stringa da criptare: ");
    fgets(baseStr, 128, stdin);

    int choice;
    printf("Scegli:\n1 - per scegliere una chiave a richiesta (più lunga della stringa precedente ma al massimo lunga 128 caratteri):\n2 - per fare in modo che il programma scelga a caso una chiave per crittare la stringa:\n");
    scanf("%d", &choice);
    char key[128];
    char output[128];
    int i;
    if(choice == 1){

        
        printf("Inserisci la chiave desiderata: ");
        fgetc(stdin);
        fgets(key, 128, stdin);
        if (strlen(key) >= strlen(baseStr)){

            //char input[strlen(baseStr) + 1];
            //encryptDecrypt(baseStr, encrypted, key);

            

            
	        for(i = 0; i < strlen(baseStr); i++) {
		    output[i] = baseStr[i] ^ key[i];
	        }
            printf("Crittato: %s\n", output);

            for(i = 0; i < strlen(baseStr); i++) {
		    output[i] = output[i] ^ key[i];
	        }
            printf("Decrittato: %s\n", output);
            //nota a me stesso: fai una funzione per non ripetere le stesse cose

        } else {
            printf("La chiave è più piccola della stringa iniziale");
        }

        


    }   else if (choice == 2) {

        int i;
        time_t t ;
        srand ((unsigned) time(&t));
        for(i=0; i<=strlen(baseStr); i++){
            key[i] = (rand () % 128);
        }
        printf("La tua chiave random è: %s\n", key);

        for(i = 0; i < strlen(baseStr); i++) {
		output[i] = baseStr[i] ^ key[i];
	    }
        printf("Crittato: %s\n", output);

        for(i = 0; i < strlen(baseStr); i++) {
		output[i] = output[i] ^ key[i];
	    }
        printf("Decrittato: %s\n", output);

    }  else {
        printf("Invalid number");
    }



	
	/*char encrypted[strlen(baseStr)];
	encryptDecrypt(baseStr, encrypted);
	printf("Crittato:%s\n", encrypted);
	
	char decrypted[strlen(baseStr)];
	encryptDecrypt(encrypted, decrypted);
	printf("Decrittato:%s\n", decrypted);*/
}