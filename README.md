# Seguridad-2022-2023
Repositorio creado para la asignatura de Seguridad en Sistemas Robóticos del grado de Ingeniería de Robótica Software


## Practica 1
### Enunciado
En esta práctica usaremos el algoritmo de cifrado Caesar para cifrar un mensaje de texto plano. El objetivo será descifrarlo por fuerza bruta e imprimir el mensaje descifrado por pantalla junto con la clave que se usó para cifrar el texto original.

Un ejemplo de esta práctica sería:

Si la clave es 23,

A -> X

B -> Y

C -> Z

...

Texto plano:  THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG

Texto Cifrado: QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD

$> echo 'QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD' | ./breakcaesar

23: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG

### Modo de ejecución
Desde el directorio del repositorio:

cd Practica_1

make

echo "MSG_TO_CYPHER" | ./caesar CLAVE

./breakcaesar < texto_cifrado.txt

