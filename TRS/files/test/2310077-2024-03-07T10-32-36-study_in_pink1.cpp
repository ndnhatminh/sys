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

bool o_e (float a) {
    if (int(a) % 2 == 0) return true ;
    else return false ;
}

// exp
int r1(float a) {
    if (a < 0) a = 0 ;
    else if (a > 600) a = 600;
    int res = a;
    a = ceil(a) ;
    if (a < res) a += 1 ;
    return a ;
}
// money
int r2(float a) {
    if (a < 0) a = 0 ;
    else if (a > 3000) a = 3000;
    int res = a;
    a = ceil(a) ;
    if (a < res) a += 1 ;
    return a ;
}
// hp
int r3(float a) {
    if (a < 0) a = 0 ;
    else if (a > 666) a = 666;
    int res = a ;
    a = ceil(a) ;
    if (a < res) a += 1 ;
    return a ;
}

void end2(float a, int b, int c, int d) {
    a -= c ;
    if(a < 0) {
        a = 0 ;
        d = 0 ;
        c += a ;
    }
    else {
        c += b ;
    }
}

int scp(int a) {
   int res1 = ceil(sqrt(a)) ;
   int res2 = floor(sqrt(a)) ;
   return abs(a - res1* res1) < abs(a - res2 * res2) ? res1 * res1 : res2 * res2 ;
}

int MA_X(int a[][10], int i, int j) {
    int maxx = a[i][j] ;
    int i1, j1, i2, j2, i3, j3, i4, j4 ;
    i1 = i - 1 ; j1 = j - 1 ;
    i2 = i + 1 ; j2 = j + 1 ;
    i3 = i + 1 ; j3 = j - 1 ;
    i4 = i - 1 ; j4 = j + 1 ;
    while(i1 >= 0 && j1 >= 0){
       maxx = max(maxx, a[i1][j1]) ;
       i1-- ; j1-- ;
    }
    while(i2 <= 9 && j2 <= 9) {
        maxx = max(maxx, a[i2][j2]) ;
        i2++ ; j2++ ;
    }
    while(i3 <= 9 && j3 >= 0) {
        maxx = max(maxx, a[i3][j3]) ;
        i3++ ; j3-- ;
    }
    while(i4 >= 0 && j4 <= 9) {
        maxx = max(maxx, a[i4][j4]) ;
        i4-- ; j4++ ;
    }
    return abs(maxx) ;
}

bool check(int a) {
    if((a >= 48 && a <= 57) || (a >= 65 && a <= 90) || (a >= 97 && a <= 122) || ((a == 64) || (a == 35) || (a == 37) || (a == 36) || (a == 33))) return true ;
    else return false ;
} 

int one(int a) {
    int res = a, sum = 0 ;
    while(a > 0) {
      sum += a % 10 ;
      a = a / 10 ;
    }
    return sum ;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 >= 0 && e1 <= 99) {
    exp1 = r1(exp1) ;
    exp2 = r1(exp2) ;
    // case 1
    float p1, p2, res1 ;
    p1 = r1(exp1) ;
    p2 = r1(exp2) ; 
    res1 = e1 ;
    if(e1 >= 0 && e1 <= 3) {
      if(e1 == 0) p2 += 29 ;
      else if (e1 == 1) p2 += 45 ; 
      else if (e1 == 2) p2 += 75 ;
      else p2 += (29 + 45 + 75) ;
      // guest country 
      float D = e1*3 + p1*7 ;
      if (o_e(D)) p1 += (D / 200) ;
      else p1 -= (D / 100) ; 
    }
    // case 2
    else if (e1 >= 4 && e1 <= 99) {
      if(e1 >= 4 && e1 <= 19) p2 += (res1 / 4 + 19) ;
      else if(e1 > 19 && e1 <= 49) p2 += (res1 / 9 + 21) ;
      else if(e1 > 49 && e1 <= 65) p2 += (res1 / 16 + 17) ;
      else if(e1 > 65 && e1 <= 79) {
         p2 += (res1 / 4 + 19) ;
         p2 = r1(p2) ;
         if (p2 > 200) p2 += (res1 / 9 + 21) ;
      }
      else {
         p2 += (res1 / 4 + 19) ; 
         p2 = r1(p2) ;
         p2 += (res1 / 9 + 21) ; 
         p2 = r1(p2) ;
         if (p2 > 400) {
            p2 += (res1 / 16 + 17) ;
            p2 = r1(p2) ;
            p2 += p2 * 15 / 100 ;
            p2 = r1(p2) ;
         }
      }
      p1 -= e1 ;
    }
    // round up result
    exp1 = r1(p1) ;
    exp2 = r1(p2) ;
    
    return exp1 + exp2 ;
    }
    else return -99 ;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2 > 99) return -99;
else{
float h1, p1, t1, res2, half, P1 ;
    int ct = 0 ;
    p1 = EXP1 ;
    h1 = HP1 ;
    t1 = M1 ;
    res2 = E2 ;
    half = 0.5 * M1 ;
    int s = scp(EXP1) ;
    //race 
    if (p1 >= s) P1 = 100 ;
    else P1 = ceil(((p1 / s + 80) / 123) * 100) ;
    //cout << P1 ;
    //race 2
//even
    if(o_e(res2)) {
     int d = 1 ;
    // 1
    if (h1 < 200) {
    t1 -= 150 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 150 ;
    }
        h1 += h1 / 100 * 30 ;
        h1 = r3(h1) ;
    }
    else if (h1 >= 200 && d == 1) {
    t1 -= 70 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 70 ;
    }
        //cout << ct ;
        h1 += h1 / 100 * 10 ;
        h1 = r3(h1) ;
        //cout << h1 << " " << t1 ;
    }
    
    //2
    if (p1 < 400 && d == 1) {
    t1 -= 200 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 200 ;
    }
        p1 += p1 / 100 * 13 ;
        p1 = r1(p1) ;
        //cout << p1 << " " << t1 ;
    }
    else if (p1 >= 400 && d == 1) {
    t1 -= 120 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 120 ;
    }
        p1 += p1 / 100 * 13 ;
        p1 = r1(p1) ;
    }

    //3
    if (p1 < 300 && d == 1) {
    t1 -= 100 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 100 ;
    }
      p1 -= p1 / 100 * 10 ;
      p1 = r1(p1) ;
      //cout << p1 << " " << t1 ;
    }
    else if(p1 >= 300 & d == 1) {
    t1 -= 120 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 120 ;
    }
      p1 -= p1 / 100 * 10 ;
      p1 = r1(p1) ;
    }
    }
//odd
    else {
    //cout << p1 << " " << h1 << " " << t1 << " " << ct << " " << half << "\n" ;
    int d = 1 ;
    while(ct <= half && d == 1) {
               // 1
    if (h1 < 200 && d == 1) {
    t1 -= 150 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 150 ;
    }
        h1 += h1 / 100 * 30 ;
        h1 = r3(h1) ;
        if (ct > half) break ;
    }
    else if(h1 >= 200 && d == 1) {
    t1 -= 70 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 70 ;
    }
        //cout << ct ;
        h1 += h1 / 100 * 10 ;
        h1 = r3(h1) ;
        if (ct > half) break ;
    }
    
    //2
    if (p1 < 400 && d == 1) {
    t1 -= 200 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 200 ;
    }
        p1 += p1 / 100 * 13 ;
        p1 = r1(p1) ;
        if (ct > half) break ;
    }
    else if(p1 >= 400 && d == 1) {
    t1 -= 120 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 120 ;
    }
        p1 += p1 / 100 * 13 ;
        p1 = r1(p1) ;
        if (ct > half) break ;
    }

    //3
    if (p1 < 300 && d == 1) {
    t1 -= 100 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 100 ;
    }
      p1 -= p1 / 100 * 10 ;
      p1 = r1(p1) ;
      if (ct > half) break ;
    }
    else if(p1 >= 300 && d == 1) {
    t1 -= 120 ;
    if(t1 < 0) {
        d = 0 ;
        ct += t1 ;
        t1 = 0 ;
    }
    else {
        ct += 120 ;
    }
      p1 -= p1 / 100 * 10 ;
      p1 = r1(p1) ;
      if (ct > half) break ;
    }
        }

      //cout << h1 << " " << p1 << endl ;
    }
      h1 -= h1 * 17 / 100 ;
      h1 = r3(h1) ;
      p1 += p1 * 17 / 100 ;
      p1 = r1(p1) ;
    float P2 ;
    if (p1 >= scp(p1)) P2 = 100 ;
    else P2 = ceil(((p1 / scp(p1) + 80) / 123) * 100) ;
    //cout << P2 ;

    //race 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11} ;
    int pi ;
    if (E2 > 10) {
        pi = (E2 % 10) + (E2 / 10) ;
        pi = pi % 10 ;
    }
    else pi = E2 ;
    float P3 = P[pi] ;
    //cout << h1 << " " << p1 << " " << t1 << endl ;
    //xac suat
    if(P1 == 100 && P2 == 100 && P3 == 100) {
        p1 -= p1 * 25 / 100 ;
        p1 = r1(p1) ;
    }
    else {
        if(ceil((P1 + P2 + P3) / 3) < 50) {
        h1 -= h1 * 15 / 100 ;
        h1 = r3(h1) ;
        p1 += p1 * 15 / 100 ;
        p1 = r1(p1) ;
    }
    else if (ceil((P1 + P2 + P3) / 3) >= 50 && ceil((P1 + P2 + P3) / 3) != 100) {
       h1 -= h1 * 10 / 100 ;
       h1 = r3(h1) ;
       p1 += p1 * 20 / 100 ;
       p1 = r1(p1) ; 
    }
    }


    HP1 = h1 ;
    EXP1 = p1 ;
    M1 = t1 ;
    return HP1 + EXP1 + M1 ;
}
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
   if(E3 < 0 || E3 > 99) return -99 ;
   else {
       int taxi[10][10], det[10][10], resi = 0, resj = 0, result ;
   for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        taxi[i][j] = ((E3 * j) + (i * 2))*(i - j) ;
        if(taxi[i][j] > (E3*2)) resi++ ;
        if(taxi[i][j] < (-E3)) resj++ ;
    }
   }

   for(int i = 0 ; i < 10 ; i++) {
    for(int j = 0 ; j < 10 ; j++) {
        det[i][j] = MA_X(taxi, i, j) ;
    }
   }
   int i, j ;
   i = one(resi) ;
   j = one(resj) ;
   while(i >= 10) {
     i = one(i) ;
   } 
   while(j >= 10) {
    j = one(j) ;
   }
   float h1, h2, p1, p2 ;
   h1 = HP1 ; h2 = HP2 ;
   p1 = EXP1 ; p2 = EXP2 ;
   if(abs(taxi[i][j]) > det[i][j]) {
     p1 -= p1 * 12 / 100 ; p1 = r1(p1) ; EXP1 = p1 ;
     p2 -= p2 * 12 / 100 ; p2 = r1(p2) ; EXP2 = p2 ;
     h1 -= h1 * 10 / 100 ; h1 = r3(h1) ; HP1 = h1 ;
     h2 -= h2 * 10 / 100 ; h2 = r3(h2) ; HP2 = h2 ;
     return taxi[i][j] ;
   }
   else {
     p1 += p1 * 12 / 100 ; p1 = r1(p1) ; EXP1 = p1 ;
     p2 += p2 * 12 / 100 ; p2 = r1(p2) ; EXP2 = p2 ;
     h1 += h1 * 10 / 100 ; h1 = r3(h1) ; HP1 = h1 ;
     h2 += h2 * 10 / 100 ; h2 = r3(h2) ; HP2 = h2 ;
     return det[i][j] ;
   }
   }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
  string se = "" ;
  string ss = s, emaill = email ;
  for (int i = 0 ; i < emaill.find('@') ; i++) se += emaill[i] ;
  
  if(strlen(s) < 8) return -1 ;
  else if(strlen(s) > 20) return -2 ;
  else if(ss.find(se) != std::string::npos) return -(300 + ss.find(se)) ;
  
  int cnt = 1, c ;
  for (int i = 1 ; i < strlen(s) ; i++) {
     if(s[i] == s[i - 1]) {
        cnt++ ;
        if(cnt > 2) {
          c = i - 2 ;
          break ;
        }
     }
       else cnt = 1 ;
  }

  if(cnt > 2) return -(400 + c) ;
  if((ss.find('@') == std::string::npos) && (ss.find("#") == std::string::npos) && (ss.find('%') == std::string::npos) && (ss.find('$') == std::string::npos) && (ss.find('!') == std::string::npos)) return -5 ;

  for(int i = 0 ; i < strlen(s) ; i++) {
    if(!(check(int(s[i])))) return i ;
  }
  
  return -10 ;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
  string s[num_pwds] ;
  for(int i = 0; i < num_pwds ; i++) {
    while(*arr_pwds[i]) s[i] += *arr_pwds[i]++ ;
  }
  int l = 0, cnt = 0, maxx = -1, res ;
  for(int i = 0 ; i < num_pwds ; i++) {
    //l = s[i].size() ;
    for (int j = 0 ; j < num_pwds ; j++) {
       if(s[j] == s[i]) cnt++ ;
    }
    if (cnt > maxx) {
        maxx = cnt ;
        res = i ;
        l = s[i].size() ;
    }
    else if(cnt == maxx) {
        if(s[i].size() > l) {
            maxx = cnt ;
            l = s[i].size() ;
            res = i ;
        }
    }
    //if(s[i].size() > l) l = s[i].size() ;
    cnt = 0 ;
  }
  return res ;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////