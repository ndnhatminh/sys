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
    if (e1 >= 0 && e1 <= 3) {      //case 1
        switch (e1){
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 149;
                break;
        } if (exp2 < 0) {
            exp2 = 0;
        } if (exp2 > 600) {
            exp2 = 600;
        }
        int D = (e1 * 3) + (exp1 * 7);
        if (D % 2 == 0) {
            exp1 += ceil(D/200);
        } else {
            exp1 -= ceil(D/100);  
        } if (exp1 > 600){
            exp1 = 600;
        } if (exp1 < 0) {
            exp1 = 0;
        }
    }
    if (e1 >= 4 && e1 <= 99) {         //case 2
       if ((e1 >= 4) && (e1 <= 19)){
            exp2 += e1 / 4 + (e1 % 4 != 0); //"e1 % 4 != 0" will give 1 if true and 0 if false
            exp2 += 19;
       }
        if ((e1 >= 20) && (e1 <= 49)){
            exp2 += e1 / 9 + (e1 % 9 != 0);
            exp2 += 21;
        } if ((e1 >= 50) && (e1 <= 65)){
            exp2 += e1 / 16 + (e1 % 16 != 0);
            exp2 += 17;
        } if ((e1 >= 66) && (e1 <= 79)) { 
            exp2 += e1 / 4 + (e1 % 4 != 0);
            exp2 += 19;
            if (exp2 > 200){
                exp2 += e1 / 9 + (e1 % 9 != 0);
                exp2 += 21;
            }
        } if (e1 >= 80 && e1 <= 99) {
            exp2 += e1 / 4 + (e1 % 4 != 0);
            exp2 += 19;
            exp2 += e1 / 9 + (e1 % 9 != 0);
            exp2 += 21;
            if (exp2 > 400){
             exp2 += e1 / 16 + (e1 % 16 != 0);
             exp2 += 17;
             exp2 = ceil(exp2 * 1.15);
            }
            }
        } if (exp2 < 0) {
            exp2 = 0;
        } if (exp2 > 600) {
            exp2 = 600;
        }
    if ((e1 >= 4) && (e1 <= 99)){
        exp1 -= e1;
    }  if (exp1 < 0) {
            exp1 = 0;
        }
        if (exp1 > 600) {
            exp1 = 600; 
        }
    if ((e1 > 99) || (e1 < 0)){
        return -99;
    } else {
    return exp1 + exp2;   
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function        
    if ((E2 > 99) || (E2 < 0)){
        E2 = -99;
    }
    int lower1 = sqrt(EXP1);
    int upper1 = lower1 + 1;
    int S1;
    if (abs(lower1 * lower1 - EXP1) <= abs(upper1 * upper1 - EXP1)) {
        S1 = lower1 * lower1;
    } else {
        S1 = upper1 * upper1;
    }
    double P1;
    if (EXP1 >= S1){
        P1 = 100;
    } else {
        P1 = (((static_cast<double>(EXP1) / S1) + 80) / 123.0) * 100;
    }

   int pay = M1 * 0.5;                 //road 02
    int totalcost = 0;
        if (E2 % 2 != 0){
            for(int i = 0; i < 100; i++){ 
            if (HP1 < 200){
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
                totalcost += 150;
            if (totalcost > pay) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
            }
            } else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
                totalcost += 70;
            if (totalcost > pay) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
            }
            } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
            if (EXP1 < 400){
                M1 -= 200;
                totalcost += 200;
            } else {
                M1 -= 120;
                totalcost += 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
            if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
            if (totalcost > pay) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
            }
            if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
            if (EXP1 < 300) {
            M1 -= 100;
            totalcost += 100;
            if (totalcost > pay) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
            }
        } else if (EXP1 >= 300) {
            M1 -= 120;
            totalcost += 120;
            EXP1 = ceil(EXP1 * 0.9);
            if (totalcost > pay) {
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
            }
        } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
    i++;
            }
        } else {
            for (int i = 0; i < 1; i++){
            if (HP1 < 200){
                HP1 = ceil(HP1 * 1.3);
                M1 -= 150;
            if (M1 <= 0){
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
         }
            } else {
                HP1 = ceil(HP1 * 1.1);
                M1 -= 70;
            if (M1 <= 0){
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
         }
            } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
            if (EXP1 < 400){
                M1 -= 200;
            } else {
                M1 -= 120;
            }
            EXP1 = ceil(EXP1 * 1.13);
             if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    } if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
            if (M1 <= 0){
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
         } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
            if (EXP1 < 300) {
            M1 -= 100;
            if (M1 <= 0){
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
         }
        } else if (EXP1 >= 300){
            M1 -= 120;
            EXP1 = ceil(EXP1 * 0.9);
            if (M1 <= 0){
            HP1 = ceil(HP1 * 0.83);
            EXP1 = ceil(EXP1 * 1.17);
            break;
         }
        } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
    i++;
        }
        }
     int lower2 = sqrt(EXP1);
     int upper2 = lower2 + 1;
     int S2;
    if (abs(lower2 * lower2 - EXP1) <= abs(upper2 * upper2 - EXP1)) {
        S2 = lower2 * lower2;
    } else {
        S2 = upper2 * upper2;
    }
    double P2;
    if (EXP1 >= S2){
        P2 = 100;
    } else {
        P2 = (((static_cast<double>(EXP1) / S2) + 80) / 123.0) * 100;
    }
        int i;                         //road 03
        int firstdigit, seconddigit, P;
        int P3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if (E2 < 10){
            i = E2;
        } else {
            firstdigit = E2 / 10;
            seconddigit = E2 % 10;
            i = firstdigit + seconddigit;
            i %= 10;
        }
        if ((P1 == 100) && (P2 == 100) && (P3[i] == 100)){
            EXP1 = ceil(float(EXP1 * 0.75));
        } else {
            P = (P1 + P2 + P3[i])/3;
        }
        if (P < 50){
            HP1 = ceil(float(HP1 * 0.85));
            EXP1 = ceil(float(EXP1 * 1.15));
        } else {
            HP1 = ceil(float(HP1 * 0.9));
            EXP1 = ceil(float(EXP1 * 1.2));
        }
        if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if (M1 < 0) {
        M1 = 0;
    } else if (M1 > 3000) {
        M1 = 3000;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 > 99) || (E3 < 0)){
        return -99;
    }
    int taxipoint[10][10] = {0};
    int SherlockWatson[10][10] = {0};
    int sumi = 0;
    int sumj = 0;
    int maxpoint;
    int temp;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxipoint[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    } 
   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        if (taxipoint[i][j] > E3 * 2) {
                sumi++;
            }
         if (taxipoint[i][j] < -E3) {
                sumj++;
            }
        }
    }
    while (sumi >= 10) {
        temp = 0;
        while (sumi != 0) {
            temp += sumi % 10;
            sumi /= 10;
        }
        sumi = temp;
    }   
    while (sumj >= 10) {
        temp = 0;
        while (sumj != 0) {
            temp += sumj % 10;
            sumj /= 10;
        }
        sumj = temp;
    }
    int a = sumi;
    int b = sumj;
    maxpoint = taxipoint[sumi][sumj];
    sumi = a;
    sumj = b;
    for (int i = 0; i < 10 ; i++) {
    sumi += i;
    sumj += i;
     if (sumi > 9 || sumj > 9) {
        break;
    }
    if (taxipoint[sumi][sumj] >= maxpoint) {
        maxpoint = taxipoint[sumi][sumj];
    }
}   sumi = a;
    sumj = b;

    for (int i = 0; i < 10; i++) {
    sumi -= i;
    sumj -= i;
    if (sumi < 0 || sumj < 0) {
        break;
    }
    if (taxipoint[sumi][sumj] > maxpoint) {
        maxpoint = taxipoint[sumi][sumj];
    }
}   sumi = a;
    sumj = b;

    for (int i = 0; ; i++) {
    sumi += i;
    sumj -= i;
    if (sumi >= 10 || sumj < 0) {
        break;
    }
    if (taxipoint[sumi][sumj] > maxpoint) {
        maxpoint = taxipoint[sumi][sumj];
    }
}  sumi = a;
   sumj = b;

    for (int i = 0; ; i++) {
    sumi -= i;
    sumj += i;
    if (sumi < 0 || sumj >= 10) {
        break;
    }
    if (taxipoint[sumi][sumj] > maxpoint) {
        maxpoint = taxipoint[sumi][sumj];
    }
}   sumi = a;
    sumj = b;
    if (maxpoint >= abs(taxipoint[sumi][sumj])) {
        EXP1 = ceil(float(EXP1 * 1.12));
        EXP2 = ceil(float(EXP2 * 1.12));
        HP1 = ceil(float(HP1 * 1.1));
        HP2 = ceil(float(HP2 * 1.1));
    } else {
       EXP1 = ceil(float(EXP1 * 0.88));
        EXP2 = ceil(float(EXP2 * 0.88));
        HP1 = ceil(float(HP1 * 0.9));
        HP2 = ceil(float(HP2 * 0.9));
    } if (HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    } if (HP2 < 0) {
        HP2 = 0;
    } else if (HP2 > 666) {
        HP2 = 666;
    } if (EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    } if (EXP2 < 0) {
        EXP2 = 0;
    } else if (EXP2 > 600) {
        EXP2 = 600;
    }
     int greatergrade;
   if (abs(taxipoint[sumi][sumj]) < maxpoint){
      greatergrade = maxpoint;
   } else {
      greatergrade = taxipoint[sumi][sumj];
   }
    return greatergrade;
    return -1;
}

//Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string checkemail(email);
    int beforemail = checkemail.find('@'); //find the @ in the email
    string se = checkemail.substr(0, beforemail); //extract substring before @ to be checked in the password
    string password(s);
    if (password.length() < 8){
      return -1;
    } else if (password.length() > 20){
      return -2;
    }
    if (password.find(se) != string::npos){  //use string::npos to check if se is in the string, avoid checking outside the string
      return -(300 + password.find(se));
    }
    bool specialchar = false;
      for (int i = 0; i < password.length(); i++) {
      if ((password[i] == password[i+1]) && (password[i+1] == password[i+2])){ 
        return -(400 + i);
      }
      char c = password[i];
        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            specialchar = true;
        }
    }
    if (specialchar == false){
      return -5;
    } else {
      for (int i = 0; i < password.length(); i++) {
         char c = password[i];
if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!')) {
            return i;
        }
      }
    }
    return -10;
    return -99; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
  string somepassword;
  int count;
  int maxcount = 0;
  int maxlength = 0;
  int firstoccurence = 0;

  for (int i = 0; i < num_pwds; i++){  //scan through an array of passwords
    somepassword = arr_pwds[i];
    count = 1;
  for (int j = i + 1; j < num_pwds; j++) { //check for a password that appears the most
    if (somepassword == arr_pwds[j]) {
    count++;
  }
  }
  if (count > maxcount || (count == maxcount && somepassword.length() > maxlength)) { //find the correct password
    maxcount = count;   //keep track of the most frequent password                         
    maxlength = somepassword.length();           
    firstoccurence = i;
  }
  }
    return firstoccurence;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////