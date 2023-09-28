/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:54:04 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/22 11:49:07 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
#include "libft.h"

int	main(void)
{
	int			ok;
	int			i;
	int			ret1;
	int			ret2;
	const char	s[] = "Hola mundo \0 ajjaja";
	char		str1[] = "Hola mundo \0 ajjaja";
	char		str2[] = "Hola mundo \0 ajjaja";
	char		str3[] = "12345678901234567890123456789012345678901";
	char		empty_str[] = "";
	char		buff1[42];
	char		buff2[42];

	// ft_isalpha test
	// -------------------------------------
	printf("0 - FT_ISALPHA TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	ok = 1;
	while (i < 256)
	{
		if (isalpha(i) != ft_isalpha(i))
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
		printf("OK: Return of isalpha(i) == ft_isalpha(i) from i = 0 to %d\n", (i-1));
	else
	{
		printf("KO: Return of isalpha(%d) != ft_isalpha(%d)\n", i, i);
		printf("\tHint: isalpha(%d) = %d vs. ft_isalpha(%d) = %d\n", \
				i, isalpha(i), i, ft_isalpha(i));
	}
	printf("\n");

	// ft_isdigit test
	// -------------------------------------
	printf("1 - FT_ISDIGIT TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	ok = 1;
	while (i < 256)
	{
		if (isdigit(i) != ft_isdigit(i))
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
		printf("OK: Return of isdigit(i) == ft_isdigit(i) from i = 0 to %d\n", (i-1));
	else
	{
		printf("KO: Return of isdigit(%d) != ft_isdigit(%d)\n", i, i);
		printf("\tHint: isdigit(%d) = %d vs. ft_isdigit(%d) = %d\n", \
				i, isdigit(i), i, ft_isdigit(i));
	}
	printf("\n");

	// ft_isalnum test
	// -------------------------------------
	printf("2 - FT_ISALNUM TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	ok = 1;
	while (i < 256)
	{
		if (isalnum(i) != ft_isalnum(i))
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
		printf("OK: Return of isalnum(i) == ft_isalnum(i) from i = 0 to %d\n", (i-1));
	else
	{
		printf("KO: Return of isalnum(%d) != ft_isalnum(%d)\n", i, i);
		printf("\tHint: isalnum(%d) = %d vs. ft_isalnum(%d) = %d\n", \
				i, isalnum(i), i, ft_isalnum(i));
	}
	printf("\n");

	// ft_isascii test
	// -------------------------------------
	printf("3 - FT_ISASCII TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	ok = 1;
	while (i < 256)
	{
		if (isascii(i) != ft_isascii(i))
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
		printf("OK: Return of isascii(i) == ft_isascii(i) from i = 0 to %d\n", (i-1));
	else
	{
		printf("KO: Return of isascii(%d) != ft_isascii(%d)\n", i, i);
		printf("\tHint: isascii(%d) = %d vs. ft_isascii(%d) = %d\n", \
				i, isascii(i), i, ft_isascii(i));
	}
	printf("\n");

	// ft_isprint test
	// -------------------------------------
	printf("4 - FT_ISPRINT TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	ok = 1;
	while (i < 256)
	{
		if (isprint(i) != ft_isprint(i))
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
		printf("OK: Return of isprint(i) == ft_isprint(i) from i = 0 to %d\n", (i-1));
	else
	{
		printf("KO: Return of isprint(%d) != ft_isprint(%d)\n", i, i);
		printf("\tHint: isprint(%d) = %d vs. ft_isprint(%d) = %d\n", \
				i, isprint(i), i, ft_isprint(i));
	}
	printf("\n");

	// ft_strlen test
	// -------------------------------------
	printf("5 - FT_STRLEN TEST\n");
	printf("-------------------------------------\n");
	printf("String to test: %s\n", s);
	if (strlen(s) == ft_strlen(s))
		printf("OK: Return of strlen(s) == ft_strlen(s) is %zu\n", ft_strlen(s));
	else
	{
		printf("KO: Return of strlen(s) != ft_strlen(s)\n");
		printf("\tHint: strlen(s) = %zu vs. ft_strlen(s) = %zu\n", \
				strlen(s), ft_strlen(s));
	}
	printf("\n");

	// ft_memset test
	// -------------------------------------
	i = 0;
	ok = 1;
	printf("6 - FT_MEMSET TEST\n");
	printf("-------------------------------------\n");
	printf("Strings to test:\n\t str1: %s\n\t str2: %s\n", str1, str2);
	memset(str1 + 7, '*', 5);
	ft_memset(str2 + 7, '*', 5);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: str1[i] == str2[i] from i = 0 to %d\n", (i-1));
		printf("String after ft_memset(str2 + 7, '*', 5): %s\n", str2);

	}
	else
	{
		printf("KO: str1[i] != str2[i] at i = %d\n", i);
		printf("\tHint:\tstr1 after    memset(str1 + 7, '*', 5): %s\n", str1);
		printf("\t\tstr2 after ft_memset(str2 + 7, '*', 5): %s\n", str2);
	}
	printf("\n");

	// ft_bzero test
	// -------------------------------------
	i = 0;
	ok = 1;
	printf("7 - FT_BZERO TEST\n");
	printf("-------------------------------------\n");
	printf("Strings to test:\n\t str1: %s\n\t str2: %s\n", str1, str2);
	bzero(str1 + 12, 3);
	ft_bzero(str2 + 12, 3);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: str1[i] == str2[i] from i = 0 to %d\n", (i-1));
		printf("String after ft_bzero(str2 + 12, 5): %s\n", str2);

	}
	else
	{
		printf("KO: str1[i] != str2[i] at i = %d\n", i);
		printf("\tHint:\tstr1 after    bzero(str1 + 12, 3): %s\n", str1);
		printf("\t\tstr2 after ft_bzero(str2 + 12, 3): %s\n", str2);
	}
	printf("\n");

	// ft_memcpy test
	// -------------------------------------
	i = 0;
	ok = 1;
	memset(buff1, 42, sizeof(buff1));
	memset(buff2, 42, sizeof(buff2));
	printf("8 - FT_MEMCPY TEST\n");
	printf("-------------------------------------\n");
	printf("Strings to test:\n\t buff1: %s\n\t buff2: %s\n\t str3: %s\n", buff1, buff2, str3);
	memcpy(buff1, str3, 42);
	ft_memcpy(buff2, str3, 42);
	while (buff1[i] != '\0')
	{
		if (buff1[i] != buff2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: buff1[i] == buff2[i] from i = 0 to %d\n", (i-1));
		printf("Buffer after ft_memcpy(buff2, str3, 42): %s\n", buff2);

	}
	else
	{
		printf("KO: buff1[i] != buff2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    memcpy(buff1, str3, 42): %s\n", buff1);
		printf("\t\tbuff after ft_memcpy(buff2, str3, 42): %s\n", buff2);
	}

	ft_memcpy(((void *)0), ((void *)0), 3); // no debe dar segmentation fault
	//ft_memcpy(((void *)0), "sí debe dar un segmentatio fault", 17);
	//ft_memcpy("este también", ((void *)0), 17);
	printf("\n");

	// ft_memmove test
	// -------------------------------------i
	i = 0;
	ok = 1;
	memset(buff1, 42, sizeof(buff1));
	memset(buff2, 42, sizeof(buff2));
	printf("9 - FT_MEMMOVE TEST\n");
	printf("-------------------------------------\n");
	printf("Strings to test:\n\t buff1: %s\n\t buff2: %s\n\t str3: %s\n", buff1, buff2, str3);
	memmove(buff1, str3, 42);
	ft_memmove(buff2, str3, 42);
	while (buff1[i] != '\0')
	{
		if (buff1[i] != buff2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: buff1[i] == buff2[i] from i = 0 to %d\n", (i-1));
		printf("Buffer after ft_memmove(buff2, str3, 42): %s\n", buff2);

	}
	else
	{
		printf("KO: buff1[i] != buff2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    memmove(buff1, str3, 42): %s\n", buff1);
		printf("\t\tbuff after ft_memmove(buff2, str3, 42): %s\n", buff2);
	}
	printf("\n");
	i = 0;
	ok = 1;
	printf("Strings to test:\n\t str1: %s\n\t str2: %s\n", str1, str2);
	memmove(str1, str1 + 2, 10);
	ft_memmove(str2, str2 + 2, 10);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: str1[i] == str2[i] from i = 0 to %d\n", (i-1));
		printf("String after ft_memmove(str2, str2 + 2, 10): %s\n", str2);

	}
	else
	{
		printf("KO: str1[i] != str2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    memmove(str1, str1 + 2, 10): %s\n", str1);
		printf("\t\tbuff after ft_memmove(str2, str2 + 2, 10): %s\n", str2);
	}
	printf("\n");
	i = 0;
	ok = 1;
	printf("Strings to test:\n\t str1: %s\n\t str2: %s\n", str1, str2);
	memmove(str1 + 2, str1, 10);
	ft_memmove(str2 + 2, str2, 10);
	while (str1[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: str1[i] == str2[i] from i = 0 to %d\n", (i-1));
		printf("String after ft_memmove(str2 + 2, str2, 10): %s\n", str2);

	}
	else
	{
		printf("KO: str1[i] != str2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    memmove(str1 + 2, str1, 10): %s\n", str1);
		printf("\t\tbuff after ft_memmove(str2 + 2, str2, 10): %s\n", str2);
	}
	printf("\n");

	// ft_strlcpy test
	// -------------------------------------
	i = 0;
	ok = 1;
	memset(buff1, 42, sizeof(buff1));
	memset(buff2, 42, sizeof(buff2));
	printf("10 - FT_STRLCPY TEST\n");
	printf("-------------------------------------\n");
	printf("Strings to test:\n\t buff1: %s\n\t buff2: %s\n\t str3: %s\n", buff1, buff2, str3);
	ret1 = strlcpy(buff1, str3, sizeof(buff1));
	ret2 = ft_strlcpy(buff2, str3, sizeof(buff2));
	while (buff1[i] != '\0')
	{
		if (buff1[i] != buff2[i] || ret1 != ret2)
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: buff1[i] == buff2[i] from i = 0 to %d\n", (i-1));
		printf("Buffer after ft_strlcpy(buff2, str3, sizeof(buff2)): %s\n", buff2);
		printf("Return after ft_strlcpy(buff2, str3, sizeof(buff2)): %d\n", ret2);
	}
	else
	{
		printf("KO: buff1[i] != buff2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    strlcpy(buff1, str3, sizeof(buff1)): %s\n", buff1);
		printf("\t\tReturn after strlcpy(buff1, str3, sizeof(buff1)): %d\n", ret1);
		printf("\t\tbuff after ft_strlcpy(buff2, str3, sizeof(buff2)): %s\n", buff2);
		printf("\t\tReturn after ft_strlcpy(buff2, str3, sizeof(buff2)): %d\n", ret2);

	}
	printf("\n");
	i = 0;
	ok = 1;
	memset(buff1, 42, sizeof(buff1));
	memset(buff2, 42, sizeof(buff2));
	printf("Strings to test:\n\t buff1: %s\n\t buff2: %s\n\t empty_str: %s\n", buff1, buff2, empty_str);
	ret1 = strlcpy(buff1, empty_str, sizeof(buff1));
	ret2 = ft_strlcpy(buff2, empty_str, sizeof(buff2));
	while (buff1[i] != '\0')
	{
		if (buff1[i] != buff2[i] || ret1 != ret2)
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok == 1)
	{
		printf("OK: buff1[i] == buff2[i] from i = 0 to %d\n", i);
		printf("Buffer after ft_strlcpy(buff2, empty_str, sizeof(buff2)): %s\n", buff2);
		printf("Return after ft_strlcpy(buff2, empty_str, sizeof(buff2)): %d\n", ret2);
	}
	else
	{
		printf("KO: buff1[i] != buff2[i] at i = %d\n", i);
		printf("\tHint:\tbuff after    strlcpy(buff1, empty_str, sizeof(buff1)): %s\n", buff1);
		printf("\t\tReturn after strlcpy(buff1, empty_str, sizeof(buff1)): %d\n", ret1);
		printf("\t\tbuff after ft_strlcpy(buff2, empty_str, sizeof(buff2)): %s\n", buff2);
		printf("\t\tReturn after ft_strlcpy(buff2, empty_str, sizeof(buff2)): %d\n", ret2);
	}
	printf("\n");
	
}
