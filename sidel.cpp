#include<bits/stdc++.h>
#define ROWS 6

using namespace std;

int seidel(float A[ROWS][ROWS],float B[ROWS],float estimativa[ROWS],int n,float taxa_erro){

    float xi,dist_max,dist_rel,erro;
    
    for (int k = 0; k < n; k++){
        dist_max=0;
        for (int i = 0; i < ROWS; i++){
            xi = B[i];
            for (int j = 0; j < ROWS; j++){
                if(i != j)
                    xi -= A[i][j]*estimativa[i];
            }
            if(dist_max < abs(estimativa[i] - xi/A[i][i])){
                dist_max = abs(estimativa[i] - xi/A[i][i]);
            }
            estimativa[i] = xi/A[i][i];
        }

        dist_rel = dist_max/abs(*max_element(estimativa,estimativa+ROWS)); 
        if(taxa_erro > dist_rel){
            return k;
        }
    }
    return n;
}


int main(){

    float A[ROWS][ROWS] = {
        {13, 3, 2, 1, 0, 0}, 
        {3, 13, 3, 2, 1, 0}, 
        {2, 3, 13, 3, 2, 1}, 
        {1, 2, 3, 13, 3, 2}, 
        {0, 1, 2, 3, 13, 3}, 
        {0, 0, 1, 2, 3, 13}};
    float B[ROWS] = {1, 2, 3, 4, 5, 6};
    float estimativa[ROWS] = {0, 0, 0, 0, 0, 0};
    int n = 100;
    float taxa_erro = 0.05;   
    int iteracao;
    
    iteracao = seidel(A,B,estimativa,n,taxa_erro);
    
    cout << fixed << setprecision(6);
    cout << "Seidel convergiu com " << iteracao << " iteracoes\n";
    cout << "Estimativas :\n";
    for (int i = 0; i < ROWS; i++){
        cout << " X" << i << ": "<< estimativa[i] << "\n";
    }
    cout << "\n";

    return 0;
}