void tc_1198()
{
    std::cout << "----- Testcase 1198 -----" << std::endl;
    int E2 = 6, HP1 = 287, EXP1 = 410, M1 = 3000;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}