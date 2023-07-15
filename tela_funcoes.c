//funcoes_tela.c

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <time.h>

#include "tela_funcoes.h"

int two_to_n(int n){
  //recebe um int
  //retorna um int
  //retorna o resultado de 2 elevado ao numero passado como argumento da função
  int x = 1;
  for(int i=0; i<n;i++)
    x *= 2;
  return x;
}

int tela_menu(usuario *jogador){
  //stdscr
  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x);

  //texto pricipal
  char char_menu1 = 'w';
  int menu1 = 0;
  mvprintw(y/2-3,x/2-16," Adquirir figurinhas");
  mvprintw(y/2-1,x/2-16," Ver álbum");
  mvprintw(y/2+1,x/2-16," zerar álbum");
  mvprintw(y/2+3,x/2-16," sair do programa");

  //beiradas
  attron(COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvprintw(0, i, "u");
    mvprintw(y-1, i, "u");
  }
  for(int i=0;i<y;i++){
    mvprintw(i, 0, "u");
    mvprintw(i, x-1, "u");
  }
  attroff(COLOR_PAIR(1));

  move(y/2-3,x/2-17);

  //cursor no menu principal
  do {
    refresh();
    char_menu1 = getch();
    if(char_menu1 == 'w')
    {
      if(menu1==0)
        continue;
      else
        menu1--;
      move(y/2-3+2*menu1,x/2-17);
    }
    else if(char_menu1=='s')
    {
      if(menu1==3)
        continue;
      else
        menu1++;
      move(y/2-3+2*menu1,x/2-17);
    }
    else
    {
      continue;
    }
    refresh();
  } while( char_menu1!=10);

  //retornos
  if(menu1==0){
    refresh();
    endwin();
		return 0;
  }
	else if(menu1==1){
		refresh();
    endwin();
    return 1;
	}

	else if(menu1==2){
		refresh();
    endwin();
		return 2;
	}
  else if(menu1==3){
    refresh();
    endwin();
    return 3;
  }
}

int tela_abrir_fig(usuario *jogador){

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x);

  WINDOW *menufigs = newwin(y, x, 0, 0); //nova janela

  char char_abrir_fig = 'w'; //controla cursor
  int num_abrir_fig = 0; //controla retorno

  //texto principal
  mvwprintw(menufigs, y/2-3,x/2-15,"Abrir pacote (preço = 5 moedas)");
  mvwprintw(menufigs, y/2-1,x/2-15,"Ganhar moedas");
  mvwprintw(menufigs, y/2+1,x/2-15,"voltar");

  //moedas
  mvwprintw(menufigs, 3, 3, "quantidade de moedas: %d", jogador->moedas);

  //bordas
  wattron(menufigs, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(menufigs, 0, i, "u");
    mvwprintw(menufigs, y-1, i, "u");
  }
  for(int i=0;i<y;i++){
    mvwprintw(menufigs, i, 0, "u");
    mvwprintw(menufigs, i, x-1, "u");
  }
  wattroff(menufigs, COLOR_PAIR(1));

  //move cursor
	wmove(menufigs, y/2-3,x/2-16);

  do {
    wrefresh(menufigs);
    char_abrir_fig = getch();

    if(char_abrir_fig == 'w')
    {
      if(num_abrir_fig==0)
        continue;
      else
        num_abrir_fig--;
      wmove(menufigs, y/2-3+2*num_abrir_fig,x/2-16);
    }
    else if(char_abrir_fig=='s')
    {
      if(num_abrir_fig==2)
        continue;
      else
        num_abrir_fig++;
      wmove(menufigs, y/2-3+2*num_abrir_fig,x/2-16);
    }
    else
    {
      continue;
    }

    wrefresh(menufigs);
  } while( char_abrir_fig!=10);

  //retornos
  if(num_abrir_fig==0){
    wrefresh(menufigs);
    delwin(menufigs);
    endwin();
		return 0;
  }
	else if(num_abrir_fig==1){
		wrefresh(menufigs);
		delwin(menufigs);
    endwin();
		return 1;
	}
	else if(num_abrir_fig==2){
		wrefresh(menufigs);
		delwin(menufigs);
    endwin();
		return 2;
	}

}


void abre_pacote(usuario *jogador){

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x); //80 24

  WINDOW *jan_abre_pacote = newwin(y, x, 0, 0);

  char char_abre_pacote;

  //moedas
  mvwprintw(jan_abre_pacote, 3, 3, "quantidade de moedas: %d", jogador->moedas);

  //bordas
  wattron(jan_abre_pacote, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(jan_abre_pacote, 0, i, "u");
    mvwprintw(jan_abre_pacote, y-1, i, "u");}
  for(int i=0;i<y;i++){
    mvwprintw(jan_abre_pacote, i, 0, "u");
    mvwprintw(jan_abre_pacote, i, x-1, "u");
  }
  wattroff(jan_abre_pacote, COLOR_PAIR(1));

  //move cursor
	wmove(jan_abre_pacote, y/2-3,x/2-8);

  //mensagens principais
  mvwprintw(jan_abre_pacote, y/2-3, x/2-20, "Aperte algum botão para abrir um pacote");

  wrefresh(jan_abre_pacote);

  char_abre_pacote = getch();

  //sorteia a figurinha ganha
  srand(time(NULL));
  int temp = rand()%4+1;

  //coloca frase da figurinha
  if(jogador->figurinhas & two_to_n(temp-1))
  {
    mvwprintw(jan_abre_pacote, y/2-1, x/2-22, "    Você ganhou a figurinha repetida %d ", temp);
    mvwprintw(jan_abre_pacote, y/2, x/2-18, "Por isso, te recompensaremos com 3 moedas");
    jogador->moedas += 3;
  }
  else
  {
    mvwprintw(jan_abre_pacote, y/2-1, x/2-22, "    Parabéns por conseguir a figurinha %d ", temp);
  }

  //adiociona a figurinha no usuario
  (*jogador).figurinhas |= two_to_n(temp-1);


  //mostra imagem de acordo com a figurinha
  switch(temp)
  {
    case 1:
      y = y/2;
      x = x/2 - 16;
      mvwprintw(jan_abre_pacote, 3+y, x, ".----------------------------.");
      mvwprintw(jan_abre_pacote, 4+y, x, "|                            |");
      mvwprintw(jan_abre_pacote, 5+y, x, "|                            |");
      mvwprintw(jan_abre_pacote, 6+y, x, "|        |\\__/,|   (`\\       |");
      mvwprintw(jan_abre_pacote, 7+y, x,"|        |o o  |__ _)        |");
      mvwprintw(jan_abre_pacote, 8+y, x,"|      _.( T   )  `  /       |");
      mvwprintw(jan_abre_pacote, 9+y, x,"|     ((_ `^--' /_<  \\       |");
      mvwprintw(jan_abre_pacote, 10+y, x,"|     `` `-'(((/  (((/       |");
      mvwprintw(jan_abre_pacote, 11+y, x,"|                            |");
      mvwprintw(jan_abre_pacote, 12+y, x,"|                            |");
      mvwprintw(jan_abre_pacote, 13+y, x,"|                            |");
      mvwprintw(jan_abre_pacote, 14+y, x,"'----------------------------'");
      break;

    case 2:
      y=y/2+2;
      x=x/2 - 16;
      mvwprintw(jan_abre_pacote, 0+y, x,".---------------------.");
      mvwprintw(jan_abre_pacote, 1+y, x,"|        ',           |");
      mvwprintw(jan_abre_pacote, 2+y, x,"|     .-`-,\\__        |");
      mvwprintw(jan_abre_pacote, 3+y, x,"|       .'    '',     |");
      mvwprintw(jan_abre_pacote, 4+y, x,"|     .'_.  ._  `;.   |");
      mvwprintw(jan_abre_pacote, 5+y, x,"| __ / `      `  `.\\  |");
      mvwprintw(jan_abre_pacote, 6+y, x,"|/--,| 0)   0)     )`_|");
      mvwprintw(jan_abre_pacote, 7+y, x,"||   ;.-----.__ _-'); |");
      mvwprintw(jan_abre_pacote, 8+y, x,"| '--./         `.`/  |");
      mvwprintw(jan_abre_pacote, 9+y, x,"|    :   '`      |.   |");
      mvwprintw(jan_abre_pacote, 10+y, x,"|    | \\     /  //    |");
      mvwprintw(jan_abre_pacote, 11+y, x,"|    \\ '---'  /'      |");
      mvwprintw(jan_abre_pacote, 12+y, x,"|     `------' \\      |");
      mvwprintw(jan_abre_pacote, 13+y, x,"|      _/       `--...|");
      mvwprintw(jan_abre_pacote, 14+y, x,"'---------------------'");
      break;

    case 3:
      x=x/2-16;
      y=y/2;
      mvwprintw(jan_abre_pacote, 1+y, x,".--------------------.");
      mvwprintw(jan_abre_pacote, 2+y, x,"|                    |");
      mvwprintw(jan_abre_pacote, 3+y, x,"|         __         |");
      mvwprintw(jan_abre_pacote, 4+y, x,"|      -=(o '.       |");
      mvwprintw(jan_abre_pacote, 5+y, x,"|         '.-.\\      |");
      mvwprintw(jan_abre_pacote, 6+y, x,"|         /|  \\\\     |");
      mvwprintw(jan_abre_pacote, 7+y, x,"|         '|  ||     |");
      mvwprintw(jan_abre_pacote, 8+y, x,"|          _\\_):,_   |");
      mvwprintw(jan_abre_pacote, 9+y, x,"|                    |");
      mvwprintw(jan_abre_pacote, 10+y, x,"|                    |");
      mvwprintw(jan_abre_pacote, 11+y, x,"'--------------------'");
      break;

    case 4:
      y=y/2;
      x=x/2-16;
      mvwprintw(jan_abre_pacote, 1+y, x,".------------------------.");
      mvwprintw(jan_abre_pacote, 2+y, x,"|                        |");
      mvwprintw(jan_abre_pacote, 3+y, x,"|    ___                 |");
      mvwprintw(jan_abre_pacote, 4+y, x,"| __/_  `.  .-'''-.      |");
      mvwprintw(jan_abre_pacote, 5+y, x,"| \\_,` | \\-'  /   )`-')  |");
      mvwprintw(jan_abre_pacote, 6+y, x,"|  '') `''`    \\  ((`'`  |");
      mvwprintw(jan_abre_pacote, 7+y, x,"| ___Y  ,    .'7 /|      |");
      mvwprintw(jan_abre_pacote, 8+y, x,"|(_,___/...-` (_/_/      |");
      mvwprintw(jan_abre_pacote, 9+y, x,"|                        |");
      mvwprintw(jan_abre_pacote, 10+y, x,"|                        |");
      mvwprintw(jan_abre_pacote, 11+y, x,"'------------------------'");
      break;
  }

  wrefresh(jan_abre_pacote);

  char_abre_pacote = getch();

  delwin(jan_abre_pacote);
  endwin();
}

void ganha_moedas(usuario *jogador){

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x);

  //declara janela
  WINDOW *jan_ganha_moedas = newwin(y, x, 0, 0);

  //char auxiliar
  char char_ganha_moeda;

  //sorteia a quantidade de moedas a ser ganha
  srand(time(NULL));
  int temp = rand()%6+1;

  //moedas
  mvwprintw(jan_ganha_moedas, 3, 3, "quantidade de moedas: %d", jogador->moedas);

  //bordas
  wattron(jan_ganha_moedas, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(jan_ganha_moedas, 0, i, "u");
    mvwprintw(jan_ganha_moedas, y-1, i, "u");}
  for(int i=0;i<y;i++){
    mvwprintw(jan_ganha_moedas, i, 0, "u");
    mvwprintw(jan_ganha_moedas, i, x-1, "u");
  }
  wattroff(jan_ganha_moedas, COLOR_PAIR(1));

  //primeira parte
  mvwprintw(jan_ganha_moedas, y/2-3,x/2-22,"Aperte algum botão para lançar o dado");
  wmove(jan_ganha_moedas, 0,0);
  wrefresh(jan_ganha_moedas);

  //espera clique
  char_ganha_moeda = getch();

  //segunda parte
  mvwprintw(jan_ganha_moedas, y/2-1, x/2-10, "deu %d", temp);
  (*jogador).moedas += temp;
  wmove(jan_ganha_moedas, 0, 0);
  wrefresh(jan_ganha_moedas);

  //espera clique
  char_ganha_moeda = getch();

  //terceira parte
  mvwprintw(jan_ganha_moedas, y/2+1, x/2-20, "Parabéns, você ganhou %d moedas", temp );
  mvwprintw(jan_ganha_moedas, y/2+2, x/2-20, "Agora você tem %d mooedas", jogador->moedas);
  wmove(jan_ganha_moedas, 0, 0);
  wrefresh(jan_ganha_moedas);

  //espera clique + fecha janela
  char_ganha_moeda = getch();
  delwin(jan_ganha_moedas);
  endwin();
}

int tela_sem_moedas(usuario *jogador){

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch
  keypad(stdscr, TRUE); // habilita f1 f2 f3


  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x); //80 24

  //declara janela
  WINDOW *tela_sem_moedas = newwin(y, x, 0, 0);

  //declara char auxiliar
  char char_sem_moedas;

  //moedas
  mvwprintw(tela_sem_moedas, 3, 3, "quantidade de moedas: %d", jogador->moedas);

  wattron(tela_sem_moedas, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(tela_sem_moedas, 0, i, "u");
    mvwprintw(tela_sem_moedas, y-1, i, "u");}
  for(int i=0;i<y;i++){
    mvwprintw(tela_sem_moedas, i, 0, "u");
    mvwprintw(tela_sem_moedas, i, x-1, "u");
  }
  wattroff(tela_sem_moedas, COLOR_PAIR(1));

  //texto principal
  mvwprintw(tela_sem_moedas, y/2-3,x/2-7,"Moedas insificientes");
  mvwprintw(tela_sem_moedas, y/2-2, x/2-7, "Você possui %d moedas, sendo que são necessárias 5 moedas", jogador->moedas);
	wmove(tela_sem_moedas, y/2-3,x/2-8);
  wrefresh(tela_sem_moedas);

  //espera clique + fecha janela
  char_sem_moedas = getch();
  delwin(tela_sem_moedas);
  endwin();
}


void reinicia_user(usuario *jogador){

  //muda configuracoes do usuario
  jogador->figurinhas = 0;
  jogador->moedas = 0;

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x); //80 24

  //declara janela
  WINDOW *jan_reinicia_user = newwin(y, x, 0, 0);

  //declara char auxiliar
  char char_reinicia_user;

  //bordas
  wattron(jan_reinicia_user, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(jan_reinicia_user, 0, i, "u");
    mvwprintw(jan_reinicia_user, y-1, i, "u");}
  for(int i=0;i<y;i++){
    mvwprintw(jan_reinicia_user, i, 0, "u");
    mvwprintw(jan_reinicia_user, i, x-1, "u");
  }
  wattroff(jan_reinicia_user, COLOR_PAIR(1));

  //frase principal
  mvwprintw(jan_reinicia_user, y/2-3,x/2-30,"Figurinhas reiniciadas, aperte algum botão para continuar");

  //moedas
  mvwprintw(jan_reinicia_user, 3, 3, "quantidade de moedas: %d", jogador->moedas);

	wmove(jan_reinicia_user, 0,0);
  wrefresh(jan_reinicia_user);

  //espera clique
  char_reinicia_user = getch();

  //apaga janela
  delwin(jan_reinicia_user);
  endwin();
}

void mostra_fig(usuario *jogador){

  initscr(); //inicia tela
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_WHITE);
  noecho(); // não ecoa enquanto estivermos no getch

  int y, x; //pega a quantidade de linha e coluna da janela
  getmaxyx(stdscr, y, x); //80 24

  //declara janela
  WINDOW *tela_mostra_fig = newwin(y, x, 0, 0);

  //bordas
  wattron(tela_mostra_fig, COLOR_PAIR(1));
  for(int i=0;i<x; i++){
    mvwprintw(tela_mostra_fig, 0, i, "u");
    mvwprintw(tela_mostra_fig, y-1, i, "u");}
  for(int i=0;i<y;i++){
    mvwprintw(tela_mostra_fig, i, 0, "u");
    mvwprintw(tela_mostra_fig, i, x-1, "u");
  }
  wattroff(tela_mostra_fig, COLOR_PAIR(1));

  //mostra as figurinhas
  if(jogador->figurinhas & 1){
    int y = 0;
    int x = 10;
  mvwprintw(tela_mostra_fig, 3+y, x, ".----------------------------.");
  mvwprintw(tela_mostra_fig, 4+y, x, "|                            |");
  mvwprintw(tela_mostra_fig, 5+y, x, "|                            |");
  mvwprintw(tela_mostra_fig, 6+y, x, "|        |\\__/,|   (`\\       |");
  mvwprintw(tela_mostra_fig, 7+y, x,"|        |o o  |__ _)        |");
  mvwprintw(tela_mostra_fig, 8+y, x,"|      _.( T   )  `  /       |");
  mvwprintw(tela_mostra_fig, 9+y, x,"|     ((_ `^--' /_<  \\       |");
  mvwprintw(tela_mostra_fig, 10+y, x,"|     `` `-'(((/  (((/       |");
  mvwprintw(tela_mostra_fig, 11+y, x,"|                            |");
  mvwprintw(tela_mostra_fig, 12+y, x,"|                            |");
  mvwprintw(tela_mostra_fig, 13+y, x,"|                            |");
  mvwprintw(tela_mostra_fig, 14+y, x,"'----------------------------'");
  }

  else{
    int y = 0;
    int x = 10;
  mvwprintw(tela_mostra_fig, 3+y, x, ".----------------------------.");
  mvwprintw(tela_mostra_fig, 4+y, x, "| .------------------------. |");
  mvwprintw(tela_mostra_fig, 5+y, x, "| |           __           | |");
  mvwprintw(tela_mostra_fig, 6+y, x, "| |          /  |          | |");
  mvwprintw(tela_mostra_fig, 7+y, x, "| |          `| |          | |");
  mvwprintw(tela_mostra_fig, 8+y, x, "| |           | |          | |");
  mvwprintw(tela_mostra_fig, 9+y, x, "| |          _| |_         | |");
  mvwprintw(tela_mostra_fig, 10+y, x, "| |         |_____|        | |");
  mvwprintw(tela_mostra_fig, 11+y, x, "| |                        | |");
  mvwprintw(tela_mostra_fig, 12+y, x, "| |                        | |");
  mvwprintw(tela_mostra_fig, 13+y, x, "| '------------------------' |");
  mvwprintw(tela_mostra_fig, 14+y, x, "'----------------------------'");
  }

  if(jogador->figurinhas & 2){
     int y=16;
     int x=10;
   mvwprintw(tela_mostra_fig, 0+y, x,".---------------------.");
   mvwprintw(tela_mostra_fig, 1+y, x,"|        ',           |");
   mvwprintw(tela_mostra_fig, 2+y, x,"|     .-`-,\\__        |");
   mvwprintw(tela_mostra_fig, 3+y, x,"|       .'    '',     |");
   mvwprintw(tela_mostra_fig, 4+y, x,"|     .'_.  ._  `;.   |");
   mvwprintw(tela_mostra_fig, 5+y, x,"| __ / `      `  `.\\  |");
   mvwprintw(tela_mostra_fig, 6+y, x,"|/--,| 0)   0)     )`_|");
   mvwprintw(tela_mostra_fig, 7+y, x,"||   ;.-----.__ _-'); |");
   mvwprintw(tela_mostra_fig, 8+y, x,"| '--./         `.`/  |");
   mvwprintw(tela_mostra_fig, 9+y, x,"|    :   '`      |.   |");
   mvwprintw(tela_mostra_fig, 10+y, x,"|    | \\     /  //    |");
   mvwprintw(tela_mostra_fig, 11+y, x,"|    \\ '---'  /'      |");
   mvwprintw(tela_mostra_fig, 12+y, x,"|     `------' \\      |");
   mvwprintw(tela_mostra_fig, 13+y, x,"|      _/       `--...|");
   mvwprintw(tela_mostra_fig, 14+y, x,"'---------------------'");
  }

  else{
    int y = 16;
    int x = 10;
  mvwprintw(tela_mostra_fig, 0+y, x,".----------------------.");
  mvwprintw(tela_mostra_fig, 1+y, x,"| .------------------. |");
  mvwprintw(tela_mostra_fig, 2+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 3+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 4+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 5+y, x,"| |      _____       | |");
  mvwprintw(tela_mostra_fig, 6+y, x,"| |     / ___ `.     | |");
  mvwprintw(tela_mostra_fig, 7+y, x,"| |    |_/___) |     | |");
  mvwprintw(tela_mostra_fig, 8+y, x,"| |     .'____.'     | |");
  mvwprintw(tela_mostra_fig, 9+y, x,"| |    / /____       | |");
  mvwprintw(tela_mostra_fig, 10+y, x,"| |    |_______|     | |");
  mvwprintw(tela_mostra_fig, 11+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 12+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 13+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 14+y, x,"| |                  | |");
  mvwprintw(tela_mostra_fig, 15+y, x,"| '------------------' |");
  mvwprintw(tela_mostra_fig, 16+y, x,"'----------------------'");
  }
  if(jogador->figurinhas & 4){
    int x=80;
    int y=3;
   mvwprintw(tela_mostra_fig, 1+y, x,".--------------------.");
   mvwprintw(tela_mostra_fig, 2+y, x,"|                    |");
   mvwprintw(tela_mostra_fig, 3+y, x,"|         __         |");
   mvwprintw(tela_mostra_fig, 4+y, x,"|      -=(o '.       |");
   mvwprintw(tela_mostra_fig, 5+y, x,"|         '.-.\\      |");
   mvwprintw(tela_mostra_fig, 6+y, x,"|         /|  \\\\     |");
   mvwprintw(tela_mostra_fig, 7+y, x,"|         '|  ||     |");
   mvwprintw(tela_mostra_fig, 8+y, x,"|          _\\_):,_   |");
   mvwprintw(tela_mostra_fig, 9+y, x,"|                    |");
   mvwprintw(tela_mostra_fig, 10+y, x,"|                    |");
   mvwprintw(tela_mostra_fig, 11+y, x,"'--------------------'");
  }

  else{
  int x=80;
  int y=3;
  mvwprintw(tela_mostra_fig, 1+y, x,".--------------------.");
  mvwprintw(tela_mostra_fig, 2+y, x,"| .----------------. |");
  mvwprintw(tela_mostra_fig, 3+y, x,"| |     ______     | |");
  mvwprintw(tela_mostra_fig, 4+y, x,"| |    / ____ `.   | |");
  mvwprintw(tela_mostra_fig, 5+y, x,"| |    `'  __) |   | |");
  mvwprintw(tela_mostra_fig, 6+y, x,"| |    _  |__ '.   | |");
  mvwprintw(tela_mostra_fig, 7+y, x,"| |   | |____) |   | |");
  mvwprintw(tela_mostra_fig, 8+y, x,"| |    |______.'   | |");
  mvwprintw(tela_mostra_fig, 9+y, x,"| |                | |");
  mvwprintw(tela_mostra_fig, 10+y, x,"| '----------------' |");
  mvwprintw(tela_mostra_fig, 11+y, x,"'--------------------'");
  }

  if(jogador->figurinhas & 8){
    int y=16;
    int x=80;
   mvwprintw(tela_mostra_fig, 1+y, x,".------------------------.");
   mvwprintw(tela_mostra_fig, 2+y, x,"|                        |");
   mvwprintw(tela_mostra_fig, 3+y, x,"|    ___                 |");
   mvwprintw(tela_mostra_fig, 4+y, x,"| __/_  `.  .-'''-.      |");
   mvwprintw(tela_mostra_fig, 5+y, x,"| \\_,` | \\-'  /   )`-')  |");
   mvwprintw(tela_mostra_fig, 6+y, x,"|  '') `''`    \\  ((`'`  |");
   mvwprintw(tela_mostra_fig, 7+y, x,"| ___Y  ,    .'7 /|      |");
   mvwprintw(tela_mostra_fig, 8+y, x,"|(_,___/...-` (_/_/      |");
   mvwprintw(tela_mostra_fig, 9+y, x,"|                        |");
   mvwprintw(tela_mostra_fig, 10+y, x,"|                        |");
   mvwprintw(tela_mostra_fig, 11+y, x,"'------------------------'");
  }

  else{
  int y=16;
  int x=80;
  mvwprintw(tela_mostra_fig, 1+y, x,".------------------------.");
  mvwprintw(tela_mostra_fig, 2+y, x,"| .--------------------. |");
  mvwprintw(tela_mostra_fig, 3+y, x,"| |      _    _        | |");
  mvwprintw(tela_mostra_fig, 4+y, x,"| |     | |  | |       | |");
  mvwprintw(tela_mostra_fig, 5+y, x,"| |     | |__| |_      | |");
  mvwprintw(tela_mostra_fig, 6+y, x,"| |     |____   _|     | |");
  mvwprintw(tela_mostra_fig, 7+y, x,"| |         _| |_      | |");
  mvwprintw(tela_mostra_fig, 8+y, x,"| |        |_____|     | |");
  mvwprintw(tela_mostra_fig, 9+y, x,"| |                    | |");
  mvwprintw(tela_mostra_fig, 10+y, x,"| '--------------------' |");
  mvwprintw(tela_mostra_fig, 11+y, x,"'------------------------'");
  }


  //frase principal
  mvwprintw(tela_mostra_fig, y/2-3,x/2-30,"Clique em algum botão para sair");
	wmove(tela_mostra_fig, 0,0);
  wrefresh(tela_mostra_fig);

  //espera clique
  char char_mostra_fig;
  char_mostra_fig = getch();

  //deleta janela
  delwin(tela_mostra_fig);
  endwin();
}
