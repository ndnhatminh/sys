/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef _H_STUDY_IN_PINK_1_H_
#define _H_STUDY_IN_PINK_1_H_

#include "main.h"

bool readFile( const string & filename, int & HP1, int & HP2, int & EXP1, int & EXP2, int & M1, int & M2, int & E1, int & E2, int & E3);

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Change HP
void change_hp(int & hp);

// Change EXP
void chang_exp(int & exp);

// Change MONEY
void change_money(int & m);

//Check square number
int nearest_square_number(int & exp);

//Tim E2
int E2_can_tim (int & E2);

//Tim i,j
int so_can_tim (int & k);

//Ba ki tu lien tiep
bool ba_ki_tu_lt (string & s_string, int & so_ki_tu, int & sci);

//Ki tu dac biet
bool ki_tu_dac_biet(string & s_string, int & so_ki_tu);

//Vi pham
bool vi_pham(string & s_string, int & so_ki_tu, int & vi_tri_vi_pham);

//Ket qua bai 5
int ket_qua(int & num_pwds, int so_lan_xuat_hien[], int do_dai_chuoi[], int & vi_tri_tra_ve);

//Lam tron len
int ceil1(float & a);

// Task 1
int firstMeet(int & exp1, int & exp2, int e1);

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3);

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3);

// Task 4
int checkPassword(const char * s, const char * email);

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds);

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* _H_STUDY_IN_PINK_1_H_ */
