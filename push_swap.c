/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 05:57:37 by hnagasak          #+#    #+#             */
/*   Updated: 2023/10/25 04:33:24 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_test(void)
{
	t_stack	*stack;

	stack = create_stack("stack_A");
	printf("create %s Stack!!\n", stack->name);
	push(stack, 111);
	push(stack, 222);
	push(stack, 333);
	print_stack(stack);
	printf("pop %d\n", pop(stack));
	printf("pop %d\n", pop(stack));
	push(stack, 444);
	/// 444 111
	printf("-----\n");
	print_stack(stack);

	printf("top:%p bottom:%p\n", stack->top, stack->bottom);
	printf("pop %d\n", pop(stack));
	printf("top:%p bottom:%p\n", stack->top, stack->bottom);
	printf("pop %d\n", pop(stack));
	printf("top:%p bottom:%p\n", stack->top, stack->bottom);
	printf("pop %d\n", pop(stack));
	printf("top:%p bottom:%p\n", stack->top, stack->bottom);
	printf("-----\n");
	print_stack(stack);

	printf("top:%p bottom:%p\n", stack->top, stack->bottom);
}

void test(){

	t_stack	*a;
	t_stack	*b;

	a = create_stack("Stack-A");
	b = create_stack("Stack-B");
	push(a, 111);
	push(a, 222);
	push(a, 333);
	push(b, 444);
	push(b, 555);
	push(b, 666);
	print_stack(a);
	print_stack(b);
	pb(a,b);
	print_stack(a);
	print_stack(b);

}

int	main(int argc, char *argv[])
{
	size_t	size;

	size = argc - 1;
	printf("count:%zu\n", size);
	printf("argv[1]:%s\n", argv[1]);
	test();
}
