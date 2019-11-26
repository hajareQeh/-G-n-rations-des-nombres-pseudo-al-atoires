/*
*méthode : Explicit Inverse Congruential Generator
*This method is due to Eichermann and Herrmann. 
* It is based on the recursion:
*			x(n+1) = (a*x(n) + c)^(-1) mod m = (ax(n) + c)^(m−2) mod m
*
*
*
*/

//qehoui hajare
//x(n+1) = (a*x(n) + c)^(-1) mod m 
//
//input  : x(0),m,a,c
//output : x(1),x(2)......,x(100)....
//pour voir la période

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>  

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
float temps;
    clock_t t1, t2;
 
    t1 = clock();
fichier = fopen("test2surtrois.txt", "w");
 
    if (fichier != NULL)
    {
	fprintf(fichier,"x( %d )=",inc);
	mpz_out_str(fichier,10,x);
	fprintf(fichier,"\n");
	mpz_set(cmp,x);
        
 	do{
		inc++;
		mpz_mul(tmp, a, x);
		mpz_add(tmp, tmp, c);
		if(mpz_invert(inv_x,tmp,M)!=0){
		//mpz_clear(tmp);
        	// On l'écrit dans le fichier
        	//fprintf(fichier,"x( %d )= ",inc);
		mpz_out_str(fichier,10,inv_x);
		//mpz_clear(x);
		mpz_set(x,inv_x);
		//mpz_clear(t);
		
		fprintf(fichier,"\n");
		}else{
			fprintf(fichier,"pas d'inverse\n");
		fprintf(fichier,"la period est : %d",inc);
		fclose(fichier);
 t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
		return 0;
	}
	
	}while(mpz_cmp(cmp,x)!=0);

	fprintf(fichier,"la period est : %d",inc);
	
        fclose(fichier);
    	
     }else
	printf("Impossible d'ouvrir le fichier test.txt");

 t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);
 

//gmp_printf("%Zd\n", a);
system("pause" );
return 0;
}
