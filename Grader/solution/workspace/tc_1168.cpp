void tc_1168()
{
    std::cout << "----- Testcase 1168 -----" << std::endl;
    int E2 = 34, HP1 = 215, EXP1 = 448, M1 = 784;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}