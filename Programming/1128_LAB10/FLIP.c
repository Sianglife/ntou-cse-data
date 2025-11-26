int main() {
    int i, j;
    int *p, *q;
    p = &i;
    p = &*&i;
    // i = (int) p; // Warning: incompatible pointer to integer conversion
    // q = &p; //
    // *q = &j; //
    // i = (*&)j; //
    i = *&*&j;
    i = *p++ + *q;
}