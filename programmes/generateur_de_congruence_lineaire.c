//qehoui hajare
//X(n+1)=a.x(n)+c mod M
//
//input  : x(0)
//output : x(1),x(2)......,x(...)
//pour voir la période

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>  
#include <time.h>
int main(int argc, char* argv[]){

    float temps;
    clock_t t1, t2;
 
    t1 = clock();
 
    
     
   
 

//FILE* fichier = NULL;
mpz_t    x;
mpz_t inc;
mpz_t  a;
mpz_t  c;
mpz_t M;
mpz_t t;
mpz_t tmp;
mpz_t cmp;

mpz_init(cmp);
mpz_init(inc);
mpz_init(x);

mpz_init(M);    	// Initialise la variable M
mpz_add_ui( M, M, 100000000);  // Place 10^8 dedans

mpz_init(c);    	// Initialise la variable a
mpz_add_ui( c, c, 1832);  // Place 1 dedans

mpz_init(a);    	// Initialise la variable a
mpz_add_ui(a, a, 2);  // Place 31415821 dedans


mpz_init(tmp);
mpz_init(t);    	// Initialise la variable t

do {
printf("donner un x( 0 ) = ");
gmp_scanf("%Zd", x);
}while(mpz_cmp(x,M)>=0);

//fichier = fopen("test.txt", "w");
 
    //if (fichier != NULL)
   // {
	//fprintf(fichier,"x( %d )=",inc);
	//mpz_out_str(fichier,10,x);
	//fprintf(fichier,"\n");
	mpz_set(cmp,x);
        
 	do{	 mpz_add_ui( inc, inc, 1);
		//inc++;
		mpz_mul(tmp, a, x);
		mpz_add(tmp,c,tmp);
		mpz_mod(t,tmp,M);
		//mpz_clear(tmp);
        	// On l'écrit dans le fichier
        	//fprintf(fichier,"x( %d )= ",inc);
		//mpz_out_str(fichier,10,t);
		//mpz_clear(x);
		mpz_set(x,t);
		//mpz_clear(t);
		//fprintf(fichier,"\n");
	}while(mpz_cmp(cmp,x)!=0);

	//fprintf(fichier,"la period est : %d",inc);
	
       // fclose(fichier);
    
     //}else
	//printf("Impossible d'ouvrir le fichier test.txt");

 t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("temps = %f\n", temps);

gmp_printf("la period est : %Zd\n", inc);
return 0;
}



