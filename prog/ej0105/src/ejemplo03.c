/*
 * ejemplo03.c
 * Prueba la función 'g_type_register_static'.
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
 
 static void
 t_double_class_init (TDoubleClass *class)
 {
 }
 
 static void
 t_double_init (TDouble *self)
 {
 }
 
 GType
 t_double_get_type (void)
 {
   static GType type = 0;
   GTypeInfo info;
 
   if (type == 0) {
     info.class_size = sizeof (TDoubleClass);
     info.base_init = NULL;
     info.base_finalize = NULL;
     info.class_init = (GClassInitFunc)  t_double_class_init;
     info.class_finalize = NULL;
     info.class_data = NULL;
     info.instance_size = sizeof (TDouble);
     info.n_preallocs = 0;
     info.instance_init = (GInstanceInitFunc)  t_double_init;
     info.value_table = NULL;
     type = g_type_register_static (G_TYPE_OBJECT, "TDouble", &info, 0);
   }
   
   return type;
 }
 
 int
 main (int argc, char **argv)
 {
   GType dtype;
   TDouble *d;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");
   
  dtype = t_double_get_type (); /* equivale a  'dtype = T_TYPE_DOUBLE' */
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

  g_object_unref (d); /* Elimina el objeto 'd'. */
  
  return 0;
 }
 

