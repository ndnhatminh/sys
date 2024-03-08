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
void limitexp(int &exp1) {
    if(exp1 < 0) exp1 = 0;
    if(exp1 > 600) exp1 = 600;
 }
 void limitHP(int &hp1) {
    if(hp1 < 0) hp1 = 0;
    if(hp1 > 666) hp1 = 666;
 }
 void limitM(int &m1) {
    if(m1 < 0) m1 = 0;
    if(m1 > 3000) m1 = 3000;
 }
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    limitexp(exp1);
    limitexp(exp2);
    if(e1 >= 0 && e1 <= 99) {
    if(e1 >= 0 && e1 <= 3) {
       if(e1 == 0) {
         exp2 += 29;
       }else if(e1 == 1) {
         exp2 += 45;
       }else if(e1 == 2) {
         exp2 += 75;
       }else {
         exp2 += 149;
       }  
       int D = e1*3 + exp1*7;
       if(D%2 == 0) {
            exp1  = ceil((double)exp1 + (double)D/200);
       }else {
            exp1 = ceil((double)exp1 - (double)D/100);
       }
    }else if(e1 > 3 && e1 < 100) {
       if(e1 >= 4 && e1 <= 19) {
          exp2 = ceil(exp2 + (double)e1/4 + 19);
       }else if(e1 >= 20 && e1 <= 49) {
          exp2 = ceil(exp2 + (double)e1/9 + 21);
       }else if(e1 >= 50 && e1 <= 65) {
          exp2 = ceil(exp2 + (double)e1/16 + 17);
       }else if(e1 >= 66 && e1 <= 79) {
          exp2 = ceil(exp2 + (double)e1/4 + 19);
            if(exp2 > 200) {
               exp2 = ceil(exp2 + (double)e1/9 + 21); 
            }
       }else {
          exp2 = ceil(exp2 + (double)e1/4 + 19);
          exp2 = ceil(exp2 + (double)e1/9 + 21);
            if(exp2 > 400) {
               exp2 = ceil(exp2 + (double)e1/16 + 17);
                exp2 = ceil((double)exp2 * 1.15); 
            }
       }
         exp1 -= e1;
    }
    limitexp(exp1);
    limitexp(exp2);
;    return exp1 + exp2;
    }else {
       return -99;
    }
}

// Task 2
double probaty(int exp1) {
   int sqrtNum = sqrt(exp1);
    if(sqrtNum * sqrtNum == exp1) {
      return 1.00;
    }
   int lowerSquare = 0;
    int higherSquare = 1;

    // Tìm số chính phương lớn hơn M
    while (higherSquare * higherSquare < exp1) {
        lowerSquare = higherSquare;
        higherSquare++;
    }

    // So sánh khoảng cách giữa số chính phương gần M và M
    int lowerDiff = exp1 - lowerSquare * lowerSquare;
    int higherDiff = higherSquare * higherSquare - exp1;

    // Chọn số chính phương gần M nhất
    int S = (lowerDiff < higherDiff) ? lowerSquare * lowerSquare : higherSquare * higherSquare;
    return (S < exp1) ? 1.00 : ((double)exp1/S + 80)/123; 
}
void way2_odd(int& exp1, int& hp1, int& m1, int mch) {
    if(hp1 < 200) {
       hp1 = ceil((double)hp1 * 1.3);
       m1 -= 150;
    }else {
      hp1 = ceil((double)hp1 * 1.1);
      m1 -= 70;
    }
    limitHP(hp1);
    if(m1 <= 0 || m1 <= mch) return;
    if(exp1 < 400){
      m1 -= 200;
    }else{
      m1 -= 120;
    }
    exp1 = ceil((double)exp1 * 1.13);
    limitexp(exp1);
    if(m1 <= 0 || m1 <= mch) return;
    if(exp1 < 300) {
     m1 -= 100;
    }else{
      m1 -= 120;
    }
    exp1 = ceil((double)exp1 * 0.9);
    limitexp(exp1);
}
void way2_even(int& exp1, int& hp1, int& m1) {
    if(hp1 < 200) {
       hp1 = ceil((double)hp1 * 1.3);
       m1 -= 150;
    }else {
      hp1 = ceil((double)hp1 * 1.1);
      m1 -= 70;
    }
    limitHP(hp1);
    if(m1 <= 0) return;
    if(exp1 < 400){
      m1 -= 200;
    }else{
      m1 -= 120;
    }
    exp1 = ceil((double)exp1 * 1.13);
    limitexp(exp1);
    if(m1 <= 0) return;
    if(exp1 < 300) {
     m1 -= 100;
    }else{
      m1 -= 120;
    }
    exp1 = ceil((double)exp1 * 0.9);
    limitexp(exp1);
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2 >= 0 && E2 <= 99) {
    // Define value [] hp,exp, m
     limitHP(HP1);
     limitexp(EXP1);
     limitM(M1);
     double P1, P2, P3, P;
     double Pch[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; 
     //way 1
     P1 = probaty(EXP1);
     //way 2
     if(E2%2 != 0) {
       int mch = ceil((double)M1/2);
       while(M1 >= mch) {
        way2_odd(EXP1,HP1,M1,mch);
         limitM(M1);
         if(M1 <= 0) break;
       }
     }else {
       way2_even(EXP1,HP1,M1);
       limitM(M1);
     }
     HP1 = ceil((double)HP1 - HP1*0.17);
     EXP1 = ceil((double)EXP1 * 1.17);
     limitHP(HP1);
     limitexp(EXP1);
     P2 = probaty(EXP1);
     //way 3
      if(E2 < 10) {
        P3 = Pch[E2];
      }else{
        int n = E2 % 10;
        int m = E2/10;
        int i = (n+m)%10;
        P3 = Pch[i]/100;
      }
      //Xac Xuat Tim ra Vali
      if(P1 == 1.00 && P2 == 1.00 && P3 == 1.00) {
         EXP1 = ceil((double)EXP1 * 0.75);
      }else {
         P = (P1 + P2 + P3)/3;
          if(P < 0.5) {
             HP1 = ceil((double)HP1 * 0.85);
             EXP1 = ceil((double)EXP1 * 1.15);
          }else{
            HP1 = ceil((double)HP1 * 0.9);
            EXP1 = ceil((double)EXP1 * 1.2);
          }
      }
      limitexp(EXP1);
      limitHP(HP1);
    return HP1 + EXP1 + M1;
    }else {
      return -99;
    }
}

// Task 3
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void sortArray(int arr[], int size) {
    quickSort(arr, 0, size - 1);
}
int max(int a, int b) {
	if(a >= b) return a;
	else return b; 
}
// chuyển số hàng chục thành đơn vị
int simpnum(int x) {
   	int num;
   	while(x > 9 && x < 100) {
      num = x % 10;
      x = x/10;
      x = x + num;
   	}
   	return x;
   }
// Lower Bound
int lower_bound(const int arr[100], int target) {
    int low = 0, high = 100;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

// Upper Bound
int upper_bound(const int arr[100], int target) {
    int low = 0, high = 100;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}
 // make value off Sherlock ad Watso whe meet The Killer Taxi 
int valueOfSherlock(int* arr, int x, int y) {
   int maxcheophai = arr[x*10 + y];
   int maxcheotrai = arr[x*10 + y];
   int x1, x2;
   int y1, y2;
   int maxtam;
   int i = 0; 
   if(x == 9 || y == 9) {
   if(x==9) {
   	  x1 = x; y1 = y;
   	  x2 = y1; y2 = x1;
    }else {
    	x1 = y; y1 = x;
    	x2 = x; y2 = y;
    } 
     
       while((x2 + i) <= (x1 - i)) {
       	maxtam = max(arr[(x1 - i)*10 + y1 + i],arr[(x2 + i)*10 + y2 - i]);
       	maxcheophai = max(maxcheophai,maxtam);
       	i++;
       }
      while(x != 0 && y != 0) {
      	maxtam = arr[(x - 1)*10 + y - 1];
        maxcheotrai = max(maxcheotrai,maxtam);
         x -= 1; y -= 1;
       }
       maxtam = max(maxcheotrai,maxcheophai);
       return maxtam;
   }
   if(x == 0 || y == 0) {
   	 if(x == 0) {
   	    x1 = y; y1 = x; 
   	    x2 = x; y2 = y;
   	   }else {
        x1 = x; y1 = y;
        x2 = y; y2 = x;
   }  
       i = 0;
       while((x2 + i) <= (x1 - i)) {
       	maxtam = max(arr[(x1 - i)*10 + y1 + i],arr[(x2 + i)*10 + y2 - i]);
       	maxcheophai = max(maxcheophai,maxtam);
       	i++;
       }
       while(x != 9 && y != 9) {
       	maxtam = arr[(x + 1)*10 + y + 1];
       	maxcheotrai = max(maxcheotrai,maxtam);
       	x += 1; y += 1;
       }
       maxtam = max(maxcheotrai,maxcheophai);
       return maxtam;
   } 
    i = 0;
    while((x + i) != 9 && (y + i) != 9) {
    	maxtam = arr[(x + i + 1)*10 + y + i +1];
    	maxcheotrai = max(maxcheotrai, maxtam);
    	i += 1;
    }
    i = 0;
    while((x - i) != 0 && (y - i) != 0) {
    	maxtam = arr[(x - i -1)*10 + y - i -1];
      maxcheotrai = max(maxcheotrai,maxtam);
      i += 1;
    }
    i = 0;
    while((x + i) != 9 && (y - i) != 9  && (x + i) != 0 && (y - i) != 0){
    	maxtam = arr[(x + i + 1)*10 + y - i -1];
      maxcheophai = max(maxcheophai,maxtam);
      i += 1;
    }
    i = 0;
    while((x - i) != 9 && (y + i) != 9 && (x - i) != 0 && (y + i) != 0) {
    	maxtam = arr[(x - i -1)*10 + y + i +1];
    	maxcheophai = max(maxcheophai, maxtam);
    	i += 1;
    }
    maxtam = max(maxcheotrai,maxcheophai);
    if(maxtam < 0) maxtam = abs(maxtam);
    return maxtam;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 >= 0 && E3 <= 99) {
    int * taxi = new int[100];
    int txar[100];
	  for(int i = 0; i< 10; i++) {
	  	for(int j = 0; j < 10; j++) {
	  		taxi[i*10 + j] = (E3 * j + i * 2)*(i - j);
        txar[i*10 + j] = taxi[i*10 +j];
	  	}
	  }
    int valuex = E3 * 2;
    int valuey = - E3; 
    sortArray(txar,100);
    int x = 100 - upper_bound(txar,valuex);
	  int y = lower_bound(txar,valuey);
    x = simpnum(x);
    y = simpnum(y);
    int sherlock = valueOfSherlock(taxi,x,y);
    int tx = abs(taxi[x*10 + y]);
     if(tx > sherlock) {
      EXP1 = ceil((double)EXP1 * 0.88);
      HP1 = ceil((double)HP1 * 0.9);
      EXP2 = ceil((double)EXP2 * 0.88);
      HP2 = ceil((double)HP2 * 0.9);
     }else{
      EXP1 = ceil((double)EXP1 * 1.12);
      HP1 = ceil((double)HP1 * 1.1);
      EXP2 = ceil((double)EXP2 * 1.12);
      HP2 = ceil((double)HP2 * 1.1); 
     }
     limitexp(EXP1);
     limitexp(EXP2);
     limitHP(HP1);
     limitHP(HP2);
    delete[] taxi;
    if(tx > sherlock) {
      return taxi[x*10 + y];
    }else{
     return sherlock;
    }
  }else {
    return -99;
  }
}

// Task 4
char* makese(string email, char* se) {
	int i = email.find("@");
    string sub = email.substr(0,i);
    se = new char[sub.length() + 1];
    strcpy(se,sub.c_str());
    return se;
}
bool checkSpecsign(char s) {
	if(s == '@' || s == '#' || s == '%' || s == '$' || s == '!') {
		return true;
	}else{
		return false;
	}
}

bool checksign(const char* s) {
	int len = strlen(s);
	bool tmp = 1;
    for(int i = 0; i < len; i++) {
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || checkSpecsign(s[i])) tmp = 1;
         else return false; 
    }
    return tmp;
}
bool checkSamesign(const char* s) {
      int len = strlen(s);
	for(int i = 0; i < len; i++) {
		if(s[i] == s[i+1] && s[i] == s[i+2]) return false;
	}
	return true;
}

bool checkValid(const char* s,const char* se) {
	bool c1 = 0,c2 = 0,c3 = 0,c4 = 0,c5 = 0;
	if(strlen(s) >= 8 && strlen(s) <= 20) c1 = 1;
	if(checksign(s)) c2 = 1;
	if(strstr(s,se) == NULL) c3 = 1;
    if(checkSamesign(s)) c4 = 1;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
    if(checkSpecsign(s[i])) {
    	c5 = 1;
    	break;
    }
      else 	c5 = 0;
  }
	if(c1 && c2 && c3 && c4 && c5) return true;
    else return false;
}
int checkPassword(const char * s, const char * email) {
    char* se;
    string emtmp(email);
    se = makese(emtmp,se);
    if(checkValid(s,se)) return -10;
    if(strlen(s) < 8) return -1;
    if(strlen(s) > 20) return -2;
   if(strstr(s,se) != NULL) {
    	const char* p = strstr(s,se);
    	int sei = p - s;
      return -(300 + sei);
    }
    if(!checkSamesign(s)) {
      int sci;
      for(int i = 0; i < strlen(s); i++) {
		    if(s[i] == s[i+1] && s[i] == s[i+2]) {
          sci = i;
      break;
    }
    return -(400 + sci);
	 }
 }
   bool specsign = 0;
    for(int i = 0; i < strlen(s); i++) {
    if(checkSpecsign(s[i])) {
      specsign = 1;
    	break;
    }
    }
    if(!specsign) return -5;
    int tmp;
     for(int i = 0; i < strlen(s); i++) {
    if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9' || checkSpecsign(s[i])) tmp = 1;
         else return i; 
    }
    return -99;
  }

// Task 5
bool checkStringsame(string s, string ds[], int count, int& ind) { 
	for(int i = 0; i < count; i++) {
		if(ds[i] == s) {
           ind = i;
          return true;
        }
	}
	return false;
}
int indexMax(int arr[],int count) {
   int max = 0;
   int index;
   for(int i = 0; i< count; i++) {
   	if(arr[i] > max) {
   		max = arr[i];
   		index = i;
   	}
   }
   return index;
}
int findIndstring(string s[], string max, int num_pwds) {
   int i;
   for(i = 0; i < num_pwds; i++) {
   	   if(s[i] == max) break;
   }
   return i;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string s[num_pwds]; 
    for(int i = 0; i < num_pwds; i++) {
    s[i] = string(arr_pwds[i]);
    }
    string ds[30];
    int ind;
    int arr[30]; 
    for(int &x : arr) x = 0;
    int count = 0;
    for(int i = 0; i < num_pwds; i++) {
    	if(checkStringsame(s[i],ds,count,ind)) {
    		arr[ind] += 1;
    	}else{
    		ds[count] = s[i];
    		arr[count] += 1;
    		count += 1;
    	}
    }
     ind =  indexMax(arr,count);
     string max = ds[ind];
     for(int i = 0; i < count; i++) {
     	if(arr[i] == arr[ind] && max.size() < ds[i].size()) {
            max = ds[i];
     	}
     }
     int i = findIndstring(s,max,num_pwds);
       return i;
       return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////