void tc_1203()
{
    std::cout << "----- Testcase 1203 -----" << std::endl;
    int E2 = 10, HP1 = 100, EXP1 = 600, M1 = 1200;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}