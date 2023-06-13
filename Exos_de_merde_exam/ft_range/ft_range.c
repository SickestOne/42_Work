#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

int    *ft_range(int start, int end)
{
    int i = 0;
    int t_s = start;
    int t_end = end;
    int len = 0;
    if (start == 0 && end < start)
    {
        while (t_s != t_end)
        {
            i++;
            t_s--;
        }
    }
    else
        while (t_s < t_end)
        {
            i++;
            t_s++;
        }
    len = i + 1;
    int *tab = malloc(sizeof(int) * (len));
    if (!tab)
        return (0);
    if (start == 0 && end == 0)
    {
        tab[0] = 0;
        return (tab);
    }
    if ((start <= 0 && end >= 1) || (start >= 1 && end >= 1))
    {
        t_s = start;
        t_end = end;
        int j = 0;
        int t = 0;
        while (t_s < (end + 1))
        {
            t = t_s;
            tab[j] = t_s;
            t_s++;
            j++;
        }
        return (tab);
    }
    else if (start == 0 && end < 0)
    {
        t_s = start;
        t_end = end;
        int k = 0;
        while (len > k)
        {
            tab[k] = t_s;
            t_s -= 1;
            k++;
        }
        return (tab);
    }
    return (tab);
}

int    main()
{
    int i;
    int *t = ft_range(0, -3);
    for (i = 0; t[i]; i++)
        printf("%d\n", t[i]);
    return (0);
}

/*- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/
