void tc_1220()
{
    std::cout << "----- Testcase 1220 -----" << std::endl;
    int E2 = 50, HP1 = 181, EXP1 = 327, M1 = 638;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}