void tc_1193()
{
    std::cout << "----- Testcase 1193 -----" << std::endl;
    int E2 = 14, HP1 = 235, EXP1 = 532, M1 = 1235;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}