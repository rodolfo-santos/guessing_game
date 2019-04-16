#include <stdio.h>
#include <locale.h>
#include <time.h>

int main(){
setlocale(LC_ALL, "Portuguese");

tela_inicial();
pergunta_nome_do_jogador();
jogo();

return 0;
}

///////////// FUNÇÕES ////////////////////


void wait ( int seconds ){
  clock_t endwait;
  endwait = clock () + seconds * CLK_TCK;
  while (clock() < endwait) {}
}

void tela_inicial(){
    printf("#############################\n");
    printf("#    JOGO DE ADIVINHAÇÃO    #\n");
    printf("#############################\n");
}

void pergunta_nome_do_jogador(){
    char jogador;
    printf("DIGITE O SEU NOME: ");
    scanf("%s", &jogador);
    system("cls");
}

void contador(){
    int cont = 3;
    while(cont > 0){
        printf("O jogo irá começar em %d...", cont);
        cont--;
        wait(1);
        system("cls");
    }
}

void jogo(){
    contador();

    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    int numerosecreto = numero_grande % 100;


    int chute;
    int tentativa = 0;
    double pontos = 1000;

   while(1){
        tentativa++;
        printf("Tentativa %d !\n", tentativa);
        printf("Digite o seu chute: ");
        scanf("%d", &chute);
        if(chute < 0 || chute >= 100){
            system("cls");
            printf("Digite um numero inteiro positivo menor que 100\n");
            tentativa--;
            continue;
        }

        int acertou = (chute == numerosecreto);
        int maior = (numerosecreto > chute);

        if(acertou){
            system("cls");
            printf("\n Voce ACERTOU na tentativa %d\n\n", tentativa);
            printf("Fim do Jogo!\n");
            printf("Você fez: %.1f pontos!", pontos);
            break;
        } else{
            if(maior){
                system("cls");
                printf("\n É MAIOR! \n\n");
                int pontosperdidos = (numerosecreto - chute) / 2;
                pontos = pontos - pontosperdidos;

            } else{
                system("cls");
                printf("\n É MENOR! \n\n");
                double pontosperdidos = (chute - numerosecreto) / (double)2;
                pontos = pontos - pontosperdidos;
            }

        }
    }
}

