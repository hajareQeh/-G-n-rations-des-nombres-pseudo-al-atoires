/* qehoui hajare
* X(n+1)=a.x(n) mod M
*
* input  : x(0)
* output : x(1),x(2)......,x(100)
* pour voir la période
*
*cmd (sur linux) pour compiler : gcc -Wall -o code1 mlcg.c -lgmp
*cmd pour éxécuter : ./code1
*/

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>  

int main(int argc, char* argv[]){

FILE* fichier = NULL;
mpz_t    x;
int inc=0;
mpz_t  a;
mpz_t M;
mpz_t t;
mpz_t tmp;
mpz_t cmp;

mpz_init(cmp);

mpz_init(x);

mpz_init(M);    	// Initialise la variable M
mpz_add_ui( M, M, 4096);  // Place 17 dedans

mpz_init(a);    	// Initialise la variable a
mpz_add_ui(a, a, 10);  // Place 2 dedans


mpz_init(tmp);
mpz_init(t);    	// Initialise la variable t

do {
printf("donner un x( %d ) = ",inc);
gmp_scanf("%Zd", x);
}while(mpz_cmp(x,M)>=0);

fichier = fopen("test.txt", "w");
 
    if (fichier != NULL)
    {
	fprintf(fichier,"x( %d )=",inc);
	mpz_out_str(fichier,10,x);
	fprintf(fichier,"\n");
	mpz_set(cmp,x);
        
 	do{
		inc++;
		mpz_mul(tmp, a, x);
		mpz_mod(t,tmp,M);
		//mpz_clear(tmp);
        	// On l'écrit dans le fichier
        	//fprintf(fichier,"x( %d )= ",inc);
		mpz_out_str(fichier,10,t);
		//mpz_clear(x);
		mpz_set(x,t);
		//mpz_clear(t);
		fprintf(fichier,"\n");
	}while(mpz_cmp(cmp,x)!=0);

	fprintf(fichier,"la period est : %d",inc);
	
        fclose(fichier);
    
     }else
	printf("Impossible d'ouvrir le fichier test.txt");



//gmp_printf("%Zd\n", a);
system("pause" );
return 0;
}

