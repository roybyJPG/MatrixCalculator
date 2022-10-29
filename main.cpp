#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void leerMatriz(int **M, int fil, int col);
void sumaMatrices();
void restaMatrices();
void multiplicacionMatrices();
void matrizTranspuesta();
void imprimirMatriz(int **M, int fil, int col);
void menu();

void matrizAleatoria( int fil, int col );

//void leerMatrizAleatoria(int **M, int filRan, int columRan);

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
        cin >> opcion;
        if( cin.fail() || cin.bad() ){
            opcion = 0;
            cin.clear();
            cin.ignore( '\n', 80 );
        }

            switch( opcion ){
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
                    cout << "\n\nFIN DEL PROGRAMA\n\n";
                    exit(0);
                    break;

                default:
                    cout << "\n\nOPCION NO VALIDA\n\n";
                    break;
        }

    }while( opcion != 5 );
}

void leerMatriz(int **M, int fil, int col)
{
        cout << "\nRellenar la matriz:\n";
        for( int i = 0; i < fil; i++ ){
            for( int j = 0; j < col; j++ ){
                cout << "Matriz[" << i << "][" << j << "]: ";
                cin >> M[i][j];
            }
        }
}

void sumaMatrices()
{
    int fil, col;

    cout << "\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
         << "\nDimension de la matriz:";
    cout << "\nFilas de la matriz: "; cin >> fil;
    cout << "Columnas de la matriz: "; cin >> col;

    if(fil<=4,col<=4){

        int** A = new int*[fil];
        for( int i = 0; i < fil; i++ )
            A[i] = new int[col];

        int** B = new int*[fil];
        for( int i = 0; i < fil; i++ )
            B[i] = new int[col];

        int** C = new int*[fil];
        for( int i = 0; i < fil; i++ )
            C[i] = new int[col];

        cout << "\nDatos de la matriz A: ";
        leerMatriz( A, fil, col );

        cout << "\nDatos de la matriz B: ";
        leerMatriz( B, fil, col );

        for( int i = 0; i < fil; i++ )
            for( int j = 0; j < col; j++ )
                C[i][j] = A[i][j] + B[i][j];

        cout << "\nMatriz A:\n";
        imprimirMatriz( A, fil, col );
        cout << "\nMatriz B:\n";
        imprimirMatriz( B, fil, col );
        cout << "\nSuma de las matrices (A+B):\n";
        imprimirMatriz( C, fil, col );

    } else{
        matrizAleatoria(fil,col);
    }
}

void restaMatrices()
{
    int fil, col;

    cout << "\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
         << "\nDimension de la matriz:";
    cout << "\nFilas de la matriz: "; cin >> fil;
    cout << "Columnas de la matriz: "; cin >> col;

    int** A = new int*[fil];
    for( int i = 0; i < fil; i++ )
        A[i] = new int[col];

    int** B = new int*[fil];
    for( int i = 0; i < fil; i++ )
        B[i] = new int[col];

    int** C = new int*[fil];
    for( int i = 0; i < fil; i++ )
        C[i] = new int[col];

    cout << "\nDatos de la matriz A: ";
    leerMatriz( A, fil, col );

    cout << "\nDatos de la matriz B: ";
    leerMatriz( B, fil, col );

    for( int i = 0; i < fil; i++ )
        for( int j = 0; j < col; j++ )
            C[i][j] = A[i][j] - B[i][j];

    cout << "\nMatriz A:\n";
    imprimirMatriz( A, fil, col );
    cout << "\nMatriz B:\n";
    imprimirMatriz( B, fil, col );
    cout << "\nResta de las matrices (A-B):\n";
    imprimirMatriz( C, fil, col );
}

void multiplicacionMatrices()
{
    int filA, colA, filB, colB;

    cout << "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
         << "\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRIZ B\n";

    cout << "\nDimension de la matriz A:";
    cout << "\nFilas de la matriz: "; cin >> filA;
    cout << "Columnas de la matriz: "; cin >> colA;

    int** A = new int*[filA];
    for( int i = 0; i < filA; i++ )
        A[i] = new int[colA];

    leerMatriz( A, filA, colA );

    cout << "\nDimension de la matriz B:";
    cout << "\nFilas de la matriz: "; cin >> filB;
    cout << "Columnas de la matriz: "; cin >> colB;

    int** B = new int*[filB];
    for( int i = 0; i < filB; i++ )
        B[i] = new int[colB];

    leerMatriz( B, filB, colB );

    int** C = new int*[filA];
    for( int i = 0; i < filA; i++ )
        C[i] = new int[colA];

    if( colA == filB ){
        for( int i = 0; i < filA; ++i ){
            for( int j = 0; j < colB; ++j ){
                C[i][j] = 0;
                for( int z = 0; z < colA; ++z )
                    C[i][j] += A[i][z] * B[z][j];
            }
        }

        cout << "\nMatriz A:\n";
        imprimirMatriz( A, filA, colA );
        cout << "\nMatriz B:\n";
        imprimirMatriz( B, filB, colB );
        cout << "\nMultiplicacion de las matrices (A*B):\n";
        imprimirMatriz( C, filA, colB );

    }else
        cout << "\n         NO SE PUEDEN MULTIPLICAR"
             << "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
             << "\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRI B";

}

void matrizTranspuesta()
{
    int filO, colO;

    cout << "\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
         << "\nDimension de la matriz:";
    cout << "\nFilas de la matriz: "; cin >> filO;
    cout << "Columnas de la matriz: "; cin >> colO;

    if(filO<=4,colO<=4){

    int** A = new int*[filO];
        for( int i = 0; i < filO; i++ )
            A[i] = new int[colO];

    cout << "\nDatos de la matriz A: ";
    leerMatriz( A, filO, colO );

    cout << "\nMatriz original:\n";
    imprimirMatriz( A, filO, colO );

    cout << "\nMatriz transpuesta:\n";
    for( int i = 0; i < filO; i++ ){
        cout << "\n| ";
        for( int j = 0; j < colO; j++ )
            cout << A[j][i] << " ";

        cout << " |";
    }
    cout << endl;

    } else{
        matrizAleatoria(filO, colO);
    }

}

void matrizAleatoria( int fil, int col )
{
    int M[fil][col];
    unsigned int seedMatrix=chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine motor(seedMatrix);
    uniform_int_distribution<int>filRan(0,99);
    uniform_int_distribution<int>colRan(0,99);

    //for( int i; i < fil; i++ ){
        //M[i]=filRan(motor);
        //cout << "\n| ";
            //for( int j; j < col; j++ ){
           // M[j]=colRan(motor);
            //cout << M[i][j] << " ";

    //

    //cout<<"Columnas: "<<columRan(motor)<<endl;
    //cout<<"Filas: "<<filRan(motor)<<endl;

}

void leerMatrizAleatoria(int M, int fil, int col)
{

}

void imprimirMatriz( int **M, int fil, int col )
{
    for( int i = 0; i < fil; i++ ){
        cout << "\n| ";
        for( int j = 0; j < col; j++ )
            cout << M[i][j] << " ";

        cout << " |";
    }
    cout << endl;
}
