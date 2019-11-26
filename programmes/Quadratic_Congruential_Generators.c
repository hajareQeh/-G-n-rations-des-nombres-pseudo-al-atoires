
/*
 * QEHOUI hajare
 * 
*méthode : Quadratic Congruential Generators
* The transformation T is quadratic instead of linear. 
* We consider the recurrence:
* 					x(n) = (ax(n-1)^2  + bx(n−1) + c) mod m
*
*/


//x(n) = (ax(n-1)^2  + bx(n−1) + c) mod m

//input  : x(0),m,a,c,b
//output : x(1),x(2)......,x(100)....
//pour voir la période

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>  

int main(int argc, char* argv[]){

FILE* fichier = NULL;
mpz_t    x;
int inc=0;
mpz_t  a;
mpz_t  c;
mpz_t  b;
mpz_t M;
mpz_t t;
mpz_t tmp,tmp2;
mpz_t cmp;

mpz_t inv_x;

mpz_init(cmp);
mpz_init(inv_x);
mpz_init(x);
mpz_init(c);    	
mpz_init(M);    	// Initialise la variable M
mpz_init(a);    	// Initialise la variable a
mpz_init(b);
mpz_init(tmp);
mpz_init(tmp2);
mpz_init(t);    	// Initialise la variable t
printf("donner un M = ");
gmp_scanf("%Zd", M);
printf("donner un a = ");
gmp_scanf("%Zd", a);
printf("donner un c = ");
gmp_scanf("%Zd", c);
printf("donner un b = ");
gmp_scanf("%Zd", b);
do {
printf("donner un x( %d ) = ",inc);
gmp_scanf("%Zd", x);
}while(mpz_cmp(x,M)>=0);

fichier = fopen("test3surtrois.txt", "w");
 
    if (fichier != NULL)
    {
	fprintf(fichier,"x( %d )=",inc);
	mpz_out_str(fichier,10,x);
	fprintf(fichier,"\n");
	mpz_set(cmp,x);
        
 	do{
		inc++;
		mpz_mul(tmp, b, x);
		mpz_mul(tmp2, x, x);
		mpz_mul(tmp2, tmp2, a);
		mpz_add(tmp, tmp, c);
		mpz_add(tmp, tmp, tmp2);
		mpz_mod(tmp,tmp,M);
		//mpz_clear(tmp);
        	// On l'écrit dans le fichier
        	fprintf(fichier,"x( %d )= ",inc);
		mpz_out_str(fichier,10,tmp);
		//mpz_clear(x);
		mpz_set(x,tmp);
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
