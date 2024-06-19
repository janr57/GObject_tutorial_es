/*
 * tdouble.h
 * Declaración del tipo TDouble.
 */

#pragma once

#include <glib-object.h>

/* Declaración del tipo TDouble */
#define T_TYPE_DOUBLE (t_double_get_type ())
G_DECLARE_FINAL_TYPE(TDouble, t_double, T, DOUBLE, GObject)

/* Constructor de instancias de TDouble */
TDouble * t_double_new (double value);

/* Getter */
gboolean t_double_get_value (TDouble *self, double *value);

/* Setter */
void t_double_set_value (TDouble *self, double value);
  
/* Funciones aritméticas */
TDouble * t_double_add (TDouble *self, TDouble *other);
TDouble * t_double_sub (TDouble *self, TDouble *other);
TDouble * t_double_mul (TDouble *self, TDouble *other);
TDouble * t_double_div (TDouble *self, TDouble *other);
TDouble * t_double_uminus (TDouble *self);
