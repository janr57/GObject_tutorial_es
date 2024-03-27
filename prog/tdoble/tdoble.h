/*
 * tdoble.h
 * Declaración del objeto TDoble.
 */

#pragma once
 
 #include <glib-object.h>
 
 #define T_TYPE_DOBLE  (t_doble_get_type ())
 G_DECLARE_FINAL_TYPE (TDoble, t_doble, T, DOBLE, GObject)
 
 gboolean
 t_doble_get_value (TDoble *self, double *valor);
 
 void
 t_doble_set_value (TDoble *self, double valor);
 
 TDoble *
 t_doble_new (double valor);
