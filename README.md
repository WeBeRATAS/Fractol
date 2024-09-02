# Fractol
Fractol 42


# Documentación del Proyecto de Fractales

## Descripción General

Este proyecto genera fractales de Mandelbrot y Julia utilizando la biblioteca `mlx` para la visualización gráfica. El punto de entrada del programa es el archivo `main.c`.

## Estructura del Proyecto

- `main.c`: Contiene la función principal del programa.
- `fractol.h`: Archivo de cabecera que contiene las definiciones y declaraciones necesarias.
- `events.c`: Maneja los eventos del teclado y el ratón.
- `init.c`: Inicializa la estructura del fractal y los recursos de `mlx`.
- `render.c`: Contiene la lógica para renderizar los fractales.

## Archivos Fract-ol

### main.c
*******************************

#### Función `main`

**Descripción**: Punto de entrada del programa. Verifica los argumentos de la línea de comandos, inicializa la estructura del fractal, renderiza el fractal y maneja el bucle de eventos.

**Parámetros**:
- `int ac`: Número de argumentos de la línea de comandos.
- `char **av`: Array de cadenas de caracteres que contiene los argumentos de la línea de comandos.

**Retorno**: `int`: Código de salida del programa.

**Lógica**:
1. Verifica si el número de argumentos y el nombre del fractal son correctos.
2. Si el fractal es de tipo Julia, convierte los argumentos adicionales a números de punto flotante y los asigna a las variables correspondientes.
3. Inicializa la estructura `fractal` llamando a `fractal_init`.
4. Renderiza el fractal llamando a `fractal_render`.
5. Inicia el bucle de eventos de la biblioteca `mlx` llamando a `mlx_loop`.

## Estructura `t_fractal`
*****************************

**Descripción**: Contiene los datos necesarios para generar y manejar los fractales.

**Campos**:
- `char *name`: Nombre del fractal (e.g., "mandelbrot" o "julia").
- `double julia_x`: Coordenada X para el fractal de Julia.
- `double julia_y`: Coordenada Y para el fractal de Julia.
- `void *mlx_connection`: Conexión a la biblioteca `mlx`.
- `void *mlx_window`: Ventana de la biblioteca `mlx`.
- `t_img img`: Estructura que contiene los datos de la imagen.
- `double escape_value`: Valor de escape para el fractal.
- `int iterations_definition`: Número de iteraciones para el fractal.
- `double shift_x`: Desplazamiento en el eje X.
- `double shift_y`: Desplazamiento en el eje Y.
- `int current_color`: Color actual del fractal.
- `double zoom`: Nivel de zoom del fractal.

## Archivos del proyecto
**********************************************************

### events.c

**Descripción**: Maneja los eventos del teclado y el ratón.

**Funciones**:
- `key_handler`: Maneja los eventos del teclado.
- `mouse_handler`: Maneja los eventos del ratón.
- `julia_track`: Actualiza las coordenadas del fractal de Julia en función del movimiento del ratón.

### init.c
***********************

**Descripción**: Inicializa la estructura del fractal y los recursos de `mlx`.

**Funciones**:
- `fractal_init`: Inicializa la estructura del fractal.
- `fractal_cleanup`: Libera los recursos utilizados por el fractal.

### render.c
********************************

**Descripción**: Contiene la lógica para renderizar los fractales.

**Funciones**:
- `fractal_render`: Renderiza el fractal en la ventana de `mlx`.

## Archivos Adicionales

### string_utils.c
**************************

**Descripción**: Este archivo contiene funciones auxiliares para manipulación de cadenas y conversión de cadenas a números.

**Funciones**:

1. **putstr_fd**

**Descripción**: Escribe una cadena de caracteres en un descriptor de archivo especificado.

**Parámetros**:
- `char *s`: Cadena de caracteres a escribir.
- `int fd`: Descriptor de archivo donde se escribirá la cadena.

**Lógica**:
- Verifica si la cadena es `NULL` o si el descriptor de archivo es inválido.
- Si la cadena no está vacía, escribe el primer carácter y llama recursivamente a `putstr_fd` con el resto de la cadena.

2. **atoidbl**

**Descripción**: Convierte una cadena de caracteres a un número de punto flotante (`double`).

**Parámetros**:
- `char *s`: Cadena de caracteres que representa un número.

**Lógica**:
- Inicializa las variables para la parte entera, la parte fraccionaria, el signo y la potencia.
- Omite los espacios en blanco y los signos.
- Convierte la parte entera de la cadena.
- Convierte la parte fraccionaria de la cadena si existe.

### fractal_utils.c
*************************************

**Descripción**: Este archivo contiene funciones específicas para el manejo y cálculo de fractales.

**Funciones**:

1. **mandelbrot**

**Descripción**: Calcula el número de iteraciones para el fractal de Mandelbrot en un punto dado.

**Parámetros**:
- `double x`: Coordenada X del punto.
- `double y`: Coordenada Y del punto.
- `int max_iterations`: Número máximo de iteraciones.

**Lógica**:
- Inicializa las variables para las coordenadas y el contador de iteraciones.
- Realiza iteraciones para calcular si el punto pertenece al conjunto de Mandelbrot.
- Retorna el número de iteraciones.

  2. **julia**

**Descripción**: Calcula el número de iteraciones para el fractal de Julia en un punto dado.

**Parámetros**:
- `double x`: Coordenada X del punto.
- `double y`: Coordenada Y del punto.
- `double c_re`: Parte real del parámetro complejo.
- `double c_im`: Parte imaginaria del parámetro complejo.
- `int max_iterations`: Número máximo de iteraciones.

**Lógica**:
- Inicializa las variables para las coordenadas y el contador de iteraciones.
- Realiza iteraciones para calcular si el punto pertenece al conjunto de Julia.
- Retorna el número de iteraciones.

### math_utils.c
*************************************

**Descripción**: Este archivo contiene funciones matemáticas auxiliares utilizadas en el cálculo de fractales.

**Funciones**:

1. **map**

**Descripción**: Mapea un valor de un rango a otro rango.

**Parámetros**:
- `double value`: Valor a mapear.
- `double start1`: Inicio del rango original.
- `double stop1`: Fin del rango original.
- `double start2`: Inicio del rango de destino.
- `double stop2`: Fin del rango de destino.

**Lógica**:
- Calcula y retorna el valor mapeado al nuevo rango.

2. **clamp**

**Descripción**: Limita un valor a un rango específico.

**Parámetros**:
- `double value`: Valor a limitar.
- `double min`: Valor mínimo del rango.
- `double max`: Valor máximo del rango.

**Lógica**:
- Retorna el valor limitado al rango especificado.


## Ejecución del Programa

Para ejecutar el programa, utiliza el siguiente comando:

```sh
./fractol <nombre_del_fractal> [<parametros_adicionales>]
