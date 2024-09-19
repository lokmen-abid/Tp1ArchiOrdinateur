/*
    Lokmen Abid CODE PERMANENT UQTR : ABIL1933****
    Haithem Sissaoui CODE PERMANENT UQTR : SISH2735****
    Ahmed derouiche CODE PERMANENT UQTR : DERA6431****

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>



/*
 * Fonction : additionSINT Cette fonction effectue la somme de deux nombres entiers sign�s sur 16 bits.
 *            Elle permet de d�tecter les cas de d�bordements positifs et n�gatifs.
 * 2 Param�tres d'entr�e :
 *    n1 (short int) Premier nombre entier sign� de 16 bits.
 *    n2 (short int) Deuxi�me nombre entier sign� de 16 bits.
 * Param�tres en sortie : Aucun (void)
 * Type de passage : Par valeur pour n1 et n2.
 * Cette fonction demande � l'utilisateur de fournir deux nombres entiers sign�s, puis les additionne.
 * le r�sultat de la somme et indique s'il y a un d�bordement positif ou n�gatif.
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
        printf(" le r�esultat de somme est invalide : %hd \n",Somme);
    }
    else if (n1<0 && n2<0 && Somme>=0){
        printf("c'est le cas de debordement negatif\n");
        printf(" le r�esultat de somme est invalide : %hd\n",Somme);
    }
    else
        printf(" Le resultat est valide :%hd \n",Somme);


}

/*
 * Fonction : epsilonf Cette fonction �value l'epsilon de l'architecture INTEL pour la repr�sentation r�elle simple pr�cision (float).
 *            Elle affiche la valeur de l'epsilon ainsi que le nombre de chiffres binaires significatifs de la partie fractionnaire.
 * Param�tres en entr�e : Aucun
 * Param�tres en sortie : Aucun
 * Type de passage : Aucun
 * Cette fonction utilise l'algorithme pr�sent� dans les notes de cours pour calculer l'epsilon
 * et d�termine le nombre de chiffres binaires significatifs de la partie fractionnaire.
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

    printf("\n Epsilon pour la repr�sentation r�elle simple pr�cision (SP) : %e\n", epsilon);
    printf("\n Nombre de chiffres binaires significatifs pour SP : %d\n", dg_binary);
}

/*
    on'a utiliser la biblioth�que limits.h pour avoir le r�sultat d'epsilon
*/

float epsilonf(){
    float epsilon = FLT_EPSILON;
    int dg_binaire=FLT_MANT_DIG;
    printf("la valeur d'epsilon est : %e\n",epsilon);
    printf("la valeur digits binaires est : %d\n",dg_binaire);

}

/*
 * Fonction : epsilond Cette fonction �value l'epsilon de l'architecture INTEL pour la repr�sentation double pr�cision (double).
 *            Elle affiche la valeur de l'epsilon ainsi que le nombre de chiffres binaires significatifs de la partie fractionnaire.
 * Param�tres en entr�e : Aucun
 * Param�tres en sortie : Aucun
 * Type de passage : Aucun
 * Cette fonction utilise l'algorithme pr�sent� dans les notes de cours pour calculer l'epsilon
 * et d�termine le nombre de chiffres binaires significatifs de la partie fractionnaire.
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

    printf("Epsilon pour la repr�sentation r�elle double pr�cision (DP) : %e\n", epsilon);
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
 * Fonction : somme_f Cette fonction calcule la sommation successive de 1/n pour n it�rations
 *            en utilisant des nombres r�els simple pr�cision (float).
 *            Elle affiche la valeur de n, le r�sultat de la sommation ainsi que l'erreur de calcul.
 * Param�tres en entr�e : n (int) nombre d'it�rations pour la sommation.
 * Param�tres en sortie : somme_float
 * Type de passage :Par valeur pour n.
 * Cette fonction demande � l'utilisateur de fournir le nombre d'it�rations (n), puis elle effectue
 * la sommation successive de 1/n en utilisant des nombres r�els simple pr�cision (float).
 * Elle affiche ensuite la valeur de n, le r�sultat de la sommation et l'erreur de calcul.
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
 * Fonction : somme_d  Cette fonction calcule la sommation successive de 1/n pour n it�rations en utilisant des nombres r�els double pr�cision (double).
 *               Elle affiche la valeur de n, le r�sultat de la sommation ainsi que l'erreur de calcul.
 * Param�tres en entr�e : n (int) nombre d'it�rations pour la sommation.
 * Param�tres en sortie : somme_double
 * Type de passage :Par valeur pour n.
 * Cette fonction demande � l'utilisateur de fournir le nombre d'it�rations (n), puis elle effectue
 * la sommation successive de 1/n en utilisant des nombres r�els double pr�cision (double).
 * Elle affiche ensuite la valeur de n, le r�sultat de la sommation et l'erreur de calcul.
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
 *             i allant de 1 � 32767 (de 32767 jusqu'� 1 ) en utilisant des nombres r�els simple pr�cision (float) pour chaque valeur
 *             d'exposant n = 1, 2, 3 . Elle affiche la valeur de n et le r�sultat de la sommation.
 * Param�tres en entr�e : Aucun
 * Param�tres en sortie : somme
 * Cette fonction utilise l'algorithme de sommation ascendante (desdescendante pour la fonction Dscf) et calcule la somme de la suite (1/in)
 * pour i allant de 1 � 32767, pour chaque valeur d'exposant n = 1, 2, 3 en utilisant des nombres r�els simple pr�cision (float).
 * Elle affiche ensuite la valeur de n et le r�sultat de la sommation.
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
 *             i allant de 1 � 32767 (de 32767 jusqu'� 1 ) en utilisant des nombres r�els simple pr�cision (double) pour chaque valeur
 *             d'exposant n = 1, 2, 3 . Elle affiche la valeur de n et le r�sultat de la sommation.
 * Param�tres en entr�e : Aucun
 * Param�tres en sortie : somme
 * Cette fonction utilise l'algorithme de sommation ascendante (desdescendante pour la fonction Dscd) et calcule la somme de la suite (1/in)
 * pour i allant de 1 � 32767, pour chaque valeur d'exposant n = 1, 2, 3 en utilisant des nombres r�els simple pr�cision (double).
 * Elle affiche ensuite la valeur de n et le r�sultat de la sommation.
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
    //On a effectu� l'appel de la fonction additionSINT()
    additionSINT();
    //On a effectu� l'appel de la fonction epsilon_f()
    epsilon_f();
    printf("\n");
    epsilonf();
    printf("\n");
    //On a effectu� l'appel de la fonction epsilon_d()
    epsilond();
    printf("\n");
    epsilon_d();
    printf("\n");
    max_float();
    printf("\n");
    max_double();
    /*
        Nous avons utilis� une boucle do-while pour v�rifier la valeur de N.
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
        Nous avons utilis� une boucle do-while pour v�rifier la valeur de X.
    */
    do {
        printf("donne une Valeur X: \n");
        scanf("%d",&X);
    }while(!(X==1||X==2|X==3));
    /*
        on fait l'�xecution de 4 fonctions de somme
    */
    printf("\n");
    printf("le r�sultat de la somme ascendante de type float : %f ",somme_Ascf(X));
    printf("\n");
    printf("le r�sultat de la somme descendante de type float : %f ",somme_Ascd(X));
    printf("\n");
    printf("le r�sultat de la somme ascendante de type double : %f ",somme_Dscf(X));
    printf("\n");
    printf("le r�sultat de la somme descendante de type double  : %f ",somme_Dscd(X));


    return 0;
}
