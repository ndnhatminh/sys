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

void Check(int &n, int Max)
{
    // n = (n < m) ? m : (n > M) ? M : n;
    n = max(0, min(n, Max));
};

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    // TODO: Complete this function
    if (E1 >= 0 && E1 <= 99)
    {
		Check(EXP1, 600);
		Check(EXP2, 600);

        if ((0 <= E1) && (E1 <= 3))
        {
            switch (E1)
            {
            case 0:
                EXP2 += 29;
                Check(EXP2, 600);
                break;
            case 1:
                EXP2 += 45;
                Check(EXP2, 600);
                break;
            case 2:
                EXP2 += 75;
                Check(EXP2, 600);
                break;
            case 3:
                EXP2 += 29 + 45 + 75;
                Check(EXP2, 600);
                break;
            };
            int d = E1 * 3 + EXP1 * 7;
            double df = (double)d;
            double EXP1_f = (double)EXP1;

            /*if (d % 2)
                  {EXP1 = EXP1 - (int)( (double)df/100 + 0.999); Check(EXP1, 600);}
              else{EXP1 = EXP1 + (int)( (double)df/100 + 0.999); Check(EXP1, 600);}*/
            if (d % 2)
            {
                int k = d / 100;
                EXP1 = EXP1 - k;
                Check(EXP1, 600);
                Check(EXP2, 600);
            }
            else
            {
                EXP1 = EXP1 + (int)((double)df / 200 + 0.999);
                Check(EXP1, 600);
            }
        }
        else if ((4 <= E1) && (E1 <= 99))
        {
            if (E1 <= 19)
            {
                EXP2 += (int)((double)E1 / 4 + 19 + 0.999);
                Check(EXP2, 600);
            }
            else if (E1 <= 49)
            {
                EXP2 += (int)((double)E1 / 9 + 21 + 0.999);
                Check(EXP2, 600);
            }
            else if (E1 <= 65)
            {
                EXP2 += (int)((double)E1 / 16 + 17 + 0.999);
                Check(EXP2, 600);
            }
            else if (E1 <= 79)
            /***/ {
                EXP2 += (int)((double)E1 / 4 + 19 + 0.999);
                Check(EXP2, 600);
                if (EXP2 > 200)
                {
                    EXP2 += (int)((double)E1 / 9 + 21 + 0.999);
                    Check(EXP2, 600);
                }
        /***/}
        else
        /**/ {

            EXP2 += (int)((double)E1 / 4 + 19 + 0.999) + (int)((double)E1 / 9 + 21 + 0.999);


            Check(EXP2, 600);
            if (EXP2 > 400)
            {
                EXP2 += (int)((double)E1 / 16 + 17 + 0.999);
                EXP2 = (int)((double)EXP2 * 1.15 + 0.999);
            }
            Check(EXP2, 600);

           /**/ }
        ;
        EXP1 = EXP1 - E1;
        }

        Check(EXP1, 600);
        Check(EXP2, 600);

        return (EXP1 + EXP2);
    }
    else
        return -99;
    // return exp1 + exp2;
}

int soChinhPhuong(int x)
{
    int a = sqrt(x);

    int b = a * a;
    int c = (a + 1) * (a + 1);

    if ((x - b) < (c - x))
        return b;
    else
        return c;
}
bool Checkmoney(int currentM, int originalM, int E2)
{

	if (currentM <= 0) {
		return true;
	}

    if (E2 % 2 != 0)
    {
        // cout << (currentM < originalM /2 ) << '\n';
        return ((double)currentM < ((double)originalM / 2.0));
    }
    else
    {
        // cout << (currentM <= 0) << '\n';
        return currentM <= 0;
    }
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function

	if (E2 < 0 || E2 > 99) {
		return -99;
	}

	Check(EXP1, 600);
	Check(HP1, 666);
	Check(M1, 3000);

    int chinhPhuong = soChinhPhuong(EXP1);
    int originalM = M1;
    double P1, P2;

    if (EXP1 >= chinhPhuong)
    {
        P1 = 1;
    }
    else
    {
        P1 = (1.0 * EXP1 / chinhPhuong + 80) / 123;
    }

    do
    {

		if (Checkmoney(M1, originalM, E2))
        {
            break;
        }

        // SK 1
        if (HP1 < 200)
        {
            HP1 = (int)(1.3 * HP1 + 0.999);
            M1 -= 150;
        }
        else
        {
            HP1 = (int)(1.1 * HP1 + 0.999);
            M1 -= 70;
        }
        // Check(M1, originalM);
        //   Check(EXP2, 0, 600);
        Check(HP1, 666);
        Check(EXP1, 600);
        Check(M1, 3000);

        //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';

        if (Checkmoney(M1, originalM, E2))
        {
            break;
        }
        // SK 2
        if (EXP1 < 400)
        {
            M1 -= 200;
        }
        else
        {
            M1 -= 120;
        }

        EXP1 = (int)(1.13 * EXP1 + 0.999);
        Check(EXP1, 600);
        Check(M1, 3000);

        //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';

        // Check(M1, 3000);
        if (Checkmoney(M1, originalM, E2))
        {
            break;
        }

        // SK 3
        if (EXP1 < 300)
        {
            M1 -= 100;
        }
        else
        {
            M1 -= 120;
        }


        EXP1 = (int)(0.999 + EXP1 * 0.9);

        //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';

        //       Check(EXP2, 0, 600);
        Check(EXP1, 600);
        Check(M1, 3000);
        // Check(M1, 3000);
        if (Checkmoney(M1, originalM, E2))
        {
            break;
        }
    } while (E2 % 2 != 0);

    HP1 = (int)(0.999 + HP1 * 0.83);
    EXP1 = (int)(0.999 + EXP1 * 1.17);

    Check(EXP1, 600);
    Check(HP1, 666);

    //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';


   	chinhPhuong = soChinhPhuong(EXP1);

    if (EXP1 >= chinhPhuong)
        P2 = 1;
    else
        P2 = (1.0 * EXP1 / chinhPhuong + 80) / 123;

    // Task 3
    double P3;
    double P_array[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10)
        P3 = P_array[E2];
    else
        P3 = P_array[((E2 % 10) + (E2 / 10)) % 10];


    //cout << ((E2 % 10) + (E2 / 10)) % 10 << '\n';
    // cout << P1 << ' ' << P2 << ' ' << P3 << '\n';
    //cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';

    double p_trungbinh = (P1 + P2 + P3 / 100.0) / 3.0;

    //cout << p_trungbinh << '\n';

    if (p_trungbinh == 1)
    {
        EXP1 = (int)(0.999 + 0.75 * EXP1);

        // cout << HP1 << ' ' << EXP1 << ' ' << M1 << '\n';

    } else {
    	if (p_trungbinh < 0.5)
		{
		    HP1 = (int)(0.999 + 0.85 * HP1);
		    EXP1 = (int)(0.999 + 1.15 * EXP1);
		}
		else
		{
		    HP1 = (int)(0.999 + 0.9 * HP1);
		    EXP1 = (int)(0.999 + 1.2 * EXP1);
		}
    }
    //       Check(EXP2, 0, 600);
    Check(EXP1, 600);
    Check(HP1, 666);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
	if (E3 < 0 || E3 > 99) {
		return -99;
	}


    Check(EXP1, 600);
	Check(HP1, 666);
    Check(EXP2, 600);
	Check(HP2, 666);

    // TODO: Complete this function
    int map[10][10];
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = ((E3 * j) + (i * 2)) * (i - j);
           //cout << map[i][j] << '\t';
        }
        //cout << '\n';
    }


    int r = 0;
    int s = 0;
    for (int e = 0; e < 10; e++)
    {
        for (int f = 0; f < 10; f++)
        {

            if (map[e][f] > E3 * 2)
            {
                r++;
            }

            if (map[e][f] < -E3)
            {
                s++;
            }

        	// cout << map[e][f] << ' ';
        }
    }

    while (r >= 10)
    {
        r = (r / 10) + (r % 10);
    }

    while (s >= 10)
    {
        s = (s / 10) + (s % 10);
    }

	int i = r;
	int j = s;

    // cout << i << ' ' << j << '\n';



    int diem_taxi = map[i][j];
    int diem_sherlock = map[i][j];

    while ((i <= 9) && (j <= 9) && (i >= 0) && (j >= 0))
    {
        diem_sherlock = max(diem_sherlock, map[i][j]);
        i++;
        j++;
    }

    i = r;
    j = s;

    while ((i <= 9) && (j <= 9) && (i >= 0) && (j >= 0))
    {
        // if (map[i][j] > diem_sherlock)
        {
            diem_sherlock = max(diem_sherlock, map[i][j]);
            i--;
            j--;
        }
    }

	i = r;
    j = s;

    while ((i <= 9) && (j <= 9) && (i >= 0) && (j >= 0))
    {
        // if (map[i][j] > diem_sherlock)
        {
            diem_sherlock = max(diem_sherlock, map[i][j]);
            i++;
            j--;
        }
    }

 	i = r;
    j = s;

    while ((i <= 9) && (j <= 9) && (i >= 0) && (j >= 0))
    {
        // if (map[i][j] > diem_sherlock)
        {
            diem_sherlock = max(diem_sherlock, map[i][j]);
            i--;
            j++;
        }
    }
    if (abs(diem_taxi) > diem_sherlock)
    {
        EXP1 = (int)(0.999 + (0.88 * EXP1));
        EXP2 = (int)(0.999 + (0.88 * EXP2));
        HP1 = (int)(0.999 + (0.9 * HP1));
        HP2 = (int)(0.999 + (0.9 * HP2));

        Check(EXP1, 600);
    	Check(HP1, 666);
        Check(EXP2, 600);
    	Check(HP2, 666);
    }
    else
    {
        EXP1 = (int)(0.999 + (1.12 * EXP1));
        EXP2 = (int)(0.999 + (1.12 * EXP2));
        HP1 = (int)(0.999 + (1.1 * HP1));
        HP2 = (int)(0.999 + (1.1 * HP2));

        Check(EXP1, 600);
    	Check(HP1, 666);
        Check(EXP2, 600);
    	Check(HP2, 666);
    }

    // cout << diem_taxi << ' ' << diem_sherlock << '\n';

    return (abs(diem_taxi) > diem_sherlock) ? (diem_taxi) : (diem_sherlock);
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // TODO: Complete this function

    int s_l = strlen(s);

    if ((s_l < 8))
        return -1;

    if (s_l > 20)
        return -2;

    for (int i = 0; i < s_l; i++)
    {
        if (s[i] == email[0])
        {
			// cout << i << ' ';

            int j = i + 1;
            int k = 1;
            while ( (j < s_l && s[j] == email[k]) && email[k] != '@')
            {
                j++;
                k++;
            }

            if (email[k] == '@')
            {
                return -300 - i;
            }
        }
    }

    for (int i = 2; i < s_l; i++)
    {
    	// cout << s[i-2];
        if ((s[i - 2] == s[i]) && (s[i - 1] == s[i]))
            return -400 - (i-2);
    }

    bool co_ki_tu_dac_biet = false;
    int co_ki_tu_ko_hop_le = -1;

    for (int i = 0; i < s_l; i++)
    {
        char c = s[i];

        switch (s[i])
        {
        case '@':
        case '#':
        case '%':
        case '$':
        case '!':
            co_ki_tu_dac_biet = true;
            break;

        default:
            if (!isalnum(c) && co_ki_tu_ko_hop_le == -1)
            {
                co_ki_tu_ko_hop_le = i;
            }
        }
    }

    if (!co_ki_tu_dac_biet)
    {
        return -5;
    }

    if (co_ki_tu_ko_hop_le != -1)
    {
        return co_ki_tu_ko_hop_le;
    }

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    int n = num_pwds;
    int dem[n];
    int lon_nhat = 0;
    int i, j, k;

    for (int k = 0; k < n; k++)
    {
        dem[k] = 0;
    }
    /*for (int i = 2; i< n; i++){
          for (int j=1; j < i; j++)
          {
              if (arr_pwds[j] == arr_pwds[i])
              {
                  dem[j]++; break;
              }
          }
      }*/
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (!strcmp(arr_pwds[i], arr_pwds[j]))
                dem[i]++;
        }
    }
    for (k = 0; k < n; k++)
    {
        if (dem[k] > lon_nhat)
            lon_nhat = dem[k];
    }
    /*i=0;int chieu_dai_lon_nhat = 0; j=0;
      for (k=0; k< n;k++)
      {
          if (dem[k] == lon_nhat)
            {
                 vitri[i] = k; i++;
            }
            for (i=0 ; i < n; i++)
            {
                if (strlen(arr_pwds[vitri[i]])> chieu_dai_lon_nhat)
                   {chieu_dai_lon_nhat = strlen(arr_pwds[vitri[i]]);j= i;}
            }
      }*/
    int max_chieu_dai = 0;
    int max_i = 0;
    for (int i = 0; i < n; i++)
    {
        int l = strlen(arr_pwds[i]);
        if ((dem[i] == lon_nhat) && (l > max_chieu_dai))
        {
            max_chieu_dai = l;
            max_i = i;
        }
    }
    return max_i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
