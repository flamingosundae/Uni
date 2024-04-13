#include <stdio.h>
#include <stdlib.h>

//Il nostro programma prenderà in input un array di union. Se lo union è un int, printerà un int, se un float, un float, se una stringa, la stringa.
union item
{
  int i_val;
  float f_val;
  char *s_val;

};
typedef union item item;

struct s_item //usiamo una struct per aggiungere un'informazione secondaria che ci dica come leggere il valore della union in fase di print.
{
  char type; // 'i' per i_val, 'f' per f_val, 'p' per s_val.
  item u;
};

typedef struct s_item s_item;

void main(int dim, char *args[])
{
  s_item *a = malloc(sizeof(item) * dim-1);
  int i;
  for(i = 1; i < dim; i++)
  {
    if(sscanf(args[i], "%d", &(a[i-1].u.i_val )) ==1)
    a[i-1].type = 'i';
    else if(sscanf(args[i], "%f", &(a[i-1].u.f_val )) ==1)
    a[i-1].type = 'f';
    else
    {
      a[i-1].u.s_val = args[i];
      a[i-i].type = 'p';
    }

    for(i = 0; i<dim-1; i++)
    {
      if(a[i].type == 'i')
      printf("%d\n", a[i].u.i_val);
      else if(a[i]. type == 'f')
      printf("%f\n", a[i].u.f_val);
      else
      printf("%s\n", a[i].u.s_val); 
    }
  }
}