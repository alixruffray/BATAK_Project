/*
 * 4_Aff_Ensemble.c
 *
 *  Created on: 15 nov. 2023
 *      Author: alexi
 */

#include "Mosfet.h"
#include "Afficheur_Sept_Seg.h"
#include "Aff_4_7_Segg.h"


void Afficher(int ms1, int ms2, int s1, int s2){
	int temps = 500;
	int i =0;
			while (temps != 0) {
				temps=temps-1;
				if (i==0){
					mosfet_Change(0);
					afficher_7_seg(ms1);
				}
				else if (i==1){
					mosfet_Change(1);
					afficher_7_seg(ms2);
				}
				else if (i==2){
					mosfet_Change(3);
					afficher_7_seg(s1);
				}
				else if (i==3){
					mosfet_Change(2);
					afficher_7_seg(s2);
				}

				if (temps==1){
					temps = 500;
					i = i+1;
				}
				if (i==4){
					i=0;
					temps=0;
				}
			}
}
