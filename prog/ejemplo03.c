/*
 * ejemplo03.c
 * Prueba la función 'g_type_register_static'.
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
 
 static void
 t_doble_class_init (TDobleClass *class) {
 }
 
 static void
 t_doble_init (TDoble *self) {
 }
 
 GType
 t_doble_get_type (void) {
   static GType type = 0;
   GTypeInfo info;
 
   if (type == 0) {
     info.class_size = sizeof (TDobleClass);
     info.base_init = NULL;
     info.base_finalize = NULL;
     info.class_init = (GClassInitFunc)  t_doble_class_init;
     info.class_finalize = NULL;
     info.class_data = NULL;
     info.instance_size = sizeof (TDoble);
     info.n_preallocs = 0;
     info.instance_init = (GInstanceInitFunc)  t_doble_init;
     info.value_table = NULL;
     type = g_type_register_static (G_TYPE_OBJECT, "TDoble", &info, 0);
   }
   return type;
 }
 
 int
 main (int argc, char **argv) {
   GType dtype;
   TDoble *d;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");
   
  dtype = t_doble_get_type (); /* equivale a  'dtype = T_TYPE_DOBLE' */
  if (dtype) {
    g_print ("Registro correcto. El tipo es %lx.\n", dtype);
  } else {
    g_print ("Registro incorrecto.\n");
  }
 
  d = g_object_new (T_TYPE_DOBLE, NULL);
  if (d) {
    g_print ("La instancia se ha creado correctamente. Su dirección es %p.\n", d);
  } else {
    g_print ("Error en la creación de la instancia.\n");
  }

  g_object_unref (d); /* Elimina el objeto 'd'. */
  
  return 0;
 }
 

