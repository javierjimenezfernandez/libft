/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part2_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 20:25:32 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/19 14:04:26 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	int	ft_count_words(char const *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		else
		{
			if (flag)
			{
				count++;
				flag = 0;
			}
		}
		s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static size_t	ft_compute_trimmed_size(char const *s1, char const *set)
{
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	size = ft_strlen(s1) + 1;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			size--;
		else
			break ;
		i++;
	}
	j = ft_strlen(s1);
	while (j-- && j > i)
	{
		if (ft_strchr(set, s1[j]))
			size--;
		else
			break ;
	}
	return (size);
}

char	ft_test_func_mapi(unsigned int i, char c)
{
	c += i;
	return (c);
}

void	ft_test_func_iteri(unsigned int i, char *c)
{
	*c += i;
}


int	main(void)
{
	char	**word_list;
	char	substr_1[] = "Hola Mundo";
	char	substr_2[] = "";
	char	join_1[] = "Hola Mundo";
	char	join_2[] = " Cruel";
	char	join_3[] = "";
	char	strtrim_str[] = "___-_Hola_-Mundo_";
	char	strtrm_sep[] = "_-";
	char	split_str[] = " hola,   ¿qué  tal?   ";
	char	test_separator = ' ';
	char	all_a[] = "aaaaaaaaaaaaaaaaaaaaaaaaaa";
	char	*test_p;
	char	*test_str;
	char	*test_ret;
	int		word_count;
	int		i;
	int		int_test;
	int		zero = 0;
	int		int_max = 2147483647;
	int		int_min = -2147483648;

	printf("\n");

	/* ft_substr test */
	/* ------------------------------------- */
	printf("0 - FT_SUBSTR TEST\n");
	printf("-------------------------------------\n");
	test_str = substr_1;
	printf("string to test: \"%s\"\n", test_str);
	test_ret = ft_substr(test_str, 2, 100);
	printf("ft_substr(\"%s\", 2, 100) = %s\n", test_str, test_ret);
	free(test_ret);
	test_ret = ft_substr(test_str, 2, 4);
	printf("ft_substr(\"%s\", 2, 4) = %s\n", test_str, test_ret);
	free(test_ret);
	test_ret = ft_substr(test_str, 2, 0);
	printf("ft_substr(\"%s\", 2, 0) = %s\n", test_str, test_ret);
	free(test_ret);
	test_ret = ft_substr(test_str, 100, 4);
	printf("ft_substr(\"%s\", 100, 4) = %s\n", test_str, test_ret);
	free(test_ret);
	test_str = substr_2;
	printf("string to test: \"%s\"\n", test_str);
	test_ret = ft_substr(test_str, 2, 100);
	printf("ft_substr(\"%s\", 2, 100) = %s\n", test_str, test_ret);
	free(test_ret);
	printf("\n");

	/* ft_strjoin test */
	/* ------------------------------------- */
	printf("1 - FT_STRJOIN TEST\n");
	printf("-------------------------------------\n");
	printf("strings to join:\n\t\"%s\"\n\t\"%s\"\n", join_1, join_2);
	test_ret = ft_strjoin(join_1, join_2);
	printf("strings joined:\n\t\"%s\"\n", test_ret);
	free(test_ret);
	printf("strings to join:\n\t\"%s\"\n\t\"%s\"\n", join_3, join_2);
	test_ret = ft_strjoin(join_3, join_2);
	printf("strings joined:\n\t\"%s\"\n", test_ret);
	free(test_ret);
	printf("\n");

	/* ft_strtrim test */
	/* ------------------------------------- */
	printf("2 - FT_STRTRIM TEST\n");
	printf("-------------------------------------\n");
	test_str = strtrim_str;
	printf("ft_compute_trimmed_size(\"%s\", \"%s\") = %zu\n", \
		test_str, strtrm_sep, ft_compute_trimmed_size(test_str, strtrm_sep));
	test_ret = ft_strtrim(test_str, strtrm_sep);
	printf("ft_strtrim(\"%s\", \"%s\") = %s\n", test_str, strtrm_sep, test_ret);
	free(test_ret);
	printf("\n");

	/* ft_split test */
	/* ------------------------------------- */
	printf("3 - FT_SPLIT TEST\n");
	printf("-------------------------------------\n");
	i = 0;
	test_str = split_str;
	printf("string to test: \"%s\"\n", test_str);
	printf("word_count = %d\n", ft_count_words(test_str, test_separator));
	printf("word_len (of the first word) = %d\n", ft_wordlen(test_str, test_separator));
	word_count = ft_count_words(test_str, ' ');
	word_list = ft_split(test_str, ' ');
	printf("word_list:\n");
	while (i < word_count + 1)
	{
		printf("%s\n", word_list[i]);
		i++;
	}
	while (i--)
		free(word_list[i]);
	free(word_list);
	printf("\n");

	/* ft_itoa test */
	// -------------------------------------
	printf("4 - FT_ITOA TEST\n");
	printf("-------------------------------------\n");
	int_test = int_min;
	test_ret = ft_itoa(int_test);
	printf("ft_numlen(%d) = %d\n", int_test, ft_numlen(int_test));
	printf("ft_itoa(%d) = \"%s\"\n", int_test, test_ret);
	free(test_ret);
	int_test = zero;
	test_ret = ft_itoa(int_test);
	printf("ft_numlen(%d) = %d\n", int_test, ft_numlen(int_test));
	printf("ft_itoa(%d) = \"%s\"\n", int_test, test_ret);
	free(test_ret);
	int_test = int_max;
	test_ret = ft_itoa(int_test);
	printf("ft_numlen(%d) = %d\n", int_test, ft_numlen(int_test));
	printf("ft_itoa(%d) = \"%s\"\n", int_test, test_ret);
	free(test_ret);
	printf("\n");

	/* ft_strmapi test */
	// -------------------------------------
	printf("5 - FT_STRMAPI TEST\n");
	printf("-------------------------------------\n");
	test_p = ft_strdup(all_a);
	test_ret = ft_strmapi(test_p, ft_test_func_mapi);
	printf("ft_strmapi(\"%s\") = \"%s\"\n", test_p, test_ret);
	free(test_p);
	free(test_ret);
	printf("\n");

	/* ft_striteri test */
	// -------------------------------------
	printf("6 - FT_STRITERI TEST\n");
	printf("-------------------------------------\n");
	test_p = ft_strdup(all_a);
	printf("ft_striteri(\"%s\") = ", test_p);
	ft_striteri(test_p, ft_test_func_iteri);
	printf("\"%s\"\n", test_p);
	free(test_p);
	printf("\n");

	/* ft_putchar_fd test */
	// -------------------------------------
	printf("7 - FT_PUTCHAR_FD TEST\n");
	printf("-------------------------------------\n");
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	printf("\n");

	/* ft_putstr_fd test */
	// -------------------------------------
	printf("8 - FT_PUTCHAR_FD TEST\n");
	printf("-------------------------------------\n");
	ft_putstr_fd("Hola Mundo\n", 1);
	printf("\n");

	/* ft_putendl_fd test */
	// -------------------------------------
	printf("9 - FT_PUTENDL_FD TEST\n");
	printf("-------------------------------------\n");
	ft_putendl_fd("Hola Mundo", 1);
	printf("\n");

	/* ft_putnbr_fd test */
	// -------------------------------------
	printf("10 - FT_PUTNBR_FD TEST\n");
	printf("-------------------------------------\n");
	ft_putnbr_fd(int_min, 1);
	printf("\n");
	ft_putnbr_fd(zero, 1);
	printf("\n");
	ft_putnbr_fd(int_max, 1);
	printf("\n");


	printf("\nLEAKS:\n");
	system("leaks a.out");
	return (0);
}
