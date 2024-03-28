/*
 * tdoble.c
 * Definición del objeto TDoble.
 */

#include "tdoble.h"

struct _TDoble {
  GObject parent;
  double valor;
};

G_DEFINE_TYPE (TDoble, t_doble, G_TYPE_OBJECT)

static void
t_doble_class_init (TDobleClass *class)
{
}

static void
t_doble_init (TDoble *self)
{
}

gboolean
t_doble_get_value (TDoble *self, double *valor)
{
  g_return_val_if_fail (T_IS_DOBLE (self), FALSE);

  *valor = self->valor;
  
  return TRUE;
}

void
t_doble_set_value (TDoble *self, double valor)
{
  g_return_if_fail (T_IS_DOBLE (self));

  self->valor = valor;
}

TDoble *
t_doble_new (double valor)
{
  TDoble *d;

  d = g_object_new (T_TYPE_DOBLE, NULL);
  d->valor = valor;
  
  return d;
}
