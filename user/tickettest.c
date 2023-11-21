// TODO: IMPLEMENT HERE
int main()
{
    int rc, i;

    for (i = 1; i <= 5; i++)
    {
        rc = fork();
        if (rc == 0)
        {
            settickets(i * 10);
        }
    }
}