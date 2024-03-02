void tc_1221()
{
    std::cout << "----- Testcase 1221 -----" << std::endl;
    int E2 = 6, HP1 = 73, EXP1 = 448, M1 = 341;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}