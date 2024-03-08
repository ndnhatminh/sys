void tc_1238()
{
    std::cout << "----- Testcase 1238 -----" << std::endl;
    int E2 = 42, HP1 = 244, EXP1 = 169, M1 = 520;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}