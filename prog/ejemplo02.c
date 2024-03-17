/*
 * ejemplo2.c
 */

#include <locale.h>
#include <glib-object.h>

static void
show_ref_count  (GObject *instance) {
  if  (G_IS_OBJECT (instance)) {
    /* Los usuarios no deberían utilizar el método 'ref_count' en sus programas.
       pues interferirían de una forma impredecible con GObject */
    /* Aquí se utiliza solo como demostración */
    g_print ("  La cuenta de referencia de la instancia es %d.\n", instance->ref_count);
  }
  else {
    g_print ("  La instancia recibida no es un objeto de 'GObjectClass'.\n");
  }
}

int
main (int argc, char **argv)
{
  GObject *instance;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");

  g_print ("- Se crea el objeto 'instancia' llamando a 'g_object_new'.\n");
  instance = g_object_new(G_TYPE_OBJECT, NULL);
  show_ref_count (instance);
  g_print("\n");
  
  g_print ("- Se referencia 'instancia' llamando a 'g_object_ref'.\n");
  g_object_ref (instance);
  show_ref_count (instance);
  g_print("\n");

  g_print ("- Se desreferencia 'instancia' llamando a 'g_object_unref'.\n");
  g_object_unref(instance);
  show_ref_count (instance);
  g_print("\n");

  g_print ("- Se desreferencia 'instancia' llamando a 'g_object_unref'.\n");
  g_object_unref (instance);
  g_print ("  Ahora la cuenta de referencia vale cero y la instancia se destruye.\n");
  g_print ("  Su memoria asociada se libera y pasaría a estar disponible para el sistema.\n");
  g_print("  Una llamada a 'show_ref_count(instance)' daría un error, pues la instancia\n");
  g_print("  ya no existe.\n");
  /* show_ref_count (instance); */
  
  return 0;
}

