void tc_1248()
{
    std::cout << "----- Testcase 1248 -----" << std::endl;
    int E2 = 22, HP1 = 596, EXP1 = 67, M1 = 591;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}