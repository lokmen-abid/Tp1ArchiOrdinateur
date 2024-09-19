/*
    Lokmen Abid CODE PERMANENT UQTR : ABIL19339900
    Haithem Sissaoui CODE PERMANENT UQTR : SISH27359900
    Ahmed derouiche CODE PERMANENT UQTR : DERA64310200

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>



/*
 * Fonction : additionSINT Cette fonction effectue la somme de deux nombres entiers signés sur 16 bits.
 *            Elle permet de détecter les cas de débordements positifs et négatifs.
 * 2 Paramètres d'entrée :
 *    n1 (short int) Premier nombre entier signé de 16 bits.
 *    n2 (short int) Deuxième nombre entier signé de 16 bits.
 * Paramètres en sortie : Aucun (void)
 * Type de passage : Par valeur pour n1 et n2.
 * Cette fonction demande à l'utilisateur de fournir deux nombres entiers signés, puis les additionne.
 * le résultat de la somme et indique s'il y a un débordement positif ou négatif.
 */

void additionSINT(){
    short int n1,n2,Somme;
    printf("donner une valeur de n1: \n");
    scanf("%hd",&n1);
    printf("donner une valeur de n2: \n");
    scanf("%hd",&n2);

    Somme=n1+n2;

    if(n1>0 && n2>0 && Somme<0){
        printf("c'est le cas de debordement positif \n");
        printf(" le réesultat de somme est invalide : %hd \n",Somme);
    }
    else if (n1<0 && n2<0 && Somme>=0){
        printf("c'est le cas de debordement negatif\n");
        printf(" le réesultat de somme est invalide : %hd\n",Somme);
    }
    else
        printf(" Le resultat est valide :%hd \n",Somme);


}

/*
 * Fonction : epsilonf Cette fonction évalue l'epsilon de l'architecture INTEL pour la représentation réelle simple précision (float).
 *            Elle affiche la valeur de l'epsilon ainsi que le nombre de chiffres binaires significatifs de la partie fractionnaire.
 * Paramètres en entrée : Aucun
 * Paramètres en sortie : Aucun
 * Type de passage : Aucun
 * Cette fonction utilise l'algorithme présenté dans les notes de cours pour calculer l'epsilon
 * et détermine le nombre de chiffres binaires significatifs de la partie fractionnaire.
 */

void epsilon_f() {
    float epsilon = 1.0;
    int dg_binary = 0;
    float plusEps = 1+epsilon;

    while (plusEps>1) {
        epsilon /= 2.0;
        plusEps=1+epsilon;
        dg_binary++;
    }

    epsilon=epsilon*2;
    dg_binary=dg_binary-1;

    printf("\n Epsilon pour la représentation réelle simple précision (SP) : %e\n", epsilon);
    printf("\n Nombre de chiffres binaires significatifs pour SP : %d\n", dg_binary);
}

/*
    on'a utiliser la bibliothèque limits.h pour avoir le résultat d'epsilon
*/

float epsilonf(){
    float epsilon = FLT_EPSILON;
    int dg_binaire=FLT_MANT_DIG;
    printf("la valeur d'epsilon est : %e\n",epsilon);
    printf("la valeur digits binaires est : %d\n",dg_binaire);

}

/*
 * Fonction : epsilond Cette fonction évalue l'epsilon de l'architecture INTEL pour la représentation double précision (double).
 *            Elle affiche la valeur de l'epsilon ainsi que le nombre de chiffres binaires significatifs de la partie fractionnaire.
 * Paramètres en entrée : Aucun
 * Paramètres en sortie : Aucun
 * Type de passage : Aucun
 * Cette fonction utilise l'algorithme présenté dans les notes de cours pour calculer l'epsilon
 * et détermine le nombre de chiffres binaires significatifs de la partie fractionnaire.
 */


void epsilon_d() {
    double epsilon = 1.0;
    int dg_binary = 0;
    double plusEps = 1+epsilon;

     while (plusEps>1) {
        epsilon /= 2.0;
        plusEps=1+epsilon;
        dg_binary++;
    }

    epsilon=epsilon*2;
    dg_binary=dg_binary-1;

    printf("Epsilon pour la représentation réelle double précision (DP) : %e\n", epsilon);
    printf("Nombre de chiffres binaires significatifs pour DP : %d\n", dg_binary);
}

double epsilond(){
    double epsilon = DBL_EPSILON;
    int dg_binaire=DBL_MANT_DIG;
    printf("la valeur d'epsilon est : %e\n",epsilon);
    printf("la valeur digits binaires est : %d\n",dg_binaire);

}



float max_float(){
    float max = FLT_MAX;
    printf("la valeur maximale : %e\n",max);
}

double max_double(){
    double max = DBL_MAX;
    printf("la valeur maximale : %e\n",max);
}

/*
 * Fonction : somme_f Cette fonction calcule la sommation successive de 1/n pour n itérations
 *            en utilisant des nombres réels simple précision (float).
 *            Elle affiche la valeur de n, le résultat de la sommation ainsi que l'erreur de calcul.
 * Paramètres en entrée : n (int) nombre d'itérations pour la sommation.
 * Paramètres en sortie : somme_float
 * Type de passage :Par valeur pour n.
 * Cette fonction demande à l'utilisateur de fournir le nombre d'itérations (n), puis elle effectue
 * la sommation successive de 1/n en utilisant des nombres réels simple précision (float).
 * Elle affiche ensuite la valeur de n, le résultat de la sommation et l'erreur de calcul.
 */

float Somme_f(int n){
    float somme_float=0.0;
    float saut = 1.0/n;
    int i;
    for (i=1;i<=n;i++){
        somme_float+=saut;
    }
    printf("Erruer : %f \n",1-somme_float);
    return somme_float;
}

/*
 * Fonction : somme_d  Cette fonction calcule la sommation successive de 1/n pour n itérations en utilisant des nombres réels double précision (double).
 *               Elle affiche la valeur de n, le résultat de la sommation ainsi que l'erreur de calcul.
 * Paramètres en entrée : n (int) nombre d'itérations pour la sommation.
 * Paramètres en sortie : somme_double
 * Type de passage :Par valeur pour n.
 * Cette fonction demande à l'utilisateur de fournir le nombre d'itérations (n), puis elle effectue
 * la sommation successive de 1/n en utilisant des nombres réels double précision (double).
 * Elle affiche ensuite la valeur de n, le résultat de la sommation et l'erreur de calcul.
 */

double Somme_d(int n){
    double somme_double=0.0;
    double saut = 1.0/n;
    int i;
    for (i=1;i<=n;i++){
        somme_double+=saut;
    }
    printf("Erruer : %f \n",1-somme_double);
    return somme_double;
}

/*
 * Fonction : somme_Ascf( somme_Dscf) Cette fonction calcule la sommation ascendante(desdescendante ) de la suite (1/in) pour
 *             i allant de 1 à 32767 (de 32767 jusqu'à 1 ) en utilisant des nombres réels simple précision (float) pour chaque valeur
 *             d'exposant n = 1, 2, 3 . Elle affiche la valeur de n et le résultat de la sommation.
 * Paramètres en entrée : Aucun
 * Paramètres en sortie : somme
 * Cette fonction utilise l'algorithme de sommation ascendante (desdescendante pour la fonction Dscf) et calcule la somme de la suite (1/in)
 * pour i allant de 1 à 32767, pour chaque valeur d'exposant n = 1, 2, 3 en utilisant des nombres réels simple précision (float).
 * Elle affiche ensuite la valeur de n et le résultat de la sommation.
 */

float somme_Ascf(int n){
    float somme=0.0;
    int i ;
    for (i=1;i<=32767;i++){
        somme+=1.0/(pow(i,n));
    }
    return somme;
}

float somme_Dscf(int n){
    float somme=0.0;
    int i ;
    for (i=32767;i>0;i--){
        somme+=1.0/(pow(i,n));
    }
    return somme;

}

/*
 * Fonction : somme_Ascd( somme_Dscd) Cette fonction calcule la sommation ascendante(desdescendante ) de la suite (1/in) pour
 *             i allant de 1 à 32767 (de 32767 jusqu'à 1 ) en utilisant des nombres réels simple précision (double) pour chaque valeur
 *             d'exposant n = 1, 2, 3 . Elle affiche la valeur de n et le résultat de la sommation.
 * Paramètres en entrée : Aucun
 * Paramètres en sortie : somme
 * Cette fonction utilise l'algorithme de sommation ascendante (desdescendante pour la fonction Dscd) et calcule la somme de la suite (1/in)
 * pour i allant de 1 à 32767, pour chaque valeur d'exposant n = 1, 2, 3 en utilisant des nombres réels simple précision (double).
 * Elle affiche ensuite la valeur de n et le résultat de la sommation.
 */


double somme_Ascd(int n){
    double somme=0.0;
    int i ;
    for (i=1;i<=32767;i++){
        somme+=1.0/(pow(i,n));
    }
    return somme;
}

double somme_Dscd(int n){
    double somme=0.0;
    int i ;
    for (i=32767;i>0;i--){
        somme+=1.0/(pow(i,n));
    }
    return somme;
}

/*
    La Fonction main ()
*/


int main()
{
    /* Deux variables, X et Y, de type (int).
    Nous effectuons des validations sur ces deux valeurs, ensuite*/
    int N,X;
    //On a effectué l'appel de la fonction additionSINT()
    additionSINT();
    //On a effectué l'appel de la fonction epsilon_f()
    epsilon_f();
    printf("\n");
    epsilonf();
    printf("\n");
    //On a effectué l'appel de la fonction epsilon_d()
    epsilond();
    printf("\n");
    epsilon_d();
    printf("\n");
    max_float();
    printf("\n");
    max_double();
    /*
        Nous avons utilisé une boucle do-while pour vérifier la valeur de N.
    */
    do {
        printf("donne une Valeur N: \n");
        scanf("%d",&N);
    }while(!( N==100 || N==1000 || N==10000));
    float res_f= Somme_f(N);
    printf("Resultat de la sommation float : %f\n", res_f);
    printf("\n");
    double res_d=Somme_d(N);
    printf("Resultat de la sommation double : %lf\n", res_d);
    /*
        Nous avons utilisé une boucle do-while pour vérifier la valeur de X.
    */
    do {
        printf("donne une Valeur X: \n");
        scanf("%d",&X);
    }while(!(X==1||X==2|X==3));
    /*
        on fait l'éxecution de 4 fonctions de somme
    */
    printf("\n");
    printf("le résultat de la somme ascendante de type float : %f ",somme_Ascf(X));
    printf("\n");
    printf("le résultat de la somme descendante de type float : %f ",somme_Ascd(X));
    printf("\n");
    printf("le résultat de la somme ascendante de type double : %f ",somme_Dscf(X));
    printf("\n");
    printf("le résultat de la somme descendante de type double  : %f ",somme_Dscd(X));


    return 0;
}
