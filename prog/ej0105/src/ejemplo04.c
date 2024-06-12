/*
 * ejemplo04.c
 * Prueba la macro G_DEFINE_TYPE
 */

#include <locale.h>
#include <glib-object.h>

#define T_TYPE_DOUBLE  (t_double_get_type ())

typedef struct _TDouble TDouble;
struct _TDouble {
  GObject parent;
  double value;
};

typedef struct _TDoubleClass TDoubleClass;
struct _TDoubleClass {
  GObjectClass parent_class;
};

G_DEFINE_TYPE (TDouble, t_double, G_TYPE_OBJECT) /* o G_DEFINE_FINAL_TYPE (...) */

static void
t_double_class_init (TDoubleClass *class)
{
}

static void
t_double_init (TDouble *self)
{
}

int
main (int argc, char **argv)
{
  GType dtype;
  TDouble *d;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");
  
  dtype = T_TYPE_DOUBLE; /* o dtype = t_double_get_type (); */
  if (dtype) {
    g_print ("Registro correcto. El tipo de objeto 'TDouble' es %lx.\n", dtype);
  } else {
    g_print ("Registro de 'TDouble' incorrecto.\n");
  }

  d = g_object_new (T_TYPE_DOUBLE, NULL);
  if (d) {
    g_print ("Instancia de 'TDouble' creada correctamente, su dirección es %p.\n", d);
  } else {
    g_print ("Error en la creación de la instancia 'TDouble'.\n");
  }

  g_object_unref (d); /* Elimina el objeto 'd'. */

  return 0;
}

