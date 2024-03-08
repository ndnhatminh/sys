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
	//Function Help Task1
void limitValues1(int & EXP1, int & EXP2){
  if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (EXP2 < 0) EXP2 = 0;
    if (EXP2 > 600) EXP2 =600;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
  // TODO: Complete this function
  if ( E1< 0 || E1> 99) {
    return -99;
  }
  else {
  limitValues1(EXP1, EXP2);
    if (E1 >= 0 && E1 <= 3) {
      if (E1 == 0 ) {
        EXP2 =EXP2 + 29;
      }
      if (E1 == 1) {
        EXP2 =EXP2 + 45;
      }
      if (E1 == 2) {
        EXP2 =EXP2 + 75;
      }
      if (E1 == 3) {
        EXP2 =EXP2 + 149;
      }
      int D=E1*3 + EXP1*7;
      if (D % 2 == 0) {
        EXP1 = ceil(EXP1 + (float)D /200);
      }
      else {
        EXP1 = ceil(EXP1 - (float)D /100);
      }
      limitValues1(EXP1, EXP2);
    }
    else {
      if (E1 >= 4 && E1 <= 19) {
        EXP2 = ceil(EXP2 + ((float)E1 / 4 + 19));
      }
      if (E1 >= 20 && E1 <= 49) {
        EXP2 = ceil(EXP2 + ((float)E1 / 9 + 21));
      }
      if (E1 >= 50 && E1 <= 65) {
        EXP2 = ceil(EXP2 + ((float)E1 / 16 + 17));
      }
      if (E1 >= 66 && E1 <= 79) {
        EXP2 = ceil(EXP2 + ((float)E1 / 4 + 19));
        if (EXP2 > 200) {
          EXP2 = ceil(EXP2 + ((float)E1 / 9 + 21));
        }
      }
      if (E1 >= 80 && E1 <= 99) {
        EXP2 = ceil(EXP2 + ((float)E1 / 4 + 19));
        EXP2 = ceil(EXP2 + ((float)E1 / 9 + 21));
        if (EXP2 > 400) {
          EXP2 = ceil(EXP2 + ((float)E1 / 16 + 17));
          EXP2 = ceil(EXP2 * 1.15);
        }
      }
      EXP1 = ceil(EXP1 - E1);
    }
  }
  limitValues1(EXP1, EXP2);
  return EXP1 + EXP2;
}


// Task 2
//Fuction help in Task 2
int nearestPerfectSquare(int number) {
    int largestPerfectSquare = sqrt(number);
    int smallestPerfectSquare = largestPerfectSquare + 1;
    int distance1 = abs(number - largestPerfectSquare * largestPerfectSquare);
    int distance2 = abs(number - smallestPerfectSquare * smallestPerfectSquare);
    if (distance1 <= distance2) {
       	return largestPerfectSquare * largestPerfectSquare;
    } else {
        return smallestPerfectSquare * smallestPerfectSquare;
    }
}
int calculateI(int NUM) {
    int i = 0;
    if (NUM < 10) {
        i = NUM ;
    } else {
        int sum = NUM / 10 + NUM % 10;
        i = sum % 10;
    }
return i;
}
void limitValues2(int & HP1, int & EXP1, int & M1) {
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (M1 < 0) M1 = 0;
    if (M1 > 3000) M1 = 3000;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
	if (E2 < 0 || E2 > 99) {
        return -99;
    }
    else {
        limitValues2(HP1, EXP1, M1);  
        //Way I
        int S1= nearestPerfectSquare(EXP1);
        double P1,P2;
        if (EXP1 < S1) {
        	P1 = ((float)EXP1/(float)S1 + 80)/123;
		}
        else {
        	P1 = 1;
    	}
		//Way II
		int M = M1;
	  	int expenses = 0;
	  	int lan = 0;
	  	bool stopLoop = false;
	  	bool expenseExceeded = false;
	  	// E2 = 39; M1 = 890; HP1 = 333; EXP1 = 430;
	  	if (E2 % 2 == 1){
	    	while (!stopLoop) {
	      		  if (HP1 >= 200) {
		      	  	M1 -= 70;
		        	expenses += 70;
	        		HP1 = ceil(HP1 * 1.1);
	      		  } else {
			        M1 -= 150;
			        expenses += 150;
			        HP1 = ceil(HP1 * 1.3);
	      		  }
			      if (expenses > M * 0.5 && !expenseExceeded) {
			          expenseExceeded = true; 
			      }
			      if (expenseExceeded) {
			          break; 
			      }
			      if (EXP1 >= 400) {
			        M1 -= 120;
			        expenses += 120;
			        EXP1 = ceil(EXP1 * 1.13);
			      } else {
			        M1 -= 200;
			        expenses += 200;
			        EXP1 = ceil(EXP1 * 1.13);
			      } 
			      if (expenses > M * 0.5 && !expenseExceeded) {
			          expenseExceeded = true; 
			      }
			      if (expenseExceeded) {
			          break; 
			      }
			      if (EXP1 < 300) {
			        M1 -= 100;
			        expenses += 100;
			        EXP1 = ceil(EXP1 * 0.9);
			      } else {
			        M1 -= 120;
			        expenses += 120;
			        EXP1 = ceil(EXP1 * 0.9);
			      }
			      if (expenses > M * 0.5 && !expenseExceeded) {
			          expenseExceeded = true; 
			      }
			      if (expenseExceeded) {
			          break; 
			      }
			}
	    HP1 = ceil(HP1 * 0.83);
	    EXP1 = ceil(EXP1 * 1.17);
	    limitValues2(HP1, EXP1, M1);
	  } else {
	      while (M1 > 0 && lan < 3){
	        if (HP1 >= 200) {
	          M1 -= 70;
	          HP1 = ceil(HP1 * 1.1);
	        } else {
	          M1 -= 150;
	          HP1 = ceil(HP1 * 1.3);
	        } 
	        ++lan;
	    
	        if (EXP1 >= 400) {
	          M1 -= 120;
	          EXP1 = ceil(EXP1 * 1.13);
	        } else {
	          M1 -= 200;
	          EXP1 = ceil(EXP1 * 1.13);
	        }
	        ++lan;
	        if (EXP1 < 300) {
	          M1 -= 100;
	          EXP1 = ceil(EXP1 * 0.9);
	        } else {
	          M1 -= 120;
	          EXP1 = ceil(EXP1 * 0.9);
	        }
	        ++lan;
	      }
	      HP1 = ceil(HP1 * 0.83);
	      EXP1 = ceil(EXP1 * 1.17);
	      limitValues2( HP1, EXP1, M1);
	    }
	    int S2= nearestPerfectSquare(EXP1);
	    if (EXP1 < S2) {
        	P2 = ((float)EXP1/(float)S2 + 80)/123;
		}
        else {
        	P2 = 1;
    	}
        // Way III
        double P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.5, 0.22, 0.83, 0.64, 0.11};
        int y= calculateI(E2);
        double P3 = P[y];
        double finalProbability = (P1 + P2 + P3) / 3.0;
		if (P1 == 1 && P2 == 1 && P3 == 1) {
            EXP1 = ceil(EXP1 * 0.75); 
    	} else {
        	if (finalProbability < 0.5) {
            	HP1 = ceil(HP1 * 0.85); 
            	EXP1 = ceil(EXP1 * 1.15); 
        	} else {
            	HP1 = ceil(HP1 * 0.9); 
            	EXP1 = ceil(EXP1 * 1.2); 
        	}
    	}
	}
    limitValues2( HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

// Task 3
// Clamp Function Task 3
int clamp(int a, int b, int c)
{
    if (a < b)
        return b;
    if (a > c)
        return c;
    return a;
}
int maxDiag(int taxi[10][10], int row, int column)
{
    int res = taxi[row][column];
    int i = column - row >= 0 ? 0 : row - column;
    int j = column - row >= 0 ? column - row : 0;
    while (i < 10 and j < 10)
    {
        res = max(res, taxi[i][j]);
        i++;
        j++;
    }
    i = column + row > 9 ? column + row - 9 : 0;
    j = column + row > 9 ? 9 : column + row;
    while (i < 10 and j >= 0)
    {
        res = max(res, taxi[i][j]);
        i++;
        j--;
    }
    return res;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{	 
	// TODO: Complete this function
    // Check for conditions
    if (E3 < 0 or E3 > 99)
        return -99;
    HP1 = clamp(HP1, 0, 666);
    EXP1 = clamp(EXP1, 0, 600);
    HP2 = clamp(HP2, 0, 666);
    EXP2 = clamp(EXP2, 0, 600);

    // Taxi coordinate matrix
    int taxi[10][10];
    int x = 0, y = 0; // Intersect coordinate
    // Taxi moves along rows
    // Row: i, Column: j
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            taxi[i][j] = (E3 * j + i * 2) * (i - j);
            if (taxi[i][j] > E3 * 2)
                x++;
            if (taxi[i][j] < -E3)
                y++;
        }
    }
    while (x > 9)
        x = x % 10 + x / 10;
    while (y > 9)
        y = y % 10 + y / 10;
    // Sherlock's point
    int sher = abs(maxDiag(taxi, x, y));
    // EXP and HP change after the chase
    EXP1 = clamp(ceil(abs(taxi[x][y]) > sher ? EXP1 * 88 / 100.0 : EXP1 * 112 / 100.0), 0, 600);
    EXP2 = clamp(ceil(abs(taxi[x][y]) > sher ? EXP2 * 88 / 100.0 : EXP2 * 112 / 100.0), 0, 600);
    HP1 = clamp(ceil(abs(taxi[x][y]) > sher ? HP1 * 90 / 100.0 : HP1 * 110 / 100.0), 0, 666);
    HP2 = clamp(ceil(abs(taxi[x][y]) > sher ? HP2 * 90 / 100.0 : HP2 * 110 / 100.0), 0, 666);
    // Return value of the winner of the chase
    return abs(taxi[x][y]) > sher ? taxi[x][y] : sher;
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	// Min Max Length
    int min_length = 8;
    int max_length = 20;

    // 	Check Length
    int length = strlen(s);
    if (length < min_length) {
        return -1;  // Password too short
    } else if (length > max_length) {
        return -2;  // Password too long
    }

    // " se " String
    const char* at_position = strchr(email, '@');
    string se = email;
    se = se.substr(0, at_position - email);

	// Check "se" in Password
	const char* found = strstr(s, se.c_str());
	if (found != NULL) {
	      return -(300 + (found - s));  // Password got the " se "
	}
	
	// Check Double Chars
	for (int i = 0; i < length - 2; i++) {
		if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
	        return -(400 + i);  // Password got the Double Chars
	    }
	}
	
	// Check Special Char
	const char* special_chars = "@#%$!";
	const char* contains_special_char = strpbrk(s, special_chars);
	if (contains_special_char == NULL) {
	    return -5;  // No Special Char
	}
	
	//	Check Email
    int email_length = strlen(email);
    if (email_length > 100) {
        return -3;  // Email too long
    }

    // Find " se " String
    if (at_position == NULL) {
        return -4;  // Forgot the '@'
    } else if (strchr(at_position + 1, '@') != NULL) {
        return -6;  // Many '@'
    }
	
	// The Others
	for (int i = 0; i < length; i++) {
	    if (isalpha(s[i]) && !(islower(s[i]) ||   isupper(s[i]))) {
	        return -(500 + i);  // Password Invalid
	    }
	}
   	return -10; // Pasword Invalid
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	    int max_count = 0;
    int max_length = 0;
    const char * correct_password = nullptr;

    // the Most Apppearance and the Longest
    for (int i = 0; i < num_pwds; ++i) {
        const char * pwd = arr_pwds[i];
        int len = strlen(pwd);
        int count = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pwd) == 0) {
                count++;
            }
        }
        if (count > max_count || (count == max_count && len > max_length)) {
            max_count = count;
            max_length = len;
            correct_password = pwd;
        }
    }

    // First Location 
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], correct_password) == 0) {
            return i;
        }
    }
    return -1; // No Founded
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
