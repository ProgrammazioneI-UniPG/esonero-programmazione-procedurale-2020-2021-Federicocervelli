#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 

int main () {
    char baseStr[128];
    printf("Inserisci la stringa da criptare, se supera i 128 caratteri verrà tagliata: ");
    fgets(baseStr, 128, stdin);    

    int scelta;
    printf("Scegli:\n1 - per scegliere una chiave a richiesta (più lunga della stringa precedente ma al massimo lunga 128 caratteri):\n2 - per fare in modo che il programma scelga a caso una chiave per crittare la stringa:\n");
    scanf("%d", &scelta);
    char key[128];
    char output[128];
    int i;
    if(scelta == 1){

        
        printf("Inserisci la chiave desiderata: ");
        fgetc(stdin);       //fgetc() ritorna EOF quindi evita che fgets() venga skippato
        fgets(key, 128, stdin);
        if (strlen(key) >= strlen(baseStr)){

	        for(i = 0; i < strlen(baseStr); i++) {
		    output[i] = baseStr[i] ^ key[i];
	        }
            printf("Crittato: %s\n", output);

            for(i = 0; i < strlen(baseStr); i++) {
		    output[i] = output[i] ^ key[i];
	        }
            printf("Decrittato: %s\n", output);

        } else {
            printf("La chiave è più piccola della stringa iniziale");
        }
    }   else if (scelta == 2) {
        
        int i;
        time_t t ;
        srand ((unsigned) time(&t));
        for(i=0; i<=strlen(baseStr); i++){      //generazione chiave random
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
}