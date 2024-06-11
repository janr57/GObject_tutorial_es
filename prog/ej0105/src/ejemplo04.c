/*
 * ejemplo04.c
 * Prueba la macro G_DEFINE_TYPE
 */

#include <locale.h>
#include <glib-object.h>

#define T_TYPE_DOBLE  (t_doble_get_type ())

typedef struct _TDoble TDoble;
struct _TDoble {
  GObject parent;
  double value;
};

typedef struct _TDobleClass TDobleClass;
struct _TDobleClass {
  GObjectClass parent_class;
};

G_DEFINE_TYPE (TDoble, t_doble, G_TYPE_OBJECT) /* o G_DEFINE_FINAL_TYPE (...) */

static void
t_doble_class_init (TDobleClass *class)
{
}

static void
t_doble_init (TDoble *self)
{
}

int
main (int argc, char **argv)
{
  GType dtype;
  TDoble *d;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");
  
  dtype = T_TYPE_DOBLE; /* o dtype = t_doble_get_type (); */
  if (dtype) {
    g_print ("Registro correcto. El tipo de objeto 'TDoble' es %lx.\n", dtype);
  } else {
    g_print ("Registro de 'TDoble' incorrecto.\n");
  }

  d = g_object_new (T_TYPE_DOBLE, NULL);
  if (d) {
    g_print ("Instancia de 'TDoble' creada correctamente, su dirección es %p.\n", d);
  } else {
    g_print ("Error en la creación de la instancia 'TDoble'.\n");
  }

  g_object_unref (d); /* Elimina el objeto 'd'. */

  return 0;
}

