#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
#include <iostream>

int updateEXP(int EXP) {
    if (EXP > 600) {
        return 600;
    } else if (EXP < 0) {
        return 0;
    } else {
        return EXP;
    }
}


int firstMeet(int &EXP1, int &EXP2, int E1) {
    
  
      if(E1 <0 || E1 >99) return -99; 
    else{
        if(E1 >= 0 && E1 <=3){ 
    switch (E1) {
        case 0:
            EXP2 += 29;
            break;
        case 1:
            EXP2 += 45;
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3:
            EXP2 += 29 + 45 + 75;
            break;
        default:
            break;
    }
        
    
    
    int D = E1 * 3 + EXP1 * 7;
    
   
    if (D % 2 == 0) {
        EXP1 = ceil(EXP1 + D/200.0);
    } else {
        EXP1 = ceil(EXP1 - D/100.0);
    }
    EXP1 = updateEXP(EXP1);
    EXP2 = updateEXP(EXP2);
        }
    
     else if (E1 >= 4 && E1 <= 19) {
        EXP2 += ceil(E1 / 4.0 + 19);
        EXP1 -= E1;
        EXP1 = updateEXP(EXP1);
        EXP2 = updateEXP(EXP2);
    } else if (E1 <= 49) {
        EXP2 = ceil(EXP2+(E1 / 9.0 + 21));
        EXP1 -= E1 ; 
        EXP1 = updateEXP(EXP1);
        EXP2 = updateEXP(EXP2);
    } else if (E1 >= 50 && E1 <= 65) {
        EXP2 += ceil(E1 / 16.0 + 17);
        EXP1 -= E1;
        EXP1 = updateEXP(EXP1);
        EXP2 = updateEXP(EXP2);
    } else if (E1 >= 66 && E1 <= 79) {
        EXP2 += ceil(E1 / 4.0 + 19); 
          if (EXP2 > 200) {
                EXP2 += ceil(E1 / 9.0 + 21); 
           
          }     else {EXP2 = EXP2*1;}
           EXP1 -= E1;
            EXP1 = updateEXP(EXP1);
            EXP2 = updateEXP(EXP2);         
    }
     else if (E1 >= 80 && E1 <= 99) {
        EXP2 += ceil(E1 / 4.0 + 19); 
         EXP2 += ceil(E1 / 9.0 + 21); 
              if (EXP2 > 400) {
                EXP2 += ceil(E1 / 16.0 + 17); 
                
            
             EXP2 = ceil(EXP2 * 1.15);
              }else {EXP2 = EXP2*1;}
            EXP1 -= E1; 
            EXP1 = updateEXP(EXP1);
            EXP2 = updateEXP(EXP2);
        }

}

  
    return EXP1 + EXP2;
}



// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
   
   double P1, P2, P3;
    int S = round(sqrt(EXP1));
    S = S * S;
    if (EXP1 >= S)
    {
        P1 = 100;
    }
    else
    {
        P1 = 100* ( EXP1/S + 80.0)/ 123.0;
    }
    
    if ( M1 == 0){
        HP1 = ceil(HP1 *0.83);
        EXP1 = ceil(EXP1 *1.17);
    }

    else { if ( E2<0||E2 >99) return -99;
        else if (E2 % 2 == 0)
    {
        while (M1)
        {
          if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }

            if (M1 <= 0)
                break;
            // su kien 2
              if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 = ceil(EXP1 * 1.13);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 1.13);
                }
            

            if (M1 <= 0)
                break;

            // su kien 3
            if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil(EXP1 * 0.9);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 0.9);
                }

            break;
        }
                if(M1 < 0){
                  M1 = 0;
                  }else if (M1 >3000){
                       M1 = 3000;
                       }
         }

      else {
        double halfM = 0.5 * M1;
        while (M1)
        {
            // su kien 1
             if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            }
            else
            {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            }

            if (M1 <= 0 || M1 < halfM)
                break;
            //su kien 2
            if (EXP1 < 400)
                {
                    M1 -= 200;
                    EXP1 = ceil(EXP1 * 1.13);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 1.13);
                }

            if (M1 <= 0 || M1 < halfM)
                break;

            // su kien 3
            if (EXP1 < 300)
                {
                    M1 -= 100;
                    EXP1 = ceil(EXP1 * 0.9);
                }
                else
                {
                    M1 -= 120;
                    EXP1 = ceil(EXP1 * 0.9);
                }

            if (M1 <= 0 || M1 < halfM)
                break;
        }
        if(M1 < 0){
           M1 = 0;
            }else if (M1 >3000){
                 M1 = 3000;
                }
    }
    
    }
    if (HP1 > 666){
        HP1 = 666;
    }else if(HP1 < 0){
        HP1=0;
    }

    HP1 = ceil(HP1 *0.83);
    EXP1 = ceil(EXP1 *1.17);

    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
        }
    

    // tang giam HP EXP
    // check EXP > 600

    S = round(sqrt(EXP1));
    S = S * S;
    if (EXP1 >= S)
    {
        P2 = 100;
    }
    else
    {
         P2 = 100 * (EXP1/S + 80.0)/123.0;
    }

    double P[10]  =  {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};

    int index = (E2 / 10 + E2 % 10) % 10;
      P3 = P[index];

    double Ptrungbinh = (P1 + P2 + P3)/3 ;  // double Ptrungbinh 

    if (P1 == 100 && P2 == 100 && P3 == 100)
    {
        EXP1 = ceil(EXP1*0.75);
    }
    else if (Ptrungbinh < 50)
    {
        HP1 = ceil(HP1 * 0.85);
        EXP1 = ceil(EXP1 * 1.15);
    }
    else
    {
        HP1 = ceil(HP1 * 0.9);
        EXP1 = ceil( EXP1 *1.2);
    }
    // check EXP > 600
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
        }
   

    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
   int tenMaTran[10][10] = {0};
  int countI = 0, countJ = 0;
    if(E3 <0 || E3 >99){return -99;}
    else {E3 = E3;}
  // Tính điểm cho taxi
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      tenMaTran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
      if (tenMaTran[i][j] > (E3 * 2) ) {
        countI++;
      }
      if (tenMaTran[i][j] < (-E3)) {
        countJ++;
      }
    }
  }

  // Xử lý số có 2 chữ số
  countI = countI / 10 + countI % 10;
  countI = countI / 10 + countI % 10;
  countJ = countJ / 10 + countJ % 10;
  countJ = countJ / 10 + countI % 10;

  // Tìm điểm cho Sherlock và Watson
  int diemSherlock = tenMaTran[countI][countJ];
  int diemtaxi = tenMaTran[countI][countJ];
  for (int i = 0; i < 10; i++) {
    int j = countJ - countI + i;
      if ((0+i)>=0 && (j >=0) && (j<=9) && (0+1)<=9) {
        if (tenMaTran[i][j] > diemSherlock) {
          diemSherlock = tenMaTran[i][j];
        }
      }
  }
  for (int i=0; i < 10; i++ ){
    int j = countI + countJ - i;
      if ((0+i)>=0 && (j >=0) && (j<=9) && (0+1)<=9) {
        if (tenMaTran[i][j] > diemSherlock) {
          diemSherlock = tenMaTran[i][j];
        }
      }
    }
  

  // Lấy giá trị tuyệt đối và so sánh
  diemSherlock = abs(diemSherlock);
  if (diemSherlock >= abs(diemtaxi)) {
    // Sherlock và Watson đuổi kịp taxi
    HP1  = ceilf(HP1*110.0/100);
    EXP1 = ceilf(EXP1 * 112.0/100);
    HP2  = ceilf(HP2*110.0/100);
    EXP2 = ceilf(EXP2 * 112.0/100);
     if (HP1 > 666){
        HP1 = 666;
    }else if(HP1 < 0){
        HP1=0;
    }
    if (HP2 > 666){
        HP2 = 666;
    }else if(HP2 < 0){
        HP2=0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
        }
    if (EXP2 > 600) {
        EXP2 = 600;
    } else if (EXP2 < 0) {
        EXP2 = 0;
        }
    return diemSherlock;
  } else {
    // Sherlock và Watson không đuổi kịp taxi
   
    HP1  = ceilf(HP1*90.0/100);
    EXP1 = ceilf(EXP1*88.0/100);
    HP2  = ceilf(HP2 * 90.0/100);
    EXP2 = ceilf(EXP2 * 88.0/100);
     if (HP1 > 666){
        HP1 = 666;
    }else if(HP1 < 0){
        HP1=0;
    }
    if (HP2 > 666){
        HP2 = 666;
    }else if(HP2 < 0){
        HP2=0;
    }
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
        }
    if (EXP2 > 600) {
        EXP2 = 600;
    } else if (EXP2 < 0) {
        EXP2 = 0;
        }
    return diemtaxi;
  }
}


// Task 4
int checkPassword(const char *s, const char *email) {
    string se(email);
    se = se.substr(0, se.find("@"));
    string str(s);

    if (str.length() < 8) {
        return -1;
    }

    if (str.length() > 20) {
        return -2;
    }

    size_t sei = str.find(se);
    if (sei != string::npos) {
        return -(300 + sei);
    }
    size_t sci;
    for (int i = 0; i < str.length() - 2; ++i) {
        if (str[i] == str[i + 1] && str[i] == str[i + 2]||str[i]==str[i+1] ) {
            sci = i; 
            return -(400 + sci);
        }
    }

    if (str.find("!") == string::npos && 
        (str.find("@") == string::npos && str.find("#") == string::npos && 
         str.find("$") == string::npos && str.find("%") == string::npos)) {
        return -5;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||
              (str[i] >= 'A' && str[i] <= 'Z') ||
              (str[i] >= '0' && str[i] <= '9') ||
              (str[i] == '@' || str[i] == '#' || str[i] == '$' || str[i] == '%' || str[i] == '!'))) {
            return i;
        }
    }

    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{  int soLanXuatHienMax = 0;
    int viTriMax = 0;

    for (int i = 0; i < num_pwds; ++i)
    {
        int soLanXuatHien = 0;
        for (int j = 0; j < num_pwds; ++j)
        {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                soLanXuatHien++;
            }
        }

        if (soLanXuatHien > soLanXuatHienMax)
        {
            soLanXuatHienMax = soLanXuatHien;
            viTriMax = i;
        }
        else if (soLanXuatHien == soLanXuatHienMax)
        {
            if (strlen(arr_pwds[i]) > strlen(arr_pwds[viTriMax]))
            {
                soLanXuatHienMax = soLanXuatHien;
                viTriMax = i;
            }
        }
    }

    return viTriMax;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////