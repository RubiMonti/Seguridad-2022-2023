# Instrucciones para ejecutar el ejercicio:
Primero accedemos a la carpeta caesar.

Despues compilamos los ejecutables
~~~
cd caesar
make
~~~
Tenemos la opción de cifrar nuestro propio texto y se nos guardará en un fichero llamado texto_cifrado.txt
~~~
./caesar "CLAVE" < "fichero de texto"
~~~
Por último, podemos descifrar este texto o uno que ya estuviese cifrado con el siguiente comando:
~~~
./breakcaesar < texto_cifrado.txt
~~~
