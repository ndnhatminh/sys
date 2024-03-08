void tc_1196()
{
    std::cout << "----- Testcase 1196 -----" << std::endl;
    int E2 = 96, HP1 = 69, EXP1 = 96, M1 = 69;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}