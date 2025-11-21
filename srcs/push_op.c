#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_idx;

	dest_idx = next_top(dest, dest->top);
	dest->stack[dest_idx] = src->stack[src->top];
	dest->top = dest_idx;
	src->stack[src->top] = 0;
	src->top = next_bot(src, src->top);
}

void	push_a(t_build *data)
{
	push (&data->b, &data->a);
	ft_printf ("pa\n");
}
void	push_b(t_build *data)
{
	push (&data->a, &data->b);
	ft_printf ("pb\n");
}


//checker si a ou b empty

/*void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;
	
	if (is_full(dest))
		return ;                                      // Si dest pleine, ne fait rien
	
	dest_i = next_up(dest, dest->top);               // Calcule nouvelle position top de dest
	dest->stack[dest_i] = src->stack[src->top];      // Copie la valeur
	dest->top = dest_i;                              // Met à jour le top de dest
	
	src->stack[src->top] = 0;                        // Efface l'ancienne valeur
	src->top = next_down(src, src->top);             // Met à jour le top de src
}
```

**Étapes détaillées :**

1. **Prépare destination :** `dest_i = next_up(dest, dest->top)`
   - Calcule où va être le nouveau sommet de `dest`
   - C'est **au-dessus** du sommet actuel

2. **Copie la valeur :** `dest->stack[dest_i] = src->stack[src->top]`
   - Prend l'élément au sommet de `src`
   - Le place dans `dest`

3. **Met à jour dest :** `dest->top = dest_i`
   - Le nouveau sommet de `dest` est maintenant `dest_i`

4. **Nettoie src :** `src->stack[src->top] = 0`
   - Efface l'ancienne position (met à 0)

5. **Met à jour src :** `src->top = next_down(src, src->top)`
   - Le sommet de `src` descend d'une position

**Exemple visuel :**
```
AVANT:
src (A):  top → [5]     dest (B):  top → [9]
                [3]                       [2]
                [7]

APRÈS push(src, dest):
src (A):  top → [3]     dest (B):  top → [5]  ← nouveau
                [7]                       [9]
                                          [2]
										  */