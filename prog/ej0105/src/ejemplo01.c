/*
* ejemplo01.c
* Ejemplo de creación y destrucción de instancias de 'GObjectClass'.
 * https://github.com/ToshioCP/Gobject-tutorial/blob/main/gfm/sec2.md
 * https://github.com/ToshioCP/Gobject-tutorial/tree/main
 */

#include <locale.h>
#include <glib-object.h>

int
main (int argc, char **argv)
{
  GObject *instancia1, *instancia2;
  GObjectClass *clase1, *clase2;

  /* Para que g_print no transforme la codificación de caracteres
     por su cuenta y no se vean los acentos */
  setlocale(LC_CTYPE, "");

  /* Creación de dos instancias de la clase 'GObject' */
  instancia1 = g_object_new (G_TYPE_OBJECT,  NULL);
  instancia2 = g_object_new (G_TYPE_OBJECT, NULL);
  g_print ("Dirección de 'instancia1': %p\n", instancia1);
  g_print ("Dirección de 'instancia2': %p\n", instancia2);

  /* Comprobación de que las dos instancias pertenecen a la misma clase */
  clase1 = G_OBJECT_GET_CLASS (instancia1);
  clase2 = G_OBJECT_GET_CLASS (instancia2);
  g_print("Dirección de la clase de 'instancia1': %p\n", clase1);
  g_print("Dirección de la clase de 'instancia2': %p\n", clase2);
  
  /* Destrucción de las instancias */
  g_object_unref(instancia1);
  g_object_unref(instancia2);

  return 0;
}
