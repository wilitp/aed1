# Laboratorio 1 - Algorítmos y estructuras de datos 1

### 7. Indagá en Hoogle sobre las funciones map y filter. También podés consultar su tipo en ghci con el comando :t

Map y filter son funciones que reciben una función y una lista, y devuelven otra lista.

- Map devuelve una lista de igual longitud, en la que cada elemento es la imagen de aplicar la función recibida al elemento de igual posición en la lista recibida como input.

- Filter devuelve una lista con los elementos de la lista original que cumplen con el predicado(función) recibida.

#### ¿A qué equivale la expresión map succ [1, -4, 6, 2, -8], donde succ n = n+1?

```haskell
map succ [1, -4, 6, 2, -8] = [2, -3, 7, 3, -7]
```

#### ¿Y la expresión filter esPositivo [1, -4, 6, 2, -8]?

```haskell
filter esPositivo [1, -4, 6, 2, -8] = [1, 6, 2]
```
