/*
*qehoui hajare
*
*Générateurs congruentiels inverses
*
*méthode : the inversive congruential sequences by Eichenauer and Lehn
* 		x(n+1)=(a x(n)^(-1) +c ) mod p
* with :
* 		p : prime;
* 		x(n) in {0,1,....,p-1,inf}
* 
* NB : x^(-1) *x = 1 mod p
*
*max period length p+1
*
*/



//input  : x(0)
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
mpz_t M;
mpz_t t;
mpz_t tmp;
mpz_t cmp;

mpz_t inv_x;

mpz_init(cmp);
mpz_init(inv_x);
mpz_init(x);
mpz_init(c);    	
mpz_init(M);    	// Initialise la variable M
mpz_init(a);    	// Initialise la variable a


mpz_init(tmp);
mpz_init(t);    	// Initialise la variable t
printf("donner un M = ");
gmp_scanf("%Zd", M);
printf("donner un a = ");
gmp_scanf("%Zd", a);
printf("donner un c = ");
gmp_scanf("%Zd", c);
do {
printf("donner un x( %d ) = ",inc);
gmp_scanf("%Zd", x);
}while(mpz_cmp(x,M)>=0);

fichier = fopen("testunsurtrois.txt", "w");
 
    if (fichier != NULL)
    {
	fprintf(fichier,"x( %d )=",inc);
	mpz_out_str(fichier,10,x);
	fprintf(fichier,"\n");
	mpz_set(cmp,x);
        
 	do{
		inc++;
		if(mpz_invert(inv_x,x,M)!=0){
			
		
		
		mpz_mul(tmp, a, inv_x);
		mpz_add(tmp, tmp, c);
		mpz_mod(t,tmp,M);
		//mpz_clear(tmp);
        	// On l'écrit dans le fichier
        	fprintf(fichier,"x( %d )= ",inc);
		mpz_out_str(fichier,10,t);
		//mpz_clear(x);
		mpz_set(x,t);
		//mpz_clear(t);
		
		fprintf(fichier,"\n");
		}else{
			
		fprintf(fichier,"la period est : %d",inc);
		fclose(fichier);
		return 0;
	}
	
	}while(mpz_cmp(cmp,x)!=0);

	fprintf(fichier,"la period est : %d",inc);
	
        fclose(fichier);
    	
     }else
	printf("Impossible d'ouvrir le fichier test.txt");



//gmp_printf("%Zd\n", a);
system("pause" );
return 0;
}
