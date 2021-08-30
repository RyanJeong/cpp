namespace {
    int static_func(void)
    {

        return 3;
    }

    int static_var = 1;
}

int main(void)
{
    static_var=static_func();

    return 0;
}