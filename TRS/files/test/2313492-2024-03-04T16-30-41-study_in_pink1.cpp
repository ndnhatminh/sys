#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0) || (e1 > 99)) return -99;
    else {
    EXP(exp1);
    EXP(exp2);
    E(e1);
    if (e1 < 4) {
        switch (e1) {
        case 0:
            exp2 += 29;
            EXP(exp2)
            break;
        case 1:
            exp2 += 45;
            EXP(exp2)
            break;
        case 2:
            exp2 += 75;
            EXP(exp2)
            break;
        case 3:
            exp2 += (29 + 45 + 75);
            EXP(exp2)
            break;
        }

        int D = 3 * e1 + 7 * exp1;

        if ((D % 2) == 0) {
            exp1 = ceil(exp1 + D/200.0);
            EXP(exp1);
        }

        else {
            exp1 = ceil(exp1 - D/100.0);
            EXP(exp1);
        }
    }
    else {
        if (e1 <= 19) {
            exp2 += 1.0 * e1 / 4 + 19 + 0.999;
            EXP(exp2);
        }

        if (e1 >= 20 && e1 <= 49) {
            exp2 += 1.0 * e1 / 9 + 21 + 0.999;
            EXP(exp2);
        }

        if (e1 >= 50 && e1 <= 65) {
            exp2 += 1.0 * e1 / 16 + 17 + 0.999;
            EXP(exp2);
        }

        if (e1 >= 66 && e1 <= 79) {
            exp2 += 1.0 * e1 / 4 + 19 + 0.999;
            EXP(exp2);
            if (exp2 > 200) exp2 += 1.0 * e1 / 9 + 21 + 0.999;
            EXP(exp2);
        }

        if (e1 >= 80 && e1 <= 99) {
            exp2 += 1.0 * e1 / 4 + 19 + 0.999;
            EXP(exp2);
            exp2 += 1.0 * e1 / 9 + 21 + 0.999;
            EXP(exp2);
            if (exp2 > 400) {
                exp2 += 1.0 * e1 / 16 + 17 + 0.999;
                exp2 = exp2 * 1.15 + 0.999;
                EXP(exp2);
            }
        }


      exp1 -= e1;
    }

    EXP(exp1);
    EXP(exp2);
  }
    
    return exp1 + exp2;
  
}


// Task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
  int final = 0;
  if (E2 < 0 || E2 > 99) final = -99;
  else {
    HP(HP1);
    EXP(EXP1);
    M(M1);
    // con đường 1 
    float P1 = 1;
    int S1 = nearestSquare(EXP1);
    if ( EXP1 >= S1 ) P1 = 1.0;
    else P1 = ( (1.0*EXP1/S1) + 80 )/123;

    //con duong 02
    //E2 le
    if (E2 % 2 == 1) { 
      float half = M1 / 2;
      HP(HP1);
      EXP(EXP1);
      M(M1);
      while (M1 > 0 && 1.0*M1 >= half) {
        //1
        if (HP1 < 200) {
          HP1 = up(HP1 * 1.3);
          M1 -= 150;
          HP(HP1);
          M(M1);
        }
        else {
          HP1 = up(HP1 * 1.1);
          M1 -= 70;
          HP(HP1);
          M(M1);
        }
        HP(HP1);

        if ( M1 < half) break;
        // 2
        if (EXP1 < 400) {
          M1 -= 200;
        }
        else {
        M1 -= 120;
        }
        M(M1);
        EXP1 = up(EXP1 * 1.13);
        EXP(EXP1);

        if ( M1 < half) break;
        // 3
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        M(M1);
        EXP1 = up(EXP1 * 0.9);
        EXP(EXP1);
        if ( M1 < half) break;        
      }
    }
    else {
      for (int i = 0; i < 1; i++){
        HP(HP1);
        EXP(EXP1);
        M(M1);
        // 1
        if ( M1 <= 0) break;
        if (HP1 < 200) {
          HP1 = up(HP1 * 1.3);
          M1 -= 150;
          HP(HP1);
          M(M1);
        }
        else {
          HP1 = up(HP1 * 1.1);
          M1 -= 70;
        }
        HP(HP1);
        M(M1);

        if ( M1 == 0) break;
        // 2
        if (EXP1 < 400) M1 -= 200;
        else M1 -= 120;
        M(M1);
        EXP1 = up(EXP1 * 1.13);
        EXP(EXP1);
        
        if ( M1 == 0) break;
        // 3
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;
        M(M1);
        EXP1 = up(EXP1 * 0.9);
        EXP(EXP1);
        if ( M1 == 0) break;
      } 
    }

    HP1 = up(HP1 * 0.83);
    EXP1 = up(EXP1 * 1.17);
    HP(HP1);
    EXP(EXP1);

    float P2 = 1;
    int S2 = nearestSquare(EXP1);
    if ( EXP1 >= S2 ) P1 = 1.0;
    else P2 = ( (1.0*EXP1/S2) + 80 )/123;

    // con duong 3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    int i = 0;
    i = onedigittask2(E2);
    float P3 = P[i] / 100.0f;
    
    if (P1 == P2 && P1 == P2 && P3 == 1) {
      EXP1 = up(EXP1 * 0.75);
      EXP(EXP1);
    }
    else {
      float Paverage = (P1 + P2 + P3) / 3;
      if (Paverage < 0.5) {
        HP1 = up(HP1 * 0.85);
        EXP1 = up(EXP1 * 1.15);
      }
      else {
        HP1 = up(HP1 * 0.9);
        EXP1 = up(EXP1 * 1.2);
      }
      EXP(EXP1);
      HP(HP1);
    }
    final = HP1 + EXP1 + M1;
  }
  return final;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
  int final = 0;
  if ((E3 < 0) || (E3 > 99)) final = -99;
  else {
  
  //tao map
    HP(HP1);
    HP(HP2);
    EXP(EXP1);
    EXP(EXP2);
    int map[10][10] = {{0}};

    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        map[i][j] = (E3 * j + i * 2) * (i - j);
      }
    }

  // tim i j
    int firstRow = 0;
    int firstCol = 0;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (map[i][j] > E3 * 2) firstRow++;
        if (map[i][j] < -E3) firstCol++;
      }
  }

    int Row = onedigit(firstRow); 
    int Col = onedigit(firstCol); 
    int SWpoint = map[Row][Col];

  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
        int newRow = Row + i;
        int newCol = Col + j;
        while (newRow >= 0 && newRow < 10 && newCol >= 0 && newCol < 10) {
          if (map[newRow][newCol] > SWpoint) {
            SWpoint = map[newRow][newCol];
          }
          newRow += i;
          newCol += j;
        }
    }
  }
                                                                  //cout << Row << endl << Col << endl << NewRow << endl << NewCol << endl;
    
    SWpoint = abs(SWpoint);

    if (abs(map[Row][Col]) > SWpoint) {
      EXP1 = up(EXP1 * 0.88); 
      EXP2 = up(EXP2 * 0.88); 
      HP1 = up(HP1 * 0.9); 
      HP2 = up(HP2 * 0.9); 
      HP(HP1);
      HP(HP2);
      EXP(EXP1);
      EXP(EXP2);
      final = map[Row][Col];
    }
  else {
      EXP1 = up(EXP1 * 1.12); 
      EXP2 = up(EXP2 * 1.12); 
      HP1 = up(HP1 * 1.1); 
      HP2 = up(HP2 * 1.1); 
      HP(HP1);
      HP(HP2);
      EXP(EXP1);
      EXP(EXP2);
      final = SWpoint;
    }
  }

  return final;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string emailcopy = email;
    string scopy = s;
    string se = emailcopy.substr(0, emailcopy.find('@'));
    
    if ( scopy.length() < 8 ) return -1;
    if ( scopy.length() > 20) return -2;

    if ( scopy.find(se) != string::npos ){
        return -(300 + scopy.find(se) );
    }

    for (int i = 0; i < scopy.length() - 2; ++i) {
        if (scopy[i] == scopy[i + 1] && scopy[i+1] == scopy[i + 2]) {
            return -( 400 + i );
        }
    }

    int count = 0;
    for (int i = 0; i < scopy.length(); i++){
      char u = scopy[i];
      if ( u == '@' || u == '#' || u == '$' || u == '!' || u == '%'){
      count++;
      }
    }
    if (count == 0) return -5;

    

    for (int i = 0; i < scopy.length(); i++) {
        char c = scopy[i];
        if ( !thuonghoaso(c)  &&  c != '@' && c != '#' &&  c != '%' && c != '$' && c != '!') {
            return i;  
        }
    }
    
  return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int * exist = new int[num_pwds];
    int max = 0;
    int length = 0;
    int pos = 0;
    int count = 0;

    for  (int i = 0; i < num_pwds; i++) exist[i] = 1;
      for (int i = 0; i < num_pwds; i++) {
        for (int j = i + 1; j < num_pwds; j++) {
          if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
            exist[i]++;
          } 
        }
      }
      

    for (int i = 0; i < num_pwds; i++) {
      if (exist[i] > max) max = exist[i];
    }


    for (int i = 0; i < num_pwds; i++) {
      if (strlen(arr_pwds[i]) > length) {
        length = strlen(arr_pwds[i]);
      }
    }
     
  
    for (int i = 0; i < num_pwds; i++) {
      if (exist[i] == max) count++;
    }
   
    if (count == 1) {
      for (int i = 0; i < num_pwds; i++) {
        if (exist[i] == max) {
          pos = i;
          break;
        }
      }
    }
    if (count > 1) {
      for (int i = 0; i < num_pwds; i++) {
        if ((exist[i] == max) && (strlen(arr_pwds[i]) == length)) {
          
          pos = i;

          break;
        }
      }
    }
    delete[] exist;
    return pos;
}



//Task 2: ham tim so chinh phuong gan nhat
int nearestSquare(int a) {
    
    int b = sqrt(a);
    int c = b * b;
    int d = (b + 1) * (b + 1);
    if (abs(d - a) < abs(c - a)) return d;
    else return c;
}
//Task 2: Ham xu ly so cua con duong 3
int onedigit(int E2) {
    if (E2 < 10) return E2;
    else {
        int sum = 0;
        while (E2) {
            sum += E2 % 10;
            E2 /= 10;
        }
        return onedigit(sum);
    }
}

int onedigittask2(int E2) {
  if (E2 < 10) return E2;
    else {
      int sum = 0;
      sum = E2%10 + E2/10 ;
      return sum%10;
    }
}

// Task 3: kiem tra cheo trai va phai

int up(float a){
  a = (int) ( a + 0.999);
  return a;
}

int thuonghoaso(int a) {
return ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9'));
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////