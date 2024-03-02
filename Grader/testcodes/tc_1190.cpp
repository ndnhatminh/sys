void tc_1190()
{
    std::cout << "----- Testcase 1190 -----" << std::endl;
    int E2 = 90, HP1 = 90, EXP1 = 90, M1 = 90;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}