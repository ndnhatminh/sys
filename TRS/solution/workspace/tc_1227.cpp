void tc_1227()
{
    std::cout << "----- Testcase 1227 -----" << std::endl;
    int E2 = 90, HP1 = 268, EXP1 = 168, M1 = 368;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}