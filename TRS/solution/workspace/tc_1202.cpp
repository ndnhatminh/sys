void tc_1202()
{
    std::cout << "----- Testcase 1202 -----" << std::endl;
    int E2 = 6, HP1 = 79, EXP1 = 84, M1 = 587;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}