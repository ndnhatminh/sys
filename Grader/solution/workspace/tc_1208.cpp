void tc_1208()
{
    std::cout << "----- Testcase 1208 -----" << std::endl;
    int E2 = 70, HP1 = 131, EXP1 = 244, M1 = 1389;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}