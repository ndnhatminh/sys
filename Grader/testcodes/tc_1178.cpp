void tc_1178()
{
    std::cout << "----- Testcase 1178 -----" << std::endl;
    int E2 = 72, HP1 = 498, EXP1 = 517, M1 = 1222;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}