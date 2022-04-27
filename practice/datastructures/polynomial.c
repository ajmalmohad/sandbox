#include <stdio.h>

struct Term{
    int coefficient;
    int exponent;
};

int main(){
    int n1,n2;
    printf("Enter Number of terms in First Polynomial: ");
    scanf("%d",&n1);
    struct Term pol1[n1];
    printf("Enter terms of First Polynomial in descending order of exponents:\n");
    for (int i = 0; i < n1; i++){
        printf("Enter Coefficient and Exponent of Term %d : ", i+1);
        scanf("%d", &pol1[i].coefficient);
        scanf("%d", &pol1[i].exponent);
    }

    printf("First Polynomial :");
    for (int i = 0; i < n1; i++){
        printf(" %dx^%d ", pol1[i].coefficient, pol1[i].exponent);        
        if(i!=n1-1) printf("+");
    }

    printf("\nEnter Number of terms in Second Polynomial: ");
    scanf("%d",&n2);
    struct Term pol2[n2];
    printf("Enter terms of Second Polynomial in descending order of exponents:\n");
    for (int i = 0; i < n2; i++){
        printf("Enter Coefficient and Exponent of Term %d : ", i+1);
        scanf("%d", &pol2[i].coefficient);
        scanf("%d", &pol2[i].exponent);
    }

    printf("Second Polynomial :");
    for (int i = 0; i < n2; i++){
        printf(" %dx^%d ", pol2[i].coefficient, pol2[i].exponent);        
        if(i!=n2-1) printf("+");
    }

    printf("\nAdding Two Polynomials :");
    struct Term pol3[n1+n2];
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(pol1[i].exponent > pol2[j].exponent){
            pol3[k].exponent = pol1[i].exponent;
            pol3[k].coefficient = pol1[i].coefficient;
            i++; k++;
        }else if(pol1[i].exponent < pol2[j].exponent){
            pol3[k].exponent = pol2[j].exponent;
            pol3[k].coefficient = pol2[j].coefficient;
            j++; k++;
        }else{
            pol3[k].exponent = pol1[i].exponent;
            pol3[k].coefficient = pol1[i].coefficient + pol2[j].coefficient;
            i++; j++; k++;
        }
    }

    while(i<n1){
        pol3[k].exponent = pol1[i].exponent;
        pol3[k].coefficient = pol1[i].coefficient;
        i++; k++;
    }

    while (j<n2){
        pol3[k].exponent = pol2[j].exponent;
        pol3[k].coefficient = pol2[j].coefficient;
        j++; k++;
    }

    for (int i = 0; i < k; i++){
        printf(" %dx^%d ", pol3[i].coefficient, pol3[i].exponent);        
        if(i!=k-1) printf("+");
    }
    
    
}