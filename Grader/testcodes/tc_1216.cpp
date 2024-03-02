void tc_1216()
{
    std::cout << "----- Testcase 1216 -----" << std::endl;
    int E2 = 52, HP1 = 138, EXP1 = 381, M1 = 1198;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}