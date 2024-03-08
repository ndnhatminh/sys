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

int limithp (int n){
  if (n < 0)
	return 0;
  if (n > 666)
	return 666;
  else
	return n;
}

int limitexp (int n){
  if (n < 0)
	return 0;
  if (n > 600)
	return 600;
  else
	return n;
}

int limitm (int n){
  if (n < 0)
	return 0;
  if (n > 3000)
	return 3000;
  else
	return n;
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    int D;
    if (E1 < 0 || E1 > 99)
    return -99;
    EXP1 = limitexp (EXP1);
    EXP2 = limitexp (EXP2);
  if (0 <= E1 && E1 <= 3){
      switch (E1){
        case 0:
          EXP2 += 29;
          EXP2 = limitexp (EXP2);
          break;
        case 1:
          EXP2 += 45;
          EXP2 = limitexp (EXP2);
          break;
        case 2:
          EXP2 += 75;
          EXP2 = limitexp (EXP2);
          break;
        case 3:
          EXP2 += 29 + 45 + 75;
          EXP2 = limitexp (EXP2);
          break;
        }
      D = E1 * 3 + EXP1 * 7;
      if (D % 2 != 0){
          EXP1 = ceil (EXP1 - D / 100.0);
          EXP1 = limitexp (EXP1);
        }
      else
          EXP1 = ceil (EXP1 + D / 200.0);
          EXP1 = limitexp (EXP1);
    }
  else{
        if (4 <= E1 && E1 <= 19)
            EXP2 += ceil (E1 / 4.0) + 19;
            EXP2 = limitexp (EXP2);
        if (20 <= E1 && E1 <= 49)
            EXP2 += ceil (E1 / 9.0) + 21;
            EXP2 = limitexp (EXP2);
        if (50 <= E1 && E1 <= 65)
            EXP2 += ceil (E1 / 16.0) + 17;
            EXP2 = limitexp (EXP2);
        if (66 <= E1 && E1 <= 79){
            EXP2 += ceil (E1 / 4.0) + 19;
            EXP2 = limitexp (EXP2);
        if (EXP2 > 200)
            EXP2 += ceil (E1 / 9.0) + 21;
            EXP2 = limitexp (EXP2);
        }
        if (80 <= E1 && E1 <= 99){
            EXP2 += ceil (E1 / 4.0) + 19 + ceil (E1 / 9.0) + 21;
            EXP2 = limitexp (EXP2);
            if (EXP2 > 400){
                EXP2 += ceil (E1 / 16.0) + 17;
                EXP2 = limitexp (EXP2);
                EXP2 = ceil(EXP2*1.15);
                EXP2 = limitexp (EXP2);
            }
        }
        EXP1 -= E1;
        EXP1 = limitexp (EXP1);
    }
    return EXP1 + EXP2;
}

// Task 2
double pct (int n){
  int S, S1, S2;
  S = n;
  while ((sqrt (S) != round (sqrt (S))))
	{
	  S++;
	}
  S1 = S;
  S = n;
  while ((sqrt (S) != round (sqrt (S))))
	{
	  S--;
	}
  S2 = S;
  if (abs (S2 - n) < abs (S1 - n))
	S = S2;
  else
	S = S1;
  if (n >= S)
	return 1;
  else
	return (n * 1.0 / S + 80) / 123;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    double P1, P2, P3;
    if (E2 < 0 || E2 > 99)
	return -99;
  HP1=limithp(HP1);
    EXP1 = limitexp (EXP1);
    M1=limitm(M1);
    P1 = pct (EXP1);
    if(M1>0){
    if (E2 % 2 == 0){
	  for (int i = 0; i < 1; i++){
		  if (HP1 < 200){
			  M1 -= 150;
			  HP1 = ceil (HP1 * 1.3);
			  HP1 = limithp (HP1);
			  if (M1 <= 0){
				  break;
				}
			}
		  else{
			  M1 -= 70;
			  HP1 = ceil (HP1 * 11.0/10);
			  HP1 = limithp (HP1);
			  if (M1 <= 0){
				  break;
				}
			}
		  if (EXP1 >= 400){
			  M1 -= 120;
			  EXP1 = ceil (EXP1 * 1.13);
			  EXP1 = limitexp (EXP1);
			  if (M1 <= 0){
				  break;
				}
			}
		  else{
			  M1 -= 200;
			  EXP1 = ceil (EXP1 * 1.13);
			  EXP1 = limitexp (EXP1);
			  if (M1 <= 0){
				  break;
				}
			}
		  if (EXP1 >= 300){
			  M1 -= 120;
			  EXP1 = ceil (EXP1 * 0.9);
			  EXP1 = limitexp (EXP1);
			  if (M1 <= 0){
				  break;
				}
			}
		  else{
			  M1 -= 100;
			  EXP1 = ceil (EXP1 * 0.9);
			  EXP1 = limitexp (EXP1);
			  if (M1 <= 0){
				  break;
				}
			}
		}
	}
    if (E2 % 2 != 0){
	  int a = ceil (M1 / 2.0);
	  while (M1 >= a){
		  if (HP1 < 200){
			  M1 -= 150;
			  HP1 = ceil (HP1 * 1.3);
			  HP1 = limithp (HP1);
			  if (M1 < a){
				  break;
				}
			}
		  else{
			  M1 -= 70;
			  HP1 = ceil (HP1 * 11.0/10);
			  HP1 = limithp (HP1);
			  if (M1 < a){
				  break;
				}
			}
		  if (EXP1 >= 400){
			  M1 -= 120;
			  EXP1 = ceil (EXP1 * 1.13);
			  EXP1 = limitexp (EXP1);
			  if (M1 < a){
				  break;
				}
			}
		  else{
			  M1 -= 200;
			  EXP1 = ceil (EXP1 * 1.13);
			  EXP1 = limitexp (EXP1);
			  if (M1 < a){
				  break;
				}
			}
		  if (EXP1 >= 300){
			  M1 -= 120;
			  EXP1 = ceil (EXP1 * 0.9);
			  EXP1 = limitexp (EXP1);
			  if (M1 < a){
				  break;
				}
			}
		  else{
			  M1 -= 100;
			  EXP1 = ceil (EXP1 * 0.9);
			  EXP1 = limitexp (EXP1);
			  if (M1 < a){
				  break;
				}
			}
		}
	}
    }
    HP1 = ceil (HP1 * 0.83);
	HP1 = limithp (HP1);
    EXP1 = ceil (EXP1 * 1.17);
	EXP1 = limitexp (EXP1);
    P2 = pct (EXP1);
    P3 = P[(E2 / 10 + E2 % 10) % 10] / 100.0;
    if (P1 == 1 && P2 == 1 & P3 == 1){
	    EXP1 = ceil (EXP1 * 0.75);
		EXP1 = limitexp (EXP1);
	   }
    else{
	  if ((P1 + P2 + P3) / 3.0 >= 0.5){
		  HP1 = ceil (HP1 * 0.9);
		  HP1 = limithp (HP1);
		  EXP1 = ceil (EXP1 * 1.2);
		  EXP1 = limitexp (EXP1);
		}
	  else{
		  HP1 = ceil (HP1 * 0.85);
		  HP1 = limithp (HP1);
		  EXP1 = ceil (EXP1 * 1.15);
		  EXP1 = limitexp (EXP1);
		}
	}
    HP1 = limithp (HP1);
    EXP1 = limitexp (EXP1);
    M1 = limitm (M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99)
	return -99;
  HP1=limithp(HP1);
    EXP1 = limitexp (EXP1);
    HP2=limithp(HP2);
    EXP2 = limitexp (EXP2);
    const int ROW = 10, COL = 10;
    int a[ROW][COL];
    int m=0, n=0;
    for (int i = 0; i < ROW; i++){
	    for (int j = 0; j < COL; j++){
			a[i][j] = ((E3 * j) + (i * 2)) * (i - j);
      //cout<<setw(5)<<a[i][j]<<" ";
		    if (((E3 * j) + (i * 2)) * (i - j) > E3 * 2){
			    m++;
		    }
		    if (((E3 * j) + (i * 2)) * (i - j) < -E3){
			    n++;
			}
      //if(j==9) cout << endl;
		}
	}
  //cout<<m<<" "<<n<<endl;
    for (int i = 0; i < 2; i++){
	    m = m / 10 + m % 10;
	    n = n / 10 + n % 10;
	} 
  //cout<<m<<" "<<n<<endl;
    int b = m;
    int c = n;
    int max=a[m][n];
    int max1=-9999, max2=-9999, max3=-9999, max4=-9999;
    while (b < ROW && c < COL){
	    b++;
	    c++;
	    if (b > ROW - 1 || c > COL - 1){
		    break;
		}
	    if (a[b][c] > max)
		    max1 = a[b][c];
	}
    b = m;
    c = n;
    while (b > -1 && c < COL){
	    b--;
	    c++;
	    if (b < 0 || c > COL - 1){
		    break;
		}
	    if (a[b][c] > max){
		    max2 = a[b][c];
		}
	}
    b = m;
    c = n;
    while (b < ROW && c > -1){
	    b++;
	    c--;
	    if (b > ROW - 1 || c < 0){
		    break;
		}
	    if (a[b][c] > max)
		    max3 = a[b][c];
	}
	b = m;
    c = n;
    while (b > -1 && c > -1){
	    b--;
	    c--;
	    if (b < 0 || c < 0){
		    break;
		}
	    if (a[b][c] > max)
            max4 = a[b][c];
	}
  //cout<<max1<<" "<<max2<<" "<<max3<<" "<<max4<<endl;
  if (max1 > max){
	max = max1;
    }
    if (max2 > max){
	max = max2;
    }
    if (max3 > max){
	max = max3;
    }
    if (max4 > max){
	max = max4;
    }
   // cout<<max<<endl;
  max=abs(max);
    if (abs(a[m][n]) > max){
	    EXP1 = ceil (EXP1 * 88.0/100);
		EXP1 = limitexp (EXP1);
	    EXP2 = ceil (EXP2 * 88.0/100);
		EXP2 = limitexp (EXP2);
        HP1 = ceil (HP1 * 0.9);
		HP1 = limithp (HP1);
        HP2 = ceil (HP2 * 0.9);
		HP2 = limithp (HP2);
		return a[m][n];
	}
	else {
	    EXP1 = ceil (EXP1 * 112.0/100);
		EXP1 = limitexp (EXP1);
	    EXP2 = ceil (EXP2 * 112.0/100);
		EXP2 = limitexp (EXP2);
	    HP1 = ceil (HP1 * 11.0 / 10);
		HP1 = limithp (HP1);
      HP2 = ceil (HP2 * 11.0 / 10);
		HP2 = limithp (HP2);
		return max;
	}

}

// Task 4
const int sym[5]= {33,35,36,37,64};

int checksymbol(const char* pass){
    int count=0;
    for(int i=0;i<strlen(pass);i++){
        for(int j=0;j<5;j++){
            if(pass[i]==sym[j]) {
                count++;
            }
        }
    }
    return count;
}

int checkchain(const char* s){
    int chain=1;
    int i;
    for(i=0;i<strlen(s);i++){
        if(s[i]==s[i+1]) chain++;
        if(s[i+2]==s[i]) chain++;
        else if(s[i+2]!=s[i]) chain=1;
            if(chain==3) return chain;
        }
    return chain;
}

int checkPassword(const char* s, const char* email){
    string se;
    for(int i=0;i<100;i++){
        se.assign(email,0,i);
        if(email[i]==64)
        break;
    }
    int sel=se.length();
    if(strlen(s)<8) return -1;
    if(strlen(s)>20) return -2;
    if(strlen(s)>sel){
    for (int i = 0; i <= strlen(s) - sel; i++){
        int j;
        for (j = 0; j < sel; j++){
            if (s[i + j] != se[j])
                break;
        }
        if (j == sel)
            return -(300+i);
        }
    }
    if(checkchain(s)==3){ 
        for(int i=0;i<strlen(s);i++){
            if((s[i]==s[i+1])&&(s[i+1]==s[i+2]))
            return -(400+i);
            }
    }
    if(checksymbol(s)==0) return -5;
    for (int i = 0; i < strlen(s); i++){
        if(s[i]<33||s[i]==34||(s[i]>37&&s[i]<48)||(s[i]>57&&s[i]<64)||(s[i]>90&&s[i]<97)||s[i]>122)
        return i;
        }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int appearance[50];
    for(int i=0;i<num_pwds;i++){
        string find=arr_pwds[i];
        int count=0;
        for(int j=i;j<num_pwds;j++){
            if(find.compare(arr_pwds[j])==0)
            count++;
        }
        appearance[i]=count;
    }
    int longest=strlen(arr_pwds[0]);
    int most=appearance[0];
    string correct=arr_pwds[0];
    for(int m=1;m<num_pwds;m++){
        if(appearance[m]>most){
        most=appearance[m];
        longest=strlen(arr_pwds[m]);
        correct=arr_pwds[m];
        }
        else if(appearance[m]==most){
            if(strlen(arr_pwds[m])>longest){
            most=appearance[m];
            longest=strlen(arr_pwds[m]);
            correct=arr_pwds[m];
            }
        }
    }
    int n;
    for(int i=0;i<num_pwds;i++){
        if(correct.compare(arr_pwds[i])==0){
            n=i;
            break;
        }
    }
    return n;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////