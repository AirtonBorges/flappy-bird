/*Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

#define MAXIMO_X 35
#define ESPACO_CANO = 5;
using namespace std;


/**
    F L A P B I R D (M2 Algoritmos)
    - Lembrando: n�o permitido o uso de fun��es e vari�veis compostas como structs, vetores e matrizes
    - Corrigir os rastros (p�ssaro e obst�culos)
    - Implementar colis�o
    - Implementar pontua��o (mais um ponto para cada obst�culo superado)
    - Fazer 2 obst�culos simult�neos (obstaculo1 e obstaculo2)
    - Deixar a pontua��o vis�vel durante todo o jogo
    - Definir marcos para acelerar a velocidade
*/



int main()
{
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, A SEGUIR.
    //INICIO: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR N�O FIQUE PISCANDO NA TELA
    //INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.

    int xPassaroX = 5, xPassaroY = 10;
    int xObstaculoX = MAXIMO_X;
    int xNovoObstaculoX = MAXIMO_X / 2;
    int xObstaculosY;
    int xTecla;
    int xPlacar = 0;

    srand(time(NULL));

    Sleep(2000);
    while (true) { //esse la�o faz o jogo rodar para sempre
        cout << "------------------ " << xPlacar << " ------------------";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "--------------------------------------";
        ///POSICIONA O PÁSSARO

        ///POSICIONA OS OBSTACULOS
        xObstaculosY = 1;
        while (xObstaculosY < 20) {
            coord.X = xObstaculoX;
            coord.Y = xObstaculosY;
            int xPosicaoAberturaObstaculo = rand() % 15 + 3;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(xObstaculosY < 5 || xObstaculosY > 7){
                cout<<char(219);
            }

            coord.X = xNovoObstaculoX;
            coord.Y = xObstaculosY;

            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(xObstaculosY < 3 || xObstaculosY > 5){
                cout<<char(219);
            }

            xObstaculosY++;
            if(xObstaculoX <= 0) {
                xObstaculoX = MAXIMO_X;
            }
            if(xNovoObstaculoX <= 0) {
                xNovoObstaculoX = MAXIMO_X;
            }
        }

        xObstaculoX--;
        xNovoObstaculoX--;

        ///TEMPO DE ESPERA
        Sleep(200);
        system("cls");
    }

    return 0;
}
