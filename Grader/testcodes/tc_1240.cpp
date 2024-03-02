void tc_1240()
{
    std::cout << "----- Testcase 1240 -----" << std::endl;
    int E2 = 86, HP1 = 262, EXP1 = 25, M1 = 136;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}