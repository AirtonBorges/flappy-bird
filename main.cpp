/*Vers�o beta desenvolvida por Thiago Felski Pereira para disciplina de Algoritmos*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h> ///para o getch()
///https://stackoverflow.com/questions/34474627/linux-equivalent-for-conio-h-getch

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
    //IN�CIO: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    COORD coord;
    //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO IN�CIO DA TELA
    ///ALERTA: N�O MODIFICAR O TRECHO DE C�DIGO, ACIMA.


    int bird_x=5, bird_y=10;
    int obstaculo_x=129, obstaculo_y;
    int tecla;

    ///DESENHO DO CEN�RIO
    cout<<"----------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<"----------------------------------------------------------------------------------------------------------------------------------";

    Sleep(2000);
    while (true) { //esse la�o faz o jogo rodar para sempre

        ///POSICIONA O PÁSSARO

        ///POSICIONA O OBST�CULO

        obstaculo_y=1;
        while(obstaculo_y<20){
            coord.X = obstaculo_x;    coord.Y = obstaculo_y;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            if(obstaculo_y<5 || obstaculo_y>7){
                cout<<char(219);
            } else {
                cout<<" ";
            }

            coord.X = obstaculo_x + 5;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            cout<<" ";

            int espaco_entre_obstaculos = 120;
            int espaco_entre = 20;

            int novo_x = obstaculo_x + 10;
            if(obstaculo_x < espaco_entre_obstaculos) {
                coord.X = novo_x;
                coord.Y = obstaculo_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_y<3 || obstaculo_y>5){
                    cout<<char(219);
                } else {
                    cout<<" ";
                }

                coord.X = novo_x + 5;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<" ";
            }


            int novo_novo_x = novo_x + 10;
            espaco_entre_obstaculos -= espaco_entre;
            if(obstaculo_x < espaco_entre_obstaculos) {
                coord.X = novo_novo_x;
                coord.Y = obstaculo_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_y<3 || obstaculo_y>5){
                    cout<<char(219);
                } else {
                    cout<<" ";
                }

                coord.X = novo_novo_x + 5;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<" ";
            }

            int novo_novo_novo_x = novo_novo_x + 10;
            espaco_entre_obstaculos -= espaco_entre;
            if(obstaculo_x < espaco_entre_obstaculos) {
                coord.X = novo_novo_novo_x;
                coord.Y = obstaculo_y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                if(obstaculo_y<3 || obstaculo_y>5){
                    cout<<char(219);
                } else {
                    cout<<" ";
                }

                coord.X = novo_novo_novo_x + 5;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                cout<<" ";
            }
            obstaculo_y++;
        }

        obstaculo_x--;

        ///TEMPO DE ESPERA
        Sleep(200);
    }

    return 0;
}
