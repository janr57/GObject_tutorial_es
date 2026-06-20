/*
 * ejemplo02.c
 * Prueba de las referencias a una instancia.
 */

#include <locale.h>
#include <glib-object.h>

static void
show_ref_count  (GObject *inst)
{
  if  (G_IS_OBJECT (inst)) {
    /* Los usuarios no deberían utilizar el método 'ref_count' en sus programas.
       pues interferirían de una forma impredecible con GObject */
    /* Aquí se utiliza solo como demostración */
    g_print ("  Cuenta de referencia de la instancia: %d.\n", inst->ref_count);
  }
  else {
    g_print ("  La instancia recibida no es un objeto de 'GObjectClass'.\n");
  }
}

int
main (int argc, char **argv)
{
  GObject *instancia;

  // Para que g_print no transforme la codificación de caracteres
  // por su cuenta y no se vean los acentos.
  setlocale(LC_CTYPE, "");

  g_print ("- Se crea el objeto 'instancia', llamando a 'g_object_new'.\n");
  instancia = g_object_new(G_TYPE_OBJECT, NULL);
  show_ref_count (instancia);
  g_print("\n");
  
  g_print ("- Se añade una referencia a 'instancia', llamando a 'g_object_ref'.\n");
  g_object_ref (instancia);
  show_ref_count (instancia);
  g_print("\n");

  g_print ("- Se elimina una referencia, llamando a 'g_object_unref'.\n");
  g_object_unref(instancia);
  show_ref_count (instancia);
   g_print("\n");

  g_print ("- Se elimina la última referencia, llamando a 'g_object_unref'.\n");
  g_object_unref (instancia);
  g_print ("  La cuenta de referencia vale cero y la instancia se destruye.\n");
  g_print ("  Su memoria asociada se libera.\n");
  g_print("  Una llamada a 'show_ref_count(instance)' daría un error, pues la\n");
  g_print("  instancia  ya no existe.\n");
  g_print("  Por ello, se ha comentado esta línea en el código fuente.\n");
  /* show_ref_count (instancia); */
  
  return 0;
}

