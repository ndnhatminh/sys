/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "tc.h"
// #include "Tien_004142.h"
// #include "study_in_pink1.h"

using namespace std;

void sa_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        return;
    }

    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
}

void sa_tc_01_b() {
    cout << "----- Sample Testcase 01-b -----" << endl;
    int EXP1 = 400, EXP2 = 300, E1 = 1;

    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
}

void sa_tc_02() {
    cout << "----- Sample Testcase 02 -----" << endl;
    int EXP1 = 500, EXP2 = 450, E1 = 40;
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
}

void sa_tc_03() {
    cout << "----- Sample Testcase 03 -----" << endl;
    int EXP1 = 500, EXP2 = 450, E1 = 81;
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;
}

void sa_tc_04() {
    cout << "----- Sample Testcase 04 -----" << endl;
    int E3 = 39, HP1 = 333, EXP1 = 590, M1 = 890;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << endl;
    int result = traceLuggage(HP1, EXP1, M1, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << endl;
}

void sa_tc_05() {
    cout << "----- Sample Testcase 05 -----" << endl;
    int E3 = 59, HP1 = 400, EXP1 = 600, HP2 = 350, EXP2 = 500;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 
        << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;
    int result = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 
        << ", HP2: " << HP2 << ", EXP2: " << EXP2 
        << ", result: " << result
        << endl;
}

void sa_tc_06() {
    cout << "----- Sample Testcase 06 -----" << endl;
    char email[] = "pink@gmail.com";
    char s[] = "012345pink#pink";
    cout << "email: " << email << ", s: " << s << endl;
    int result = checkPassword(s, email);
    cout << "email: " << email << ", s: " << s << ", result: " << result << endl;
}

void sa_tc_07() {
    cout << "----- Sample Testcase 07 -----" << endl;
    char email[] = "pink@gmail.com";
    char s[] = "123xyz";
    cout << "email: " << email << ", s: " << s << endl;
    int result = checkPassword(s, email);
    cout << "email: " << email << ", s: " << s << ", result: " << result << endl;
}

void sa_tc_08() {
    cout << "----- Sample Testcase 08 -----" << endl;
    const char * arr_pwds[] = {"123xyz", "pink#pink", "pink123", "xxxx@xxxx", "pink#pink", "pink123", "pink123"};
    int num_pwds = 7;
    cout << "num_pwds: " << num_pwds << endl;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "num_pwds: " << num_pwds << ", result: " << result << endl;
}

void sa_tc_09() {
    cout << "----- Sample Testcase 09 -----" << endl;
    const char * arr_pwds[] = {"pink123", "xxxx@xxxx", "123xyz", "pink#pink", "pink#pink", "pink123"};
    int num_pwds = 6;
    cout << "num_pwds: " << num_pwds << endl;
    int result = findCorrectPassword(arr_pwds, num_pwds);
    cout << "num_pwds: " << num_pwds << ", result: " << result << endl;
}

int main(int argc, const char * argv[]) {
    if (argc == 1) {
        // sa_tc_01();
        // sa_tc_02();
        // sa_tc_03();
        // sa_tc_04();
        // sa_tc_05();
        // sa_tc_06();
        // sa_tc_07();
        // sa_tc_08();
        // sa_tc_09();

        // tc_01();
        // tc_05();
    }
    else if (argc == 2) {
        int func_idx = atoi(argv[1]) - 1;
        void (*func_ptr[365])() = {
            tc_1001,
            tc_1002,
            tc_1003,
            tc_1004,
            tc_1005,
            tc_1006,
            tc_1007,
            tc_1008,
            tc_1009,
            tc_1010,
            tc_1011,
            tc_1012,
            tc_1013,
            tc_1014,
            tc_1015,
            tc_1016,
            tc_1017,
            tc_1018,
            tc_1019,
            tc_1020,
            tc_1021,
            tc_1022,
            tc_1023,
            tc_1024,
            tc_1025,
            tc_1026,
            tc_1027,
            tc_1028,
            tc_1029,
            tc_1030,
            tc_1031,
            tc_1032,
            tc_1033,
            tc_1034,
            tc_1035,
            tc_1036,
            tc_1037,
            tc_1038,
            tc_1039,
            tc_1040,
            tc_1041,
            tc_1042,
            tc_1043,
            tc_1044,
            tc_1045,
            tc_1046,
            tc_1047,
            tc_1048,
            tc_1049,
            tc_1050,
            tc_1051,
            tc_1052,
            tc_1053,
            tc_1054,
            tc_1055,
            tc_1056,
            tc_1057,
            tc_1058,
            tc_1059,
            tc_1060,
            tc_1061,
            tc_1062,
            tc_1063,
            tc_1064,
            tc_1065,
            tc_1066,
            tc_1067,
            tc_1068,
            tc_1069,
            tc_1070,
            tc_1071,
            tc_1072,
            tc_1073,
            tc_1074,
            tc_1075,
            tc_1076,
            tc_1077,
            tc_1078,
            tc_1079,
            tc_1080,
            tc_1081,
            tc_1082,
            tc_1083,
            tc_1084,
            tc_1085,
            tc_1086,
            tc_1087,
            tc_1088,
            tc_1089,
            tc_1090,
            tc_1091,
            tc_1092,
            tc_1093,
            tc_1094,
            tc_1095,
            tc_1096,
            tc_1097,
            tc_1098,
            tc_1099,
            tc_1100,
            tc_1101,
            tc_1102,
            tc_1103,
            tc_1104,
            tc_1105,
            tc_1106,
            tc_1107,
            tc_1108,
            tc_1109,
            tc_1110,
            tc_1111,
            tc_1112,
            tc_1113,
            tc_1114,
            tc_1115,
            tc_1116,
            tc_1117,
            tc_1118,
            tc_1119,
            tc_1120,
            tc_1121,
            tc_1122,
            tc_1123,
            tc_1124,
            tc_1125,
            tc_1126,
            tc_1127,
            tc_1128,
            tc_1129,
            tc_1130,
            tc_1131,
            tc_1132,
            tc_1133,
            tc_1134,
            tc_1135,
            tc_1136,
            tc_1137,
            tc_1138,
            tc_1139,
            tc_1140,
            tc_1141,
            tc_1142,
            tc_1143,
            tc_1144,
            tc_1145,
            tc_1146,
            tc_1147,
            tc_1148,
            tc_1149,
            tc_1150,
            tc_1151,
            tc_1152,
            tc_1153,
            tc_1154,
            tc_1155,
            tc_1156,
            tc_1157,
            tc_1158,
            tc_1159,
            tc_1160,
            tc_1161,
            tc_1162,
            tc_1163,
            tc_1164,
            tc_1165,
            tc_1166,
            tc_1167,
            tc_1168,
            tc_1169,
            tc_1170,
            tc_1171,
            tc_1172,
            tc_1173,
            tc_1174,
            tc_1175,
            tc_1176,
            tc_1177,
            tc_1178,
            tc_1179,
            tc_1180,
            tc_1181,
            tc_1182,
            tc_1183,
            tc_1184,
            tc_1185,
            tc_1186,
            tc_1187,
            tc_1188,
            tc_1189,
            tc_1190,
            tc_1191,
            tc_1192,
            tc_1193,
            tc_1194,
            tc_1195,
            tc_1196,
            tc_1197,
            tc_1198,
            tc_1199,
            tc_1200,
            tc_1201,
            tc_1202,
            tc_1203,
            tc_1204,
            tc_1205,
            tc_1206,
            tc_1207,
            tc_1208,
            tc_1209,
            tc_1210,
            tc_1211,
            tc_1212,
            tc_1213,
            tc_1214,
            tc_1215,
            tc_1216,
            tc_1217,
            tc_1218,
            tc_1219,
            tc_1220,
            tc_1221,
            tc_1222,
            tc_1223,
            tc_1224,
            tc_1225,
            tc_1226,
            tc_1227,
            tc_1228,
            tc_1229,
            tc_1230,
            tc_1231,
            tc_1232,
            tc_1233,
            tc_1234,
            tc_1235,
            tc_1236,
            tc_1237,
            tc_1238,
            tc_1239,
            tc_1240,
            tc_1241,
            tc_1242,
            tc_1243,
            tc_1244,
            tc_1245,
            tc_1246,
            tc_1247,
            tc_1248,
            tc_1249,
            tc_1250,
            tc_1251,
            tc_1252,
            tc_1253,
            tc_1254,
            tc_1255,
            tc_1256,
            tc_1257,
            tc_1258,
            tc_1259,
            tc_1260,
            tc_1261,
            tc_1262,
            tc_1263,
            tc_1264,
            tc_1265,
            tc_1266,
            tc_1267,
            tc_1268,
            tc_1269,
            tc_1270,
            tc_1271,
            tc_1272,
            tc_1273,
            tc_1274,
            tc_1275,
            tc_1276,
            tc_1277,
            tc_1278,
            tc_1279,
            tc_1280,
            tc_1281,
            tc_1282,
            tc_1283,
            tc_1284,
            tc_1285,
            tc_1286,
            tc_1287,
            tc_1288,
            tc_1289,
            tc_1290,
            tc_1291,
            tc_1292,
            tc_1293,
            tc_1294,
            tc_1295,
            tc_1296,
            tc_1297,
            tc_1298,
            tc_1299,
            tc_1300,
            tc_1301,
            tc_1302,
            tc_1303,
            tc_1304,
            tc_1305,
            tc_1306,
            tc_1307,
            tc_1308,
            tc_1309,
            tc_1310,
            tc_1311,
            tc_1312,
            tc_1313,
            tc_1314,
            tc_1315,
            tc_1316,
            tc_1317,
            tc_1318,
            tc_1319,
            tc_1320,
            tc_1321,
            tc_1322,
            tc_1323,
            tc_1324,
            tc_1325,
            tc_1326,
            tc_1327,
            tc_1328,
            tc_1329,
            tc_1330,
            tc_1331,
            tc_1332,
            tc_1333,
            tc_1334,
            tc_1335,
            tc_1336,
            tc_1337,
            tc_1338,
            tc_1339,
            tc_1340,
            tc_1341,
            tc_1342,
            tc_1343,
            tc_1344,
            tc_1345,
            tc_1346,
            tc_1347,
            tc_1348,
            tc_1349,
            tc_1350,
            tc_1351,
            tc_1352,
            tc_1353,
            tc_1354,
            tc_1355,
            tc_1356,
            tc_1357,
            tc_1358,
            tc_1359,
            tc_1360,
            tc_1361,
            tc_1362,
            tc_1363,
            tc_1364,
            tc_1365,
        };

        func_ptr[func_idx]();
    }
    else {
        string input_file(argv[1]);
        int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
        if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
            return 1;
        }
    }
    return 0;
}