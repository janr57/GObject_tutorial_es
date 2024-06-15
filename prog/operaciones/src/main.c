/*
 * main.c
 * Prueba de operaciones aritméticas con el valor de instancias TDouble.
 */

#include <stdlib.h>
#include <locale.h>

#include "tdouble.h"

void print_val (TDouble *obj, char *str)
{
  double value;
  
  if (t_double_get_value(obj, &value)) {
    g_print ("'%s': %3.6f\n", str, value);
  } else {
    g_print ("Error, la instancia '%s' no tiene valor.\n", str);
    exit (1);
  }
}

int
main (void)
{
  TDouble *obj1, *obj2, *obj3;
  double value;
  const double val1 = 24.0;
  const double val2 = 14.0;
  double val3;

  setlocale (LC_CTYPE, "");

  g_print(" ------------------------\n");
  
    /* Se crea la instancia de TDouble, 'obj1' */
  obj1 = t_double_new (val1);
  if (!t_double_get_value(obj1, &value)) {
    g_print ("Error, no se ha podido crear la instancia 'obj1'.\n");
    exit (1);
  }
  print_val (obj1, "obj1");
  
  /* Se crea la instancia de TDouble, 'obj2' */
  obj2 = t_double_new (val2);
  if (!t_double_get_value(obj2, &value)) {
    g_print ("Error, no se ha podido crear la instancia 'obj2'.\n");
    exit (1);
  }
  print_val (obj2, "obj2");

  g_print(" ------------------------\n");
    
  /* Suma */
  obj3 = t_double_add (obj1, obj2);
  print_val (obj3, "obj1 + obj2");

    /* Resta */
    obj3 = t_double_sub (obj1, obj2);
  print_val (obj3, "obj1 - obj2");

  /* Multiplicación */
    obj3 = t_double_mul (obj1, obj2);
    print_val (obj3, "obj1 * obj2");

  /* División */
  obj3 = t_double_div (obj1, obj2);
  print_val (obj3, "obj1 / obj2");

  /* Cambio de signo */
    obj3 = t_double_uminus (obj1);
    print_val (obj3, "-obj1");    

  g_object_unref (obj1);
  g_object_unref(obj2);
  g_object_unref(obj3);

  g_print(" ------------------------\n");
    
  g_print ("OK!\n");

  return EXIT_SUCCESS;
}
