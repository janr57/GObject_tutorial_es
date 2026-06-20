/*
 * ejemplo05.c
 * Prueba las macros G_DECLARE_FINAL_TYPE y G_DEFINE_FINAL_TYPE
 */

#include <locale.h>
#include <glib-object.h>
 
#define T_TYPE_DOUBLE  (t_double_get_type ())
G_DECLARE_FINAL_TYPE (TDouble, t_double, T, DOUBLE, GObject)
 
struct _TDouble {
  GObject parent;
  double value;
};
 
G_DEFINE_TYPE (TDouble, t_double, G_TYPE_OBJECT)
 
static void
t_double_class_init (TDoubleClass *class)
{
}
 
 static void
 t_double_init (TDouble *self)
 {
 }
 
int
main (int argc, char **argv) {
  GType dtype;
  TDouble *d;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");
  
  dtype = t_double_get_type (); /* or dtype = T_TYPE_DOUBLE */
  if (dtype) {
    g_print ("Registro correcto. El tipo de objeto es %lx.\n", dtype);
  } else {
    g_print ("Registro incorrecto.\n");
  }
 
  d = g_object_new (T_TYPE_DOUBLE, NULL);
  if (d) {
    g_print ("La instancia se ha creado correctamente. Su dirección es %p.\n", d);
  } else {
    g_print ("Error en la creación de la instancia.\n");
  }
 
  if (T_IS_DOUBLE (d)) {
    g_print ("La variable 'd' es una instancia de TDouble.\n");
  } else {
    g_print ("La variable 'd' no es una instancia de TDouble.\n");
  }
 
  if (G_IS_OBJECT (d)) {
    g_print ("La variable 'd' es una instancia de GObject.\n");
  } else {
    g_print ("La variable 'd' no es una instancia de GObject.\n");
  }
  
  g_object_unref (d);
 
  return 0;
 }
