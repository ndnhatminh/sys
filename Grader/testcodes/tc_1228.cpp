void tc_1228()
{
    std::cout << "----- Testcase 1228 -----" << std::endl;
    int E2 = 54, HP1 = 195, EXP1 = 74, M1 = 164;
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << std::endl;
    int result = traceLuggage(HP1, EXP1, M1, E2);
    std::cout << "E2: " << E2 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", M1: " << M1 << ", result: " << result << std::endl;
}