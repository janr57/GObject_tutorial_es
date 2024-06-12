/*
 * main.c
 * Se prueba el objeto TDouble.
 */

#include <locale.h>
#include <glib-object.h>
#include "tdouble.h"

int
main (int argc, char **argv) {
  TDouble *d;
  double value;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");

  d = t_double_new (10.0);
  if (t_double_get_value (d, &value)) {
    g_print ("t_double_get_value succesfully assigned %lf to value.\n", value);
  } else {
    g_print ("t_double_get_value failed.\n");
  }

  t_double_set_value (d, -20.0);
  g_print ("Now, set d (TDouble object) with %lf.\n", -20.0);
  
  if (t_double_get_value (d, &value)) {
    g_print ("t_double_get_value succesfully assigned %lf to value.\n", value);
  } else {
    g_print ("t_double_get_value failed.\n");
  }
  
  g_object_unref (d);

  return 0;
}
