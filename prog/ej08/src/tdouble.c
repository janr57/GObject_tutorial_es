/*
 * tdouble.c
 * Definición del tipo TDouble.
 */

#include "tdouble.h"

static guint t_double_signal;

/* Estructura que se declaró en tdouble.h como tipo C TDouble */
struct _TDouble {
  GObject parent;
  double value;
};

/* Definición del tipo TDouble */
/* Se lleva a cabo el registro del tipo del sistema TDouble,
   se define la función t_double_get_type, etc.
   y se crean algunas macros auxiliares, como T_IS_DOUBLE */
G_DEFINE_FINAL_TYPE (TDouble, t_double, G_TYPE_OBJECT);

/* Inicialización de la clase */
static void
t_double_class_init (TDoubleClass *class)
{
  t_double_signal = g_signal_new ("div-by-zero",
			  G_TYPE_FROM_CLASS (class),
			  G_SIGNAL_RUN_LAST | G_SIGNAL_NO_RECURSE | G_SIGNAL_NO_HOOKS,
			  0 /* Class offset. Una subclase no podría modificar el manejador de señal (manejador por defecto) */,
			  NULL /* acumulador */,
			  NULL /* datos del acumulador */,
			  NULL /* C marshaller. Se usará g_closure_marshal_generic() */,
			  G_TYPE_NONE /* Tipo de retorno del manejador */,
			  0 /* número de parámetros */
			  );
}

/* Inicialización del objeto */
static void
t_double_init (TDouble *self) {}

/* Constructor de objetos */
TDouble *
t_double_new (double value)
{
  TDouble *obj;
  
  obj = g_object_new (T_TYPE_DOUBLE, NULL);
  obj->value = value;
  
  return obj;
}

/* Getter */
gboolean
t_double_get_value (TDouble *self, double *value)
{
  g_return_val_if_fail (T_IS_DOUBLE (self), FALSE);
  *value = self->value;
  
  return TRUE;
}

/* Setter */
void
t_double_set_value (TDouble *self, double value)
{
  g_return_if_fail (T_IS_DOUBLE (self));
  self->value = value;
}

TDouble *
t_double_add (TDouble *self, TDouble *other)
{
    g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
    g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
    // El valor del parámetro 'other' se debe obtener mediante el método 'getter'
    double value;
    if (! t_double_get_value (other, &value)) {
      return NULL;
    }
    
    return t_double_new (self->value + value);
}

TDouble *
t_double_sub (TDouble *self, TDouble *other)
{
    g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
    g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
    // El valor del parámetro 'other' se debe obtener mediante el método 'getter'
    double value;
    if (! t_double_get_value (other, &value)) {
      return NULL;
    }

    return t_double_new (self->value - value);
}

TDouble *
t_double_mul (TDouble *self, TDouble *other)
{
    g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
    g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
    // El valor del parámetro 'other' se debe obtener mediante el método 'getter'
    double value;
    if (! t_double_get_value (other, &value)) {
      return NULL;
    }

    return t_double_new (self->value * value);
}

TDouble *
t_double_div (TDouble *self, TDouble *other)
{
    g_return_val_if_fail (T_IS_DOUBLE (self), NULL);
    g_return_val_if_fail (T_IS_DOUBLE (other), NULL);
    // El valor del parámetro 'other' se debe obtener mediante el método 'getter'
    double value;
    if (! t_double_get_value (other, &value)) {
      return NULL;
    } else if (value == 0) {
      g_signal_emit (self, t_double_signal, 0);
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
