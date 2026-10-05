float acc;
float mac(float a, float b) {
    return acc + (a * b);
}
__attribute__((section(".init")))
void mac_init(void) {
    acc = -3.1412;
}
