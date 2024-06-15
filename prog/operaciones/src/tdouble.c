/*
 * tdouble.c
 * Definición del tipo TDouble.
 */

#include "tdouble.h"

struct _TDouble {
  GObject parent;
  double value;
};

G_DEFINE_FINAL_TYPE (TDouble, t_double, G_TYPE_OBJECT);

static void
t_double_class_init (TDoubleClass *class) {};

static void
t_double_init (TDouble *self) {};

gboolean
t_double_get_value (TDouble *self, double *value)
{
  g_return_val_if_fail (T_IS_DOUBLE (self), FALSE);
  *value = self->value;
  return TRUE;
}

void
t_double_set_value (TDouble *self, double value)
{
  g_return_if_fail (T_IS_DOUBLE (self));
  self->value = value;
}

TDouble *
t_double_new (double value)
{
  TDouble *obj;
  obj = g_object_new (T_TYPE_DOUBLE, NULL);
  obj->value = value;
  return obj;
}

TDouble *
t_double_add (TDouble *self, TDouble *other)
{
  double value;
  
  g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
  g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
  if (! t_double_get_value (other, &value)) {
    return NULL;
  }

  return t_double_new (self->value + value);
}

TDouble *
t_double_sub (TDouble *self, TDouble *other)
{
  double value;
  
  g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
  g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
  if (! t_double_get_value (other, &value)) {
    return NULL;
  }
  return t_double_new (self->value - value);
}

TDouble *
t_double_mul (TDouble *self, TDouble *other)
{
  double value;
  
  g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
  g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
  if (! t_double_get_value (other, &value)) {
    return NULL;
  }
  return t_double_new (self->value * value);
}

TDouble *
t_double_div (TDouble *self, TDouble *other)
{
  double value;
  g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
  g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
  if ((! t_double_get_value (other, &value)) || value == 0.0) {
    return NULL;
  }
  return t_double_new (self->value / value);
}

TDouble *
t_double_uminus (TDouble *self)
{
  g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
  return t_double_new (-self->value);
}

