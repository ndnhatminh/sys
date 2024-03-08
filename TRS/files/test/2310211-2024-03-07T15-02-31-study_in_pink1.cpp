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

//CAUTION:
//    - remember to round UP HP, EXP, M in any case it's a float / double
//    - if E is out of range where range is the available scope of the function -> return -99
//    - update function's parameters if asked. 
// Task 1

bool checkEventCode(int E) {
  return (E < 0 || E > 99);
}

//dealing with exp overflow [0, 600], and rounding up.
//taking exp as reference
void addExp(int &exp, double delta) {
  //round up
  float tmp = exp;
  tmp += delta;
  tmp = ceil(tmp);
  exp = tmp;
  //overflow
  if(exp > 600) {
    exp = 600;
  }
  if(exp < 0) {
    exp = 0;
  }
}

//dealing with hp overflow [0, 666], and rounding up.
//taking hp as reference
void addHp(int &hp, double delta) {
  //round up
  float tmp = hp;
  tmp += delta;
  tmp = ceil(tmp);
  hp = tmp;
  //overflow
  if(hp > 666) {
    hp = 666;
  }
  if(hp < 0) {
    hp = 0;
  }
}

//dealing with money overflow [0, 3000], and rounding up.
//taking money as reference
void addM(int &m, double delta) {
  //round up
  float tmp = m;
  tmp += delta;
  tmp = ceil(tmp);
  m = tmp;
  //overflow
  if(m > 3000) {
    m = 3000;
  }
  if(m < 0) {
    m = 0;
  }
}

int firstMeet(int & exp1, int & exp2, int e1) {
  if(checkEventCode(e1))
    return -99;
  //first case E in [0, 3]
  if(e1 <= 3) {
    //add exp for Watson depends on Sherlock's explaination
    if(e1 == 0 || e1 == 3) {
      addExp(exp2, 29);
    }
    if(e1 == 1 || e1 == 3) {
      addExp(exp2, 45);
    }
    if(e1 == 2 || e1 == 3) {
      addExp(exp2, 75);
    }
    //Sherlock's decision
    int d = e1 * 3 + exp1 * 7;
    if(d % 2 == 0) {
      addExp(exp1, d / 200.0); 
    }
    else {
      addExp(exp1, -d / 100.0);
    }
  }
  //second case E in [4, 99]
  else {
    bool explainAllThree = false;
    //add exp for Watson depends on Sherlock's explaination
    if(e1 <= 19) {
      addExp(exp2, e1 / 4.0 + 19.0);
    }
    else if(e1 <= 49) {
      addExp(exp2, e1 / 9.0 + 21.0);
    }
    else if(e1 <= 65) {
      addExp(exp2, e1 / 16.0 + 17.0);
    }
    else if(e1 <= 79) {
      addExp(exp2, e1 / 4.0 + 19.0);
      if(exp2 > 200) {
        addExp(exp2, e1 / 9.0 + 21.0);
      }
    }
    else if(e1 <= 99) {
      addExp(exp2, e1 / 4.0 + 19.0);
      addExp(exp2, e1 / 9.0 + 21.0);
      if(exp2 > 400) {
        addExp(exp2, e1 / 16.0 + 17.0);
        explainAllThree = true;
      }
    }
    if(explainAllThree) {
      addExp(exp2, exp2 * 15 / 100.0);
    }
    addExp(exp1, -e1);
  }
  return exp1 + exp2;
}

//a helper function that finds the closet square number of the given number
int findClosetSquareNumber(int num) {
  int squareRoot = sqrt(num);
  int numSmaller = squareRoot * squareRoot;
  int numLarger = (squareRoot + 1) * (squareRoot + 1);
  //numLarger - num < num - numSmaller <=> numLarger + numSmaller < 2 * num
  int closetSquareNumber = (numLarger + numSmaller < 2 * num ? numLarger : numSmaller);
  return closetSquareNumber;
}

//a helper function that's calculate the exp using the formula given
double calculateExp(int exp1) {
  double p;
  int s = findClosetSquareNumber(exp1);
  if(s <= exp1) {
    p = 1;
  }
  else {
    p = ((exp1 / (double) s) + 80) / 123.0;
  }
  return p;
}

//helper functions that compute event
//parameters are passed as preference
//return the total paid money in the event
int event1(int &HP1, int &M1) {
  if(HP1 < 200) {
    addHp(HP1, HP1 * 30 / 100.0);
    addM(M1, -150);
    return 150;
  }
  else {
    addHp(HP1, HP1 * 10 / 100.0);
    addM(M1, -70);
    return 70;
  }
}
int event2(int &EXP1, int &M1) {
  int ret;
  if(EXP1 < 400) {
    addM(M1, -200);
    ret = 200;
  }
  else {
    addM(M1, -120);
    ret = 120;
  }
  addExp(EXP1, EXP1 * 13 / 100.0);
  return ret;
}
int event3(int &EXP1, int &M1) {
  int ret;
  if(EXP1 < 300) {
    addM(M1, -100);
    ret = 100;
  }
  else {
    addM(M1, -120);
    ret = 120;
  }
  addExp(EXP1, -EXP1 * 10 / 100.0);
  return ret;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) { 
  if(checkEventCode(E2))
    return -99;
  //the first road
  double p1 = calculateExp(EXP1);
  //the second road
  //events
  if(E2 & 1) {
    int initial = (int) ceil(M1 * 0.5);
    int spent = 0;
    while(spent <= initial) {
      spent += event1(HP1, M1);
      if(spent > initial)
        break;
      spent += event2(EXP1, M1);
      if(spent > initial)
        break;
      spent += event3(EXP1, M1);
    }
  }
  else {
    if(M1 > 0)
      event1(HP1, M1);
    cout << "EXP1 " << EXP1 << " M1 " << M1 << '\n';
    if(M1 > 0)
      event2(EXP1, M1);
    if(M1 > 0)
      event3(EXP1, M1);
  }
  //end of events
  addHp(HP1, -HP1 * 17 / 100.0);
  addExp(EXP1, EXP1 * 17 / 100.0);
  double p2 = calculateExp(EXP1);
  //the third road
  double pValue[] = {.32, .47, .28, .79, 1, .5, .22, .83, .64, .11};
  int id = (E2 < 10 ? E2 : (E2 % 10 + (E2 / 10)) % 10);
  double p3 = pValue[id];
  double p = (p1 + p2 + p3) / 3;
  if(p1 + p2 + p3 == 3) {
    addExp(EXP1, -EXP1 * 0.25);
  }
  else if(p < 0.5) {
    addHp(HP1, -HP1 * 0.15);
    addExp(EXP1, EXP1 * 0.15);
  }
  else {
    addHp(HP1, -HP1 * 10 / 100.0);
    addExp(EXP1, EXP1 * 20 / 100.0);    
  }
  return HP1 + EXP1 + M1;
}

void compress(int &num) {
  while(num >= 10) {
    num = (num % 10 + (num / 10));
  }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
  if(checkEventCode(E3))
    return -99;
  int taxiPts[10][10];
  //int currPts[10][10];
  int meetX = 0, meetY = 0;
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++) {
      taxiPts[i][j] = ((E3 * j) + (2 * i)) * (i - j);
      // cout << taxiPts[i][j] << " \n"[j == 9];
      if(taxiPts[i][j] > E3 * 2)
        meetX++;
      if(taxiPts[i][j] < -E3)
        meetY++;
    }   
  //use lambda expression because i don't want to deal with using array as parameter, i also can't use vector
  //get the max value in the left diagonal passing through (x, y)
  auto getLeft = [&] (int x, int y) {
    int ret = taxiPts[x][y];
    int ux = x - 1, uy = y - 1;
    while(ux >= 0 && uy >= 0) {
      ret = max(ret, taxiPts[ux][uy]);
      ux--;
      uy--;
    }
    ux = x + 1, uy = y + 1;
    while(ux < 10 && uy < 10) {
      ret = max(ret, taxiPts[ux][uy]);
      ux++;
      uy++;
    }
    return ret;
  };
  //get the max value in the right diagonal passing through (x, y)
  auto getRight = [&] (int x, int y) {
    int ret = taxiPts[x][y];
    int ux = x - 1, uy = y + 1;
    while(ux >= 0 && uy < 10) {
      ret = max(ret, taxiPts[ux][uy]);
      ux--;
      uy++;
    }
    ux = x + 1, uy = y - 1;
    while(ux < 10 && uy >= 0) {
      ret = max(ret, taxiPts[ux][uy]);
      ux++;
      uy--;
    }
    return ret;
  };
  compress(meetX);
  compress(meetY);

  //calculate the pts for each diagonal (this can be precomputed, but i'm lazy)
  // for(int i = 0; i < 10; i++)
  //   for(int j = 0; j < 10; j++) {
  //     currPts[i][j] = abs(max(getRight(i, j), getLeft(i, j)));
  //   }

  //don't actually need to calculate every Sherlock and Watson's pts
  int pts = abs(max(getRight(meetX, meetY), getLeft(meetX, meetY)));
  //sadly, they can't catch the taxi
  if(abs(taxiPts[meetX][meetY]) > pts) {
    addExp(EXP1, EXP1 * -0.12);
    addExp(EXP2, EXP2 * -0.12);
    addHp(HP1, HP1 * -0.1);
    addHp(HP2, HP2 * -0.1);  
    return taxiPts[meetX][meetY];
  }
   addExp(EXP1, EXP1 * 0.12);
  addExp(EXP2, EXP2 * 0.12);
  addHp(HP1, HP1 * 0.1);
  addHp(HP2, HP2 * 0.1);
  return pts;
}

// Task 4
//if multiple conditions are violated, the functon return the condition that appears first in the return list
int checkPassword(const char * s, const char * email) {
  string pass(s), e(email);
    // pass = pass.substr(0, pass.size() - 1);
  if(pass.size() < 8) {
    return -1;
  }
  if(pass.size() > 20) {
    return -2;
  }
  string se = "";
  for(char i : e) {
    if(i == '@') 
      break;
    se += i;
  }
  int sei = -1;
  if(pass.size() >= se.size()) {
    for(int i = 0; i < pass.size() - se.size() + 1; i++) {
      if(i >= pass.size())
        break;
      if(se == pass.substr(i, se.size())) {
        sei = i;
        break;
      }
    }
  }
  if(sei != -1) {
    return -(300 + sei);
  }
  int sci = -1;
  for(int i = 0; i < pass.size() - 2; i++) {
    if(pass[i] == pass[i + 1] && pass[i] == pass[i + 2]) {
      sci = i;
      break;
    }
  }
  if(sci != -1) {
    return -(400 + sci);
  }
  bool ok = false;
  for(char i : pass) {
    for(char special : {'@', '#', '%', '$', '!'}) {
      if(i == special)
        ok = true;
    }
  }
  if(!ok) {
    return -5;
  }
  for(int i = 0; i < pass.size(); i++) {
    if('a' <= pass[i] && pass[i] <= 'z') 
      continue;
    if('A' <= pass[i] && pass[i] <= 'Z')
      continue;
    if('0' <= pass[i] && pass[i] <= '9')
      continue;
    ok = false;
    for(char special : {'@', '#', '%', '$', '!'}) {
      if(pass[i] == special)
        ok = true;
    }
    if(ok)
      continue;
    return i;
  }
  return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
  string s[num_pwds];
  bool mark[num_pwds];
  pair<int, int> a[num_pwds]; //occurrences, idx
  for(int i = 0; i < num_pwds; i++) {
    mark[i] = false;
    s[i] = string(arr_pwds[i]);
  }
  for(int i = 0; i < num_pwds; i++) {
    a[i].second = i;
    mark[i] = true;
    for(int j = i + 1; j < num_pwds; j++) {
      if(mark[j]) 
        continue;
      if(s[i] == s[j]) {
        a[i].first++;
        mark[j] = true;
      }
    }
  }
  int maxLen = 0, occurrences = 0, ans = 0;
  for(int i = 0; i < num_pwds; i++) {
    if(occurrences < a[i].first) {
      occurrences = a[i].first;
      maxLen = s[a[i].second].size();
      ans = a[i].second;
    }
    if(occurrences == a[i].first) {
      if(maxLen < s[a[i].second].size()) {
        maxLen = s[a[i].second].size();
        ans = a[i].second;
      }
    }
  }
  return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
