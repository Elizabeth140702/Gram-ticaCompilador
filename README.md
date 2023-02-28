Este programa  tiene como intención implementar la gramática que se encuentra en el archivo "compilador.lr" con ayuda de un analizador léxico y un algoritmo para trabajar con tablas lr.
Al momento de inicializarlo, le ingresé la siguiente sintaxis:

![image](https://user-images.githubusercontent.com/84193277/221746051-1734e38b-e91d-450c-9220-dd53144f3bc0.png)


Esto era lo que se iba a verificar si era o no correcto, por lo que al correr el programa obtenemos esto en consola:


![image](https://user-images.githubusercontent.com/84193277/221746184-055398eb-2fc7-4730-8d7f-fa9aeb49f468.png)


Como vemos aquí está en "Cadena de entrada"  la primer palabra que ingresamos, es decir, int. En la segunda tenemos "test" y en la tercera ";" que sería todo lo que ingresamos al inicio.

![image](https://user-images.githubusercontent.com/84193277/221746540-cc7aaa5b-8901-4e26-a289-f8f2ba6f3085.png)

Continuando con la tabla lr podemos observar que el orden va correctamente basándonos en la gramática del compilador que nos mandó el profesor.
![image](https://user-images.githubusercontent.com/84193277/221746765-adac8094-cc8c-49e5-9fd3-c1426554f3fc.png)


Por último tenemos las reducciones del autómata que nos dan en cadena de entrada el signo de pesos indicando que finalizó, como la sintaxis fue correcta, el resultado es una aceptación.

![image](https://user-images.githubusercontent.com/84193277/221749191-50943d99-38b0-4ff3-b23b-6bd80b2539f0.png)

Ahora ponemos una sintaxis incorrecta, o sea "int test", esto nos dice que el autómata no es aceptado debido a que sabemos por sí sólo que está mal, pero para comprobar hice la tabla lr en un excel:


![image](https://user-images.githubusercontent.com/84193277/221752043-930da11f-22f4-441f-b661-5f31c7bfbe46.png)



En el primer caso los números de las filas y columnas sí concordaron con los resultados que debería de dar, en el segundo también pero este resultado nos dio un autómata no aceptado.
