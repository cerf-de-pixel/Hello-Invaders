
/*********************************************
**          -   Hello Invaders   -          **
**********************************************
**                                          **
**      Programmer par twiy-logic.fr        **
**         <julien@twiy-logic.fr>           **
**                                          **
**********************************************/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "ConsoleUtile.h"

using namespace std;


void menue();
void pressentation();
void ecrans_help();
void game_over(int score);
void fond_ecran();
void jeux_pause();
void game();
void afficher_coeurs(int nb_vie);
void afficher_mode_programmeur(int v_sleep, int compteur, int cycle);

const char up(72), down(80), ok(13), shoot(32);
const int axe_veseau(50);
bool never_end(true);

int _tmain(int argc, _TCHAR* argv[])
{
	system("title Hello Invaders  ");
	pressentation();
	menue();
	game();
}

/**************************************
*         Affiche le menu             *
***************************************
*    - Renvoi vers 'ecran_help'       *
*      ou 'game'                      *
***************************************/
void menue()
{
	
	color(11);
	cout << endl;
	cout << "               _____________________________________________              " << endl;
	cout << "              |                                             |             " << endl;
	cout << "              |         Etes vous pret a survivre ?         |             " << endl;
	cout << "              |_____________________________________________|             " << endl;
	cout << endl << endl;
	color(10);
	cout << "                           Faites votre choix                             " << endl;
	cout << "                                                                          " << endl;
	cout << "                   ,---------------------------------,                    " << endl;
	cout << "                   |         "; 
	color(11); 
	cout << "    JOUER !    "; 
	color(10); 
	cout << "         |                    " << endl;
	cout << "                   '---------------------------------'                    " << endl;
	cout << endl;
	cout << "                   ,---------------------------------,                    " << endl;
	cout << "                   |             Aide ?              |                    " << endl;
	cout << "                   '---------------------------------'                    " << endl;

	color(12); 
	GotoXY(12, 10); cout << "-->";

	int fleche(1);
	char touche(_getch());

	while (touche != ok)
	{

		if (touche == up)	{ fleche--; }
		if (touche == down)	{ fleche++; }

		if (fleche == 0)	{ fleche = 2; }
		if (fleche == 3)	{ fleche = 1; }
		/// la nouvelle valeur de la fleche a été donné

		color(12);

		if (fleche == 1){
			GotoXY(12, 10); cout << "-->";
			GotoXY(12, 14); cout << "   ";
			GotoXY(12, 18); cout << "   ";
		}

		else if (fleche == 2){
			GotoXY(12, 10); cout << "   ";
			GotoXY(12, 14); cout << "-->";
			GotoXY(12, 18); cout << "   ";
		}

		else { cout << "erreur;  position fleche impossible"; }
		touche = _getch();
	} /// fin de la boucle du menu

	ClearScreen();

	// on n'a pas besoin de preciser ce qui ce passe si fleche == 1
	if		(fleche == 2)	{ ecrans_help(); }
	else if (fleche == 1)	{ fond_ecran(); game(); }

	color(9);
} ///fin de la fonction menu

/****************************************
*  c'est le premier ecran qui apparait  *
*****************************************/
void pressentation(){

	color(10);

	cout << endl;
	cout << "                    _   _   _____   _       _       _____   " << endl;
	cout << "                   | | | | |  ___| | |     | |     /  _  1  " << endl;
	cout << "                   | |_| | | |__   | |     | |     | | | |  " << endl;
	cout << "                   |  _  | |  __|  | |     | |     | | | |  " << endl;
	cout << "                   | | | | | |___  | |___  | |___  | |_| |  " << endl;
	cout << "                   |_| |_| |_____| |_____| |_____| 1_____/  " << endl;
	cout << endl << endl;
	cout << "       _____   __   _   _     _     ___   _____   _____   _____    _____  " << endl;
	cout << "      |_   _| |  1 | | | |   / /   /   | |  _  1 | ____| |  _  1  /  ___/ " << endl;
	cout << "        | |   |   1| | | |  / /   / /| | | | | | | |__   | |_| |  | |___  " << endl;
	cout << "        | |   | |1   | | | / /   / /_| | | | | | |  __|  |  _  /  1___  1 " << endl;
	cout << "       _| |_  | | 1  | | |/ /   / ,__  | | |_| | | |___  | | 1 1   ___| | " << endl;
	cout << "      |_____| |_|  1_| |___/   /_/   |_| |_____/ |_____| |_|  1_1 /_____/ " << endl;
	cout << endl << endl << endl << endl; color(9);
	cout << "                           Programme par twiy-logic.fr     " << endl << endl << endl;
	cout << "                       Tapez sur une touche pour continuer " << endl;
	
	fflush(stdout);
	_getch();
	ClearScreen();
}

/*****************************************************
*  ecran qui affiche l'aide et renvoie vers le menu  *
******************************************************/
void ecrans_help(){

	color(9);

	cout << endl;
	cout << "                     Bienvenue dans HELLO INVADERS,                       " << endl << endl;
	cout << "     Le but de ce jeu est de detruire le plus d'asteroides possible       " << endl << endl;
	cout << "       -  Si un asteroide franchit la frontiere, vous perdez une vie      " << endl << endl;
	cout << "       -  si vous detruisez un asteroide, vous gagnez 10 points           " << endl << endl << endl;
	cout << "                              ,---------------,        " << endl;
	cout << "                              | les touches : |        " << endl;
	cout << "                              '---------------'        " << endl << endl;
	cout << "                              Up   :   'Fleche Haut'   " << endl << endl;
	cout << "                             Down  :   'Fleche Bas'    " << endl << endl;
	cout << "                              Ok   :    ENTRE          " << endl << endl;
	cout << "                           Sshoot  :    ESPACE			" << endl << endl << endl;
	cout << "                    Tapez sur une touche pour continuer" << endl << endl;

	fflush(stdout);
	_getch();
	ClearScreen();
	menue();
}

/*****************************************************
*  ecran qui s'affiche quand les vies sont epuisées  *
*               renvoi ver le menu                   *
******************************************************/
void game_over(int score){

	ClearScreen();

	color(12);

	cout << endl;
	cout << "         _____       ___       ___  ___   _____  " << endl;
	cout << "        /  ___|     /   |     /   |/   | | ____| " << endl;
	cout << "        | |        / /| |    / /|   /| | | |__   " << endl;
	cout << "        | | __    / / | |   / / |__/ | | |  __|  " << endl;
	cout << "        | |_| |  / /  | |  / /       | | | |___  " << endl;
	cout << "        1_____/ /_/   |_| /_/        |_| |_____| " << endl << endl << endl;
	cout << "                                 _____   _     _   _____   _____   " << endl;
	cout << "                                /  _  1 | |   / / | ____| |  _  1  " << endl;
	cout << "                                | | | | | |  / /  | |__   | |_| |  " << endl;
	cout << "                                | | | | | | / /   |  __|  |  _  /  " << endl;
	cout << "                                | |_| | | |/ /    | |___  | | 1 1  " << endl;
	cout << "                                1_____/ |___/     |_____| |_|  1_1 " << endl;
	cout << endl << endl << endl;
	cout << "                                 SCORE :  " << score << endl << endl << endl;
	cout << "                                 twiy-logic.fr                 " << endl << endl;
	cout << "                       tapez sur une touche pour continuer		" << endl;

	Sleep(2000);
	fflush(stdout);
	_getch();
	ClearScreen();
	menue();
}

/************************************
*  dessine le fond d'ecran du jeu	*
*************************************/
void fond_ecran()
{
	color(9);

	cout << "  ______________________________________________________          " << endl;
	cout << " .-----------------------------------------------------.|         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||  Score :" << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||   Vie  :" << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     ||         " << endl;
	cout << " |                                                     |,         " << endl;
	cout << " '-----------------------------------------------------'          " << endl;
}

/***********************************************
*  affiche un message 'pause', stoppe le jeu   *
* tant qu'une touche n'est pas tapée et        *
* efface le message                            *
************************************************/
void jeux_pause()
{
	GotoXY(10, 10);		cout << " .-----------. " << endl;
	GotoXY(10, 11);		cout << " |   PAUSE   | " << endl;
	GotoXY(10, 12);		cout << " '-----------' " << endl;

	fflush(stdout);
	_getch();

	GotoXY(10, 10);		cout << "               " << endl;
	GotoXY(10, 11);		cout << "               " << endl;
	GotoXY(10, 12);		cout << "               " << endl;
}

void game()
{
	bool v_shoot(false), v_shoot1(false), mode_programmeur(false);
	int score(0), vie(3), niveau, v_sleep(70), axe_shoot, position_shoot, cycle(1), axe_asteroide;
	int position(7);     // 15 positions possible
	int compteur(1);
	char touche;

	while (never_end)
	{
		/* Une touche a enfin ete frappee. Lire son code. */
		while (!_kbhit())
		{
			color(5);
			position -= 2; GotoXY(axe_veseau, position); cout << "    "; position += 2;
			position--; GotoXY(axe_veseau, position); cout << "  ,I";
			position++; GotoXY(axe_veseau, position); cout << "<=KE";
			position++; GotoXY(axe_veseau, position); cout << "  'I";
			position--; // on retrouve la position initial
			position += 2; GotoXY(axe_veseau, position); cout << "    "; position -= 2; 
			
			/*************************** 			 
			*   code des asteroides 1  * 			 
			****************************/	 			
			if (compteur > 5)
			{
				if		(cycle == 1)	{ axe_asteroide = 10; }
				else if (cycle == 2)    { axe_asteroide = 16; }
				else if (cycle == 3)    { axe_asteroide = 9;  }
				else if (cycle == 4)    { axe_asteroide = 12; }
				else if (cycle == 5)    { axe_asteroide = 15; }
				else if (cycle == 6)    { axe_asteroide = 8;  }
				else if (cycle == 7)    { axe_asteroide = 6;  }
				else if (cycle == 8)    { axe_asteroide = 10; cycle = 1; }

				GotoXY(compteur, axe_asteroide);
				color(11);
				cout << "  O";
			}

			if (compteur == 50)
			{
				GotoXY(compteur - 2, axe_asteroide);
				cout << "      ";
				vie--;
				if (vie == 0){ game_over(score); }
			}

			/***************************
			*      code des tirs       *
			****************************/
			color(14);
			if (v_shoot1 == true) // efface de rayon de tir
			{
				GotoXY(axe_shoot, position_shoot);
				cout << "                                                ";
				v_shoot1 = false;
			}

			if (v_shoot == true) // affiche le rayon de tir
			{
				axe_shoot = axe_veseau - 48;
				position_shoot = position;
				GotoXY(axe_shoot, position_shoot);
				cout << "--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=->";
				v_shoot = false;
				v_shoot1 = true;
				if (axe_asteroide == position_shoot){ compteur = 0; cycle++; score += 10; }
			}

			/***************************
			*   compteur et cycles     *
			****************************/

			if (score > 50)		{ v_sleep = 50; }
			if (score > 80)		{ v_sleep = 30; }
			if (score > 100)	{ v_sleep = 25; }
			if (score > 150)	{ v_sleep = 20; }
			if (score > 300)	{ v_sleep = 15; }
			if (score > 500)	{ v_sleep = 10; }

			if (mode_programmeur == true) { afficher_mode_programmeur(v_sleep, compteur, cycle); }

			compteur++;
			if (compteur > 50)	{ compteur = 0; cycle++; }
			Sleep(v_sleep);

			/***************************
			*    score et resultats    *
			****************************/
			color(11);

			GotoXY(70, 3);	cout << "         ";
			GotoXY(70, 3);	cout << score;

			GotoXY(70, 5);	cout << "         ";
			GotoXY(70, 5);	cout << vie;

			afficher_coeurs(vie);

		}// fin de la boucle d'affichage

		touche = _getch();
		v_shoot = false;

		///on relie la touche avec ces actions
		if		(touche == up)		{ position--; }
		else if (touche == down)	{ position++; }
		else if (touche == shoot)	{ v_shoot = true; }
		else if (touche == ok)		{ jeux_pause(); }
		else if (touche == 'a')
		{
			if		(mode_programmeur == true)	{ mode_programmeur = false; }
			else if (mode_programmeur == false) { mode_programmeur = true; }
		}

		///on verifie que le veseau ne sort pas du cadre
		if (position == 3)	{ position = 4; }
		if (position == 17)	{ position = 16; }
	}//fin de while != ok

} ///fin de la fonction



void afficher_coeurs(int nb_vie)
{
	color(13);
	GotoXY(0, 20);
	if (nb_vie == 1)
	{
		cout << "         ,-. .-,                                  " << endl;
		cout << "        [   '   ]                                 " << endl;
		cout << "         ',   ,'                                  " << endl;
		cout << "           '.'                                    " << endl;
	}

	else if (nb_vie == 2)
	{
		cout << "         ,-. .-,        ,-. .-,                   " << endl;
		cout << "        [   '   ]      [   '   ]                  " << endl;
		cout << "         ',   ,'        ',   ,'                   " << endl;
		cout << "           '.'            '.'                     " << endl;
	}

	else if (nb_vie == 3)
	{
		cout << "         ,-. .-,        ,-. .-,        ,-. .-,    " << endl;
		cout << "        [   '   ]      [   '   ]      [   '   ]   " << endl;
		cout << "         ',   ,'        ',   ,'        ',   ,'    " << endl;
		cout << "           '.'            '.'            '.'      " << endl;
	}
}

// permet d'afficher a l'écran des informations inutiles pour les
// joueurs mais qui peuvent etre utile pour surveiller le programme
void afficher_mode_programmeur(int v_sleep, int compteur, int cycle)
{
	GotoXY(75, 23);		cout << "         ";
	GotoXY(75, 23);		cout << v_sleep;

	GotoXY(75, 19);		cout << "         ";
	GotoXY(75, 19);		cout << compteur;

	GotoXY(75, 21);		cout << "         ";
	GotoXY(75, 21);		cout << cycle;
}
