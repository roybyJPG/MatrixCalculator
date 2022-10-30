#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void menu();
void leerMatriz(int **M, int fil, int col);
void imprimirMatriz(int **M, int fil, int col);
void sumaMatrices();
void restaMatrices();
void multiplicacionMatrices();
void matrizTranspuesta();

void sumaMatriz_Aleatoria(int fil, int col);
void restaMatriz_Aleatoria(int fil, int col);
void byMatriz_Aleatoria(int filA, int colA, int filB, int colB);
void transMatriz_Aleatoria(int fil, int col);

//=======================================================================//

void menu()
{

    cout << "\n         CALCULADORA DE MATRICES"
         << "\n============================================"
         << "\n1.- Suma de Matrices ................... (1)"
         << "\n2.- Resta de Matrices .................. (2)"
         << "\n3.- Multiplicacion de Matrices ......... (3)"
         << "\n4.- Matriz Transpuesta ................. (4)"
         << "\n5.- Terminar ........................... (5)"
         << "\n============================================"
         << "\nSELECCIONA UNA OPCION: ";

}

int main()
{
    int opcion;

    do{
        menu();
        cin>>opcion;
        if(cin.fail() || cin.bad()){
            opcion = 0;
            cin.clear();
            cin.ignore('\n', 80);
        }

            switch(opcion){
                case 1:
                    sumaMatrices();
                    break;

                case 2:
                    restaMatrices();
                    break;

                case 3:
                    multiplicacionMatrices();
                    break;

                case 4:
                    matrizTranspuesta();
                    break;

                case 5:
                    cout<<"\n\nFIN DEL PROGRAMA\n\n";
                    exit(0);
                    break;

                default:
                    cout<<"\n\nOPCION NO VALIDA\n\n";
                    break;
        }
    }while(opcion != 5);
}

void leerMatriz(int **M, int fil, int col)
{
        cout<<"\nRellenar la matriz:\n";
        for(int i = 0; i < fil; i++){
            for(int j = 0; j < col; j++){
                cout<<"Matriz["<<i<<"]["<<j<<"]: ";
                cin>>M[i][j];
            }
        }
}

void sumaMatrices()
{
    int fil, col;

    cout<<"\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
        <<"\nDimension de la matriz:";
    cout<<"\nFilas de la matriz: ";
    cin>>fil;
    cout<<"Columnas de la matriz: ";
    cin>>col;
    cout<<endl;

    if(fil<=4 && col<=4){

        int** A = new int*[fil];
        for(int i=0; i<fil; i++)
            A[i] = new int[col];

        int** B = new int*[fil];
        for(int i=0; i<fil; i++)
            B[i] = new int[col];

        int** C = new int*[fil];
        for(int i=0; i<fil; i++)
            C[i] = new int[col];

        cout<<"\nDatos de la matriz A: ";
        leerMatriz(A, fil, col);

        cout<<"\nDatos de la matriz B: ";
        leerMatriz(B, fil, col);

        for(int i=0; i<fil; i++)
            for(int j=0; j<col; j++)
                C[i][j] = A[i][j] + B[i][j];

        cout<<"\nMatriz A:\n";
        imprimirMatriz(A, fil, col);
        cout<<"\nMatriz B:\n";
        imprimirMatriz(B, fil, col);
        cout<<"\nSuma de las matrices (A+B):\n";
        imprimirMatriz(C, fil, col);

    } else{
        sumaMatriz_Aleatoria(fil, col);
    }
}

void restaMatrices()
{
    int fil, col;

    cout<<"\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
        <<"\nDimension de la matriz:";
    cout<<"\nFilas de la matriz: ";
    cin>>fil;
    cout<<"Columnas de la matriz: ";
    cin>>col;
    cout<<endl;

    if(fil<=4 && col<=4){

        int** A = new int*[fil];
        for(int i=0; i<fil; i++)
            A[i] = new int[col];

        int** B = new int*[fil];
        for(int i=0; i<fil; i++)
            B[i] = new int[col];

        int** C = new int*[fil];
        for(int i=0; i<fil; i++)
            C[i] = new int[col];

        cout<<"\nDatos de la matriz A: ";
        leerMatriz(A, fil, col);

        cout<<"\nDatos de la matriz B: ";
        leerMatriz(B, fil, col);

        for(int i=0; i<fil; i++)
            for(int j=0; j<col; j++)
                C[i][j] = A[i][j] - B[i][j];

        cout<<"\nMatriz A:\n";
        imprimirMatriz(A, fil, col);
        cout<<"\nMatriz B:\n";
        imprimirMatriz(B, fil, col);
        cout<<"\nResta de las matrices (A-B):\n";
        imprimirMatriz(C, fil, col);

    } else{
        restaMatriz_Aleatoria(fil, col);
    }
}

void multiplicacionMatrices()
{
    int filA, colA, filB, colB;

    cout<<"\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
        <<"\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRIZ B\n";

    cout<<"\nDimension de la matriz A:";
    cout<<"\nFilas de la matriz: ";
    cin>>filA;
    cout<<"Columnas de la matriz: ";
    cin>>colA;
    cout<<endl;

    cout<<"\nDimension de la matriz B:";
    cout<<"\nFilas de la matriz: ";
    cin>>filB;
    cout<<"Columnas de la matriz: ";
    cin>>colB;
    cout<<endl;

    if(colA == filB){
    if(filA<=4 && filB<=4 && colA<=4 && colB<=4){

    int** A = new int*[filA];
    for(int i=0; i<filA; i++)
        A[i] = new int[colA];

    leerMatriz(A, filA, colA);

    int** B = new int*[filB];
    for(int i=0; i<filB; i++)
        B[i] = new int[colB];

    leerMatriz(B, filB, colB);

    int** C = new int*[filA];
    for(int i=0; i<filA; i++)
        C[i] = new int[colA];

        for(int i=0; i<filA; ++i){
            for(int j=0; j<colB; ++j){
                C[i][j] = 0;
                for(int z=0; z<colA; ++z)
                    C[i][j] += A[i][z] * B[z][j];
            }
        }

        cout<<"\nMatriz A:\n";
        imprimirMatriz(A, filA, colA);
        cout<<"\nMatriz B:\n";
        imprimirMatriz(B, filB, colB);
        cout<<"\nMultiplicacion de las matrices (A*B):\n";
        imprimirMatriz(C, filA, colB);

        } else{
        byMatriz_Aleatoria(filA, colA, filB, colB);
        }

    } else{
        cout<<"\n         NO SE PUEDEN MULTIPLICAR"
            <<"\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
            <<"\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRIz B";
        cout<<"\n"<<endl;
    }
}

void matrizTranspuesta()
{
    int filO, colO;

    cout<<"\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
        <<"\nDimension de la matriz:";
    cout<<"\nFilas de la matriz: ";
    cin>>filO;
    cout<<"Columnas de la matriz: ";
    cin>>colO;
    cout<<endl;

    if(filO<=4 && colO<=4){

    int** A = new int*[filO];
        for(int i = 0; i < filO; i++)
            A[i] = new int[colO];

    cout<<"\nDatos de la matriz A: ";
    leerMatriz(A, filO, colO);

    cout<<"\nMatriz original:\n";
    imprimirMatriz(A, filO, colO);

    cout<<"\nMatriz transpuesta:\n";
    for(int i = 0; i < filO; i++){
        cout<<"\n| ";
        for(int j = 0; j < colO; j++)
            cout<<A[j][i]<<" ";

        cout<<" |";
    }
    cout << endl;

    } else{
        transMatriz_Aleatoria(filO, colO);
    }
}

void sumaMatriz_Aleatoria(int fil, int col)
{
    unsigned int seedMatrix=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(seedMatrix);
    uniform_int_distribution<int>sumRanA(0,99);
    uniform_int_distribution<int>sumRanB(0,99);

    int MAsumA[fil][col], MAsumB[fil][col];
    //===========================================
    cout<<"Matriz aleatoria A: "<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j < col; j++){
        MAsumA[i][j]=sumRanA(motor);
        }
    }
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MAsumA[i][j]<<" ";
        cout<<" |";
    }
    cout<<"\n"<<endl;
    //===========================================
    cout<<"Matriz aleatoria B: "<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j<col; j++){
        MAsumB[i][j]=sumRanB(motor);
        }
    }
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MAsumB[i][j]<<" ";
        cout<<" |";
    }
    cout<<endl;
    //===========================================
    int** MAsumC = new int*[fil];
        for(int i=0; i<fil; i++)
            MAsumC[i] = new int[col];
    cout<<"\nSuma de las matrices aleatorias (A+B):\n";
    for(int i=0; i<fil; i++)
            for(int j=0; j<col; j++)
                MAsumC[i][j] = MAsumA[i][j] + MAsumB[i][j];
    //===========================================
    imprimirMatriz(MAsumC, fil, col);
}

void restaMatriz_Aleatoria(int fil, int col)
{
    unsigned int seedMatrix2=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor2(seedMatrix2);
    uniform_int_distribution<int>restRanA(0,99);
    uniform_int_distribution<int>restRanB(0,99);

    int MArestA[fil][col], MArestB[fil][col];
    //===========================================
    cout<<"Matriz aleatoria A: "<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j < col; j++){
        MArestA[i][j]=restRanA(motor2);
        }
    }
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MArestA[i][j]<<" ";
        cout<<" |";
    }
    cout<<"\n"<<endl;
    //===========================================
    cout<<"Matriz aleatoria B: "<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j < col; j++){
        MArestB[i][j]=restRanB(motor2);
        }
    }
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MArestB[i][j]<<" ";
        cout<<" |";
    }
    cout<<endl;
    //===========================================
    int** MArestC = new int*[fil];
        for(int i=0; i<fil; i++)
            MArestC[i] = new int[col];
    cout<<"\nResta de las matrices aleatorias (A-B):\n";
    for(int i=0; i<fil; i++)
            for(int j=0; j<col; j++)
                MArestC[i][j] = MArestA[i][j] - MArestB[i][j];
    //===========================================
    imprimirMatriz(MArestC, fil, col);
}

void byMatriz_Aleatoria(int filA, int colA, int filB, int colB)
{
    unsigned int seedMatrix3=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor3(seedMatrix3);
    uniform_int_distribution<int>byRanA(0,99);
    uniform_int_distribution<int>byRanB(0,99);

    int MAbyA[filA][colA], MAbyB[filB][colB];
    //===========================================
    cout<<"Matriz aleatoria A: "<<endl;
    for(int i=0; i<filA; i++){
        for(int j=0; j < colA; j++){
        MAbyA[i][j]=byRanA(motor3);
        }
    }
    for(int i=0; i<filA; ++i){
        cout<<"\n| ";
        for(int j=0; j<colA; ++j)
            cout<<setw(3)<<MAbyA[i][j]<<" ";
        cout<<" |";
    }
    cout<<"\n"<<endl;
    //===========================================
    cout<<"Matriz aleatoria B: "<<endl;
    for(int i=0; i<filB; i++){
        for(int j=0; j < colB; j++){
        MAbyB[i][j]=byRanB(motor3);
        }
    }
    for(int i=0; i<filB; ++i){
        cout<<"\n| ";
        for(int j=0; j<colB; ++j)
            cout<<setw(3)<<MAbyB[i][j]<<" ";
        cout<<" |";
    }
    cout<<endl;
    //===========================================
    int** MAbyC = new int*[filA];
    for(int i=0; i<filA; i++)
        MAbyC[i] = new int[colA];

        for(int i=0; i<filA; ++i){
            for(int j=0; j<colB; ++j){
                MAbyC[i][j] = 0;
                for(int z=0; z<colA; ++z)
                    MAbyC[i][j] += MAbyA[i][z] * MAbyB[z][j];
            }
        }
    //===========================================
    cout<<"\nMultiplicacion de las matrices (A*B):\n";
        imprimirMatriz(MAbyC, filA, colB);
}

void transMatriz_Aleatoria(int fil, int col)
{
    unsigned int seedMatrix4=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor4(seedMatrix4);
    uniform_int_distribution<int>transRan(0,99);

    int MAtransA[fil][col];
    //===========================================
    cout<<"Matriz aleatoria: "<<endl;
    for(int i=0; i<fil; i++){
        for(int j=0; j < col; j++){
        MAtransA[i][j]=transRan(motor4);
        }
    }
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MAtransA[i][j]<<" ";
        cout<<" |";
    }
    cout<<"\n"<<endl;

    cout<<"Matriz aleatoria transpuesta: "<<endl;
    for(int i=0; i<fil; ++i){
        cout<<"\n| ";
        for(int j=0; j<col; ++j)
            cout<<setw(3)<<MAtransA[j][i]<<" ";
        cout<<" |";
    }
    cout<<"\n"<<endl;
}

void imprimirMatriz(int **M, int fil, int col)
{
    for(int i=0; i<fil; i++){
        cout<<"\n| ";
        for(int j=0; j<col; j++)
            cout<<setw(4)<<M[i][j]<<" ";

        cout<<" |";
    }
    cout<<"\n"<<endl;
}
