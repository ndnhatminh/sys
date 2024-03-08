void tc_1162()
{
    std::cout << "----- Testcase 1162 -----" << std::endl;
    int E2 = 90, HP1 = 198, EXP1 = 307, M1 = 647;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}