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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    //4.1.1
    if (E1 >= 0 && E1 <= 3) {
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
        }
        int D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0) {
            EXP1 += static_cast<int>(ceil(D / 200.0));
        }
        else if (D % 2 == 1) {
            EXP1 -= static_cast<int>(floor(D / 100.0));
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if ( EXP1 < 0) {
            EXP1 = 0;
        }
        if (EXP2 > 600) {
            EXP2 = 600;
        } else if ( EXP2 < 0) {
            EXP2 = 0;
        }
        return EXP1 + EXP2;
    } else if (E1 >= 4 && E1 <= 99) {
         if (E1 >= 4 && E1 <= 19) {
            EXP2 += static_cast<int>(ceil(E1 / 4.0 + 19));
        } else if (E1 >= 20 && E1 <= 49) {
            EXP2 += static_cast<int>(ceil(E1 / 9.0 + 21));
        } else if (E1 >= 50 && E1 <= 65) {
            EXP2 += static_cast<int>(ceil(E1 / 16.0 + 17));
        } else if (E1 >= 66 && E1 <= 79) {
            EXP2 += static_cast<int>(ceil(E1 / 4.0 + 19));

            if (EXP2 > 200) {
                EXP2 += static_cast<int>(ceil(E1 / 9.0 + 21));
            }
        } else if (E1 >= 80 && E1 <= 99) {
            EXP2 += static_cast<int>(ceil(E1 / 4.0 + 19));
            EXP2 += static_cast<int>(ceil(E1 / 9.0 + 21));
            if (EXP2 > 400) {
                EXP2 += static_cast<int>(ceil(E1/16.0 + 17));
                EXP2 = static_cast<int>(ceil(EXP2 * 1.15));
            }
        }
        EXP1 -= static_cast<int>(ceil(E1));
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if ( EXP1 < 0) {
            EXP1 = 0;
        }
        if (EXP2 > 600) {
            EXP2 = 600;
        } else if ( EXP2 < 0) {
            EXP2 = 0;
        }
        return EXP1 + EXP2;
    } else {
        return -99;
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 >= 0 && E2 <= 99) {
        //road 1
        if (HP1 > 666) {
            HP1 = 666;
        } else if (HP1 < 0) {
            HP1 = 0;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (M1 > 3000) {
            M1 = 3000;
        } else if (M1 < 0) {
            M1 = 0;
        }
        int S = static_cast<int>(round(sqrt(EXP1)));
        double P1;
        if (EXP1 >= S) {
            P1 = 1.0;
        } else {
            P1 = (EXP1 / S + 80)/123;
        }
        
        // Road 2
        double P2;
        double oM1 = M1;
        if (E2 % 2 == 0) {
            if (M1 > 0) {
                if (HP1 < 200) {
                HP1 += ceil(HP1 * 0.3);
                M1 -= 150;
                } else {
                HP1 += ceil(HP1 * 0.1);
                M1 -= 70;
                }
            }
            if (HP1 > 666) {
                HP1 = 666;
            } else if (HP1 < 0) {
                HP1 = 0;
            }
            if (EXP1 > 600) {
                EXP1 = 600;
            } else if (EXP1 < 0) {
                EXP1 = 0;
            }
            if (M1 > 3000) {
                M1 = 3000;
            } else if (M1 < 0) {
                M1 = 0;
            }
            if (M1 > 0) {
                if (EXP1 < 400) {
                M1 -= 200;
                EXP1 += ceil(EXP1 * 0.13);
                } else {
                M1 -= 120;
                EXP1 += ceil(EXP1 * 0.13);
                }
            }
            if (HP1 > 666) {
                HP1 = 666;
            } else if (HP1 < 0) {
                HP1 = 0;
            }
            if (EXP1 > 600) {
                EXP1 = 600;
            } else if (EXP1 < 0) {
                EXP1 = 0;
            }
            if (M1 > 3000) {
                M1 = 3000;
            } else if (M1 < 0) {
                M1 = 0;
            }
            if (M1 > 0) {
                if (EXP1 < 300) {
                M1 -= 100;
                EXP1 -= floor(EXP1 * 0.1);
                } else { 
                M1 -= 120;
                EXP1 -= floor(EXP1 * 0.1);
                }
            }
            if (HP1 > 666) {
                HP1 = 666;
            } else if (HP1 < 0) {
                HP1 = 0;
            }
            if (EXP1 > 600) {
                EXP1 = 600;
            } else if (EXP1 < 0) {
                EXP1 = 0;
            }
            if (M1 > 3000) {
                M1 = 3000;
            } else if (M1 < 0) {
                M1 = 0;
            }
            HP1 -= floor(HP1 * 0.17);
            EXP1 += ceil(EXP1 * 0.17);
            if (HP1 > 666) {
                HP1 = 666;
            } else if (HP1 < 0) {
                HP1 = 0;
            }
            if (EXP1 > 600) {
                EXP1 = 600;
            } else if (EXP1 < 0) {
                EXP1 = 0;
            }
            if (M1 > 3000) {
                M1 = 3000;
            } else if (M1 < 0) {
                M1 = 0;
            }
        } else if (E2 % 2 == 1) {
            while (M1 > 0.5 * oM1) {
                if (HP1 < 200 && M1 > 0.5 * oM1) {
                    HP1 += ceil(HP1 * 0.3);
                    M1 -= 150;
                } else if (HP1 > 200 && M1 > 0.5 * oM1) {
                    HP1 += ceil(HP1 * 0.1);
                    M1 -= 70;
                }
                if (HP1 > 666) {
                    HP1 = 666;
                } else if (HP1 < 0) {
                    HP1 = 0;
                }
                if (EXP1 > 600) {
                    EXP1 = 600;
                } else if (EXP1 < 0) {
                    EXP1 = 0;
                }
                if (M1 > 3000) {
                    M1 = 3000;
                } else if (M1 < 0) {
                    M1 = 0;
                }
                if (EXP1 < 400 && M1 > 0.5 * oM1) {
                    M1 -= 200;
                    EXP1 += ceil(EXP1 * 0.13);
                } else if (EXP1 > 400 && M1 > 0.5 * oM1) {
                    M1 -= 120;
                    EXP1 += ceil(EXP1 * 0.13);
                }
                if (HP1 > 666) {
                    HP1 = 666;
                } else if (HP1 < 0) {
                    HP1 = 0;
                }
                if (EXP1 > 600) {
                    EXP1 = 600;
                } else if (EXP1 < 0) {
                    EXP1 = 0;
                }
                if (M1 > 3000) {
                    M1 = 3000;
                } else if (M1 < 0) {
                    M1 = 0;
                }
                if (EXP1 < 300 && M1 > 0.5 * oM1) {
                    M1 -= 100;
                    EXP1 -= floor(EXP1 * 0.1);
                } else if (EXP1 > 300 && M1 > 0.5 * oM1) { 
                    M1 -= 120;
                    EXP1 -= floor(EXP1 * 0.1);
                }
                if (HP1 > 666) {
                    HP1 = 666;
                } else if (HP1 < 0) {
                    HP1 = 0;
                }
                if (EXP1 > 600) {
                    EXP1 = 600;
                } else if (EXP1 < 0) {
                    EXP1 = 0;
                }
                if (M1 > 3000) {
                    M1 = 3000;
                } else if (M1 < 0) {
                    M1 = 0;
                }
            }
            HP1 -= floor(HP1 * 0.17);
            EXP1 += ceil(EXP1 * 0.17);
            if (HP1 > 666) {
                HP1 = 666;
            } else if (HP1 < 0) {
                HP1 = 0;
            }
            if (EXP1 > 600) {
                EXP1 = 600;
            } else if (EXP1 < 0) {
                EXP1 = 0;
            }
            if (M1 > 3000) {
                M1 = 3000;
            } else if (M1 < 0) {
                M1 = 0;
            }
        }
        if (EXP1 >= S) {
            P2 = 1.0;
        } 
        else {
            P2 = ((EXP1*1.0)/S + 80)/123;
        }
        //Road 3
        int k;
        if (E2 <= 9 && E2 >= 0) {
            k = E2;
        } else if (E2 >= 10 && E2 <= 99) {
            k = floor(E2 / 10) + (E2 % 10);
        }
        if (HP1 > 666) {
            HP1 = 666;
        } else if (HP1 < 0) {
            HP1 = 0;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (M1 > 3000) {
            M1 = 3000;
        } else if (M1 < 0) {
            M1 = 0;
        }
        int i = k % 10;
        int arrP[10] = {32,47,28,79,100,50,22,83,64,11};
        double P3 = arrP[i]/100.0;
        if (HP1 > 666) {
            HP1 = 666;
        } else if (HP1 < 0) {
            HP1 = 0;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (M1 > 3000) {
            M1 = 3000;
        } else if (M1 < 0) {
            M1 = 0;
        }
        //All road
        double P = (P1 + P2 + P3) / 3;
        if (P == 1.0) {
            EXP1 -= floor(EXP1 * 0.25);
        } else if (P >= 0.5) {
            HP1 -= floor(HP1 * 0.1);
            EXP1 += ceil(EXP1 * 0.2);
        } else if (P < 5.0) {
            HP1 -= floor(HP1 * 0.15);
            EXP1 += ceil(EXP1 * 0.15);
        }
        if (HP1 > 666) {
            HP1 = 666;
        } else if (HP1 < 0) {
            HP1 = 0;
        }
        if (EXP1 > 600) {
            EXP1 = 600;
        } else if (EXP1 < 0) {
            EXP1 = 0;
        }
        if (M1 > 3000) {
            M1 = 3000;
        } else if (M1 < 0) {
            M1 = 0;
        }
        return HP1 + EXP1 + M1;
    } else {
        return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(HP1 < 0) {
        HP1 = 0;
    } else if (HP1 > 666) {
        HP1 = 666;
    }
    if(HP2 < 0) {
        HP2 = 0;
    } else if (HP2 > 666) {
        HP2 = 666;
    } 
    if(EXP1 < 0) {
        EXP1 = 0;
    } else if (EXP1 > 600) {
        EXP1 = 600;
    }
    if(EXP2 < 0) {
        EXP2 = 0;
    } else if (EXP2 > 600) {
        EXP2 = 600;
    }

    if (E3 >= 0 && E3 <= 99) {
        int taxi[10][10] = {0};
        int SW[10][10] = {0};

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                int cheoTrai = 0;
                int cheoPhai = 0;

                for (int k = i, l = j; k < 10 && l < 10; ++k, ++l) {
                    cheoTrai += taxi[k][l];
                }

                for (int k = i, l = j; k < 10 && l >= 0; ++k, --l) {
                    cheoPhai += taxi[k][l];
                }

                SW[i][j] = max(cheoTrai, cheoPhai);
                if (SW[i][j] < 0) {
                    SW[i][j] = abs(SW[i][j]);
                }
            }
        }

        int x = 0;
        int y = 0;

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (taxi[i][j] > E3 * 2) {
                    x++;
                } else if (taxi[i][j] < -E3) {
                    y++;
                }
            }
        }

        int i = (x % 10) + (x / 10);
        int j = (y % 10) + (y / 10);

        while (i > 9) {
            i = (i % 10) + (i / 10);
        }

        while (j > 9) {
            j = (j % 10) + (j / 10);
        }

        int diemTaxi = taxi[i][j];
        int diemSW = SW[i][j];

        if (abs(diemTaxi) > diemSW) {
            EXP1 = ceil(EXP1 * 0.88);
            HP1 = ceil(HP1 * 0.9);
            EXP2 = ceil(EXP2 * 0.88);
            HP2 = ceil(HP2 * 0.9);
            if(HP1 < 0) {
                HP1 = 0;
            } else if (HP1 > 666) {
                HP1 = 666;
            }
            if(HP2 < 0) {
                HP2 = 0;
            } else if (HP2 > 666) {
                HP2 = 666;
            } 
            if(EXP1 < 0) {
                EXP1 = 0;
            } else if (EXP1 > 600) {
                EXP1 = 600;
            }
            if(EXP2 < 0) {
                EXP2 = 0;
            } else if (EXP2 > 600) {
                EXP2 = 600;
            }
            return diemTaxi;
        } else {
            EXP1 = ceil(EXP1 * 1.12);
            HP1 = ceil(HP1 * 1.1);
            EXP2 = ceil(EXP2 * 1.12);
            HP2 = ceil(HP2 * 1.1);
            if(HP1 < 0) {
                HP1 = 0;
            } else if (HP1 > 666) {
                HP1 = 666;
            }
            if(HP2 < 0) {
                HP2 = 0;
            } else if (HP2 > 666) {
                HP2 = 666;
            } 
            if(EXP1 < 0) {
                EXP1 = 0;
            } else if (EXP1 > 600) {
                EXP1 = 600;
            }
            if(EXP2 < 0) {
                EXP2 = 0;
            } else if (EXP2 > 600) {
                EXP2 = 600;
            }
            return diemSW;
        }
    } else {
        return -99;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = email;
    size_t aP = se.find('@');
    if (aP != string::npos) {
        se = se.substr(0, aP);
    }
    size_t dodaikytu = strlen(s);
    if (dodaikytu < 8) {
        return -1;
    }
    if (dodaikytu > 20) {
        return -2;
    }
    const char* sP = strstr(s, se.c_str());
    if (sP != nullptr) {
        return -(300 + (sP - s));
    }
    for (size_t i = 0; i < dodaikytu - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + (i));
        }
    }
    bool kytudacbiet = false;
    for (const char* p = s; *p != '\0'; ++p) {
        if (*p == '@' || *p == '#' || *p == '%' || *p == '$' || *p == '!') {
            kytudacbiet = true;
            break;
        }
    }

    if (kytudacbiet != true) {
        return -5;
    }
    for (size_t i = 0; i < dodaikytu; ++i) {
        char c = s[i];
        if ((isdigit(c) || islower(c) || isupper(c) || c == '@' || c == '#' || c == '%' || c == '$' || c == '!') != true) {
            return static_cast<int>(i);
        }
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    if (num_pwds <= 0 || arr_pwds == nullptr) {
        return -1;
    }

    int xuathiennhieunhat = 0;
    int dainhat = 0;
    int ketqua;

    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == nullptr) {
            continue;
        }

        int xuathien = 1;
        int dai = strlen(arr_pwds[i]);
        int vitridautien = i;

        for (int j = i + 1; j < num_pwds; ++j) {
            if (arr_pwds[j] != nullptr && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                xuathien++;
                arr_pwds[j] = nullptr;
            }
        }

        if (xuathien > xuathiennhieunhat || (xuathien == xuathiennhieunhat && dai > dainhat)) {
            xuathiennhieunhat = xuathien;
            dainhat = dai;
            ketqua = vitridautien;
        }
    }

    return ketqua;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////