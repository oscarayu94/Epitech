Addres is given like this

city, number streetType streetName

streetType :

    alle
    avenue
    boulevard
    chemin
    impasse
    place
    quai
    rue
    square

First look the city
    then the StreetName

The engine works on any name of street's

Each letter written = 5 most probable choices in descending order

Only one possibility = automatic validation

once a word is completed
    a) Unkown city 
        1)if only one city contains the letters sequence (as complete word or not)
        this city is validated
        2)if not// The list of all cities containing this sequence as a complete word is proposed in alphabetic order 


ERRORES DE FORMATO COMUN

city, number streetType streetName

1. Si no hay coma DONE
2. Si hay numeros antes de la coma fuera DONE
3. Si no hay 3 espacios fuera DONE
4. Si hay numeros despues del segundo espacio fuera.    DONE
5. Si despues del segundo espacio no coincide con los streetType, fuera. DONE

COMO ALMACENAR

LLegados aqui, yo haria lo siguiente

1. Almacenar ciudad DONE
2. Almacenar numeros DONE
3. Activar "tipos de avenida"
4. Almacenar nombres de ciudad. 

map

    KEY     ELEMENT

    City    Street 1, Street 2, Street 3, Street 4

    City2   Street 1, Street 2, Street 3.