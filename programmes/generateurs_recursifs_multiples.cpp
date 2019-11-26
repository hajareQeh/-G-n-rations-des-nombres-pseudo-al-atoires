#include <NTL/ZZ_pXFactoring.h>
#include <NTL/ZZ_pEX.h>
#include <NTL/lzz_pE.h>
#include <NTL/vec_lzz_pE.h>
#include <NTL/vec_lzz_pE.h>
#include <NTL/ZZ.h>
#include <gmp.h>
#include <NTL/vector.h>
#include <NTL/mat_ZZ.h>
#include <NTL/ZZ_p.h>
#include <NTL/vec_ZZ.h>
using namespace std;
using namespace NTL;
/*
 * x(n)=(-a1 x(n-1) -....-ak x(n-k)) mod p
 * 
 * nb : p premier 
 * has period length p^k -1
 * 
 * input : p , k , x(0) ,...,x(k)
 * 
 * in the programme :
 * 1- générate a polynome primitive
 * 		f(x)=x^k -a1 x^(k-1)-...-ak
 * 
 */
 
 //fonction qui génére les polynomes irréductible aliatoire de degréé n et mod p
ZZ_pX irreductible_polynome(int n,long p){
	ZZ_p::init(ZZ(p)); // define GF(p)
	ZZ_pX Q;
	BuildIrred(Q, n); // generate an irreducible polynomial Q
                      // of degree n over GF(p)
	return Q;
  }
  
  //fonction  test si premitife
  /* vérifie que :
   * pour tout e entre 0 et p^n -2 : x^e mod N != 1
   * et pour e=p^n -1 on a 		 	 x^e mod N = 1
   */
ZZ_pX polynome_premitive(int n,long p){
	ZZ_p::init(ZZ(p));
	ZZ_pX x,d;
	ZZ_pX s=ZZ_pX();
	ZZ_pX N=irreductible_polynome(n,p);//génére une polynome irréductible a l'aide de la fonction présédente
	int tmp = pow(p,n) -1;
	int i=1;
	
	do{
		x=ZZ_pX();
		SetCoeff(x,i,1);//x^i
		d=x%N;			//d=x^i mod N tq N = polynome irréductible
		i++;
	}while(d !=1 && i<tmp);
	
	if(i==tmp){
		 return N;
	}else   if(i<tmp){
						return polynome_premitive(n,p);
			}else		return s;
	
}
//multiplier les coefficient par les xi,....
ZZ_p app(ZZ_pX x,int k,const Vec<ZZ_p>& tab,int n,long p){
	ZZ_p::init(ZZ(p));
	ZZ_p g,v,t;
	for(int i=k-1; i>=0; i=i-1){
			v =coeff(x,i);
			mul(t,v,tab.get(n+i-k));
			g -=t;
	}
	return g;
}

  


//chercher dans un tableau
bool chercher_tab(const Vec<ZZ>& tab,int size, ZZ nbr){
	for (int i = 0; i < size; i++)
   {
        if(tab[i] == nbr)
          return false;
   }      
	return true;
}

int main()
{
	// p c'est le modulo
	// n le degré
	long p;
	int n;
	cout << "n (degré de polynome) = " ;
	cin >> n;
	cout << "p (modulo ) = ";
	cin >> p;
	
	ZZ_p::init(ZZ(p));
	ZZ_p a; 
	long hh = pow(p,(long)n)-1;
	Vec<ZZ_p> tab;
	tab.SetLength(hh); //il vas contenire les x0,x1....
	ZZ_pX x;
	ZZ g,t;
	ZZ v;
	int f=n;
	
	for(int i=0; i<n; i=i+1){
		cout << "x"<<i<<" = ";
		cin >> a;
		tab.put(i,a);
	}
	
	cout << "la polynome premitive :" << polynome_premitive(n,p)<< "\n";
	x=polynome_premitive(n,p);
	cout << "choisiser un nombre suppérieur a  " <<n<<" afin de calculer x(votre nombre) \n ";
	int fin;
	cin >> fin;
	tab.SetLength(fin);
	do{
	tab.put(f,app(x,n,tab,f+1,p));
	f++;
	}while(f!=fin);
	cout <<"les valeur des x de x0 a x( "<<fin <<") : " << tab << "\n";
	
}
