void tc_1215()
{
    std::cout << "----- Testcase 1215 -----" << std::endl;
    int E2 = 80, HP1 = 466, EXP1 = 272, M1 = 326;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}