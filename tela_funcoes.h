#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#ifndef  FUNCOES_H
#define FUNCOES_H


typedef struct{
  int figurinhas;
  int moedas;
} usuario;


int two_to_n(int n);
int tela_menu(usuario *jogador);
int tela_abrir_fig(usuario *jogador);
void abre_pacote(usuario *jogador);
void ganha_moedas(usuario *jogador);
int tela_sem_moedas(usuario *jogador);
void reinicia_user(usuario *jogador);
void mostra_fig(usuario *jogador);

#endif // FUNCOES_H


