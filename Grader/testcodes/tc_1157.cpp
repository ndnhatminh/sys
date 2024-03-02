void tc_1157()
{
    std::cout << "----- Testcase 1157 -----" << std::endl;
    int E2 = 54, HP1 = 126, EXP1 = 143, M1 = 128;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}