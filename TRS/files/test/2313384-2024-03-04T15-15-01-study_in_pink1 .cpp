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

int mau(int HP)
{
    return max(0, min(666, HP));
}
int kn(int EXP)
{
    return max(0, min(600, EXP));
}
int tien(int M)
{
    return max(0, min(3000, M));
}

int nv(int E)
{
    if (E > 99 || E < 0)
        return -99;
    else return E;
}

//Nhiem vu 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    EXP1 = kn(EXP1);
    EXP2 = kn(EXP2);
    if (E1 < 0 || E1 > 99) return -99;
    if (E1 >= 0 && E1 <= 3)
    {
        int arr1[3] = { 29, 45, 75 };
        if (E1 == 0) EXP2 += arr1[0];
        EXP2 = kn(EXP2);
        if (E1 == 1) EXP2 += arr1[1];
        EXP2 = kn(EXP2);
        if (E1 == 2) EXP2 += arr1[2];
        EXP2 = kn(EXP2);
        if (E1 == 3) EXP2 += arr1[0] + arr1[1] + arr1[2];
        EXP2 = kn(EXP2);
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 = ceil(EXP1 + double(D) / 200);}
        else EXP1 = ceil(EXP1 - double(D) / 100);
        EXP1 = kn(EXP1);
    }

    if (E1 >= 4 && E1 <= 99)
    {
        if (E1 >= 4 && E1 <= 19) {
            EXP2 += ceil(double(E1) / 4 + 19);
            EXP2 = kn(EXP2);
        }
        if (E1 >= 20 && E1 <= 49) {
            EXP2 += ceil(double(E1) / 9 + 21);
            EXP2 = kn(EXP2);
        }
        if (E1 >= 50 && E1 <= 65) {
            EXP2 += ceil(double(E1) / 16 + 17);
            EXP2 = kn(EXP2);
        }
        if (E1 >= 66 && E1 <= 79)
        {
            EXP2 += ceil(double(E1) / 4 + 19);
            EXP2 = kn(EXP2);
            if (EXP2 > 200)
                EXP2 += ceil(double(E1) / 9 + 21);
                EXP2 = kn(EXP2);
        }
        if (E1 >= 80 && E1 <= 99)
        {
            EXP2 += ceil(double(E1) / 4 + 19);
            EXP2 = kn(EXP2);
            EXP2 += ceil(double(E1) / 9 + 21);
            EXP2 = kn(EXP2);
            if (EXP2 > 400) {
            EXP2 += ceil(double(E1) / 16 + 17);
            EXP2 = kn(EXP2);
            EXP2 += ceil(double(EXP2) * 15 / 100);
            EXP2 = kn(EXP2);
            }
        }

        EXP2 = kn(EXP2);
        EXP1 -= E1;
        EXP1 = kn(EXP1);
    }
    return EXP1 + EXP2;
}
//task2 
void kiemtra(int &x, int &y, int &z) 
{
    if (x > 666) {
	x = 666;
    }
    if (x < 0) {
	x = 0;
	}
    if (y > 600) {
	y = 600;
	}
    if (y < 0) {
	y = 0;
	}
    if (z > 3000) {
	z = 3000;
	}
    if (z < 0) {
	z = 0;
	}
}

int timsochinhphuong(int &t) {
    int S = sqrt(t);
    int bpnho = S * S;  
    int bplon = (S + 1) * (S + 1);  
    
    if (t - bpnho <= bplon - t) {
        return bpnho;
    } 
    else {
        return bplon;
    }
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99) 
	return -99;

    kiemtra(HP1, EXP1, M1);
    double P, P1, P2, P3;

    int S1 = timsochinhphuong(EXP1);
    if (EXP1 >= S1) {
	P1 = 100;
	}
    else {
	P1 = (((double(EXP1)/double(S1)) + 80)/123)*100;
	}
 
    double M0 = (double(M1)/2);

    while ((E2 % 2) != 0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 + double(HP1)*30/100);
            M1 -= 150; 
            kiemtra(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 + double(HP1)*10/100);
            M1 -= 70;
            kiemtra(HP1, EXP1, M1);
        }
        if (M1 < M0) {
		break;
		}
		if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 + double(EXP1)*13/100);
            kiemtra(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            EXP1 = ceil(EXP1 + double(EXP1)*13/100);
            kiemtra(HP1, EXP1, M1);
        }
        if (M1 < M0) {
		break;
		}

        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 = ceil(EXP1 - double(EXP1)*10/100);
            kiemtra(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            EXP1 = ceil(EXP1 - double(EXP1)*10/100);
            kiemtra(HP1, EXP1, M1);
        }
        if (M1 < M0) {
		break;
		}

    }


    while ((E2 % 2) == 0) {

        if (M1 == 0) {
		break;
		}
		if (HP1 < 200) {
            HP1 = ceil(HP1 + double(HP1)*30/100);
            M1 -= 150;
            kiemtra(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 + double(HP1)*10/100);
            M1 -= 70;
            kiemtra(HP1, EXP1, M1);
        }
        if (M1 == 0) {break;}

        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 + double(EXP1)*13/100);
            kiemtra(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            EXP1 = ceil(EXP1 + double(EXP1)*13/100);
            kiemtra(HP1, EXP1, M1);
        }
        if (M1 == 0) {
		break;
		}
        if (EXP1 < 300) {
            M1 -= 100;
            EXP1 = ceil(EXP1 - double(EXP1)*10/100);
            kiemtra(HP1, EXP1, M1);
        }
        else {
            M1 -= 120; 
            EXP1 = ceil(EXP1 - double(EXP1)*10/100);
            kiemtra(HP1, EXP1, M1);
        }
        break;
    }

    HP1 = ceil(HP1 - double(HP1)*17/100);
    EXP1 = ceil(EXP1 + double(EXP1)*17/100);
    kiemtra(HP1, EXP1, M1);

    int S2 = timsochinhphuong(EXP1);
    if (EXP1 >= S2) {P2 = 100;}
    else {P2 = (((double(EXP1)/double(S2)) + 80)/123)*100;}
    
    int arrP3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;

    if (E2 < 10) {
	i = E2;
	}
    else {i = (E2/10  + E2%10);
	} 

    if (E2 < 10) {
	i = E2;
	} 
    else {i = (E2/10  + E2%10);
	} 

    P3 = arrP3[i];

    if (P1 == 100 && P2 == 100 && P3 == 100 ) {
        EXP1 = ceil(EXP1 - double(EXP1)*25/100);
        kiemtra(HP1, EXP1, M1);
    }
    else {
        P = (P1 + P2 + P3)/3;
        if (P < 50) {
            HP1 = ceil(HP1 - double(HP1)*15/100);
            EXP1 = ceil(EXP1 + double(EXP1)*15/100);
            kiemtra(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 - double(HP1)*10/100);
            EXP1 = ceil(EXP1 + double(EXP1)*20/100);
            kiemtra(HP1, EXP1, M1);
        }
        }
    kiemtra(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}

//task 3
 
int tong(int x)
{
    while (x > 9)
        x = (x / 10) + (x % 10);
    return x;
}


int maxduongcheo(int a[10][10], int m, int n, int x, int y)
{
    int max = a[x][y];
    int i = x - 1;
    int j = y - 1;
    while (i >= 0 && j >= 0) {

        if (a[i][j] > a[x][y])
            max = a[i][j];
        i--;
        j--;
    }

    i = x + 1;
    j = y + 1;
    while (i < m && j < n) {
        if (a[i][j] > max)
            max = a[i][j];
        i++;
        j++;
    }

    i = x - 1;
    j = y + 1;
    while (i >= 0 && j < n) {
        if (a[i][j] > max)
            max = a[i][j];
        i--;
        j++;
    }

    i = x + 1;
    j = y - 1;
    while (i < m && j >= 0) {
        if (a[i][j] > max)
            max = a[i][j];
        i++;
        j--;
    }
    return max;
}



int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) return -99;
    int diemtaxi = 0, diemSherlock = 0, diemWatson = 0;
    int taxi[10][10] = { 0 };
    int Sherlock[10][10] = { 0 };
    int demd = 0, dema = 0;

    for (int dt = 0; dt < 10; dt++)
    {
        for (int ct = 0; ct < 10; ct++)
        {
            taxi[dt][ct] = ((E3 * ct) + (dt * 2)) * (dt - ct);
        }
    }

    for (int cS = 0; cS < 10; cS++)
    {
        for (int dS = 0; dS < 10; dS++)
        {
            Sherlock[dS][cS] = abs(maxduongcheo(taxi, 10, 10, dS, cS));
        }
    }

    for (int dt = 0; dt < 10; dt++)
    {
        for (int ct = 0; ct < 10; ct++)
        {
            if (taxi[dt][ct] > E3 * 2)
                demd++;
            if (taxi[dt][ct] < -E3)
                dema++;
        }
    }
    demd = tong(demd);
    demd = tong(demd);

    dema = tong(dema);
    dema = tong(dema);

    if (abs(taxi[demd][dema]) <= Sherlock[demd][dema])
    {
        EXP1 = ceil(EXP1 + double(EXP1) * 12 / 100);
        EXP2 = ceil(EXP2 + double(EXP2) * 12 / 100);
        HP1 = ceil(HP1 + double(HP1) * 10 / 100);
        HP2 = ceil(HP2 + double(HP2) * 10 / 100);
        EXP1 = kn(EXP1);
        EXP2 = kn(EXP2);
        HP1 = mau(HP1);
        HP2 = mau(HP2);
        return Sherlock[demd][dema];
    }
    else
    {
        EXP1 = ceil(EXP1 - double(EXP1) * 12 / 100);
        EXP2 = ceil(EXP2 - double(EXP2) * 12 / 100);
        HP1 = ceil(HP1 - double(HP1) * 10 / 100);
        HP2 = ceil(HP2 - double(HP2) * 10 / 100);
        EXP1 = kn(EXP1);
        EXP2 = kn(EXP2);
        HP1 = mau(HP1);
        HP2 = mau(HP2);
        return taxi[demd][dema];
    }
}
//task 4 
int checkPassword(const char *s, const char *email)
{
    int kitu = -1;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            kitu = i;
            break;
        }
    }

    char se[101];
    strncpy(se, email, kitu);
    se[kitu] = '\0';

    int dodai = strlen(s);
    if (dodai < 8) 
        return -1;
    if (dodai > 20) 
        return -2;

   
    const char *timkiem = strstr(s, se);
    if (timkiem != NULL) 
        return -(300 + (timkiem - s));

   
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }

   
    bool kitudacbiet = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            kitudacbiet = true;
    }
    if (!kitudacbiet)
        return -5;

    
    for (int i = 0; s[i] != '\0'; i++) {
        if (!(isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || 
            s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }

    return -10;
}
//Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int lonnhat = 0;
    int dainhat = 0;
    int giatri = 0;
    int count = -1;
    int dodai_str = -1;

    for (int i = 0; i < num_pwds; i++) {
        const char *string = arr_pwds[i];
        dodai_str = strlen(string);
        count = 1;

        for (int j = i; j < num_pwds; j++) {

            if (strcmp (string, arr_pwds[j]) == 0) {
                count++;
            }

            if (count > lonnhat) {
                lonnhat = count;
                dainhat = dodai_str;
                giatri = i;
            }
            
            if (count == lonnhat && dodai_str > dainhat) {
                lonnhat = count;
                dainhat = dodai_str;
                giatri = i;
            }
        }
    }

    return giatri;
}

 

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
