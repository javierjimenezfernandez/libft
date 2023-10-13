/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonuspart_tester.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:04:15 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/13 15:13:15 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static void ft_test_lstiter(void *content)
{
	char	*len;

	len = ft_itoa(ft_strlen(content));
	ft_strlcpy(content, len, 3);
}

static void *ft_test_lstmap(void *content)
{
	char	*len;

	len = ft_itoa(ft_strlen(content));
	return (len);
}

int main(void)
{
	int		i;
	t_list	**list;
	t_list	**list_2;
	t_list	*dummy_node;
	t_list	*list_iterator;
	t_list	*test_node_1;
	t_list	*test_node_2;
	t_list	*test_node_3;
	//t_list	*test_node_4;
	//t_list	*test_node_5;
	t_list	*last_node;
	char	test_cont_1[] = "node 1";
	char	test_cont_2[] = "node 2";
	char	test_cont_3[] = "node 3";
	//char	test_cont_4[] = "node 4";
	//char	test_cont_5[] = "node 5";

	list = &dummy_node;
	list_2 = &dummy_node;

	printf("\n");

	/* ft_lstnew test */
	/* ------------------------------------- */
	printf("0 - FT_LSTNEW TEST\n");
	printf("-------------------------------------\n");
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	printf("New node address: \t%p\n", test_node_1);
	printf("New node content: \t\"%s\"\n", test_node_1->content);
	printf("Next node address: \t%p\n", test_node_1->next);
	ft_lstdelone(test_node_1, free);
	printf("\n");

	/* ft_lstadd_front test */
	/* ------------------------------------- */
	printf("1 - FT_LSTADD_FRONT TEST\n");
	printf("-------------------------------------\n");
	*list = NULL;
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_front(list, test_node_1);
	ft_lstadd_front(list, test_node_2);
	ft_lstadd_front(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	//ft_lstclear(list, free);
	//*list = NULL;
	printf("\n");

	/* ft_lstsize test */
	/* ------------------------------------- */
	printf("2 - FT_LSTSIZE TEST\n");
	printf("-------------------------------------\n");
	printf("List size: \t%d\n", ft_lstsize(*list));
	printf("Extra test -> size of an empty list: \t%d\n", ft_lstsize(NULL));
	printf("\n");

	/* ft_lstlast test */
	/* ------------------------------------- */
	printf("3 - FT_LSTLAST TEST\n");
	printf("-------------------------------------\n");
	last_node = ft_lstlast(*list);
	printf("Last node:\n");
	printf("%p: \t{last node: \"%s\"}->(%p)\n", \
			last_node, last_node->content, last_node->next);
	printf("\n");

	ft_lstclear(list, free);
	*list = NULL;

	/* ft_lstadd_back test */
	/* ------------------------------------- */
	printf("4 - FT_LSTADD_BACK TEST\n");
	printf("-------------------------------------\n");
	*list = NULL;
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_back(list, test_node_1);
	ft_lstadd_back(list, test_node_2);
	ft_lstadd_back(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	//ft_lstclear(list, free);
	//*list = NULL;
	printf("\n");

	/* ft_lstdelone test */
	/* ------------------------------------- */
	printf("5 - FT_LSTDELONE TEST\n");
	printf("-------------------------------------\n");
	ft_lstdelone(test_node_2, free);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	printf("Address of deleted node: \t%p\n", test_node_2);
	//ft_lstclear(list, free);
	ft_lstdelone(test_node_1, free);
	ft_lstdelone(test_node_3, free);
	*list = NULL;
	printf("\n");

	/* ft_lstclear test */
	/* ------------------------------------- */
	printf("6 - FT_LSTCLEAR TEST\n");
	printf("-------------------------------------\n");
	*list = NULL;
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_back(list, test_node_1);
	ft_lstadd_back(list, test_node_2);
	ft_lstadd_back(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	ft_lstclear(list, free);
	list_iterator = *list;
	/*while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");*/
	printf("Address of first node of the list after ft_lstclear(list, free): \t%p\n", *list);
	printf("\n");

	/* ft_lstiter test */
	/* ------------------------------------- */
	printf("7 - FT_LSTITER TEST\n");
	printf("-------------------------------------\n");
	*list = NULL;
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_back(list, test_node_1);
	ft_lstadd_back(list, test_node_2);
	ft_lstadd_back(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	ft_lstiter(*list, ft_test_lstiter);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	ft_lstclear(list, free);
	list_iterator = *list;
	
	/* ft_lstmap test */
	/* ------------------------------------- */
	printf("8 - FT_LSTMAP TEST\n");
	printf("-------------------------------------\n");
	*list = NULL;
	*list_2 = NULL;
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_back(list, test_node_1);
	ft_lstadd_back(list, test_node_2);
	ft_lstadd_back(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");
	*list_2 = ft_lstmap(*list, ft_test_lstmap, free);
	test_node_1 = ft_lstnew(ft_strdup(test_cont_1));
	test_node_2 = ft_lstnew(ft_strdup(test_cont_2));
	test_node_3 = ft_lstnew(ft_strdup(test_cont_3));
	ft_lstadd_back(list, test_node_1);
	ft_lstadd_back(list, test_node_2);
	ft_lstadd_back(list, test_node_3);
	i = 1;
	list_iterator = *list;
	printf("<list:\n");
	while (list_iterator->next)
	{
		printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
				list_iterator, i, list_iterator->content, list_iterator->next);
		list_iterator = list_iterator->next;
		i++;
	}
	printf("%p: \t{node %d: \"%s\"}->(%p)\n", \
			list_iterator, i, list_iterator->content, list_iterator->next);
	printf(">\n");


	//printf("<list:\n {node: "hello!"}->(null)>, [s => __strlen(s)], [x=> free(x)]\n");

}

