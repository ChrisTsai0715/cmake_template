#include "func.h"
#include "static_func.h"

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    print_info();
    print_static_info();

    return 0;
}
