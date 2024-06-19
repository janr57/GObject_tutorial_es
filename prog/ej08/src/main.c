/*
 * main.c
 * Comprobación del uso de señales.
 */

#include <stdlib.h>
#include <locale.h>

#include "tdouble.h"

static void
div_by_zero_cb (TDouble *self, gpointer user_data)
{
  g_printerr ("\nError: División entre cero.\n\n");
}

static void
t_print (char *op, TDouble *obj1, TDouble *obj2, TDouble *obj3)
{
  double v1, v2, v3;

  if (! t_double_get_value (obj1, &v1)) {
    return;
  }
  if (! t_double_get_value (obj2, &v2)) {
    return;
  }
  if (! t_double_get_value (obj3, &v3)) {
    return;
  }

  g_print ("%lf %s %lf = %lf\n", v1, op, v2, v3);
}

int
main (int argc, char **argv)
{
  TDouble *obj1, *obj2, *obj3;
  //double v1, v3;

  setlocale (LC_CTYPE, "");

  obj1 = t_double_new (10.0);
  obj2 = t_double_new (20.0);

  if ((obj3 = t_double_add (obj1, obj2)) != NULL) {
    t_print ("+", obj1, obj2, obj3);
    g_object_unref (obj3);
  }

  if ((obj3 = t_double_sub (obj1, obj2)) != NULL) {
    t_print ("-", obj1, obj2, obj3);
    g_object_unref (obj3);
  }

  if ((obj3 = t_double_mul (obj1, obj2)) != NULL) {
    t_print ("*", obj1, obj2, obj3);
    g_object_unref (obj3);
  }
 
  if ((obj3 = t_double_div (obj1, obj2)) != NULL) {
    t_print ("/", obj1, obj2, obj3);
    g_object_unref (obj3);
  }

   g_signal_connect (obj1, "div-by-zero", G_CALLBACK (div_by_zero_cb), NULL);
  t_double_set_value (obj2, 0.0);
  if ((obj3 = t_double_div (obj1, obj2)) != NULL) {
    t_print ("/", obj1, obj2, obj3);
    g_object_unref (obj3);
  }

  g_print ("Ok!\n");

  return EXIT_SUCCESS;
}
