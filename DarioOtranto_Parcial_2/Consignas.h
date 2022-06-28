#pragma once
//Parcial Domiciliario🐱‍👤
//El nivel de los alumnos del primer curso de Image Campus es “excelente” y por eso la empresa Epic Games nos solicita crear una nuevo prototipo para su nuevo juego
//  “Batalla de Pokemones, la venganza de Pikachu”.Pero Epic nos pide que cumplamos ciertos requisitos para que nuestra demo sea tomada en cuenta.
//
//
//
//
//
//Reglas:📏
//
//
//Creación🐣 :
//Debemos tener dos modos de juego : Player(contra la computadora) y Multiplayer(dos jugadores).Los dos deben de ser jugables.
//Antes de comenzar la partida se le solicitara al jugador correspondiente crear sus pokemones, se podrán crear seis por player.
//Antes de iniciar, el jugador podrá colocar manualmente sus pokemones en un tablero que nos va a servir de mundo para nuestro juego.
//El jugadores deberá tener la opción de no colocarlos manualmente y que el programa lo haga por el.
//Es importante que ni el player ni la maquina puedan colocar un jugador en una posición en donde ya exista uno.
//Este tablero, sus posiciones y pokemones serán visibles para los dos jugadores por igual.
//
//
//JUEGO🕹 :
//
//
//    Los turnos serán alternos.
//
//
//
//Ataque🗡:
//Cada jugador podrá elegir con cual de sus Pokemones atacar y a cual Pokémon enemigo desea hacerlo, esto será dando la posición en el mundo de su jugador y el contrario. (ejemplo ataque al[2][3]).
//Una vez elegida la posición, se podrá elegir entre 3 ataques diferentes(Cada uno de estos tendrá un numero de identificación hasta el 3, ejemplo: 1.Golpe de fuego, 2. Golpe de Agua. 3. Golpe de Tierra)
//Cada uno de estos ataques tendrá un valor que revisaremos en otro punto mas adelante.El valor del golpe que tiene ese ataque será descontado de la resistencia del enemigo.Una vez finalizado este mismo valor, se validara la cantidad de vidas del Pokémon si este no cuenta con ninguna, morirá.Si tiene todavía otra en su haber, se reiniciara el valor de resistencia para jugar una vez mas. (Ejemplo : La resistencia era de 1000 y llego a 0, si el Pokémon tenia 2 vidas, pasa a 1 y se reinicia su resistencia a 1000).
//
//
//
//Defensa🛡:
//El Pokémon que no tiene el turno para atacar, podrá defenderse una vez que el atacante juegue su golpe.
//El medio de defensa será un dado de 3 valores, el jugador tira el dado y si este numero es igual al numero del identificador del ataque(o sea de 1 a 3), ese golpe no le afecta, en caso contrario será descontado de su resistencia. (Ejemplo : Mi golpe tenia el ataque nro. 3, si el dado del contrario saco un 3, no descuento)
//
//
//Condición de ganador / perdedor🎉 :
//    Cuando un Pokémon se queda sin vida, este deberá ser eliminado de su posición en el mundo.
//    Perderá el primero que se quede sin Pokemones en el mundo.
//
//
//    Menú📃 :
//    1 - Necesitamos tener un menú ordenado, con una UI prolija y entendible por el usuario.
//
//    2 - Nuestro juego siempre debe de tener la opción de abandonarlo y terminarlo, aunque estemos en medio de la partida.
//
//    3 - Puntos a tener en cuenta :
//
//Titulo del juego.
//Jugar :
//    -Player.
//
//    - Multiplayer.
//
//    Reglas.
//    Autor.
//    Salir.
//
//
//    Mundo / Tablero. (Bidimensional)🗺:
//Nuestro mundo será un tablero matriz de 2 * 6. No servirá como un tablero para mover personajes, sino solo para posicionarlos y tener referencia de a que Pokémon quiero atacar.
//Debemos recordar, que siempre debemos mostrarlo.
//También una vez que un Pokémon se queda sin vida, debe ser eliminado del mundo.
//
//
//Pokemones(Struct)🐦:
//Nuestros Pokemones serán structs de 3 tipos.Nivel 1, 2 y 3 (Deben colocarle nombres simbólicos)
//Podremos tener solo tres Pokemones del nivel 1, dos del nivel 2 y uno del nivel 3.
//Miembros de los structs : Nombre, Vidas, Tipo o nivel, Resistencia, Ataque 1, Ataque 2, Ataque 3 (El ataque debe de tener un nombre simbólico).
//2. Tendremos un limite para repartir cada creación de Pokémon.Debemos repartirlos entre cada uno.
//
//Resistencia : 5000.
//Ataque 1 : 400.
//Ataque 2 : 600.
//Ataque 3 : 900.
//Vidas : 14 (El Pokémon nivel 3 tiene que tener un mínimo de 3 vidas obligatoriamente.)
//Estos valores son ejemplos prácticos, si se modifican deben de ser especificados en las reglas de juego del menú, para que el jugador los conozca.En este caso, tendría que repartir 5000 en mis Pokemonos.Ejemplo : 1000 al Nivel 3. Me restan 4000 para repartir entre los demás.
//
//
//
//Atentos a esto⚠ :
//
//Ningún Pokémon puede tener mas que su nivel siguiente.Ejemplo : Cuando los creemos y estemos repartiendo los valores, nivel 1 no puede tener mas resistencia que uno del nivel 2. Así que debemos validar que cuando los creemos no pasemos los niveles existentes en otros.Créelos de menor a mayor.
//3.Los Pokemones deberán ser creados a través de funciones.
//
//4.El Player debe ser un struct también.
//
//
//
//Funciones⚙:
//main() solo será una función de inicio, no debe de haber lógica suelta escrita adentro.
//Todo debe tener su función, será parte importante de la evaluación el criterio por el cual se creo la misma.Así como su nombre y tipo de dato.
//
//
//Plus : Quien entregue un UML del programa, tendrá la gloria🌞.
//
//
//
//
//
//Importante⛔:
//Sera penado en la evaluación los nombres elegidos para las variables y funciones que no representen fielmente para que sirven.
//Cada input de entrada de dato por consola, debe ser validado, ejemplo : si le pido al usuario ingresar un numero no puede ingresar una letra, en este caso hay que volverle a pedir el dato.Hagan uso de funciones para la misma.
//Sera penado el uso excesivo y sin lógica del system(”pause”).
//Los comentarios están permitidos, pero por ningún motivo se aceptara código comentado en la entrega del parcial.Esto será reprobación directa.
//Cualquier bug en la ejecución será penado.
//El programa debe de ejecutar y funcionar sin necesidad de que el profesor deba modificar nada en el.
//Primero se corregirá la ejecución, luego el código.
//Ortografía de menú y opciones correctas.
//Cualquier funcionalidad, acción o plus extra que quieran utilizar en la realización del parcial, será tomado en cuenta en la nota conceptual y para el mayor puntaje, pero si esto implica que dañe la ejecución u otra funcionalidad requerida en el parcial, no se será benevolente con el mismo.
//El 29 / 06 se deberá traer el proyecto a clase para ser corregido.Es importante que no se copien, sean leales a ustedes mismo, ya que si no aprenden el camino se hace mas difícil y poco llevadero.El día de entrega me tendrán que explicar one to one todo lo que hicieron y contestar mis preguntas, si noto que no saben lo que realizaron eso implica una desaprobación directa.
//➡Nomenclatura de la entrega : NombreApellido_Parcial2.Se rechazara lo que no cumpla este requisito.