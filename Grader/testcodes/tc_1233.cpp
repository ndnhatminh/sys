void tc_1233()
{
    std::cout << "----- Testcase 1233 -----" << std::endl;
    int E2 = 84, HP1 = 600, EXP1 = 500, M1 = 2000;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}