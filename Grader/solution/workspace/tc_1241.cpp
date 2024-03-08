void tc_1241()
{
    std::cout << "----- Testcase 1241 -----" << std::endl;
    int E2 = 90, HP1 = 622, EXP1 = 213, M1 = 36;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}