/*
 * main.c
 * Se prueba el objeto TDoble.
 */

#include <locale.h>
#include <glib-object.h>
#include "tdoble.h"

int
main (int argc, char **argv) {
  TDoble *d;
  double valor;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");

  d = t_doble_new (10.0);
  if (t_doble_get_value (d, &valor)) {
    g_print ("t_double_get_value succesfully assigned %lf to value.\n", valor);
  } else {
    g_print ("t_double_get_value failed.\n");
  }

  t_doble_set_value (d, -20.0);
  g_print ("Now, set d (tDouble object) with %lf.\n", -20.0);
  
  if (t_doble_get_value (d, &valor)) {
    g_print ("t_double_get_value succesfully assigned %lf to value.\n", valor);
  } else {
    g_print ("t_double_get_value failed.\n");
  }
  
  g_object_unref (d);

  return 0;
}
