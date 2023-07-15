#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

#include "tela_funcoes.h"


void inicializa_dados(usuario *jogador){
  //procedimento para abrir o arquivo "usuario.txt"
  //copiar os dados do arquivo na variável do tipo usuario
  //sendo que essa variável é passado como argumento por referência

  FILE *fp;
  int figurinhas_arq, moedas_arq;

  //abre arquivo texto
  if((fp=fopen("usuario.txt","r"))==NULL){
    printf("o arquivo nao pode ser aberto");
    exit(1);
  }

  //le dados do arquivo e salva na struct
  fscanf(fp, "%d %d", &figurinhas_arq, &moedas_arq);

  jogador->figurinhas = figurinhas_arq;
  jogador->moedas = moedas_arq;

  //fecha arquivo
  printf("Arquivo lido com sucesso!!\nAperte alguma tecla para continuar\n"
      "===================================================================\n"
      "|  Para uma experiência melhor, coloque o terminal em tela cheia! |\n"
      "===================================================================\n"
      );
  getchar();
  setbuf(stdin, NULL);
  fclose(fp);
}

void salva_dados(usuario *jogador){
  //Procedimento para salvar os dados do usuario no arquivo "usuario.txt"

  FILE *fp;
  int figurinhas_arq = jogador->figurinhas, moedas_arq = jogador->moedas;

  //abre arquivo texto
  if((fp=fopen("usuario.txt","w"))==NULL){
    printf("o arquivo nao pode ser aberto");
    exit(1);
  }

  //grava dados
  fprintf(fp, "%d %d", figurinhas_arq, moedas_arq);


  //fecha arquivo
  printf("\nArquivo salvo com sucesso!!\nAperte alguma tecla para continuar\n");
  getchar();
  setbuf(stdin, NULL);
  fclose(fp);
}

int main(){

  usuario jogador_atual;
  inicializa_dados(&jogador_atual);

  int menu_principal;
  do{
    //menu principal pode receber 0, 1, 2 ou 3
    menu_principal = tela_menu(&jogador_atual);

    if(menu_principal == 0)
    {
      //menu de abrir figurinha/ganhar moedas
      int menu_figurinhas;
      do{
        //menu_figurinhas pode recerber 0 ou 1
        menu_figurinhas = tela_abrir_fig(&jogador_atual);

        //tela para abrir pacotinho
        if (menu_figurinhas == 0)
        {
          //verifica se o jogador pode comprar pacotinho
          if(jogador_atual.moedas >= 5)
          {
            jogador_atual.moedas-=5; //retira dinheiro do usuario
            abre_pacote(&jogador_atual); //compra figurinha
          }
          else
          {
            tela_sem_moedas(&jogador_atual); //mostra uma tela sem moeda
          }
        }
        //tela para ganhar moedas
        else if(menu_figurinhas == 1)
        {
          ganha_moedas(&jogador_atual);
        }
      }while(menu_figurinhas!=2);
    }

    //mostra as figurinhas
    else if(menu_principal == 1)
    {
      mostra_fig(&jogador_atual);
    }

    //reinicia o album e as moedas do usuario
    if(menu_principal == 2)
    {
      reinicia_user(&jogador_atual);
    }

  }while(menu_principal != 3);

  //finaliza o programa
  salva_dados(&jogador_atual);

  return 0;
}


