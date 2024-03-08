void tc_1183()
{
    std::cout << "----- Testcase 1183 -----" << std::endl;
    int E2 = 20, HP1 = 472, EXP1 = 274, M1 = 2468;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}