# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int                            content;
	struct s_stack                *next;
	int                         index;
}    t_stack;

typedef struct s_stack_data_set
{
	t_stack    *stack_a;
	t_stack    *stack_b;
}    t_stack_data_set;

t_stack_data_set    *init_stacks_struct(void)
{
	t_stack_data_set    *set;
	set = malloc(sizeof(t_stack_data_set));
	if (!set)
		return (NULL);
	set->stack_a = NULL;
	set->stack_b = NULL;
	return (set);
}

void    insert_stack(t_stack **root, int value)
{
	t_stack    *current;
	t_stack    *new_node;
	current = NULL;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		exit(1);
	}
	new_node->content = value;
	new_node->index = -1;
	new_node->next = NULL;
	if (*root == NULL)
		*root = new_node;
	else
	{
		current = *root;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

t_stack    *get_next_min_node(t_stack *stack)
{
	t_stack        *root;
	t_stack        *min;
	bool        has_min;
	root = stack;
	min = NULL;
	has_min = false;
	if (root)
	{
		while (root)
		{
			if ((root->index == -1) && ((!has_min)
										|| (root->content < min->content)))
			{
				min = root;
				has_min = true;
			}
			root = root->next;
		}
	}
	return (min);
}
void    index_stack(t_stack **stack)
{
	int            index;
	t_stack        *root;
	index = 0;
	root = get_next_min_node(*stack);
	while (root)
	{
		root->index = ++index;
		root = get_next_min_node(*stack);
	}
}
t_stack    *create_list(char **input_array)
{
	size_t            index;
	t_stack            *stack_a;
	stack_a = NULL;
	index = 0;
	while (input_array[index])
	{
		insert_stack(&stack_a, atoi(input_array[index]));
		if (!stack_a)
			return (NULL);
		index++;
	}
	index_stack(&stack_a);
	return (stack_a);
}

t_stack    *init_stack_a(char *argv[])
{
	t_stack		*stack_a;
	char		**input_array;

	input_array = argv;
	stack_a = create_list(input_array);

	return (stack_a);
}

int    main(void)
{
	t_stack_data_set    *set;
	char *argv[] = {"5", "4", "1", "3", "2" ,"9",'\0'};
	set->stack_a = init_stack_a(argv); // this leads to an error in pythontutor
	set->stack_a = NULL;
//	radix_sort(&set->stack_a, &set->stack_b);
	return (0);
}

