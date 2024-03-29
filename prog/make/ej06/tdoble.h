/*
 * tdoble.h
 * Declaración del objeto TDoble.
 */

#ifndef T_DOBLE_H
#define T_DOBLE_H
 
 #include <glib-object.h>
 
 #define T_TYPE_DOBLE  (t_doble_get_type ())
 G_DECLARE_FINAL_TYPE (TDoble, t_doble, T, DOBLE, GObject)
 
 gboolean
 t_doble_get_value (TDoble *self, double *valor);
 
 void
 t_doble_set_value (TDoble *self, double valor);
 
 TDoble *
 t_doble_new (double valor);

#endif /* T_DOBLE_H */
