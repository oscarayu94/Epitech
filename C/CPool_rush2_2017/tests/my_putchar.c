void my_putchar(char c)
{
	write(1, &c,1);
}

int     my_strlen(char const *str)
{
        int i;
        int lc;

        lc = '0';
        i = 0;
        while (str[i] != '\0')
        {
                lc++;
                i++;
        }
        my_putchar(lc);
}
